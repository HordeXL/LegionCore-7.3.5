# 死亡骑士 (DK) 与恶魔猎手 (DH) 职业 AI 实现规划

> **项目**: LegionCore-7.3.5 (PlayerBot 模块)  
> **文档版本**: 1.0  
> **最后更新**: 2026-07-26

---

## 目录

1. [当前状态总览](#1-当前状态总览)
2. [系统架构回顾](#2-系统架构回顾)
3. [第一阶段：DK BotClassAI 补齐](#3-第一阶段dk-botclassai-补齐)
4. [第二阶段：DH 完整实现](#4-第二阶段dh-完整实现)
5. [文件清单与代码量估算](#5-文件清单与代码量估算)
6. [关键风险与注意事项](#6-关键风险与注意事项)
7. [实施顺序建议](#7-实施顺序建议)

---

## 1. 当前状态总览

| 组件 | DK (Class 6) | DH (Class 12) |
|------|:---:|:---:|
| **BotAISpells (法术列表)** | ✅ 已存在 `BotDeathknightSpells` | ❌ 完全缺失 |
| **BotClassAI (战场/BG AI)** | ❌ `BotDeathknightAI.h/.cpp` 缺失 | ❌ 完全缺失 |
| **DuelAI (决斗 AI)** | ✅ `DuelDeathknightAI` 已实现 | ❌ 完全缺失 |
| **FieldAI (野外 AI)** | ✅ `FieldDeathknightAI` 已实现 | ❌ 完全缺失 |
| **GroupAI (组队 AI)** | ✅ `GroupDeathknightAI` 已实现 | ❌ 完全缺失 |
| **工厂注册 (Factory)** | ❌ `CreateBotBGAIByPlayerClass` 中 case 为空 | ❌ 无任何注册 |
| **角色创建支持** | ✅ 已有 `SECTION_FLAG_DEATH_KNIGHT` 处理 | ❌ 未添加 |

---

## 2. 系统架构回顾

### 2.1 职业 AI 类继承关系

```
BotBGAI (战场AI基础类, BotAI.h)
  └── BotXXXAI (各职业战场AI, BotClassAI/)
       └── 继承 BotBGAI + BotXXXSpells

BotDuelAI (决斗AI基础类)
  └── DuelXXXAI (各职业决斗AI, BotDuelAI/)
       └── 继承 BotDuelAI + BotXXXSpells

BotFieldAI (野外AI基础类)
  └── FieldXXXAI (各职业野外AI, BotFieldAI/)
       └── 继承 BotFieldAI + BotXXXSpells

BotGroupAI (组队AI基础类)
  └── GroupXXXAI (各职业组队AI, BotGroupAI/)
       └── 继承 BotGroupAI + BotXXXSpells
```

### 2.2 工厂注册模式

每个 AI 基类都有一个静态工厂方法，通过 `switch (player->getClass())` 分发到具体职业 AI：

| 工厂函数 | 所在文件 | 返回值 |
|----------|---------|--------|
| `BotBGAI::CreateBotBGAIByPlayerClass()` | `BotAI.cpp` | `BotBGAI*` |
| `BotDuelAI::CreateBotDuelAIByPlayerClass()` | `BotDuelAI.cpp` | `BotDuelAI*` |
| `BotFieldAI::CreateBotFieldAIByPlayerClass()` | `BotFieldAI.cpp` | `BotFieldAI*` |
| `BotGroupAI::CreateBotGroupAIByPlayerClass()` | `BotGroupAI.cpp` | `BotGroupAI*` |

### 2.3 职业 AI 需要实现的虚函数

| 虚函数 | 调用时机 | 必须实现？ |
|--------|---------|:---------:|
| `ResetBotAI()` | AI 初始化/重置时 | ✅ 是 |
| `EachTick()` | 每帧更新 | ✅ 是 |
| `ProcessReady()` | 非战斗状态 | ❌ 可选 |
| `ProcessNormalSpell()` | 非战斗施法 | ❌ 可选 (FieldAI/GroupAI) |
| `ProcessMeleeSpell(Unit*)` | 近战范围内 | ✅ 是 |
| `ProcessRangeSpell(Unit*)` | 远程范围内 | ✅ 是 |
| `ProcessFlee()` | 逃跑时 | ✅ 是 |
| `ProcessHealthSpell(Unit*)` | 治疗时 | ❌ 可选 |
| `ClearMechanicAura()` | 清除控制效果 | ❌ 可选 |
| `NeedWaitSpecialSpell(uint32)` | 等待特殊技能CD | ❌ 可选 |
| `NeedFlee()` | 判断是否逃跑 | ❌ 可选 |
| `UpEnergy()` | 补充资源 (FieldAI/GroupAI) | ❌ 可选 |
| `IsMeleeBotAI()` / `IsRangeBotAI()` / `IsHealerBotAI()` | 角色定位判断 | ❌ 可选 |
| `OnLevelUp(uint32)` | 升级时 (FieldAI/GroupAI) | ❌ 可选 |
| `ProcessPullSpell(Unit*)` | 拉怪 (GroupAI) | ❌ 可选 |
| `GetSeducePriority()` | 控制技能优先级 (GroupAI) | ❌ 可选 |

---

## 3. 第一阶段：DK BotClassAI 补齐

DK 已有完整的 Duel/Field/Group AI 实现和法术列表，**只需要补齐主战场 AI 类**并在工厂中注册。

### 3.1 `BotDeathknightAI.h`

**路径**: `src/server/game/AI/PlayerAI/BotClassAI/BotDeathknightAI.h`

```cpp
#ifndef _BOT_DEATHKNIGHT_AI_H_
#define _BOT_DEATHKNIGHT_AI_H_

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

enum DeathknightTalentType
{
    DeathknightTalent_Blood,    // 鲜血 - 坦克
    DeathknightTalent_Frost,    // 冰霜 - DPS
    DeathknightTalent_Evil      // 邪恶 - DPS
};

class BotDeathknightAI : public BotBGAI, public BotDeathknightSpells
{
public:
    BotDeathknightAI(Player* player);
    ~BotDeathknightAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetRunePowerPer();
    void EachTick() override;
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void InitializeSpells();
    void UpdateTalentType();
    void ProcessReady() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;

    void UpdatePose();

    void ProcessBloodMeleeSpell(Unit* pTarget);
    void ProcessFrostMeleeSpell(Unit* pTarget);
    void ProcessEvilMeleeSpell(Unit* pTarget);

    bool ProcessBlcokCast();
    bool ProcessMgcShield();
    bool ProcessDKPull(Unit* pTarget);
    bool ProcessInfected(Unit* pTarget);
    void PetAction(Unit* pTarget);

private:
    int32 m_NeedPuniness;
    uint32 m_BotTalentType;
    bool m_IsIDLEBuff;
};

#endif // !_BOT_DEATHKNIGHT_AI_H_
```

### 3.2 `BotDeathknightAI.cpp`

**路径**: `src/server/game/AI/PlayerAI/BotClassAI/BotDeathknightAI.cpp`

实现要点：

- **`GetRunePowerPer()`**: 计算符文能量百分比 (`POWER_RUNIC_POWER`)
- **`EachTick()`**: 每帧补充符文能量（参考 `FieldDeathknightAI::UpEnergy()`）
- **`ResetBotAI()`**: 调用 `UpdateTalentType()` + `InitializeSpells(me)` + `UpdatePose()`
- **`ProcessReady()`**: 非战斗时上 Buff (`DKIDLE_Buffer`)、召唤宠物 (`DKIDLE_SummonPet`)
- **`ProcessNormalSpell()`**: 保持 Buff 和宠物
- **`ProcessRangeSpell()`**: 远程拉人 (`DKPulls_DKPull`)、打断施法 (`DKBlock_Cast`)
- **`ProcessMeleeSpell()`**: 核心战斗循环，按天赋分支分发
- **`ProcessFlee()`**: 逃跑 + 收起宠物
- **`UpdatePose()`**: 根据天赋切换灵气（鲜血/冰霜/邪恶）
- **三系专精逻辑**：可直接参考 `FieldDeathknightAI` 中的 `ProcessBloodMeleeSpell` / `ProcessFrostMeleeSpell` / `ProcessEvilMeleeSpell` 实现

### 3.3 修改工厂注册

**文件**: `src/server/game/AI/PlayerAI/BotAI.cpp` — `CreateBotBGAIByPlayerClass()`

```cpp
case CLASS_DEATH_KNIGHT:
    ret = new BotDeathknightAI(player);
    break;
```

---

## 4. 第二阶段：DH 完整实现

DH 需要从零开始创建所有组件。

### 4.1 法术列表 — `BotDemonHunterSpells`

**路径**: `src/server/game/AI/PlayerAI/BotAISpells.h` + `BotAISpells.cpp`

#### 头文件 (`BotAISpells.h`)

```cpp
class BotDemonHunterSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    // 姿态
    uint32 DHStatus_Havoc = 162264;       // 浩劫 (恶魔变形)
    uint32 DHStatus_Vengeance = 187827;   // 复仇 (恶魔变形)

    // IDLE
    uint32 DHIDLE_Buffer = 195245;        // 混沌印记 (全队Buff)
    uint32 DHIDLE_SummonPet = 188499;     // 召唤恶魔

    // 打断
    uint32 DHBlock_Disrupt = 183752;      // 打断
    uint32 DHBlock_Imprison = 217832;     // 禁锢 (沉默)

    // 防御
    uint32 DHDefense_DemonSpikes = 203720; // 恶魔尖刺 (复仇)
    uint32 DHDefense_Netherwalk = 212818;  // 虚空行走 (无敌)
    uint32 DHDefense_Blur = 198589;       // 模糊 (闪避)
    uint32 DHDefense_Darkness = 209426;   // 黑暗 (群体闪避)

    // 拉人/位移
    uint32 DHPulls_ThrowGlaive = 185123;  // 投掷战刃
    uint32 DHPulls_FelRush = 195072;      // 恶魔冲锋 (浩劫)
    uint32 DHPulls_VengefulRetreat = 198793; // 复仇回避

    // 攻击 (浩劫)
    uint32 DHAttack_ChaosStrike = 162794; // 混乱打击
    uint32 DHAttack_BladeDance = 199552;  // 刃舞
    uint32 DHAttack_EyeBeam = 198030;     // 眼棱
    uint32 DHAttack_ImmolationAura = 178740; // 献祭光环
    uint32 DHAttack_ThrowGlaive = 185123; // 投掷战刃
    uint32 DHAttack_Annihilation = 201427; // 湮灭 (强化混乱打击)
    uint32 DHAttack_DeathSweep = 210152;  // 死亡横扫 (强化刃舞)

    // 攻击 (复仇)
    uint32 DHAttack_SoulCleave = 203782;  // 灵魂裂劈
    uint32 DHAttack_FieryBrand = 204021;  // 烈火烙印
    uint32 DHAttack_SigilOfFlame = 204596; // 烈焰铭刻
    uint32 DHAttack_InfernalStrike = 189110; // 地狱打击

    // 辅助
    uint32 DHAssist_ConsumeSoul = 210042; // 吞噬灵魂 (回血)
    uint32 DHAssist_DemonicWards = 207693; // 恶魔结界 (护甲)
    uint32 DHAssist_Metamorphosis = 191427; // 恶魔变形 (变身)
};
```

> **注意**: 以上法术 ID 基于 Legion 7.3.5 的参考值，需要在实际编译前用 DBC/DB2 工具或游戏内数据核对确认。

#### 实现文件 (`BotAISpells.cpp`)

```cpp
void BotDemonHunterSpells::InitializeSpells(Player* player)
{
    // 使用 BotUtility::FindMaxRankSpellByExist 动态查找最高等级法术
    DHStatus_Havoc = BotUtility::FindMaxRankSpellByExist(player, 162264);
    DHStatus_Vengeance = BotUtility::FindMaxRankSpellByExist(player, 187827);
    // ... 全部法术都用 FindMaxRankSpellByExist 初始化
}
```

### 4.2 主战场 AI — `BotDemonHunterAI`

**路径**: `src/server/game/AI/PlayerAI/BotClassAI/BotDemonHunterAI.h` + `.cpp`

```cpp
enum DemonHunterTalentType
{
    DemonHunterTalent_Havoc,      // 浩劫 - DPS
    DemonHunterTalent_Vengeance   // 复仇 - Tank
};

class BotDemonHunterAI : public BotBGAI, public BotDemonHunterSpells
{
public:
    BotDemonHunterAI(Player* player);
    ~BotDemonHunterAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetFuryPowerPer();           // 恶魔之怒百分比
    void EachTick() override;
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void InitializeSpells();
    void UpdateTalentType();
    void ProcessReady() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsTankBotAI() override;

    void UpdatePose();                  // 切换姿态

    void ProcessHavocMeleeSpell(Unit* pTarget);    // 浩劫近战循环
    void ProcessVengeanceMeleeSpell(Unit* pTarget); // 复仇近战循环

    bool ProcessBlcokCast();            // 打断
    bool ProcessDefense();              // 防御技能
    void PetAction(Unit* pTarget);      // 宠物控制

private:
    uint32 m_BotTalentType;
    bool m_IsIDLEBuff;
    bool m_IsMetamorphosis;             // 是否在恶魔变形状态
};
```

**战斗逻辑要点**：

**浩劫 (Havoc) DPS 循环**：
1. 保持献祭光环 (`ImmolationAura`)
2. 怒气充足时打混乱打击 (`ChaosStrike`) / 湮灭 (`Annihilation`)
3. 多目标时刃舞 (`BladeDance`) / 死亡横扫 (`DeathSweep`)
4. 能量用完时眼棱 (`EyeBeam`)
5. 恶魔变形作为爆发技能

**复仇 (Vengeance) 坦克循环**：
1. 保持恶魔尖刺 (`DemonSpikes`) 减伤
2. 灵魂裂劈 (`SoulCleave`) 作为主要仇恨技能
3. 烈火烙印 (`FieryBrand`) 减少目标伤害
4. 吞噬灵魂 (`ConsumeSoul`) 回血

### 4.3 决斗 AI — `DuelDemonHunterAI`

**路径**: `src/server/game/AI/PlayerAI/BotDuelAI/`

- 在 `BotDuelClassAI.h` 中添加类声明
- 新建 `DuelDemonHunterAI.cpp`
- 实现与 `BotDemonHunterAI` 类似的战斗逻辑，但使用 `BotDuelAI` 的接口（`GetDuelEnemy()` 等）

### 4.4 野外 AI — `FieldDemonHunterAI`

**路径**: `src/server/game/AI/PlayerAI/BotFieldAI/`

- 在 `BotFieldClassAI.h` 中添加类声明
- 新建 `FieldDemonHunterAI.cpp`
- 额外实现 `ProcessNormalSpell()` 用于野外Buff和上坐骑
- 实现 `OnLevelUp()` 用于升级时重新初始化法术

### 4.5 组队 AI — `GroupDemonHunterAI`

**路径**: `src/server/game/AI/PlayerAI/BotGroupAI/`

- 在 `BotGroupClassAI.h` 中添加类声明
- 新建 `GroupDemonHunterAI.cpp`
- 额外实现 `ProcessPullSpell()` 用于拉怪
- 实现 `GetSeducePriority()` 控制技能优先级
- 实现 `IsTankBotAI()` 判断是否为复仇天赋

### 4.6 工厂注册修改

**需要修改的 4 个文件**：

| 文件 | 行号 | 修改内容 |
|------|------|---------|
| `BotAI.cpp` | `CreateBotBGAIByPlayerClass()` | 添加 `case CLASS_DEMON_HUNTER:` |
| `BotDuelAI.cpp` | `CreateBotDuelAIByPlayerClass()` | 添加 `case CLASS_DEMON_HUNTER:` |
| `BotFieldAI.cpp` | `CreateBotFieldAIByPlayerClass()` | 添加 `case CLASS_DEMON_HUNTER:` |
| `BotGroupAI.cpp` | `CreateBotGroupAIByPlayerClass()` | 添加 `case CLASS_DEMON_HUNTER:` |

### 4.7 角色创建支持

**文件**: `src/server/game/PlayerBot/PlayerBotMgr.cpp` — `SupplementPlayerBot()`

在已有职业补充逻辑后添加：

```cpp
// 补充 DH 机器人 (class 12)
pInfo->needCreateBots.push(BuildCreatePlayerData(true, 12));
pInfo->needCreateBots.push(BuildCreatePlayerData(false, 12));
```

---

## 5. 文件清单与代码量估算

### 5.1 新增文件

| # | 文件路径 | 预估行数 | 说明 |
|---|---------|:--------:|------|
| 1 | `AI/PlayerAI/BotClassAI/BotDeathknightAI.h` | ~80 | DK 战场 AI 头文件 |
| 2 | `AI/PlayerAI/BotClassAI/BotDeathknightAI.cpp` | ~520 | DK 战场 AI 实现 |
| 3 | `AI/PlayerAI/BotAISpells.h` (追加) | ~120 | DH 法术列表声明 |
| 4 | `AI/PlayerAI/BotAISpells.cpp` (追加) | ~180 | DH 法术初始化 |
| 5 | `AI/PlayerAI/BotClassAI/BotDemonHunterAI.h` | ~90 | DH 战场 AI 头文件 |
| 6 | `AI/PlayerAI/BotClassAI/BotDemonHunterAI.cpp` | ~500 | DH 战场 AI 实现 |
| 7 | `AI/PlayerAI/BotDuelAI/BotDuelClassAI.h` (追加) | ~30 | DH 决斗 AI 声明 |
| 8 | `AI/PlayerAI/BotDuelAI/DuelDemonHunterAI.cpp` | ~300 | DH 决斗 AI 实现 |
| 9 | `AI/PlayerAI/BotFieldAI/BotFieldClassAI.h` (追加) | ~30 | DH 野外 AI 声明 |
| 10 | `AI/PlayerAI/BotFieldAI/FieldDemonHunterAI.cpp` | ~300 | DH 野外 AI 实现 |
| 11 | `AI/PlayerAI/BotGroupAI/BotGroupClassAI.h` (追加) | ~30 | DH 组队 AI 声明 |
| 12 | `AI/PlayerAI/BotGroupAI/GroupDemonHunterAI.cpp` | ~300 | DH 组队 AI 实现 |
| **合计** | **12 个文件** | **~2,460 行** | |

### 5.2 修改文件

| # | 文件路径 | 修改内容 | 新增行数 |
|---|---------|---------|:--------:|
| 1 | `AI/PlayerAI/BotAI.cpp` | 工厂注册 DK + DH | ~4 |
| 2 | `AI/PlayerAI/BotDuelAI/BotDuelAI.cpp` | 工厂注册 DH | ~2 |
| 3 | `AI/PlayerAI/BotFieldAI/BotFieldAI.cpp` | 工厂注册 DH | ~2 |
| 4 | `AI/PlayerAI/BotGroupAI/BotGroupAI.cpp` | 工厂注册 DH | ~2 |
| 5 | `PlayerBot/PlayerBotMgr.cpp` | 添加 DH 角色创建 | ~5 |
| **合计** | **5 个文件** | | **~15 行** |

---

## 6. 关键风险与注意事项

### 6.1 法术 ID 正确性

- **风险**: 文档中列出的 DH 法术 ID 基于 Legion 7.3.5 的参考数据，可能不准确
- **应对**: 编译后在游戏中实际测试，或使用 DBC/DB2 提取工具验证
- **回退方案**: 使用 `BotUtility::FindMaxRankSpellByExist(player, baseID)` 动态查找，无效 ID 会返回 0 并跳过

### 6.2 DH 恶魔之怒资源系统

- **风险**: DH 使用「恶魔之怒」(Fury) 作为资源，类似盗贼的能量但恢复机制不同
- **应对**: 在 `EachTick()` 中补充恶魔之怒（参考 DK 的 `UpEnergy()` 模式）
- **注意**: 需要确认 `Powers` 枚举中是否有 `POWER_FURY` 或对应的资源类型

### 6.3 DH 双姿态复杂度

- **风险**: 浩劫 (DPS) 和复仇 (Tank) 的战斗逻辑差异较大
- **应对**: 在 `ProcessMeleeSpell()` 中按天赋分支分发，分别实现两套循环
- **注意**: 复仇天赋需要实现 `IsTankBotAI()` 返回 true

### 6.4 DK 代码复用

- **优势**: DK 的 Duel/Field/Group AI 已有完整实现，可以直接参考移植
- **注意**: `BotBGAI` 的接口与 `BotFieldAI`/`BotGroupAI` 略有不同，需要适配 `ProcessReady()` 和 `ProcessNormalSpell()` 的调用约定

### 6.5 编译验证

- 每完成一个子模块（如 DK BotClassAI）后，建议编译验证
- 重点关注：头文件包含、虚函数签名匹配、法术 ID 有效性

---

## 7. 实施顺序建议

```
第一阶段 (DK 补齐 — 低风险, 快速见效)
  1.1 创建 BotDeathknightAI.h
  1.2 创建 BotDeathknightAI.cpp (参考 FieldDeathknightAI 实现)
  1.3 修改 BotAI.cpp 工厂注册
  1.4 编译验证 ✅

第二阶段 (DH 法术列表 — 基础依赖)
  2.1 在 BotAISpells.h 添加 BotDemonHunterSpells 声明
  2.2 在 BotAISpells.cpp 添加 InitializeSpells 实现
  2.3 编译验证 ✅

第三阶段 (DH 战场 AI — 核心)
  3.1 创建 BotDemonHunterAI.h
  3.2 创建 BotDemonHunterAI.cpp
  3.3 修改 BotAI.cpp 工厂注册
  3.4 编译验证 ✅

第四阶段 (DH 子 AI 系统 — 并行)
  4.1 创建 DuelDemonHunterAI (声明 + 实现)
  4.2 创建 FieldDemonHunterAI (声明 + 实现)
  4.3 创建 GroupDemonHunterAI (声明 + 实现)
  4.4 修改对应的工厂注册文件
  4.5 编译验证 ✅

第五阶段 (角色创建与集成)
  5.1 修改 PlayerBotMgr.cpp 添加 DH 角色创建
  5.2 完整编译验证
  5.3 数据库确认 (法术 ID 核对)
  5.4 功能测试
```

---

> **文档维护者**: Reasonix AI  
> **关联文档**: [PlayerBot_Migration_Guide.md](./PlayerBot_Migration_Guide.md)