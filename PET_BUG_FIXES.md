# LegionCore 7.3.5 — 宠物相关 Bug 修复记录

> **会话：** 本次会话中应用的所有宠物相关 Bug 修复的完整记录。
> **格式：** 每条记录显示确切的文件、行号、修改前后的代码及说明。

---

## 目录

1. [src/server/game/Entities/Pet/Pet.cpp](#1-srcservergameentitiespetpetcpp)
   - [1a. 延迟事件 Lambda 中空指针检查取反（4 处）](#1a-inverted-null-check-in-delayed-event-lambdas-4-locations)
   - [1b. SetGroupUpdateFlag / ResetGroupUpdateFlag 存在早期 `return;` 桩代码](#1b-setgroupupdateflag--resetgroupupdateflag-had-early-return-stubs)
   - [1c. 猎人宠物保存跳过条件取反](#1c-hunter-pet-save-skip-condition-inverted)
   - [1d. AddSpellToActionBar 缺少 `active` 状态参数](#1d-addspelltoactionbar-missing-active-state-parameter)
2. [src/server/game/Handlers/PetHandler.cpp](#2-srcservergamehandlerspethandlercpp)
   - [2a. HandlePetSpellAutocast 条件取反](#2a-handlepetspellautocast-inverted-condition)
   - [2b. 兽栏异域宠物错误分支使用了错误的检查](#2b-stable-exotic-pet-error-branch-used-wrong-check)
   - [2c. SendStablePet 忽略了 GUID 参数](#2c-sendstablepet-ignored-the-guid-parameter)
   - [2d. HanleSetPetSlot 向回调传递了错误参数](#2d-hanlesetpetslot-passed-wrong-parameter-to-callback)
   - [2e. HandleStableChangeSlotCallback 错误的结果码 + 缺少宠物召唤](#2e-handlestablechangeslotcallback-wrong-result-code--missing-pet-summon)
3. [src/server/game/Spells/SpellEffects.cpp](#3-srcservergamesspellsspelleffectscpp)
   - [3a–3d. EffectTameCreature：顺序错误、缺少调用](#3a3d-effecttamecreature-wrong-order-missing-calls)
4. [src/server/game/Entities/Player/Player.cpp](#4-srcservergameentitiesplayerplayercpp)
   - [4a. GOSSIP_OPTION_STABLEPET 缺少 SendCloseGossip()](#4a-gossip_option_stablepet-missing-sendclosegossip)
   - [4b. ZoneTeleport — UnsummonPetTemporaryIfAny 被注释掉](#4b-zoneteleport--unsummonpettemporaryifany-was-commented-out)
   - [4c. ZoneTeleport — ResummonPetTemporaryUnSummonedIfAny 被注释掉](#4c-zoneteleport--resummonpettemporaryunsummonedifany-was-commented-out)
5. [src/common/Database/MySQLConnection.cpp](#5-srccommondatabasemysqlconnectioncpp)
   - [5a. MySQL 字符集 "utf8" → "utf8mb4"](#5a-mysql-charset-utf8--utf8mb4)
6. [数据库 — gossip_menu_option 表](#6-database--gossip_menu_option-table)
   - [6a. 缺少兽栏宠物对话选项](#6a-missing-stable-pet-gossip-options)

---

## 1. `src/server/game/Entities/Pet/Pet.cpp`

### 1a. 延迟事件 Lambda 中空指针检查取反（4 处）

**Bug：** `TempSummon::CastPetAuras` 中用于延迟法术（选项 6）的 Lambda 检查了 `if (_caster) return;` — 即当指针**有效**时返回。这意味着当施法者存在时，Lambda **始终**跳过施法，即它**从未**施放过延迟法术。

**修复：** 改为 `if (!_caster) return;` — 正确的空指针保护，仅在施法者不存在时返回。

**文件与行号（当前修复状态）：**

#### 位置 1 — 第 1754–1761 行（正数 spellId，正数 spellId 块，case 6）
```cpp
// --- 修改前 (第 1752–1761 行) ---
                        ObjectGuid targetGUID = _target->GetGUID();
                        uint32 _spellId = abs(itr.spellId);
                        _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                        {
                            if (_caster)           // <-- BUG：当施法者 IS 有效时返回
                                return;

                            if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                _caster->CastSpell(target, _spellId, true);
                        });

// --- 修改后 (第 1754–1761 行) ---
                        ObjectGuid targetGUID = _target->GetGUID();
                        uint32 _spellId = abs(itr.spellId);
                        _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                        {
                            if (!_caster)          // <-- 修复：仅在施法者 IS 为空时返回
                                return;

                            if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                _caster->CastSpell(target, _spellId, true);
                        });
```

#### 位置 2 — 第 1835–1844 行（负数 spellId，apply=false 块，case 6）
```cpp
// --- 修改前 (第 1833–1844 行) ---
                        case 6: // 延迟施法
                        {
                            ObjectGuid targetGUID = _target->GetGUID();
                            uint32 _spellId = abs(itr.spellId);
                            _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                            {
                                if (_caster)           // <-- BUG
                                    return;

                                if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                    _caster->CastSpell(target, _spellId, true);
                            });

// --- 修改后 (第 1833–1844 行) ---
                        case 6: // 延迟施法
                        {
                            ObjectGuid targetGUID = _target->GetGUID();
                            uint32 _spellId = abs(itr.spellId);
                            _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                            {
                                if (!_caster)          // <-- 修复
                                    return;

                                if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                    _caster->CastSpell(target, _spellId, true);
                            });
```

#### 位置 3 — 第 1963–1972 行（正数 spellId，apply=true 块，case 6）
```cpp
// --- 修改前 (第 1961–1972 行) ---
                    case 6: // 延迟施法
                    {
                        ObjectGuid targetGUID = _target->GetGUID();
                        uint32 _spellId = abs(itr.spellId);
                        _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                        {
                            if (_caster)               // <-- BUG
                                return;

                            if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                _caster->CastSpell(target, _spellId, true);
                        });

// --- 修改后 (第 1961–1972 行) ---
                    case 6: // 延迟施法
                    {
                        ObjectGuid targetGUID = _target->GetGUID();
                        uint32 _spellId = abs(itr.spellId);
                        _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                        {
                            if (!_caster)              // <-- 修复
                                return;

                            if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                _caster->CastSpell(target, _spellId, true);
                        });
```

#### 位置 4 — 第 2030–2039 行（负数 spellId，apply=false 块，case 6）
```cpp
// --- 修改前 (第 2028–2039 行) ---
                    case 6: // 延迟施法
                    {
                        ObjectGuid targetGUID = _target->GetGUID();
                        uint32 _spellId = abs(itr.spellId);
                        _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                        {
                            if (_caster)               // <-- BUG
                                return;

                            if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                _caster->CastSpell(target, _spellId, true);
                        });

// --- 修改后 (第 2028–2039 行) ---
                    case 6: // 延迟施法
                    {
                        ObjectGuid targetGUID = _target->GetGUID();
                        uint32 _spellId = abs(itr.spellId);
                        _caster->AddDelayedEvent(bp0, [_caster, _spellId, targetGUID]() -> void
                        {
                            if (!_caster)              // <-- 修复
                                return;

                            if (Unit* target = ObjectAccessor::GetUnit(*_caster, targetGUID))
                                _caster->CastSpell(target, _spellId, true);
                        });
```

---

### 1b. SetGroupUpdateFlag / ResetGroupUpdateFlag 存在早期 `return;` 桩代码

**Bug：** `Pet::SetGroupUpdateFlag` 和 `Pet::ResetGroupUpdateFlag` 都在函数体第一行包含了一个单独的 `return;` 语句，使其完全变成空操作。宠物的队伍更新从未发送给客户端（宠物属性、名字、模型在队伍面板中的变化从未刷新）。

**修复：** 移除了早期的 `return;` 语句，使函数得以实际执行。

**第 2188–2207 行（当前）：**
```cpp
// --- 修改前 (第 2188–2205 行) ---
void Pet::SetGroupUpdateFlag(uint32 flag)
{
    return;                                          // <-- BUG：使函数成为空操作

    Player* player = GetOwner()->ToPlayer();
    if (!player)
        return;

    if (player->GetGroup())
    {
        m_groupUpdateMask |= flag;
        player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET);
    }
}

void Pet::ResetGroupUpdateFlag()
{
    return;                                          // <-- BUG：使函数成为空操作
    m_groupUpdateMask = GROUP_UPDATE_FLAG_PET_NONE;

    if (Player* player = GetOwner()->ToPlayer())
        player->RemoveGroupUpdateFlag(GROUP_UPDATE_FLAG_PET);
}

// --- 修改后 (第 2188–2207 行) ---
void Pet::SetGroupUpdateFlag(uint32 flag)
{
    Player* player = GetOwner()->ToPlayer();
    if (!player)
        return;

    if (player->GetGroup())
    {
        m_groupUpdateMask |= flag;
        player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET);
    }
}

void Pet::ResetGroupUpdateFlag()
{
    m_groupUpdateMask = GROUP_UPDATE_FLAG_PET_NONE;

    if (Player* player = GetOwner()->ToPlayer())
        player->RemoveGroupUpdateFlag(GROUP_UPDATE_FLAG_PET);
}
```

---

### 1c. 猎人宠物保存跳过条件取反

**Bug：** 在 `Pet::SavePetToDB` 中，当另一只宠物被临时解散时，检查条件 `if (getPetType() == HUNTER_PET) return;` **跳过了所有猎人宠物的保存**。每只猎人宠物都有自己的兽栏槽位，应当**始终**被保存，因此条件写反了——它应该只跳过**非猎人**宠物（术士/DK 的召唤物，这些将由临时解散系统恢复）。

**修复：** 改为 `if (getPetType() != HUNTER_PET) return;`。

**第 407–412 行（当前）：**
```cpp
// --- 修改前 (第 406–412 行) ---
    // 如果另一只宠物被临时解散，则不将当前宠物保存为当前状态
    if (owner->GetTemporaryUnsummonedPetNumber() && owner->GetTemporaryUnsummonedPetNumber() != m_charmInfo->GetPetNumber())
    {
        // 在恢复临时解散的宠物时，该宠物无论如何都会丢失
        if (getPetType() == HUNTER_PET)              // <-- BUG：跳过了猎人宠物的保存
            return;
    }

// --- 修改后 (第 406–412 行) ---
    // 如果另一只宠物被临时解散，则不将当前宠物保存为当前状态
    if (owner->GetTemporaryUnsummonedPetNumber() && owner->GetTemporaryUnsummonedPetNumber() != m_charmInfo->GetPetNumber())
    {
        // 猎人宠物各自有自己的槽位，保存是安全的
        if (getPetType() != HUNTER_PET)              // <-- 修复：仅跳过非猎人宠物
            return;
    }
```

---

### 1d. AddSpellToActionBar 缺少 `active` 状态参数

**Bug：** 在 `TempSummon::addSpell` 中，调用 `m_charmInfo->AddSpellToActionBar(spellInfo)` 时省略了第二个参数 `active`（一个 `ActiveStates` 枚举值）。这意味着法术总是以该方法使用的任何默认值添加（可能是 `ACT_DECIDE` 或 `ACT_DISABLED`），而不是遵循调用方请求的激活状态（例如 `ACT_ENABLED`、`ACT_PASSIVE`）。这可能导致宠物法术以错误的状态出现在动作条上。

**修复：** 传入了 `active` 参数。

**第 1369–1375 行（当前）：**
```cpp
// --- 修改前 (第 1369–1375 行) ---
    if(m_charmInfo)
    {
        if (spellInfo->IsPassive() && (!spellInfo->AuraRestrictions.CasterAuraState || HasAuraState(AuraStateType(spellInfo->AuraRestrictions.CasterAuraState))))
            CastSpell(this, spellId, true);
        else
            m_charmInfo->AddSpellToActionBar(spellInfo);    // <-- BUG：缺少 'active' 参数
    }

// --- 修改后 (第 1369–1375 行) ---
    if(m_charmInfo)
    {
        if (spellInfo->IsPassive() && (!spellInfo->AuraRestrictions.CasterAuraState || HasAuraState(AuraStateType(spellInfo->AuraRestrictions.CasterAuraState))))
            CastSpell(this, spellId, true);
        else
            m_charmInfo->AddSpellToActionBar(spellInfo, active);  // <-- 修复：传递了状态参数
    }
```

---

## 2. `src/server/game/Handlers/PetHandler.cpp`

### 2a. HandlePetSpellAutocast 条件取反

**Bug：** 守卫子句 `if (!pet->HasSpell(packet.SpellID) || spellInfo->IsAutocastable()) return;` 在法术**是**可自动施放时提前返回，使得玩家无法切换任何宠物法术的自动施放开关。正确的意图是仅在法术**不是**可自动施放时才返回（因为只有可自动施放的法术才能切换）。

**修复：** 在 `spellInfo->IsAutocastable()` 前加了 `!`。

**第 332–334 行（当前）：**
```cpp
// --- 修改前 (第 332–334 行) ---
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(packet.SpellID);
    if (!pet->HasSpell(packet.SpellID) || spellInfo->IsAutocastable())  // <-- BUG
        return;

// --- 修改后 (第 332–334 行) ---
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(packet.SpellID);
    if (!pet->HasSpell(packet.SpellID) || !spellInfo->IsAutocastable()) // <-- 修复
        return;
```

---

### 2b. 兽栏异域宠物错误分支使用了错误的检查

**Bug：** 在 `HandleStableChangeSlotCallback` 中，当生物模板不可驯服（`!creatureInfo->isTameable(_player)`）时，回退分支再次检查 `creatureInfo->isTameable(_player)` 来判断错误是否是"异域宠物"。由于外层条件已经使此检查失败，内层条件始终为假，因此异域宠物错误从未向客户端发送——它总是发送普通的 `STABLE_ERR_STABLE`。

**修复：** 改为检查 `creatureInfo->TypeFlags[0] & CREATURE_TYPEFLAGS_EXOTIC`，这是确定一只生物是否为异域宠物的正确标志。

**第 527–536 行（当前）：**
```cpp
// --- 修改前 (第 527–536 行) ---
    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(pet_entry);
    if (!creatureInfo || !creatureInfo->isTameable(_player))
    {
        // if problem in exotic pet
        if (creatureInfo && creatureInfo->isTameable(_player))    // <-- BUG：此处始终为 false
            SendStableResult(STABLE_ERR_EXOTIC);
        else
            SendStableResult(STABLE_ERR_STABLE);
        return;
    }

// --- 修改后 (第 527–536 行) ---
    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(pet_entry);
    if (!creatureInfo || !creatureInfo->isTameable(_player))
    {
        // 如果是异域宠物的问题
        if (creatureInfo && (creatureInfo->TypeFlags[0] & CREATURE_TYPEFLAGS_EXOTIC))  // <-- 修复
            SendStableResult(STABLE_ERR_EXOTIC);
        else
            SendStableResult(STABLE_ERR_STABLE);
        return;
    }
```

---

### 2c. SendStablePet 忽略了 GUID 参数

**Bug：** `SendStablePet(ObjectGuid const& /*guid*/)` 有一个未命名（仅注释）的参数。`StableList` 数据包的 `StableMaster` 字段从未设置，因此客户端收到兽栏管理员 NPC 的空 GUID——这可能导致兽栏 UI 无法显示 NPC 名称或无法正确交互。

**修复：** 取消注释参数名并添加了 `list.StableMaster = guid;`。

**第 795–802 行（当前）：**
```cpp
// --- 修改前 (第 795–802 行) ---
void WorldSession::SendStablePet(ObjectGuid const& /*guid*/ /*= ObjectGuid::Empty*/)
{
    Player* player = GetPlayer();
    if (!player)
        return;

    WorldPackets::PetPackets::StableList list;
    // list.StableMaster = guid;         // <-- BUG：从未设置（被注释掉/缺失）

// --- 修改后 (第 795–802 行) ---
void WorldSession::SendStablePet(ObjectGuid const& guid /*= ObjectGuid::Empty*/)
{
    Player* player = GetPlayer();
    if (!player)
        return;

    WorldPackets::PetPackets::StableList list;
    list.StableMaster = guid;            // <-- 修复
```

---

### 2d. HanleSetPetSlot 向回调传递了错误参数

**Bug：** `AsyncQuery` 回调绑定将 `packet.PetIndex` 作为 `new_slot` 参数传递给了 `HandleStableChangeSlotCallback`。`PetIndex` 是宠物的唯一数据库 ID，而不是槽位编号。这导致回调使用一个实际上是宠物编号的槽位值进行操作，破坏了兽栏槽位的分配。

**修复：** 将 `packet.PetIndex` → `packet.NewSlot`。

**第 498–502 行（当前）：**
```cpp
// --- 修改前 (第 498–502 行) ---
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_BY_ID);
    stmt->setUInt64(0, _player->GetGUIDLow());
    stmt->setUInt32(1, packet.PetIndex);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(
        std::bind(&WorldSession::HandleStableChangeSlotCallback, this, std::placeholders::_1, packet.PetIndex)));  // <-- BUG

// --- 修改后 (第 498–502 行) ---
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_BY_ID);
    stmt->setUInt64(0, _player->GetGUIDLow());
    stmt->setUInt32(1, packet.PetIndex);

    _queryProcessor.AddQuery(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(
        std::bind(&WorldSession::HandleStableChangeSlotCallback, this, std::placeholders::_1, packet.NewSlot)));   // <-- 修复
```

---

### 2e. HandleStableChangeSlotCallback 错误的结果码 + 缺少宠物召唤

**Bug：** 回调中存在多个问题：
1. 无论宠物是被提取到活动槽位（应返回 `STABLE_SUCCESS_UNSTABLE`），回调始终发送 `STABLE_SUCCESS_STABLE`。
2. 当从兽栏提取宠物到活动槽位时，宠物**从未被召唤**。槽位交换发生了，但没有创建和加载 `Pet` 对象。
3. `if (new_slot != 100)` 块缺少 `else`，导致无论如何都会在该块之后发送 `STABLE_SUCCESS_STABLE`。

**修复：**
1. 添加了 `bool isExtract = new_slot <= PET_SLOT_HUNTER_LAST` 来确定操作类型。
2. 提取时，创建一个新的 `Pet`，通过 `LoadPetFromDB` 从数据库加载，并设置当前召唤槽位。
3. 发送正确的结果码：提取时发送 `STABLE_SUCCESS_UNSTABLE`，仅兽栏内交换时发送 `STABLE_SUCCESS_STABLE`。
4. 将 `SendStableResult` 移到 `if/else` 分支内，确保只发送一个结果码。

**第 542–566 行（当前）：**
```cpp
// --- 修改前 (第 541–563 行) ---
    // 如果是猎人宠物，则更新
    if (new_slot != 100)
    {
        // 我们需要移除并添加新宠物到不同的槽位
        GetPlayer()->SwapPetSlot(slot, static_cast<PetSlot>(new_slot));
    }

    SendStableResult(STABLE_SUCCESS_STABLE);

// --- 修改后 (第 542–566 行) ---
    // 如果是猎人宠物，则更新
    if (new_slot != 100)
    {
        // 判断是否是提取（兽栏 -> 活动槽位）还是兽栏内交换
        bool isExtract = new_slot <= PET_SLOT_HUNTER_LAST;

        // 我们需要移除并添加新宠物到不同的槽位
        GetPlayer()->SwapPetSlot(slot, static_cast<PetSlot>(new_slot));

        // 如果是提取到活动槽位，则召唤宠物
        if (isExtract)
        {
            if (Player* player = GetPlayer())
            {
                player->m_currentSummonedSlot = static_cast<PetSlot>(new_slot);
                Pet* newPet = new Pet(player, HUNTER_PET);
                if (!newPet->LoadPetFromDB(player, 0, 0))
                    delete newPet;
            }
        }

        SendStableResult(isExtract ? STABLE_SUCCESS_UNSTABLE : STABLE_SUCCESS_STABLE);
    }
    else
        SendStableResult(STABLE_SUCCESS_STABLE);
```

---

## 3. `src/server/game/Spells/SpellEffects.cpp`

### 3a–3d. EffectTameCreature：顺序错误、缺少调用

**Bug：** `Spell::EffectTameCreature` 中存在四个问题：
1. **顺序错误：** `m_caster->SetMinion(pet, true)` 在 `pet->GetMap()->AddToMap(pet->ToCreature())` **之后**调用。在设置主人之前将宠物添加到地图，可能导致宠物在没有主人关系的情况下被处理。
2. **缺少 `setActive(true)`：** 宠物未被标记为活动状态，意味着某些世界更新迭代（例如光环更新、距离检查）可能跳过它。
3. **缺少 `CastPetAuras(true)`：** 通过 `pet_aura` 数据库表定义的宠物光环（例如猎人宠物被动技能）在驯服后从未被应用。
4. **缺少 `SendTalentsInfoData(true)`：** 玩家的宠物天赋数据未刷新，因此宠物专精面板可能是过时的或空的。

**第 4622–4641 行（当前）：**
```cpp
// --- 修改前 (第 4622–4634 行) ---
    // 准备升级的视觉效果
    pet->SetLevel(level - 1);

    // 添加到世界
    pet->GetMap()->AddToMap(pet->ToCreature());

    // 升级的视觉效果
    pet->SetLevel(level);
    pet->SetEffectiveLevel(m_caster->GetEffectiveLevel());

    // 施法者现在拥有宠物
    m_caster->SetMinion(pet, true);                     // <-- BUG 1：在 AddToMap 之后调用

    pet->SavePetToDB();
    player->PetSpellInitialize();
    player->GetSession()->SendStablePet();

// --- 修改后 (第 4622–4641 行) ---
    // 准备升级的视觉效果
    pet->SetLevel(level - 1);

    // 施法者现在拥有宠物 — 必须在添加到地图之前设置宠物
    m_caster->SetMinion(pet, true);                     // <-- 修复 1：在 AddToMap 之前调用

    // 添加到世界
    pet->GetMap()->AddToMap(pet->ToCreature());
    pet->setActive(true);                               // <-- 修复 2：添加了 setActive

    // 升级的视觉效果
    pet->SetLevel(level);
    pet->SetEffectiveLevel(m_caster->GetEffectiveLevel());

    pet->SavePetToDB();
    pet->CastPetAuras(true);                            // <-- 修复 3：添加了 CastPetAuras
    player->SendTalentsInfoData(true);                  // <-- 修复 4：添加了 SendTalentsInfoData
    player->GetSession()->SendStablePet();
    player->PetSpellInitialize();                       // 保留，在 SendStablePet 之后重排
```

---

## 4. `src/server/game/Entities/Player/Player.cpp`

### 4a. GOSSIP_OPTION_STABLEPET 缺少 SendCloseGossip()

**Bug：** 当选择"兽栏宠物"对话选项时，在发送兽栏数据包之前没有关闭对话窗口。这导致客户端上的对话 UI 保持打开状态，可能造成 UI 冲突（兽栏框架出现在对话框架之上）。

**修复：** 在 `GetSession()->SendStablePet(guid);` 之前添加了 `PlayerTalkClass->SendCloseGossip();`。

**第 18345–18348 行（当前）：**
```cpp
// --- 修改前 (第 18345–18348 行) ---
        case GOSSIP_OPTION_STABLEPET:
            GetSession()->SendStablePet(guid);
            break;

// --- 修改后 (第 18345–18348 行) ---
        case GOSSIP_OPTION_STABLEPET:
            PlayerTalkClass->SendCloseGossip();
            GetSession()->SendStablePet(guid);
            break;
```

---

### 4b. ZoneTeleport — UnsummonPetTemporaryIfAny 被注释掉

**Bug：** 在 `Player::ZoneTeleport` 中，`UnsummonPetTemporaryIfAny()` 的调用被注释掉了。这意味着当玩家切换区域时，他们的宠物**没有**被临时解散，可能导致宠物被遗留在旧地图中（造成宠物悬空，客户端仍然显示但服务器无法控制）。

**修复：** 取消注释该调用。

**第 2564 行（当前）：**
```cpp
// --- 修改前 (第 2564 行) ---
    // UnsummonPetTemporaryIfAny();      // <-- BUG：被注释掉

// --- 修改后 (第 2564 行) ---
    UnsummonPetTemporaryIfAny();          // <-- 修复：已取消注释
```

完整上下文：
```cpp
    if (InstanceScript* data_s = GetInstanceScript())
        data_s->OnPlayerLeaveForScript(this);

    UnsummonPetTemporaryIfAny();          // 已取消注释
    UnsummonCurrentBattlePetIfAny(true);
```

---

### 4c. ZoneTeleport — ResummonPetTemporaryUnSummonedIfAny 被注释掉

**Bug：** 在 `ZoneTeleport` 后的延迟回调中，`player->ResummonPetTemporaryUnSummonedIfAny()` 的调用被注释掉了。这意味着在区域入口处被临时解散的宠物在传送完成后**从未**被重新召唤。宠物会丢失，直到玩家手动再次召唤它。

**修复：** 取消注释该调用。

**第 2667 行（当前）：**
```cpp
// --- 修改前 (第 2667 行) ---
                        // player->ResummonPetTemporaryUnSummonedIfAny();   // <-- BUG：被注释掉

// --- 修改后 (第 2667 行) ---
                        player->ResummonPetTemporaryUnSummonedIfAny();      // <-- 修复：已取消注释
```

完整上下文：
```cpp
                player->AddDelayedEvent(100, [player, _map]() -> void
                {
                    if (!player->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_TAXI_FLIGHT))
                    {
                        player->ResummonPetTemporaryUnSummonedIfAny();      // 已取消注释
                        player->SummonLastSummonedBattlePet();
                        player->RestoreAllControlled();
                    }
                    player->ProcessDelayedOperations();
                    player->ReCreateAreaTriggerObjects();
                });
```

---

## 5. `src/common/Database/MySQLConnection.cpp`

### 5a. MySQL 字符集 "utf8" → "utf8mb4"

**Bug：** 使用了 `mysql_set_character_set(m_Mysql, "utf8")`。在 MySQL 中，`"utf8"` 是 `utf8mb3` 的别名，只支持基本多文种平面（最大 3 字节）。这意味着任何 4 字节 UTF-8 字符（例如表情符号 🐾、某些中日韩越统一表意文字扩展区字符，或包含此类字符的魔兽世界玩家名字）都会在 INSERT/UPDATE 时导致数据截断或 MySQL 错误。

**修复：** 改为 `"utf8mb4"`（4 字节 UTF-8），这是完整的 UTF-8 实现。

**第 139 行（当前）：**
```cpp
// --- 修改前 (第 139 行) ---
        mysql_set_character_set(m_Mysql, "utf8");     // <-- BUG：仅 3 字节 UTF-8

// --- 修改后 (第 139 行) ---
        mysql_set_character_set(m_Mysql, "utf8mb4");  // <-- 修复：完整的 4 字节 UTF-8
```

完整上下文：
```cpp
        // 设置连接属性为 UTF8 以正确处理不同服务器配置的本地化
        // 核心以 UTF8 发送数据，因此 MySQL 也必须期望 UTF8
        mysql_set_character_set(m_Mysql, "utf8mb4");    // 已修复
        return PrepareStatements();
```

---

## 6. 数据库 — `gossip_menu_option` 表

### 6a. 缺少兽栏宠物对话选项（12 个菜单）

**Bug：** 许多兽栏管理员 NPC 使用的 `gossip_menu_id` 值在其 `gossip_menu_option` 表中没有 `OptionType = 14` (STABLEPET) 的行。回退到 MenuID=0 的兽栏选项仅在菜单有**零**行时才会发生——如果菜单有任何行（商人、战斗宠物治疗等），兽栏选项就永远不会被添加。

**修复：** 使用下一个可用的 `OptionIndex` 向每个受影响的菜单插入了一个兽栏宠物选项。

**SQL 脚本：**
```sql
INSERT IGNORE INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `OptionNpcflag2`, `BoxCurrency`)
VALUES
    (5283, 1, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (7889, 1, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (8805, 1, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (9212, 1, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (9499, 0, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (9572, 0, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (9821, 3, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (9864, 0, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (12106, 2, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (14991, 3, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (21580, 3, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),
    (100550, 2, 0, '我想把我的宠物寄存在这里', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0);
```

**受影响的 NPC：** 所有拥有 `npcflag & 4194304` (UNIT_NPC_FLAG_STABLEMASTER) 且其 `gossip_menu_id` 为上述值之一的生物。

**为什么这些菜单缺少兽栏选项：**
- MenuID 9821 是 Legion 数据中最常用的兽栏菜单，但原始数据包只在其中配置了 Vendor (OptionType=3) 和 Battle Pet Heal (OptionType=1)，没有 Stable (OptionType=14)
- 其他菜单同理
- MenuID=0 虽然有兽栏选项，但代码的 fallback 机制仅在菜单完全无选项时才生效
