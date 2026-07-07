# Eluna Lua Engine 集成规划文档

## LegionCore 7.3.5 × Eluna

---

## 当前状态总览

| 类别 | 总计 | ✅ 已完成 | ⏳ 需处理 |
|------|:----:|:---------:|:---------:|
| 核心引擎文件 (`.cpp`) | 12 | 8 | 4 |
| Hook 实现 (`.cpp`) | 13 | 13 | 0 |
| Method 绑定 (`.h`) | 23 | 0 | 23 |
| AI 集成类 | 2 | 0 | 2 |
| API 编译阻塞 | — | — | **1** |

---

## Phase A：编译框架 ✅ **已完成**

| 文件 | 状态 | 说明 |
|------|:----:|------|
| `LuaEngine.cpp` | ✅ 完整 | 核心引擎，Push/CHECKVAL/Call 全功能 |
| `LuaEngine.h` | ✅ 完整 | `QueryCallbackProcessorStub` 已打桩 |
| `LuaValue.cpp` | ✅ 完整 | C++17 variant + `/Y-` PCH 处理 |
| `lmarshal.cpp` | ✅ 完整 | Lua 序列化库 |
| `ElunaConfig.cpp` | ✅ 完整 | 配置读取（ConfigMgr） |
| `ElunaEventMgr.cpp` | ✅ 完整 | 事件调度器 |
| `ElunaUtility.cpp` | ✅ 完整 | 工具函数 |
| `ElunaCompat.cpp` | ✅ 完整 | Lua 5.1 兼容层 |
| `ElunaMgr.cpp` | ✅ 完整 | Eluna 管理器单例 |
| `UniqueTrackablePtr.h` | ✅ 完整 | 智能指针兼容层 |
| `ElunaLoader.cpp` | 🔴 空桩 | 所有函数为空 |
| `ElunaTemplate.cpp` | 🔴 空桩 | 仅包含头文件 |
| `ElunaSpellWrapper.cpp` | ✅ 完整 | Spells 包装器 |
| `ElunaInstanceAI.cpp` | 🔴 空桩 | 仅包含头文件 |
| `ElunaInstanceAI.h` | ⚠️ 最小桩 | 方法为空实现 |
| `ElunaCreatureAI.h` | ⚠️ 最小桩 | 方法为空实现 |
| `Methods.cpp` | 🔴 空 | 所有绑定注册禁用 |
| Hook 文件 (`hooks/*`) | ✅ 完整 | 168 个事件全部实现 |

---

## Phase B：基础 Method 绑定

**目标**：启用低复杂度的 Lua API 绑定，让 Eluna 能被 Lua 脚本调用基础功能。

### B-1：修复编译阻塞

```cpp
// dep/eluna/methods/TrinityCore/UnitMethods.h:278
// 当前：  unit->IsAlive()    ← 现代 TC API
// 需改为：unit->isAlive()    ← LegionCore API（小写 i）
```

### B-2：启用 Method 文件

按复杂度从低到高依次启用：

| 优先级 | 文件 | 绑定数 | 涉及 API |
|:------:|------|:------:|----------|
| 1 | `GlobalMethods.h` | 108 | `sWorld`, `sObjectMgr`, `sMapMgr` 等全局单例 |
| 2 | `ObjectMethods.h` | 29 | `GetGUID()`, `GetEntry()`, `GetTypeId()` |
| 3 | `WorldObjectMethods.h` | 48 | `GetMap()`, `GetZoneId()`, `GetPhaseMask()` |
| 4 | `MapMethods.h` | 19 | `GetPlayers()`, `GetCreature()`, `GetGameObject()` |
| 5 | `QuestMethods.h` | 12 | `IsQuestRewarded()`, `GetQuestStatus()` |
| 6 | `CorpseMethods.h` | 5 | `GetGhostTime()`, `GetCorpseType()` |
| 7 | `BigIntMethods.h` | 22 | 大整数操作 |
| 8 | `ElunaQueryMethods.h` | 17 | 数据库查询结果读取 |
| 9 | `WorldPacketMethods.h` | 23 | 网络包读写 |
| 10 | `ElunaProcInfoMethods.h` | 28 | Proc 事件处理器 |

