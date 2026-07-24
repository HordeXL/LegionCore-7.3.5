# LegionPlayerBot 移植指南

## 将 PlayerBot 机器人模块移植到 LegionCore-7.3.5

> **源仓库**: https://github.com/normalzero/LegionPlayerBot  
> **目标仓库**: 当前工作空间 `LegionCore-7.3.5`  
> **文档版本**: 1.0

---

## 目录

1. [概述](#1-概述)
2. [架构总览](#2-架构总览)
3. [需要移植的完整文件清单](#3-需要移植的完整文件清单)
4. [构建系统修改](#4-构建系统修改)
5. [数据库修改](#5-数据库修改)
6. [核心代码集成点（钩子）](#6-核心代码集成点钩子)
7. [配置文件修改](#7-配置文件修改)
8. [编译步骤](#8-编译步骤)
9. [已知问题与注意事项](#9-已知问题与注意事项)
10. [附录](#10-附录)

---

## 1. 概述

### 1.1 什么是 LegionPlayerBot？

LegionPlayerBot 是一个基于 LegionCore 7.3.5（魔兽世界模拟器）的**玩家机器人（PlayerBot）模块**。它允许服务器创建由 AI 控制的虚拟玩家角色，这些机器人能够：

- **自动排队进入战场**（战歌峡谷、阿拉希盆地、风暴之眼等），补充真实玩家不足
- **自动排队进入竞技场**（2v2/3v3/5v5），支持评级和非评级
- **野外行为**：在世界地图上漫游、与玩家互动、触发野外 PvP 战斗
- **组队行为**：与真实玩家组队，协助打怪、完成任务
- **决斗**：接受玩家发起的决斗
- **聊天系统**：在公共频道、队伍频道中发言，触发故事对话
- **装备/天赋管理**：根据等级自动配装、学习法术和天赋

### 1.2 移植范围

当前工作空间的 `LegionCore-7.3.5` **没有任何 PlayerBot 代码**。移植需要从源仓库复制以下部分：

| 组件 | 位置 | 文件数 | 复杂度 |
|------|------|--------|--------|
| PlayerBot 核心管理 | `src/server/game/PlayerBot/` | 10 个文件 | ⭐⭐⭐ |
| 玩家 AI 系统 | `src/server/game/AI/PlayerAI/` | 大量文件 | ⭐⭐⭐⭐⭐ |
| PlayerBot Session | `src/server/game/Server/` | 2 个文件 | ⭐⭐ |
| 数据库 SQL | `sql/` | 1 个 RAR 压缩包 | ⭐⭐ |
| 构建系统 | `cmake/` + `CMakeLists.txt` | 少量修改 | ⭐ |
| 配置文件 | `worldserver.conf.dist` | 少量修改 | ⭐ |

---

## 2. 架构总览

### 2.1 模块依赖关系

```
worldserver (主程序)
  └── game (游戏库)
       ├── Server/
       │    ├── PlayerBotSession.h/.cpp    ← 自定义 WorldSession 子类
       │    └── OnlineMgr.h/.cpp           ← 在线管理（含机器人统计）
       ├── PlayerBot/
       │    ├── PlayerBotMgr.h/.cpp        ← 核心管理器（登录/注销/排队/战场填充）
       │    ├── PlayerBotSetting.h/.cpp    ← 装备/天赋/法术配置
       │    ├── PlayerBotTalkMgr.h/.cpp    ← 聊天系统管理
       │    ├── FieldBotMgr.h/.cpp         ← 野外行为管理
       │    └── AIWaypointsMgr.h/.cpp      ← AI 路径点管理
       └── AI/PlayerAI/
            ├── BotAI.h/.cpp               ← 基础 AI 类（BotBGAI）
            ├── BotAITool.h/.cpp           ← AI 工具类/常量
            ├── BotAISpells.h/.cpp         ← AI 法术管理
            ├── BotMovementAI.h/.cpp       ← AI 移动逻辑
            ├── BotBGAIMovement.h/.cpp     ← 战场 AI 移动
            ├── BotFieldAI/                ← 野外 AI
            ├── BotGroupAI/                ← 组队 AI
            ├── BotDuelAI/                 ← 决斗 AI
            ├── BotArenaAI/                ← 竞技场 AI
            └── BotClassAI/                ← 各职业 AI（战士/法师/牧师等）
```

### 2.2 核心类说明

| 类名 | 职责 | 关键方法 |
|------|------|----------|
| `PlayerBotMgr` | 全局单例，管理所有机器人账号的登录/注销、战场排队填充、竞技场组队 | `Update()`, `AddNewPlayerBotToBG()`, `SwitchPlayerBotAI()`, `QueryBattlegroundRequirement()` |
| `PlayerBotSession` | 继承 `WorldSession`，代表机器人会话，管理调度队列 | `ProcessOnline()`, `ProcessOffline()`, `ProcessInBGQueue()`, `ProcessEnterBG()` |
| `PlayerBotSetting` | 管理机器人角色的装备、天赋、法术、坐骑配置 | `ResetPlayerToLevel()`, `LearnSpells()`, `LearnTalents()`, `EquipItem()` |
| `PlayerBotTalkMgr` | 管理机器人聊天文本，支持普通对话、故事对话、战斗喊话 | `PlayerBotTalkByType()`, `NormalTalk()`, `TriggerStoryTalk()` |
| `FieldBotMgr` | 管理野外机器人行为，包括传送、野外 PvP、故事表演 | `Update()`, `KillFieldPlayer()`, `CanTriggerWarfare()` |
| `AIWaypointsMgr` | 管理 AI 路径点系统 | `LoadAIWaypoints()`, `CreateAIWPCreature()`, `LinkWaypoint()` |
| `BotFieldAI` | 玩家野外 AI（继承自 `PlayerAI`） | `UpdateBotAI()`, `ResetBotAI()` |
| `BotGroupAI` | 玩家组队 AI | `UpdateBotAI()`, `ProcessNormalSpell()` |
| `BotDuelAI` | 决斗 AI | `DuelIsStart()`, `TryFinishDuel()` |
| `BotArenaAI` | 竞技场 AI | `UpdateAI()`, `ResetBotAI()` |
| `BotBGAI` | 战场 AI（定义在 `BotAI.h` 中） | `UpdateBotAI()`, `ResetBotAI()` |
| `BotUtility` | 静态工具类，提供伤害修正、物品操作、法术处理等 | `BotUtility::CalcBotDamage()`, `BotUtility::GetBotRndItemByLevel()` |

---

## 3. 需要移植的完整文件清单

### 3.1 PlayerBot 核心管理模块（`src/server/game/PlayerBot/`）

从源仓库复制以下 **10 个文件**：

| 文件名 | 大小 | 说明 |
|--------|------|------|
| `PlayerBotMgr.h` | ~12 KB | 核心管理器头文件 - 枚举、结构体、类声明 |
| `PlayerBotMgr.cpp` | ~108 KB | 核心管理器实现 - 登录/战场/竞技场逻辑 |
| `PlayerBotSetting.h` | ~6 KB | 装备/天赋配置头文件 |
| `PlayerBotSetting.cpp` | ~84 KB | 装备/天赋配置实现 - 各职业配装 |
| `PlayerBotTalkMgr.h` | ~3.5 KB | 聊天系统头文件 |
| `PlayerBotTalkMgr.cpp` | ~8.5 KB | 聊天系统实现 |
| `FieldBotMgr.h` | ~4.2 KB | 野外管理头文件 |
| `FieldBotMgr.cpp` | ~37 KB | 野外管理实现 - 野外 PvP 系统 |
| `AIWaypointsMgr.h` | ~2.3 KB | AI 路径点头文件 |
| `AIWaypointsMgr.cpp` | ~11 KB | AI 路径点实现 |

### 3.2 PlayerBot Session 模块（`src/server/game/Server/`）

| 文件名 | 说明 |
|--------|------|
| `PlayerBotSession.h` | 继承 `WorldSession`，包含 `BotGlobleSchedule` 调度系统 |
| `PlayerBotSession.cpp` | 调度实现：在线/离线/排队/进出战场/竞技场/LFG |
| `OnlineMgr.h` | 在线玩家管理，含机器人账号信息统计 |
| `OnlineMgr.cpp` | 在线管理实现 |

### 3.3 AI 系统模块（`src/server/game/AI/PlayerAI/`）

这是最大也是最复杂的部分。需要从源仓库的 `AI/PlayerAI/` 目录移植以下文件：

**根目录文件：**

| 文件名 | 说明 |
|--------|------|
| `BotAI.h` | 定义 `BotBGAI` 类（继承 `PlayerAI`），战场 AI 状态枚举，大量类型定义 |
| `BotAI.cpp` | BotBGAI 实现 |
| `BotAITool.h` | AI 工具类 `BotUtility`，常量定义（`BOTAI_UPDATE_TICK` 等） |
| `BotAITool.cpp` | BotUtility 实现：伤害计算、物品操作、法术处理、移动辅助 |
| `BotAISpells.h` | AI 法术管理头文件 |
| `BotAISpells.cpp` | 法术管理实现 |
| `BotMovementAI.h` | AI 移动逻辑头文件 |
| `BotMovementAI.cpp` | 移动逻辑实现 |
| `BotBGAIMovement.h` | 战场 AI 移动头文件 |
| `BotBGAIMovement.cpp` | 战场 AI 移动实现 |
| `PlayerAI.h` | 基础 PlayerAI 类（机器人 AI 的基类） |
| `PlayerAI.cpp` | PlayerAI 实现 |

**子目录（每个目录包含 .h 和 .cpp）：**

| 目录 | 文件 | 说明 |
|------|------|------|
| `BotFieldAI/` | `BotFieldAI.h`, `BotFieldAI.cpp` | 野外 AI 实现 |
| `BotGroupAI/` | `BotGroupAI.h`, `BotGroupAI.cpp` | 组队 AI 实现 |
| `BotDuelAI/` | `BotDuelAI.h`, `BotDuelAI.cpp` | 决斗 AI 实现 |
| `BotArenaAI/` | `BotArenaAI.h`, `BotArenaAI.cpp` | 竞技场 AI 实现 |
| `BotClassAI/` | 各职业 AI 文件 | 职业专属 AI 行为 |

### 3.4 数据库 SQL 文件（`sql/`）

| 文件 | 说明 |
|------|------|
| `sql/justbot.rar` | 包含机器人相关的数据库表结构和数据（需要解压） |

### 3.5 其他修改文件

| 文件/目录 | 操作 | 说明 |
|-----------|------|------|
| `cmake/options.cmake` | 修改 | 添加 `PLAYERBOT` 编译选项 |
| `src/server/game/CMakeLists.txt` | 修改 | 添加 PlayerBot 条件编译 |
| `src/server/worldserver/worldserver.conf.dist` | 修改 | 添加 PlayerBot 配置项 |
| `src/server/game/PrecompiledHeaders/gamePCH.h` | 可选修改 | 添加 PlayerBot 头文件以加速编译 |

---

## 4. 构建系统修改

### 4.1 添加编译选项（`cmake/options.cmake`）

在文件末尾添加：

```cmake
option(PLAYERBOT        "Build core with playerbot module"                           1)
```

完整的 `options.cmake` 修改后应如下所示：

```cmake
option(SERVERS          "Build worldserver and bnetserver"                            1)
option(SCRIPTS          "Build core with scripts included"                            1)
option(USE_SCRIPTPCH    "Use precompiled headers when compiling scripts"              1)
option(USE_COREPCH      "Use precompiled headers when compiling servers"              1)
option(WITH_WARNINGS    "Show all warnings during compile"                            0)
option(WITH_COREDEBUG   "Include additional debug-code in core"                       0)
option(ELUNA            "Include Eluna Lua Engine"                                    1)
option(PLAYERBOT        "Build core with playerbot module"                           1)  # ← 新增

set(WITH_SOURCE_TREE    "hierarchical" CACHE STRING "Build the source tree for IDE's.")
set_property(CACHE WITH_SOURCE_TREE PROPERTY STRINGS no flat hierarchical hierarchical-folders)
option(WITHOUT_GIT      "Disable the GIT testing routines"                            1)
```

### 4.2 修改游戏库 CMakeLists（`src/server/game/CMakeLists.txt`）

在 `CollectSourceFiles` 调用之后、`add_library` 之前，添加 PlayerBot 的条件编译块：

```cmake
# 在 CollectSourceFiles 之后添加
if (PLAYERBOT)
  # 添加 PlayerBot 模块源文件
  file(GLOB_RECURSE PLAYERBOT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBot/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerBot/*.h)

  # 添加 AI 系统源文件（PlayerAI 目录下的所有 Bot* 文件）
  file(GLOB_RECURSE PLAYERBOT_AI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/AI/PlayerAI/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AI/PlayerAI/*.h)

  # 添加 Server 目录下的 PlayerBot 相关文件
  list(APPEND PLAYERBOT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/PlayerBotSession.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/PlayerBotSession.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/OnlineMgr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Server/OnlineMgr.h)

  list(APPEND PRIVATE_SOURCES ${PLAYERBOT_SOURCES} ${PLAYERBOT_AI_SOURCES})

  message(STATUS "PlayerBot module: ENABLED")
endif()
```

**注意**: 当前工作空间的 `CollectSourceFiles` 会自动收集所有源文件。如果保持了自动收集，则只需确保文件放在正确的位置即可。但推荐使用条件编译以控制是否启用 PlayerBot。

### 4.3 添加预处理器定义（在 `game/CMakeLists.txt` 中）

在 `if (PLAYERBOT)` 块中添加：

```cmake
if (PLAYERBOT)
  target_compile_definitions(game PRIVATE PLAYERBOT)
  # ... 其他配置
endif()
```

---

## 5. 数据库修改

### 5.1 SQL 文件内容

源仓库的 `sql/justbot.rar` 是一个压缩包，需要解压后查看其中的 SQL 内容。根据源码分析，PlayerBot 模块需要以下数据库表：

**Login 数据库（`login` 或 `auth`）：**

| 表名 | 用途 | 推测结构 |
|------|------|----------|
| `playerbot_random_name` | 机器人随机名字库 | `entry` (主键), `name` (角色名) |
| `playerbot_arena_name` | 竞技场队伍随机名字库 | `entry` (主键), `name` (队伍名) |

**Character 数据库（`characters`）：**

| 表名 | 用途 | 推测结构 |
|------|------|----------|
| `playerbot_base_info` | 机器人账号基础信息 | `entry`, `account`, `name`, `race`, `class`, `gender`, `level` |
| `playerbot_equip_template` | 机器人装备模板 | `entry`, `class`, `level`, `slot`, `item_id` |
| `playerbot_talent_template` | 机器人天赋模板 | `entry`, `class`, `talent_id`, `rank` |
| `playerbot_spell_template` | 机器人法术模板 | `entry`, `class`, `spell_id` |
| `playerbot_mount_template` | 机器人坐骑模板 | `entry`, `level`, `mount_id` |
| `playerbot_talk_text` | 机器人聊天文本 | `entry`, `type`, `sub_type`, `text` |
| `playerbot_story` | 机器人故事对话 | `entry`, `step`, `index`, `text` |
| `ai_waypoints` | AI 路径点 | `entry`, `map`, `x`, `y`, `z`, `link_info`, `description` |

**World 数据库（`world`）：**

| 表名 | 用途 |
|------|------|
| `playerbot_equip_template` | 装备模板（与 characters 库可能重复，需确认） |

### 5.2 移植步骤

1. 解压 `sql/justbot.rar` 查看具体 SQL 内容
2. 根据实际 SQL 内容，在对应的数据库中执行建表语句
3. 插入初始数据（机器人名字库、装备模板等）
4. 创建 `playerbot` 前缀的机器人账号（如 `playerbot1`, `playerbot2` 等）

---

## 6. 核心代码集成点（钩子）

移植 PlayerBot 不仅仅是复制文件，还**需要在现有核心代码中插入钩子**。以下是需要修改的现有文件：

### 6.1 WorldSession 创建钩子

在 `WorldSession` 的创建逻辑中，需要识别机器人账号并使用 `PlayerBotSession` 替代普通 `WorldSession`。

**参考位置**: `src/server/game/Server/WorldSession.cpp`（或类似位置）

需要修改：
- 在 `WorldSession` 构造函数或工厂方法中，检查账号名是否以 `"playerbot"` 开头
- 如果是，创建 `PlayerBotSession` 而非普通 `WorldSession`

```cpp
// 伪代码示例
if (IsBotAccountName(accountName))
    session = new PlayerBotSession(accountId, ...);
else
    session = new WorldSession(accountId, ...);
```

### 6.2 Player 登录/登出钩子

在 `Player` 的登录和登出流程中调用 `PlayerBotMgr` 的回调：

| 需要修改的文件 | 需要添加的调用 |
|---------------|--------------|
| `Player.cpp` (或 `PlayerHandler.cpp`) | 登录时：`sPlayerBotMgr->OnPlayerBotLogin(pSession, pPlayer)` |
| | 登出时：`sPlayerBotMgr->OnPlayerBotLogout(pSession)` |
| | 角色创建时：`sPlayerBotMgr->OnPlayerBotCreate(...)` |

### 6.3 战场系统钩子

在 `BattlegroundMgr` 和 `BattlegroundQueue` 中插入 PlayerBot 填充逻辑：

| 需要修改的文件 | 需要添加的调用 |
|---------------|--------------|
| `BattlegroundMgr.cpp` | 玩家加入战场队列时：`sPlayerBotMgr->OnRealPlayerJoinBattlegroundQueue(...)` |
| | 玩家离开战场队列时：`sPlayerBotMgr->OnRealPlayerLeaveBattlegroundQueue(...)` |
| `Battleground.cpp` | 玩家进入战场时：`sPlayerBotMgr->OnRealPlayerEnterBattleground(...)` |
| | 玩家离开战场时：`sPlayerBotMgr->OnRealPlayerLeaveBattleground(...)` |

### 6.4 主循环钩子

在 `World.cpp` 的 `World::Update()` 主循环中，添加 `PlayerBotMgr` 的更新：

```cpp
// 在 World::Update() 中添加
if (PLAYERBOT)
    sPlayerBotMgr->Update();
```

### 6.5 竞技场系统钩子

在竞技场组队和排队逻辑中，需要插入机器人填充逻辑：

| 需要修改的文件 | 说明 |
|---------------|------|
| `ArenaTeamMgr.cpp` | 可能需要添加机器人竞技场队伍管理 |
| `BattlegroundQueue.cpp` | 需要添加 `ExistRealPlayer()` 等方法（源仓库中使用了这些方法） |

### 6.6 FieldBotMgr 钩子

在 `Player.cpp` 的击杀事件中：

```cpp
// 在玩家击杀另一个玩家时
if (PLAYERBOT)
    sFieldBotMgr->KillFieldPlayer(pAttacker, pVictim);
```

### 6.7 配置文件加载钩子

在 `Config.cpp` 或 `World.cpp` 的配置加载中，读取 PlayerBot 相关的配置项：

```cpp
if (PLAYERBOT) {
    uint32 maxBot = sConfigMgr->GetOption<uint32>("PlayerBot.MaxOnlineCount", 10);
    sPlayerBotMgr->SetMax(maxBot);
}
```

---

## 7. 配置文件修改

### 7.1 添加 PlayerBot 配置节（`worldserver.conf.dist`）

在文件末尾添加以下配置节：

```ini
###############################################################################
# PLAYER BOT SETTINGS
###############################################################################

PlayerBot.Enable = 1
#           启用/禁用 PlayerBot 模块 (1 = 启用, 0 = 禁用)

PlayerBot.MaxOnlineCount = 10
#           最大同时在线机器人数量

PlayerBot.AccountPrefix = "PLAYERBOT"
#           机器人账号名前缀，用于识别机器人账号

PlayerBot.AccountCount = 90
#           机器人账号数量（从 1 开始编号）

PlayerBot.Battleground.Enable = 1
#           启用战场填充功能

PlayerBot.Arena.Enable = 1
#           启用竞技场填充功能

PlayerBot.Field.Enable = 1
#           启用野外机器人行为

PlayerBot.Talk.Enable = 1
#           启用机器人聊天系统

PlayerBot.FieldWarfare.Enable = 1
#           启用野外 PvP 战斗系统

PlayerBot.FieldWarfare.Size = 5
#           野外 PvP 每方最大参战人数
```

---

## 8. 编译步骤

### 8.1 前置条件

- 确保当前工作空间的 `LegionCore-7.3.5` 能在 VS2017/2019/2022 下正常编译
- 已安装 CMake 3.9+
- MySQL 客户端库已配置

### 8.2 移植步骤

#### 第一步：复制文件

```bash
# 从源仓库克隆或下载源码
git clone https://github.com/normalzero/LegionPlayerBot.git /tmp/legionplayerbot

# 1. 复制 PlayerBot 核心模块
cp -r /tmp/legionplayerbot/src/server/game/PlayerBot \
      ./src/server/game/PlayerBot

# 2. 复制 AI 系统（PlayerAI 目录）
# 注意：需要完整复制 AI/PlayerAI/ 目录及其所有子目录
cp -r /tmp/legionplayerbot/src/server/game/AI/PlayerAI \
      ./src/server/game/AI/PlayerAI

# 3. 复制 Session 和 OnlineMgr
cp /tmp/legionplayerbot/src/server/game/Server/PlayerBotSession.h \
   ./src/server/game/Server/PlayerBotSession.h
cp /tmp/legionplayerbot/src/server/game/Server/PlayerBotSession.cpp \
   ./src/server/game/Server/PlayerBotSession.cpp
cp /tmp/legionplayerbot/src/server/game/Server/OnlineMgr.h \
   ./src/server/game/Server/OnlineMgr.h
cp /tmp/legionplayerbot/src/server/game/Server/OnlineMgr.cpp \
   ./src/server/game/Server/OnlineMgr.cpp

# 4. 复制 SQL 文件
cp /tmp/legionplayerbot/sql/justbot.rar ./sql/
```

#### 第二步：修改 CMake 构建系统

按照 [第 4 节](#4-构建系统修改) 的描述修改：
- `cmake/options.cmake` — 添加 `PLAYERBOT` 选项
- `src/server/game/CMakeLists.txt` — 添加条件编译

#### 第三步：添加核心钩子

按照 [第 6 节](#6-核心代码集成点钩子) 的描述，在现有核心代码中插入钩子调用。

#### 第四步：应用数据库修改

1. 解压 `sql/justbot.rar`
2. 查看 SQL 内容，了解需要哪些表
3. 在对应的数据库中手动创建表并插入数据
4. 创建机器人账号（`playerbot1` ~ `playerbot90`）

#### 第五步：更新配置文件

1. 在 `worldserver.conf.dist` 中添加 [第 7 节](#7-配置文件修改) 的配置项
2. 复制到 `worldserver.conf` 并配置

#### 第六步：编译

```bash
# 重新生成 CMake 配置
cd build
cmake .. -DPLAYERBOT=1

# 编译
# 对于 Visual Studio:
cmake --build . --config Release --target game
# 或直接打开 LegionCore.sln 编译 game 项目
```

### 8.3 验证编译

1. 确保 `game` 库编译成功，无链接错误
2. 确认 `worldserver` 可执行文件已更新
3. 启动服务器，检查日志中是否有 PlayerBot 初始化信息

---

## 9. 已知问题与注意事项

### 9.1 源仓库已知问题（来自 README）

| 问题 | 描述 |
|------|------|
| 战场寻路 | 机器人在战场中无法主动寻路，只能被动跟随 |
| 数据库不完整 | 除 PlayerBot 相关表外，其他数据库内容缺失 |
| BotGroupAI | 组队 AI 工作不完全 |
| 竞技场 Opcode | 机器人加入竞技场的 Opcode 需要补充实现 |

### 9.2 移植注意事项

1. **API 兼容性检查**：源仓库可能与当前工作空间存在 API 差异（如 `BattlegroundQueue` 接口、`ObjectGuid` 构造方式、`MS::Battlegrounds` 命名空间等）。移植后需要逐个修复编译错误。

2. **`INCOMPLETE_BOT` 宏**：源仓库多处使用 `#ifdef INCOMPLETE_BOT` 来限制仅战士/盗贼/法师（职业 1/5/9）有效。移植时建议先定义此宏，等稳定后再取消。

3. **`CONVERT_ARENAAI_TOBG` 宏**：在 `PlayerBotMgr.h` 中定义了此宏，将竞技场 AI 转换为战场 AI。如果不需要竞技场功能，可以保留此定义。

4. **`NON_SINGLE_GAME` 宏**：在 `PlayerBotMgr.cpp` 的构造函数中用于控制战场类型列表。需要根据你的需求定义。

5. **`PlayerAI` 基类**：`BotFieldAI`、`BotGroupAI`、`BotDuelAI`、`BotArenaAI` 都继承自 `PlayerAI`，而 `BotBGAI` 也继承自 `PlayerAI`。需要确保 `PlayerAI` 类在当前工作空间存在且接口兼容。

6. **`UnitAI` 接口**：机器人 AI 系统使用 `player->SetAI()` 和 `player->GetAI()` 来切换 AI 类型。需要确保 `Player` 类支持 `UnitAI` 接口。

7. **线程安全**：`PlayerBotMgr` 使用 `std::mutex g_uniqueLock` 确保线程安全，移植时需确认当前工作空间的线程模型是否兼容。

8. **`sWorld->FindSession()` 和 `sWorld->GetAllSessions()`**：这些方法在源仓库中被频繁使用，需要确保当前工作空间有相同接口。

### 9.3 推荐移植顺序

建议按以下顺序逐步移植，每步完成后编译验证：

```
第一阶段（核心编译通过）：
  1. PlayerBot/ 目录（10 个文件）
  2. Server/PlayerBotSession.h/.cpp
  3. Server/OnlineMgr.h/.cpp
  4. 修改 CMakeLists.txt，启用 PLAYERBOT

第二阶段（AI 系统编译通过）：
  5. AI/PlayerAI/ 根目录文件（BotAI, BotAITool, BotAISpells, BotMovementAI, PlayerAI）
  6. 各子目录 AI（BotFieldAI, BotGroupAI, BotDuelAI, BotArenaAI）
  7. BotClassAI/ 各职业 AI

第三阶段（功能集成）：
  8. 添加核心钩子（WorldSession 创建、Player 登录/登出）
  9. 战场和竞技场钩子
  10. 主循环更新

第四阶段（数据库和配置）：
  11. 应用 SQL
  12. 配置 worldserver.conf
  13. 启动测试
```

---

## 10. 附录

### 10.1 源仓库关键文件引用

以下是 PlayerBot 头文件中引用的主要外部依赖，移植时需确保这些文件在当前工作空间存在：

| 引用头文件 | 所在位置 | 说明 |
|-----------|---------|------|
| `"Log.h"` | `src/common/Logging/` | 日志系统 |
| `"Common.h"` | `src/common/` | 通用定义 |
| `"SharedDefines.h"` | `src/server/game/` | 共享定义 |
| `"DatabaseEnv.h"` | `src/server/shared/` | 数据库访问 |
| `"Timer.h"` | `src/common/` | 计时器 |
| `"Player.h"` | `src/server/game/Entities/Player/` | 玩家实体 |
| `"World.h"` | `src/server/game/World/` | 世界服务器 |
| `"BattlegroundMgr.h"` | `src/server/game/Battlegrounds/` | 战场管理器 |
| `"Battleground.h"` | `src/server/game/Battlegrounds/` | 战场类 |
| `"BattlegroundQueue.h"` | `src/server/game/Battlegrounds/` | 战场队列 |
| `"Group.h"` | `src/server/game/Groups/` | 队伍系统 |
| `"LFGMgr.h"` | `src/server/game/DungeonFinding/` | 随机副本 |
| `"Config.h"` | `src/server/game/World/` | 配置系统 |
| `"AccountMgr.h"` | `src/server/game/Accounts/` | 账号管理 |
| `"DB2Stores.h"` | `src/server/game/DataStores/` | 数据存储 |
| `"ChannelMgr.h"` | `src/server/game/Chat/` | 频道管理 |
| `"SocialMgr.h"` | `src/server/game/Entities/Player/` | 社交管理器 |
| `"CharacterPackets.h"` | `src/server/game/Server/Packets/` | 角色数据包 |
| `"Containers.h"` | `src/common/` | 容器工具 |

### 10.2 源仓库中使用的特殊 API

移植时需要注意以下 API 在当前工作空间中是否存在或名称是否一致：

| API | 使用位置 | 可能的问题 |
|-----|---------|-----------|
| `MS::Battlegrounds::BattlegroundTypeId` | PlayerBotMgr.cpp | 命名空间可能不同 |
| `MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID()` | PlayerBotMgr.cpp | 函数名可能不同 |
| `MS::Battlegrounds::MaxBrackets` | PlayerBotMgr.cpp | 常量名可能不同 |
| `sDB2Manager.GetBattlegroundBracketById()` | PlayerBotMgr.cpp | 管理类名可能不同 |
| `bgQueue.ExistRealPlayer()` | PlayerBotMgr.cpp | 需要检查是否存在此方法 |
| `bgQueue.QueryNeedPlayerCount()` | PlayerBotMgr.cpp | 需要检查是否存在此方法 |
| `bgQueue.GetFirstRealPlayerGroupInfo()` | PlayerBotMgr.cpp | 需要检查是否存在此方法 |
| `bgQueue.AllPlayerBotLeaveQueueFromRatedArena()` | PlayerBotMgr.cpp | 需要检查是否存在此方法 |
| `bg->ExistRealPlayer()` | PlayerBotMgr.cpp | 需要检查是否存在此方法 |
| `bg->GetFreeSlotsForTeam()` | PlayerBotMgr.cpp | 需要检查是否存在此方法 |
| `sWorld->FindSession().get()` | PlayerBotMgr.cpp | shared_ptr 接口可能不同 |
| `ObjectGuid::Create<HighGuid::Player>()` | PlayerBotMgr.cpp | ObjectGuid 构造方式可能不同 |
| `Trinity::Containers::RandomShuffle()` | PlayerBotMgr.cpp | 容器工具方法名可能不同 |
| `sObjectMgr->GetTrinityStringForDBCLocale()` | PlayerBotMgr.cpp | 字符串查询方法可能不同 |

### 10.3 快速参考命令

```bash
# 克隆源仓库
git clone https://github.com/normalzero/LegionPlayerBot.git /tmp/legionplayerbot

# 查看文件差异（对比 game 目录结构）
ls /tmp/legionplayerbot/src/server/game/ > /tmp/source_game_dirs.txt
ls ./src/server/game/ > /tmp/target_game_dirs.txt
diff /tmp/source_game_dirs.txt /tmp/target_game_dirs.txt

# 统计源仓库 PlayerBot 代码量
find /tmp/legionplayerbot/src/server/game/PlayerBot -name "*.cpp" -o -name "*.h" | xargs wc -l
find /tmp/legionplayerbot/src/server/game/AI/PlayerAI -name "*.cpp" -o -name "*.h" | xargs wc -l
```

---

> **文档维护者**: Reasonix AI  
> **最后更新**: 2026-07-24  
> **下一步建议**: 按照第 8.3 节的推荐移植顺序分阶段进行，每阶段完成后编译验证。