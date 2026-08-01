# PlayerBot `.bot` 命令规划

> 状态：规划中（第一版实现待确认）
> 目标：为 LegionCore 7.3.5 PlayerBot 系统新增 GM/玩家聊天命令，用于机器人的上线、下线、组队、统计、创建等管理操作。

## 背景

- 目前机器人上线由 `PlayerBotMgr::Update()` 自动补满到 `PlayerBot.MaxOnlineCount`（默认 10），**无命令入口**。
- 全部下线函数 `PlayerBotMgr::AllPlayerBotLogout()` 已存在但**无调用者**（仅 FieldWarfare 战场清理用单个 `PlayerBotLogout`）。
- 快速组队能力缺失：目前只能手动 `/invite` 附近 FieldAI 机器人（机器人自动接受邀请，`BotFieldAI.cpp:513-547`）。
- `@` 前缀命令（`@attack`/`@follow`/`@stop`/`@summon` 等）已恢复（`Chat.cpp PlayerExtraCommand`），组队内对 bot 生效。

## 命令概览

### 1. 玩家级命令（`SEC_PLAYER`，所有玩家可用）

| 命令 | 功能 | 实现 |
|------|------|------|
| `.bot team [数量]` | 快速组队：从附近在线 bot 中自动挑选补齐队伍（默认补到 5 人） | 遍历在线 bot，按距离筛选，`Group::AddMember` 直接入队 |
| `.bot invite <名称>` | 邀请指定 bot 入队 | 对指定 bot 执行 `Group::AddMember`（或复用邀请流程） |
| `.bot dismiss` | 队伍内所有 bot 离队 | `LogoutAllGroupPlayerBot(group, true)` + `Group::RemoveMember` |

### 2. GM 命令（`SEC_ADMINISTRATOR`）

| 命令 | 功能 | 实现（复用已有函数） |
|------|------|------|
| `.bot login [数量]` | 上线机器人到指定数量（无参数 = 补满上限） | `SetMax(n)` + `AllPlayerBotRandomLogin()` |
| `.bot logout` | **全部机器人下线** | `AllPlayerBotLogout()` |
| `.bot info` | 查看在线统计（各阵营数量、当前/上限） | `GetOnlineBotCount(team, true)` |
| `.bot max <数量>` | 设置在线 bot 上限 | `SetMax(n)`（改 `m_MaxOnlineBot`，配置 `PlayerBot.MaxOnlineCount`） |
| `.bot spawn <职业>` | 按职业创建新 bot 角色 | `AddNewPlayerBotByClass(count, Classes)` |
| `.bot reload` | 重新加载 bot 账号/角色信息 | `LoadPlayerBotBaseInfo()` |

### 3. 兼容层

- 保留现有 `@` 前缀命令（聊天框输入，组队内生效）：`@summon` `@attack` `@follow` `@stop` `@flee` `@setting` `@talent` `@c` `@e <slot>` `@ue <slot>` `@destroy <slot>` `@s` `@u` `@rite` `@<spellID>` `@tank/melee/ranged/dps/heal/职业前缀 ...`。

## 实现要点

- 新增文件：`src/server/scripts/Commands/cs_bot.cpp`（命令脚本，`CommandScript` 模式）。
- 注册：`ScriptLoader.cpp` 的 `AddCommandScripts()` 中加 `AddSC_bot_commandscript();`。
- 权限：玩家命令 `SEC_PLAYER`，GM 命令 `SEC_ADMINISTRATOR`。
- 依赖：`sPlayerBotMgr`（`PlayerBotMgr.h`）、`sFieldBotMgr`（`FieldBotMgr.h`）单例可直接从 scripts 层调用。
- CMake：`src/server/scripts/Commands` 使用 GLOB 收集源码，**无需改 CMakeLists**。

## 关键函数签名参考

```cpp
// PlayerBotMgr.h (公开接口)
void AllPlayerBotRandomLogin(const char* name = "");   // 补满 m_MaxOnlineBot
void AllPlayerBotLogout();                             // 全部下线
bool PlayerBotLogout(uint32 account);                  // 单个账号下线
void SetMax(int max);                                  // 设置上限
uint32 GetOnlineBotCount(TeamId team, bool hasReal);   // 在线统计
bool AddNewPlayerBotByClass(uint32 count, Classes prof);
void LoadPlayerBotBaseInfo();
void LoginGroupBotByPlayer(Player* pPlayer);           // 队伍内离线 bot 上线
void LogoutAllGroupPlayerBot(Group* pGroup, bool force);

// Group.h
bool AddMember(Player* player);                        // 直接入队
```

## 待确认事项

- [ ] 第一版实现哪些命令（建议先做 `.bot on/.bot off`）
- [ ] `.bot team` 选人策略：按距离 vs 按职业（坦/奶/输出）
- [ ] `.bot team` 是否需要把 bot 传送至玩家附近后再组队
- [ ] `.bot spawn` 的职业参数格式（中文名 vs 拼音 vs 数字）