**操作**：修改 `Methods.cpp`：
- 添加对应 `#include` 头文件
- 调用 `ElunaTemplate<T>::Register(E, "TypeName")`
- 调用 `ElunaTemplate<T>::SetMethods(E, methodTable)`

### B-3：验证

```lua
-- 测试脚本 lua_scripts/test.lua
local player = GetPlayerByGUID(1)
print(player:GetName())
```

---

## Phase C：实体 Method 绑定

**目标**：启用 Unit/Creature/GameObject/Item/Spell/Aura 绑定。

| 优先级 | 文件 | 绑定数 | 风险 |
|:------:|------|:------:|------|
| 1 | `UnitMethods.h` | 167 | ⚠️ 需先修复 `isAlive()` |
| 2 | `SpellMethods.h` | 40 | 低 |
| 3 | `SpellInfoMethods.h` | 190 | 中 — 大量 getter |
| 4 | `CreatureMethods.h` | 92 | 中 — `SetEquipment`, `Loot` |
| 5 | `GameObjectMethods.h` | 20 | 低 |
| 6 | `ItemMethods.h` | 65 | 中 |
| 7 | `AuraMethods.h` | 13 | 低 |
| 8 | `AuraEffectMethods.h` | 23 | 低 |

### C-1：需要排查的 LegionCore API 差异

启用每个文件时，检查这些容易出问题的 API：

| 潜在问题 API | 现代 TC | LegionCore |
|-------------|---------|------------|
| `Unit::IsAlive` | 大写 I | `isAlive()` |
| `Unit::GetFactionTemplateEntry` | 首字母大写 G | `getFactionTemplateEntry()` |
| `Unit::JustEngagedWith` | ✅ 存在 | `EnterCombat()` |
| `CreatureAI::JustEngagedWith` | ✅ 存在 | `EnterCombat()` |
| `ObjectGuid::ToHexString` | ✅ 存在 | `ToString()` |
| `ObjectGuid::GetRawValue` | 返回 `uint64` | 返回 `vector<uint8>` |

---

## Phase D：社交/组队 Method 绑定

**目标**：启用 Player/Group/Guild/BG/Vehicle 绑定。

| 优先级 | 文件 | 绑定数 | 风险 |
|:------:|------|:------:|------|
| 1 | `PlayerMethods.h` | **267** | 🔴 最大文件，需要逐 API 验证 |
| 2 | `GroupMethods.h` | 27 | 低 |
| 3 | `GuildMethods.h` | 16 | 低 |
| 4 | `BattleGroundMethods.h` | 18 | 中 — BG API 版本差异 |
| 5 | `VehicleMethods.h` | 6 | 低 |

### D-1：PlayerMethods.h 特别关注

`PlayerMethods.h`（267 个绑定）是最复杂的文件，建议拆分验证：

- 第 1 批：只读 getter（`GetName`, `GetLevel`, `GetRace`, `GetClass` 等）
- 第 2 批：物品/装备操作（`GetItemByPos`, `GetEquippedItem`, `HasItem` 等）
- 第 3 批：任务/成就操作（`CompleteQuest`, `Achievement` 等）
- 第 4 批：社交/邮件（`SendMail`, `Guild` 等）
- 第 5 批：战斗/PVP（`Duel`, `Honor`, `Arena` 等）

---

## Phase E：高级功能集成

**目标**：启用脚本加载、AI 集成、异步查询。

| 优先级 | 组件 | 说明 |
|:------:|------|------|
| 1 | **ElunaLoader** | 实现 `ReadFiles`/`ProcessScript`/`CompileScript`/`LoadScripts`，从 `lua_scripts/` 加载脚本 |
| 2 | **ElunaCreatureAI** | 将 CreatureAI 钩子连接到 Eluna 事件系统，实现 `GetEluna()` |
| 3 | **ElunaInstanceAI** | 将 InstanceScript 事件连接到 Eluna，实现 `GetEluna()` |
| 4 | **QueryCallbackProcessor** | 移除 Stub，改用 LegionCore 真正的 `QueryCallbackProcessor` |

