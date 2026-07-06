/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/
#include "ElunaSpellWrapper.h"
#include "ElunaIncludes.h"
#include "ElunaTemplate.h"

ElunaProcInfo::ElunaProcInfo(Unit* actor, Unit* actionTarget, uint32 typeMask,
    uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask,
    Spell* spell, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, Map* map)
    : _actor(actor), _actionTarget(actionTarget), _typeMask(typeMask), _spellTypeMask(spellTypeMask), _spellPhaseMask(spellPhaseMask)
    , _hitMask(hitMask), _spell(spell), _spellInfo(spellInfo), _schoolMask(schoolMask), _damage(0)
    , _damageType(DIRECT_DAMAGE), _attackType(BASE_ATTACK), _damageAbsorb(0), _resist(0), _block(0)
    , _heal(0), _effectiveHeal(0), _healAbsorb(0), _map(map)
{
}

ElunaProcInfo::ElunaProcInfo(ProcEventInfo& procInfo, Map* map)
    : _actor(procInfo.GetActor()), _actionTarget(procInfo.GetActionTarget()), _typeMask(procInfo.GetTypeMask()), _spellTypeMask(procInfo.GetSpellTypeMask()), _spellPhaseMask(procInfo.GetSpellPhaseMask())
    , _hitMask(0), _spell(nullptr), _spellInfo(procInfo.GetSpellInfo()), _schoolMask(procInfo.GetSchoolMask()), _damage(0)
    , _damageType(DIRECT_DAMAGE), _attackType(BASE_ATTACK), _damageAbsorb(0), _resist(0), _block(0)
    , _heal(0), _effectiveHeal(0), _healAbsorb(0), _map(map)
{
}

SpellInfo const* ElunaProcInfo::GetSpellInfo() const
{
    if (_spellInfo)
        return _spellInfo;
    if (_spell)
        return _spell->GetSpellInfo();
    return nullptr;
}

void ElunaProcInfo::SetDamage(uint32 damage, DamageEffectType damageType, WeaponAttackType attackType)
{
    _damage = damage;
    _damageType = damageType;
    _attackType = attackType;
}

void ElunaProcInfo::SetHeal(uint32 heal)
{
    _heal = heal;
    _effectiveHeal = heal;
}

void ElunaProcInfo::ApplyToProcEventInfo(ProcEventInfo& procInfo) const
{
}

ElunaSpellInfo::ElunaSpellInfo(uint32 spellId) : _spellInfo(sSpellMgr->GetSpellInfo(spellId))
{
}