### E-1：ElunaLoader 实现

```cpp
// ElunaLoader.cpp 需要实现的主要函数：
void ElunaLoader::ReadFiles(std::string const&, ScriptList&);
void ElunaLoader::LoadBytecodeChunk(char const*, size_t);
void ElunaLoader::CombineLists(ScriptList&, ScriptList const&);
ElunaScript* ElunaLoader::ProcessScript(std::string const&, std::string const&);
ElunaScript* ElunaLoader::CompileScript(std::string const&, std::string const&);
```

### E-2：ElunaCreatureAI 集成

当前的 `ElunaCreatureAI.h` 是空桩，需要：

```cpp
class ElunaCreatureAI : public ScriptedAI {
    ElunaCreatureAI(Creature* creature);
    void InitializeAI() override;      // 创建 Eluna 实例
    void UpdateAI(uint32 diff) override; // 调用 Eluna 更新
    void EnterCombat(Unit* who) override; // 触发战斗事件
    void JustDied(Unit* killer) override;
    // ... 其他 AI 钩子
};
```

移除 `ElunaCreatureAI.h` 中的空方法，替换为实际调用。
在 `Eluna::OnCreatureEvent()` 中创建 `ElunaCreatureAI` 实例。

### E-3：ElunaInstanceAI 集成

当前的 `ElunaInstanceAI.h` 是空桩，需要：

```cpp
class ElunaInstanceAI : public InstanceData {
    ElunaInstanceAI(Map* map);
    void Initialize();           // 创建 Eluna 实例
    void Update(uint32 diff) override;  // 调用 Eluna 更新
    void OnPlayerEnter(Player*) override;
    void OnCreatureCreate(Creature*) override;
    void OnGameObjectCreate(GameObject*) override;
    std::string GetSaveData() override; // 序列化 Lua 数据到 DB
    void Load(const char*) override;    // 从 DB 加载 Lua 数据
    // ... 其他 InstanceData 方法
};
```

### E-4：QueryCallbackProcessor

LegionCore 自带 `QueryCallbackProcessor`（声明于 `World.h:1039`、`WorldSocket.h:154`、`WorldSession.h:2035`），可以直接使用：

```cpp
// LuaEngine.h - 移除 Stub，引入真实类型
#include <QueryCallbackProcessor.h>  // 如果存在
// 或直接使用 LegionCore 内置的类型
```

替换 `QueryCallbackProcessorStub` 为真实的 `QueryCallbackProcessor`，并实现异步数据库查询支持。

---

## API 差异速查表

| 类别 | 现代 TrinityCore | LegionCore 7.3.5 |
|------|-----------------|-------------------|
| **Unit** | `IsAlive()` | `isAlive()` |
| **Unit** | `GetFactionTemplateEntry()` | `getFactionTemplateEntry()` |
| **Unit** | `JustEngagedWith(Unit*)` | `EnterCombat(Unit*)` |
| **CreatureAI** | `JustEngagedWith(Unit*)` | `EnterCombat(Unit*)` |
| **ObjectGuid** | `ToHexString()` | `ToString()` |
| **ObjectGuid** | `GetRawValue()` → `uint64` | `GetRawValue()` → `vector<uint8>` |
| **ObjectGuid** | `GetHighPart()`/`GetLowPart()` | ✅ 一致 |
| **Logging** | `TC_LOG_*` | `TC_LOG_*` (filter: `LOG_FILTER_TSCR`) |
| **时间** | `getMSTime()` | ✅ 一致 |
| **时间差** | `GetMSTimeDiffToNow()` | ✅ 一致 |
| **Config** | `sConfigMgr->GetBoolDefault` | ✅ 一致 |
| **Instance** | `InstanceScript` | `InstanceScript` (extend `ZoneScript`) |
| **QueryCallback** | `QueryCallbackProcessor` | ✅ 存在（`World.h:1039`） |
| **ChatCommand** | `ChatCommand` | ✅ 一致 |
| **WorldPacket** | `WorldPacket(ByteBuffer)` | ✅ 一致 |
| **SpellInfo** | `sSpellMgr->GetSpellInfo(id)` | ✅ 一致 |
| **GET_GUID** | `GetGUID()` | ✅ 一致 |

---

## 编译文件清单

### 当前编译的核心文件（12 个）

| # | 文件 | Phase A | Phase B-E |
|:-:|------|:-------:|:---------:|
| 1 | `LuaValue.cpp` | ✅ 编译 | ✅ 不变 |
| 2 | `lmarshal.cpp` | ✅ 编译 | ✅ 不变 |
| 3 | `LuaEngine.cpp` | ✅ 编译 | ✅ 不变 |
| 4 | `ElunaConfig.cpp` | ✅ 编译 | ✅ 不变 |
| 5 | `ElunaEventMgr.cpp` | ✅ 编译 | ✅ 不变 |
| 6 | `ElunaUtility.cpp` | ✅ 编译 | ✅ 不变 |
| 7 | `ElunaTemplate.cpp` | 🔴 空桩 | 📝 需要实现 |
| 8 | `ElunaSpellWrapper.cpp` | ✅ 编译 | ✅ 不变 |
| 9 | `ElunaInstanceAI.cpp` | 🔴 空桩 | 📝 Phase E 需要实现 |
| 10 | `ElunaLoader.cpp` | 🔴 空桩 | 📝 Phase E 需要实现 |
| 11 | `hooks/ServerHooks.cpp` | ✅ 编译 | ✅ 不变 |
| 12 | `methods/Methods.cpp` | 🔴 空 | 📝 Phase B-D 逐步启用 |

### 当前排除的 Hook 文件（12 个）

`CMakeLists.txt` 中需要逐步添加：

| 文件 | Phase |
|------|:----:|
| `hooks/CreatureHooks.cpp` | Phase C（需要配合 AI 集成） |
| `hooks/PlayerHooks.cpp` | Phase D |
| `hooks/SpellHooks.cpp` | Phase C |
| `hooks/GameObjectHooks.cpp` | Phase C |
| `hooks/InstanceHooks.cpp` | Phase E |
| `hooks/ItemHooks.cpp` | Phase D |
| `hooks/GroupHooks.cpp` | Phase D |
| `hooks/GuildHooks.cpp` | Phase D |
| `hooks/GossipHooks.cpp` | Phase D |
| `hooks/BattleGroundHooks.cpp` | Phase D |
| `hooks/VehicleHooks.cpp` | Phase D |
| `hooks/PacketHooks.cpp` | Phase E |

---

## 各阶段里程碑

| Phase | 里程碑 | 验证方式 |
|:-----:|--------|----------|
| **A** | `game.lib` + `scripts.lib` 编译零错误 | MSBuild 构建 ✅ |
| **B** | 基础 Method 绑定编译通过 | `GlobalMethods.h` 等 10 个文件启用 |
| **B** | Lua 脚本能调用全局函数 | `print(GetPlayerByGUID(1))` |
| **C** | Unit/Creature/Spell 绑定可用 | `unit:GetName()`, `spell:GetEntry()` |
| **D** | Player 完整绑定可用 | `player:GetQuestStatus()`, `player:SendBroadcastMessage()` |
| **E** | 脚本从 `lua_scripts/` 自动加载 | 重启服务端 → 脚本自动运行 |
| **E** | AI 事件触发 Lua 回调 | 脚本 `OnCreatureEnterCombat` 工作 |
| **E** | 副本数据 Lua 持久化 | `InstanceData` 保存/读取 Lua 状态 |

---

## 已知风险

1. **`#if ELUNA_TRINITY` 差异** — Eluna 绑定时有 36 个条件编译块，每个都需要验证 LegionCore 兼容性
2. **PlayerMethods.h 体积** — 267 个绑定，是最大的文件，最可能遇到 API 不兼容
3. **异步查询** — 真实 `QueryCallbackProcessor` 集成需要测试异步 DB 操作的稳定性
4. **C++17 隔离** — 只有 `LuaValue.cpp` 用 C++17，新增代码不得使用 C++17 特性
5. **CMake 重构** — 随着更多 Hook 文件加入编译，`CMakeLists.txt` 需要更新
