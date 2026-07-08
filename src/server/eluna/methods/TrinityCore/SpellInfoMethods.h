/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/
#ifndef SPELLINFO_METHODS
#define SPELLINFO_METHODS
namespace LuaSpellInfo
{
    /**
     * Returns the ID of the [SpellInfo].
     *
     * @return uint32 id
     */
    int GetId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the dispel type of the [SpellInfo].
     *
     * @return uint32 dispel
     */
    int GetDispel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mechanic of the [SpellInfo].
     *
     * @return uint32 mechanic
     */
    int GetMechanic(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the attributes of the [SpellInfo].
     *
     * @return uint32 attributes
     */
    int GetAttributes(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the first extended attributes of the [SpellInfo].
     *
     * @return uint32 attributesEx
     */
    int GetAttributesEx(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the second extended attributes of the [SpellInfo].
     *
     * @return uint32 attributesEx2
     */
    int GetAttributesEx2(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the third extended attributes of the [SpellInfo].
     *
     * @return uint32 attributesEx3
     */
    int GetAttributesEx3(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the fourth extended attributes of the [SpellInfo].
     *
     * @return uint32 attributesEx4
     */
    int GetAttributesEx4(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the fifth extended attributes of the [SpellInfo].
     *
     * @return uint32 attributesEx5
     */
    int GetAttributesEx5(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the sixth extended attributes of the [SpellInfo].
     *
     * @return uint32 attributesEx6
     */
    int GetAttributesEx6(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the seventh extended attributes of the [SpellInfo].
     *
     * @return uint32 attributesEx7
     */
    int GetAttributesEx7(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the custom attributes of the [SpellInfo].
     *
     * @return uint32 attributesCu
     */
    int GetAttributesCu(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the stances bitmask of the [SpellInfo] as uint32.
     *
     * @return uint32 stances
     */
    int GetStances(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the stances not bitmask of the [SpellInfo] as uint32.
     *
     * @return uint32 stancesNot
     */
    int GetStancesNot(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the targets bitmask of the [SpellInfo].
     *
     * @return uint32 targets
     */
    int GetTargets(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target creature type of the [SpellInfo].
     *
     * @return uint32 targetCreatureType
     */
    int GetTargetCreatureType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the requires spell focus entry of the [SpellInfo].
     *
     * @return uint32 requiresSpellFocus
     */
    int GetRequiresSpellFocus(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the facing caster flags of the [SpellInfo].
     *
     * @return uint32 facingCasterFlags
     */
    int GetFacingCasterFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the caster aura state required to cast the [SpellInfo].
     *
     * @return uint32 casterAuraState
     */
    int GetCasterAuraState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target aura state required to cast the [SpellInfo].
     *
     * @return uint32 targetAuraState
     */
    int GetTargetAuraState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the caster aura state that prevents casting the [SpellInfo].
     *
     * @return uint32 casterAuraStateNot
     */
    int GetCasterAuraStateNot(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target aura state that prevents casting the [SpellInfo].
     *
     * @return uint32 targetAuraStateNot
     */
    int GetTargetAuraStateNot(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell ID that must be active on the caster to cast the [SpellInfo].
     *
     * @return uint32 casterAuraSpell
     */
    int GetCasterAuraSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell ID that must be active on the target to cast the [SpellInfo].
     *
     * @return uint32 targetAuraSpell
     */
    int GetTargetAuraSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell ID that must not be active on the caster to cast the [SpellInfo].
     *
     * @return uint32 excludeCasterAuraSpell
     */
    int GetExcludeCasterAuraSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell ID that must not be active on the target to cast the [SpellInfo].
     *
     * @return uint32 excludeTargetAuraSpell
     */
    int GetExcludeTargetAuraSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the recovery time in milliseconds of the [SpellInfo].
     *
     * @return uint32 recoveryTime
     */
    int GetRecoveryTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the category recovery time in milliseconds of the [SpellInfo].
     *
     * @return uint32 categoryRecoveryTime
     */
    int GetCategoryRecoveryTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the start recovery category of the [SpellInfo].
     *
     * @return uint32 startRecoveryCategory
     */
    int GetStartRecoveryCategory(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the start recovery time in milliseconds of the [SpellInfo].
     *
     * @return uint32 startRecoveryTime
     */
    int GetStartRecoveryTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the interrupt flags of the [SpellInfo].
     *
     * @return uint32 interruptFlags
     */
    int GetInterruptFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the aura interrupt flags of the [SpellInfo].
     *
     * @return uint32 auraInterruptFlags
     */
    int GetAuraInterruptFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the channel interrupt flags of the [SpellInfo].
     *
     * @return uint32 channelInterruptFlags
     */
    int GetChannelInterruptFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the proc flags of the [SpellInfo].
     *
     * @return uint32 procFlags
     */
    int GetProcFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the proc chance of the [SpellInfo].
     *
     * @return uint32 procChance
     */
    int GetProcChance(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the proc charges of the [SpellInfo].
     *
     * @return uint32 procCharges
     */
    int GetProcCharges(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the maximum level of the [SpellInfo].
     *
     * @return uint32 maxLevel
     */
    int GetMaxLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the base level required to cast the [SpellInfo].
     *
     * @return uint32 baseLevel
     */
    int GetBaseLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell level of the [SpellInfo].
     *
     * @return uint32 spellLevel
     */
    int GetSpellLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the power type of the [SpellInfo].
     *
     * @return uint32 powerType
     */
    int GetPowerType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mana cost of the [SpellInfo].
     *
     * @return uint32 manaCost
     */
    int GetManaCost(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the mana cost per level of the [SpellInfo].
     *
     * @return uint32 manaCostPerlevel
     */
    int GetManaCostPerlevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mana per second drain of the [SpellInfo].
     *
     * @return uint32 manaPerSecond
     */
    int GetManaPerSecond(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mana per second per level drain of the [SpellInfo].
     *
     * @return uint32 manaPerSecondPerLevel
     */
    int GetManaPerSecondPerLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mana cost percentage of the [SpellInfo].
     *
     * @return uint32 manaCostPercentage
     */
    int GetManaCostPercentage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the rune cost ID of the [SpellInfo].
     *
     * @return uint32 runeCostID
     */
    int GetRuneCostID(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns the projectile speed of the [SpellInfo].
     *
     * @return float speed
     */
    int GetSpeed(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the stack amount of the [SpellInfo].
     *
     * @return uint32 stackAmount
     */
    int GetStackAmount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the totem entry at the given index for the [SpellInfo].
     *
     * @param uint32 index : the totem index (0-1)
     * @return uint32 totem
     */
    int GetTotem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the reagent entry at the given index for the [SpellInfo].
     *
     * @param uint32 index : the reagent index (0-MAX_SPELL_REAGENTS-1)
     * @return int32 reagent
     */
    int GetReagent(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the reagent count at the given index for the [SpellInfo].
     *
     * @param uint32 index : the reagent index (0-MAX_SPELL_REAGENTS-1)
     * @return uint32 reagentCount
     */
    int GetReagentCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the required equipped item class of the [SpellInfo].
     *
     * @return int32 equippedItemClass
     */
    int GetEquippedItemClass(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the required equipped item subclass mask of the [SpellInfo].
     *
     * @return int32 equippedItemSubClassMask
     */
    int GetEquippedItemSubClassMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the required equipped item inventory type mask of the [SpellInfo].
     *
     * @return int32 equippedItemInventoryTypeMask
     */
    int GetEquippedItemInventoryTypeMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the totem category entry at the given index for the [SpellInfo].
     *
     * @param uint32 index : the totem category index (0-1)
     * @return uint32 totemCategory
     */
    int GetTotemCategory(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell visual ID at the given index for the [SpellInfo].
     *
     * @param uint32 index : the visual index (0-1), index ignored for retail
     * @return uint32 spellVisual
     */
    int GetSpellVisual(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell icon ID of the [SpellInfo].
     *
     * @return uint32 spellIconID
     */
    int GetSpellIconID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the active icon ID of the [SpellInfo].
     *
     * @return uint32 activeIconID
     */
    int GetActiveIconID(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the priority of the [SpellInfo].
     *
     * @return uint32 priority
     */
    int GetPriority(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns the maximum target level of the [SpellInfo].
     *
     * @return uint32 maxTargetLevel
     */
    int GetMaxTargetLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the maximum number of affected targets of the [SpellInfo].
     *
     * @return uint32 maxAffectedTargets
     */
    int GetMaxAffectedTargets(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell family name of the [SpellInfo].
     *
     * @return uint32 spellFamilyName
     */
    int GetSpellFamilyName(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell family flags of the [SpellInfo] at the given index.
     * The flags are a 96-bit value split into three uint32 components (index 0-2).
     *
     * @param uint32 index : the flag index (0-2)
     * @return uint32 spellFamilyFlags
     */
    int GetSpellFamilyFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the damage class of the [SpellInfo].
     *
     * @return uint32 dmgClass
     */
    int GetDmgClass(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the prevention type of the [SpellInfo].
     *
     * @return uint32 preventionType
     */
    int GetPreventionType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the area group ID of the [SpellInfo].
     *
     * @return int32 areaGroupId
     */
    int GetAreaGroupId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the school mask of the [SpellInfo].
     *
     * @return uint32 schoolMask
     */
    int GetSchoolMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the duration in milliseconds of the [SpellInfo].
     *
     * @return int32 duration
     */
    int GetDuration(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the maximum duration in milliseconds of the [SpellInfo].
     *
     * @return int32 maxDuration
     */
    int GetMaxDuration(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the maximum range of the [SpellInfo].
     *
     * @return float maxRange
     */
    int GetMaxRange(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the minimum range of the [SpellInfo].
     *
     * @return float minRange
     */
    int GetMinRange(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the maximum number of ticks of the [SpellInfo].
     *
     * @return uint32 maxTicks
     */
    int GetMaxTicks(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the category of the [SpellInfo].
     *
     * @return uint32 category
     */
    int GetCategory(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the rank of the [SpellInfo].
     *
     * @return uint8 rank
     */
    int GetRank(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a bitmask of all mechanics used across all effects of the [SpellInfo].
     *
     * @return uint32 mechanicMask
     */
    int GetAllEffectsMechanicMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the allowed mechanic mask of the [SpellInfo].
     *
     * @return uint32 allowedMechanicMask
     */
    int GetAllowedMechanicMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the explicit target mask of the [SpellInfo].
     *
     * @return uint32 explicitTargetMask
     */
    int GetExplicitTargetMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the aura state of the [SpellInfo].
     *
     * @return uint32 auraState
     */
    int GetAuraState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell specific type of the [SpellInfo].
     *
     * @return uint32 spellSpecific
     */
    int GetSpellSpecific(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the weapon attack type of the [SpellInfo].
     *
     * @return uint32 attackType
     */
    int GetAttackType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mechanic mask for the given effect mask of the [SpellInfo].
     *
     * @param uint32 effectMask : bitmask of effect indices to check
     * @return uint32 mechanicMask
     */
    int GetSpellMechanicMaskByEffectMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mechanic mask for the given effect index of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect index (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 mechanicMask
     */
    int GetEffectMechanicMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the mechanic for the given effect index of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect index (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 mechanic
     */
    int GetEffectMechanic(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the diminishing returns group for the [SpellInfo].
     *
     * @param bool triggered : whether the spell is triggered
     * @return uint32 diminishingGroup
     */
    int GetDiminishingReturnsGroupForSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the diminishing returns group type for the [SpellInfo].
     *
     * @param bool triggered : whether the spell is triggered
     * @return uint32 diminishingGroupType
     */
    int GetDiminishingReturnsGroupType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the diminishing returns max level for the [SpellInfo].
     *
     * @param bool triggered : whether the spell is triggered
     * @return uint32 diminishingMaxLevel
     */
    int GetDiminishingReturnsMaxLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the diminishing returns limit duration in milliseconds for the [SpellInfo].
     *
     * @param bool triggered : whether the spell is triggered
     * @return int32 diminishingLimitDuration
     */
    int GetDiminishingReturnsLimitDuration(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the calculated cast time in milliseconds of the [SpellInfo].
     *
     * @return uint32 castTime
     */
    int CalcCastTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a passive spell, `false` otherwise.
     *
     * @return bool isPassive
     */
    int IsPassive(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is autocastable, `false` otherwise.
     *
     * @return bool isAutocastable
     */
    int IsAutocastable(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is stackable with ranks, `false` otherwise.
     *
     * @return bool isStackableWithRanks
     */
    int IsStackableWithRanks(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a passive spell stackable with ranks, `false` otherwise.
     *
     * @return bool isPassiveStackableWithRanks
     */
    int IsPassiveStackableWithRanks(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] occupies multiple aura slots, `false` otherwise.
     *
     * @return bool isMultiSlotAura
     */
    int IsMultiSlotAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] can stack on one slot from different casters, `false` otherwise.
     *
     * @return bool isStackableOnOneSlotWithDifferentCasters
     */
    int IsStackableOnOneSlotWithDifferentCasters(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] cooldown is started on event, `false` otherwise.
     *
     * @return bool isCooldownStartedOnEvent
     */
    int IsCooldownStartedOnEvent(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] persists through death, `false` otherwise.
     *
     * @return bool isDeathPersistent
     */
    int IsDeathPersistent(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] requires the target to be dead, `false` otherwise.
     *
     * @return bool isRequiringDeadTarget
     */
    int IsRequiringDeadTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] allows targeting dead units, `false` otherwise.
     *
     * @return bool isAllowingDeadTarget
     */
    int IsAllowingDeadTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a group buff, `false` otherwise.
     *
     * @return bool isGroupBuff
     */
    int IsGroupBuff(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] can be used in combat, `false` otherwise.
     *
     * @return bool canBeUsedInCombat
     */
    int CanBeUsedInCombat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a positive spell, `false` otherwise.
     *
     * @return bool isPositive
     */
    int IsPositive(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the effect at the given index of the [SpellInfo] is positive, `false` otherwise.
     *
     * @param uint8 effIndex : the effect index (0-MAX_SPELL_EFFECTS-1)
     * @return bool isPositiveEffect
     */
    int IsPositiveEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a channeled spell, `false` otherwise.
     *
     * @return bool isChanneled
     */
    int IsChanneled(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] allows movement while channeling, `false` otherwise.
     *
     * @return bool isMoveAllowedChannel
     */
    int IsMoveAllowedChannel(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns `true` if the [SpellInfo] requires combo points, `false` otherwise.
     *
     * @return bool needsComboPoints
     */
    int NeedsComboPoints(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns `true` if the [SpellInfo] is a next melee swing spell, `false` otherwise.
     *
     * @return bool isNextMeleeSwingSpell
     */
    int IsNextMeleeSwingSpell(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns `true` if the [SpellInfo] breaks stealth, `false` otherwise.
     *
     * @return bool isBreakingStealth
     */
    int IsBreakingStealth(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns `true` if the [SpellInfo] is a ranged weapon spell, `false` otherwise.
     *
     * @return bool isRangedWeaponSpell
     */
    int IsRangedWeaponSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is an auto repeat ranged spell, `false` otherwise.
     *
     * @return bool isAutoRepeatRangedSpell
     */
    int IsAutoRepeatRangedSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] has initial aggro, `false` otherwise.
     *
     * @return bool hasInitialAggro
     */
    int HasInitialAggro(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is ranked, `false` otherwise.
     *
     * @return bool isRanked
     */
    int IsRanked(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] affects an area, `false` otherwise.
     *
     * @return bool isAffectingArea
     */
    int IsAffectingArea(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] targets an area, `false` otherwise.
     *
     * @return bool isTargetingArea
     */
    int IsTargetingArea(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] needs an explicit unit target, `false` otherwise.
     *
     * @return bool needsExplicitUnitTarget
     */
    int NeedsExplicitUnitTarget(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns `true` if the [SpellInfo] is a self cast spell, `false` otherwise.
     *
     * @return bool isSelfCast
     */
    int IsSelfCast(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns `true` if the [SpellInfo] can only have a single target active at a time, `false` otherwise.
     *
     * @return bool isSingleTarget
     */
    int IsSingleTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is an explicit discovery spell, `false` otherwise.
     *
     * @return bool isExplicitDiscovery
     */
    int IsExplicitDiscovery(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a loot crafting spell, `false` otherwise.
     *
     * @return bool isLootCrafting
     */
    int IsLootCrafting(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns `true` if the [SpellInfo] is a profession or riding spell, `false` otherwise.
     *
     * @return bool isProfessionOrRiding
     */
    int IsProfessionOrRiding(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns `true` if the [SpellInfo] is a profession spell, `false` otherwise.
     *
     * @return bool isProfession
     */
    int IsProfession(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a primary profession spell, `false` otherwise.
     *
     * @return bool isPrimaryProfession
     */
    int IsPrimaryProfession(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is the first rank of a primary profession spell, `false` otherwise.
     *
     * @return bool isPrimaryProfessionFirstRank
     */
    int IsPrimaryProfessionFirstRank(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns `true` if the [SpellInfo] is an ability learned with a profession, `false` otherwise.
     *
     * @return bool isAbilityLearnedWithProfession
     */
    int IsAbilityLearnedWithProfession(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns `true` if the [SpellInfo] is affected by spell mods, `false` otherwise.
     *
     * @return bool isAffectedBySpellMods
     */
    int IsAffectedBySpellMods(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] has the given spell effect, `false` otherwise.
     *
     * @param uint32 effect : the [SpellEffects] to check for
     * @return bool hasEffect
     */
    int HasEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] has the given aura type, `false` otherwise.
     *
     * @param uint32 aura : the [AuraType] to check for
     * @return bool hasAura
     */
    int HasAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] has an area aura effect, `false` otherwise.
     *
     * @return bool hasAreaAuraEffect
     */
    int HasAreaAuraEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] only has damage effects, `false` otherwise.
     *
     * @return bool hasOnlyDamageEffects
     */
    int HasOnlyDamageEffects(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is affected by the given spell family and flags, `false` otherwise.
     * The flags are a 96-bit value split into three uint32 components in WoTLK
     * and a 128-bit value split into four uint32 components in Retail.
     *
     * @param uint32 familyName : the spell family name to check
     * @param uint32 flag0 : the first 32 bits of the spell family flags
     * @param uint32 flag1 : the second 32 bits of the spell family flags
     * @param uint32 flag2 : the third 32 bits of the spell family flags
     * @param uint32 flag3 : the fourth 32 bits of the spell family flags, only used in Retail
     * @return bool isAffected
     */
    int IsAffected(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is affected by the given [SpellModifier], `false` otherwise.
     *
     * @param [SpellModifier] mod : the spell modifier to check
     * @return bool isAffectedBySpellMod
     */
    int IsAffectedBySpellMod(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is the same rank as the given [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] spellInfo : the spell info to compare against
     * @return bool isRankOf
     */
    int IsRankOf(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a different rank of the given [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] spellInfo : the spell info to compare against
     * @return bool isDifferentRankOf
     */
    int IsDifferentRankOf(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is a higher rank than the given [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] spellInfo : the spell info to compare against
     * @return bool isHighRankOf
     */
    int IsHighRankOf(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] can pierce the immunity provided by the given [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] auraSpellInfo : the aura spell info to check against
     * @return bool canPierceImmuneAura
     */
    int CanPierceImmuneAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] can dispel the given [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] auraSpellInfo : the aura spell info to check against
     * @return bool canDispelAura
     */
    int CanDispelAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] can provide immunity against the given [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] auraSpellInfo : the aura spell info to check against
     * @return bool canSpellProvideImmunityAgainstAura
     */
    int CanSpellProvideImmunityAgainstAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is exclusively stacking with the given [SpellInfo] by specific aura, `false` otherwise.
     *
     * @param [SpellInfo] spellInfo : the spell info to compare against
     * @return bool isAuraExclusiveBySpecificWith
     */
    int IsAuraExclusiveBySpecificWith(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is exclusively stacking per caster with the given [SpellInfo] by specific aura, `false` otherwise.
     *
     * @param [SpellInfo] spellInfo : the spell info to compare against
     * @return bool isAuraExclusiveBySpecificPerCasterWith
     */
    int IsAuraExclusiveBySpecificPerCasterWith(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given [Item] fits the requirements of the [SpellInfo], `false` otherwise.
     *
     * @param [Item] item : the item to check
     * @return bool isItemFitToSpellRequirements
     */
    int IsItemFitToSpellRequirements(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] is an ability of the given skill type, `false` otherwise.
     *
     * @param uint32 skillType : the skill type to check
     * @return bool isAbilityOfSkillType
     */
    int IsAbilityOfSkillType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] needs to be triggered by the given triggering [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] triggeringSpell : the triggering spell info to check against
     * @return bool needsToBeTriggeredByCaster
     */
    int NeedsToBeTriggeredByCaster(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Checks whether the [SpellInfo] can be cast on the given target by the given caster.
     * Returns the [SpellCastResult] of the check.
     *
     * @param [WorldObject] caster : the caster to check from
     * @param [WorldObject] target : the target to check against
     * @return uint32 spellCastResult
     */
    int CheckTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given [Unit] matches the required creature type for the [SpellInfo], `false` otherwise.
     *
     * @param [Unit] target : the unit to check
     * @return bool checkTargetCreatureType
     */
    int CheckTargetCreatureType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [SpellInfo] cancels the given [AuraEffect], `false` otherwise.
     *
     * @param [AuraEffect] aurEff : the aura effect to check against
     * @return bool spellCancelsAuraEffect
     */
    int SpellCancelsAuraEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the effect index of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 effectIndex
     */
    int GetEffectIndex(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the effect type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 effectType
     */
    int GetEffectType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the aura type applied by the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 applyAuraName
     */
    int GetEffectApplyAuraName(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the amplitude in milliseconds of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 amplitude
     */
    int GetEffectAmplitude(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the die sides of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return int32 dieSides
     */
    int GetEffectDieSides(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns the real points per level of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float realPointsPerLevel
     */
    int GetEffectRealPointsPerLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the base points of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return int32 basePoints
     */
    int GetEffectBasePoints(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the points per combo point of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float pointsPerComboPoint
     */
    int GetEffectPointsPerComboPoint(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns the value multiplier of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float valueMultiplier
     */
    int GetEffectValueMultiplier(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the damage multiplier of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float damageMultiplier
     */
    int GetEffectDamageMultiplier(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the bonus multiplier of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float bonusMultiplier
     */
    int GetEffectBonusMultiplier(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the misc value of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return int32 miscValue
     */
    int GetEffectMiscValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the secondary misc value of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return int32 miscValueB
     */
    int GetEffectMiscValueB(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the chain target count of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 chainTarget
     */
    int GetEffectChainTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the item type entry of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 itemType
     */
    int GetEffectItemType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the trigger spell ID of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 triggerSpell
     */
    int GetEffectTriggerSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell class mask component at the given mask index for the given effect slot of the [SpellInfo].
     * The mask is a 96-bit value split into three uint32 components (index 0-2).
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @param uint32 maskIndex : the mask component index (0-2)
     * @return uint32 spellClassMask
     */
    int GetEffectSpellClassMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the calculated value for the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return int32 calcValue
     */
    int GetEffectCalcValue(Eluna* /*E*/)
    {
        return 1;
    }

    /**
     * Returns the calculated radius for the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float calcRadius
     */
    int GetEffectCalcRadius(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] has a radius, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool hasRadius
     */
    int GetEffectHasRadius(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the provided target mask for the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 providedTargetMask
     */
    int GetEffectProvidedTargetMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the implicit target type for the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 implicitTargetType
     */
    int GetEffectImplicitTargetType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the used target object type for the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 usedTargetObjectType
     */
    int GetEffectUsedTargetObjectType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] is an effect, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool isEffect
     */
    int EffectIsEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] is the given effect type, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @param uint32 effect : the [SpellEffects] to check for
     * @return bool isEffectType
     */
    int EffectIsEffectType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] applies an aura, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool isAura
     */
    int EffectIsAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] applies the given aura type, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @param uint32 aura : the [AuraType] to check for
     * @return bool isAuraType
     */
    int EffectIsAuraType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] is targeting an area, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool isTargetingArea
     */
    int EffectIsTargetingArea(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] is an area aura effect, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool isAreaAuraEffect
     */
    int EffectIsAreaAuraEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the given effect slot of the [SpellInfo] is a unit owned aura effect, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool isUnitOwnedAuraEffect
     */
    int EffectIsUnitOwnedAuraEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target A type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 targetA
     */
    int GetEffectTargetATarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target A selection category of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 selectionCategory
     */
    int GetEffectTargetASelectionCategory(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target A reference type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 referenceType
     */
    int GetEffectTargetAReferenceType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target A object type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 objectType
     */
    int GetEffectTargetAObjectType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target A check type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 checkType
     */
    int GetEffectTargetACheckType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target A direction type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 directionType
     */
    int GetEffectTargetADirectionType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if target A of the given effect slot of the [SpellInfo] is an area target, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool isArea
     */
    int GetEffectTargetAIsArea(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the calculated direction angle for target A of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float directionAngle
     */
    int GetEffectTargetADirectionAngle(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target B type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 targetB
     */
    int GetEffectTargetBTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target B selection category of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 selectionCategory
     */
    int GetEffectTargetBSelectionCategory(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target B reference type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 referenceType
     */
    int GetEffectTargetBReferenceType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target B object type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 objectType
     */
    int GetEffectTargetBObjectType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target B check type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 checkType
     */
    int GetEffectTargetBCheckType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target B direction type of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return uint32 directionType
     */
    int GetEffectTargetBDirectionType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if target B of the given effect slot of the [SpellInfo] is an area target, `false` otherwise.
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return bool isArea
     */
    int GetEffectTargetBIsArea(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the calculated direction angle for target B of the given effect slot of the [SpellInfo].
     *
     * @param uint32 effIndex : the effect slot (0-MAX_SPELL_EFFECTS-1)
     * @return float directionAngle
     */
    int GetEffectTargetBDirectionAngle(Eluna* /*E*/)
{
    return 1;
}


    ElunaRegister<ElunaSpellInfo> SpellInfoMethods[] =
    {
#if ELUNA_EXPANSION < EXP_RETAIL

        { "GetManaCostPerlevel",                        &LuaSpellInfo::GetManaCostPerlevel },
        { "GetManaPerSecond",                           &LuaSpellInfo::GetManaPerSecond },
        { "GetManaPerSecondPerLevel",                   &LuaSpellInfo::GetManaPerSecondPerLevel },
        { "GetManaCostPercentage",                      &LuaSpellInfo::GetManaCostPercentage },
        { "GetRuneCostID",                              &LuaSpellInfo::GetRuneCostID },
        { "GetPriority",                                &LuaSpellInfo::GetPriority },
        { "NeedsComboPoints",                           &LuaSpellInfo::NeedsComboPoints },
        { "IsBreakingStealth",                          &LuaSpellInfo::IsBreakingStealth },
        { "IsSelfCast",                                 &LuaSpellInfo::IsSelfCast },
        { "IsProfessionOrRiding",                       &LuaSpellInfo::IsProfessionOrRiding },
        { "IsAbilityLearnedWithProfession",             &LuaSpellInfo::IsAbilityLearnedWithProfession },
        { "GetEffectDieSides",                          &LuaSpellInfo::GetEffectDieSides },
        { "GetEffectPointsPerComboPoint",               &LuaSpellInfo::GetEffectPointsPerComboPoint },
#else
        { "GetManaCostPerlevel",                        METHOD_REG_NONE  },
        { "GetManaPerSecond",                           METHOD_REG_NONE  },
        { "GetManaPerSecondPerLevel",                   METHOD_REG_NONE  },
        { "GetManaCostPercentage",                      METHOD_REG_NONE  },
        { "GetRuneCostID",                              METHOD_REG_NONE  },
        { "GetPriority",                                METHOD_REG_NONE  },
        { "NeedsComboPoints",                           METHOD_REG_NONE  },
        { "IsBreakingStealth",                          METHOD_REG_NONE  },
        { "IsSelfCast",                                 METHOD_REG_NONE  },
        { "IsProfessionOrRiding",                       METHOD_REG_NONE  },
        { "IsAbilityLearnedWithProfession",             METHOD_REG_NONE  },
        { "GetEffectDieSides",                          METHOD_REG_NONE  },
        { "GetEffectPointsPerComboPoint",               METHOD_REG_NONE  },
#endif
        { "GetId",                                      &LuaSpellInfo::GetId },
        { "GetDispel",                                  &LuaSpellInfo::GetDispel },
        { "GetMechanic",                                &LuaSpellInfo::GetMechanic },
        { "GetAttributes",                              &LuaSpellInfo::GetAttributes },
        { "GetAttributesEx",                            &LuaSpellInfo::GetAttributesEx },
        { "GetAttributesEx2",                           &LuaSpellInfo::GetAttributesEx2 },
        { "GetAttributesEx3",                           &LuaSpellInfo::GetAttributesEx3 },
        { "GetAttributesEx4",                           &LuaSpellInfo::GetAttributesEx4 },
        { "GetAttributesEx5",                           &LuaSpellInfo::GetAttributesEx5 },
        { "GetAttributesEx6",                           &LuaSpellInfo::GetAttributesEx6 },
        { "GetAttributesEx7",                           &LuaSpellInfo::GetAttributesEx7 },
        { "GetAttributesCu",                            &LuaSpellInfo::GetAttributesCu },
        { "GetStances",                                 &LuaSpellInfo::GetStances },
        { "GetStancesNot",                              &LuaSpellInfo::GetStancesNot },
        { "GetTargets",                                 &LuaSpellInfo::GetTargets },
        { "GetTargetCreatureType",                      &LuaSpellInfo::GetTargetCreatureType },
        { "GetRequiresSpellFocus",                      &LuaSpellInfo::GetRequiresSpellFocus },
        { "GetFacingCasterFlags",                       &LuaSpellInfo::GetFacingCasterFlags },
        { "GetCasterAuraState",                         &LuaSpellInfo::GetCasterAuraState },
        { "GetTargetAuraState",                         &LuaSpellInfo::GetTargetAuraState },
        { "GetCasterAuraStateNot",                      &LuaSpellInfo::GetCasterAuraStateNot },
        { "GetTargetAuraStateNot",                      &LuaSpellInfo::GetTargetAuraStateNot },
        { "GetCasterAuraSpell",                         &LuaSpellInfo::GetCasterAuraSpell },
        { "GetTargetAuraSpell",                         &LuaSpellInfo::GetTargetAuraSpell },
        { "GetExcludeCasterAuraSpell",                  &LuaSpellInfo::GetExcludeCasterAuraSpell },
        { "GetExcludeTargetAuraSpell",                  &LuaSpellInfo::GetExcludeTargetAuraSpell },
        { "GetRecoveryTime",                            &LuaSpellInfo::GetRecoveryTime },
        { "GetCategoryRecoveryTime",                    &LuaSpellInfo::GetCategoryRecoveryTime },
        { "GetStartRecoveryCategory",                   &LuaSpellInfo::GetStartRecoveryCategory },
        { "GetStartRecoveryTime",                       &LuaSpellInfo::GetStartRecoveryTime },
        { "GetInterruptFlags",                          &LuaSpellInfo::GetInterruptFlags },
        { "GetAuraInterruptFlags",                      &LuaSpellInfo::GetAuraInterruptFlags },
        { "GetChannelInterruptFlags",                   &LuaSpellInfo::GetChannelInterruptFlags },
        { "GetProcFlags",                               &LuaSpellInfo::GetProcFlags },
        { "GetProcChance",                              &LuaSpellInfo::GetProcChance },
        { "GetProcCharges",                             &LuaSpellInfo::GetProcCharges },
        { "GetMaxLevel",                                &LuaSpellInfo::GetMaxLevel },
        { "GetBaseLevel",                               &LuaSpellInfo::GetBaseLevel },
        { "GetSpellLevel",                              &LuaSpellInfo::GetSpellLevel },
        { "GetPowerType",                               &LuaSpellInfo::GetPowerType },
        { "GetManaCost",                                &LuaSpellInfo::GetManaCost },
        { "GetSpeed",                                   &LuaSpellInfo::GetSpeed },
        { "GetStackAmount",                             &LuaSpellInfo::GetStackAmount },
        { "GetTotem",                                   &LuaSpellInfo::GetTotem },
        { "GetReagent",                                 &LuaSpellInfo::GetReagent },
        { "GetReagentCount",                            &LuaSpellInfo::GetReagentCount },
        { "GetEquippedItemClass",                       &LuaSpellInfo::GetEquippedItemClass },
        { "GetEquippedItemSubClassMask",                &LuaSpellInfo::GetEquippedItemSubClassMask },
        { "GetEquippedItemInventoryTypeMask",           &LuaSpellInfo::GetEquippedItemInventoryTypeMask },
        { "GetTotemCategory",                           &LuaSpellInfo::GetTotemCategory },
        { "GetSpellVisual",                             &LuaSpellInfo::GetSpellVisual },
        { "GetSpellIconID",                             &LuaSpellInfo::GetSpellIconID },
        { "GetActiveIconID",                            &LuaSpellInfo::GetActiveIconID },
        { "GetMaxTargetLevel",                          &LuaSpellInfo::GetMaxTargetLevel },
        { "GetMaxAffectedTargets",                      &LuaSpellInfo::GetMaxAffectedTargets },
        { "GetSpellFamilyName",                         &LuaSpellInfo::GetSpellFamilyName },
        { "GetSpellFamilyFlags",                        &LuaSpellInfo::GetSpellFamilyFlags },
        { "GetDmgClass",                                &LuaSpellInfo::GetDmgClass },
        { "GetPreventionType",                          &LuaSpellInfo::GetPreventionType },
        { "GetAreaGroupId",                             &LuaSpellInfo::GetAreaGroupId },
        { "GetSchoolMask",                              &LuaSpellInfo::GetSchoolMask },
        { "GetDuration",                                &LuaSpellInfo::GetDuration },
        { "GetMaxDuration",                             &LuaSpellInfo::GetMaxDuration },
        { "GetMaxRange",                                &LuaSpellInfo::GetMaxRange },
        { "GetMinRange",                                &LuaSpellInfo::GetMinRange },
        { "GetMaxTicks",                                &LuaSpellInfo::GetMaxTicks },
        { "GetCategory",                                &LuaSpellInfo::GetCategory },
        { "GetRank",                                    &LuaSpellInfo::GetRank },
        { "GetAllEffectsMechanicMask",                  &LuaSpellInfo::GetAllEffectsMechanicMask },
        { "GetAllowedMechanicMask",                     &LuaSpellInfo::GetAllowedMechanicMask },
        { "GetExplicitTargetMask",                      &LuaSpellInfo::GetExplicitTargetMask },
        { "GetAuraState",                               &LuaSpellInfo::GetAuraState },
        { "GetSpellSpecific",                           &LuaSpellInfo::GetSpellSpecific },
        { "GetAttackType",                              &LuaSpellInfo::GetAttackType },
        { "GetEffectMechanicMask",                      &LuaSpellInfo::GetEffectMechanicMask },
        { "GetEffectMechanic",                          &LuaSpellInfo::GetEffectMechanic },
        { "GetSpellMechanicMaskByEffectMask",           &LuaSpellInfo::GetSpellMechanicMaskByEffectMask },
        { "GetDiminishingReturnsGroupForSpell",         &LuaSpellInfo::GetDiminishingReturnsGroupForSpell },
        { "GetDiminishingReturnsGroupType",             &LuaSpellInfo::GetDiminishingReturnsGroupType },
        { "GetDiminishingReturnsMaxLevel",              &LuaSpellInfo::GetDiminishingReturnsMaxLevel },
        { "GetDiminishingReturnsLimitDuration",         &LuaSpellInfo::GetDiminishingReturnsLimitDuration },
        { "CalcCastTime",                               &LuaSpellInfo::CalcCastTime },
        { "IsPassive",                                  &LuaSpellInfo::IsPassive },
        { "IsAutocastable",                             &LuaSpellInfo::IsAutocastable },
        { "IsStackableWithRanks",                       &LuaSpellInfo::IsStackableWithRanks },
        { "IsPassiveStackableWithRanks",                &LuaSpellInfo::IsPassiveStackableWithRanks },
        { "IsMultiSlotAura",                            &LuaSpellInfo::IsMultiSlotAura },
        { "IsStackableOnOneSlotWithDifferentCasters",   &LuaSpellInfo::IsStackableOnOneSlotWithDifferentCasters },
        { "IsCooldownStartedOnEvent",                   &LuaSpellInfo::IsCooldownStartedOnEvent },
        { "IsDeathPersistent",                          &LuaSpellInfo::IsDeathPersistent },
        { "IsRequiringDeadTarget",                      &LuaSpellInfo::IsRequiringDeadTarget },
        { "IsAllowingDeadTarget",                       &LuaSpellInfo::IsAllowingDeadTarget },
        { "IsGroupBuff",                                &LuaSpellInfo::IsGroupBuff },
        { "CanBeUsedInCombat",                          &LuaSpellInfo::CanBeUsedInCombat },
        { "IsPositive",                                 &LuaSpellInfo::IsPositive },
        { "IsChanneled",                                &LuaSpellInfo::IsChanneled },
        { "IsMoveAllowedChannel",                       &LuaSpellInfo::IsMoveAllowedChannel },
        { "IsNextMeleeSwingSpell",                      &LuaSpellInfo::IsNextMeleeSwingSpell },
        { "IsRangedWeaponSpell",                        &LuaSpellInfo::IsRangedWeaponSpell },
        { "IsAutoRepeatRangedSpell",                    &LuaSpellInfo::IsAutoRepeatRangedSpell },
        { "HasInitialAggro",                            &LuaSpellInfo::HasInitialAggro },
        { "IsRanked",                                   &LuaSpellInfo::IsRanked },
        { "IsAffectingArea",                            &LuaSpellInfo::IsAffectingArea },
        { "IsTargetingArea",                            &LuaSpellInfo::IsTargetingArea },
        { "NeedsExplicitUnitTarget",                    &LuaSpellInfo::NeedsExplicitUnitTarget },
        { "IsSingleTarget",                             &LuaSpellInfo::IsSingleTarget },
        { "IsExplicitDiscovery",                        &LuaSpellInfo::IsExplicitDiscovery },
        { "IsLootCrafting",                             &LuaSpellInfo::IsLootCrafting },
        { "IsProfession",                               &LuaSpellInfo::IsProfession },
        { "IsPrimaryProfession",                        &LuaSpellInfo::IsPrimaryProfession },
        { "IsPrimaryProfessionFirstRank",               &LuaSpellInfo::IsPrimaryProfessionFirstRank },
        { "IsAffectedBySpellMods",                      &LuaSpellInfo::IsAffectedBySpellMods },
        { "HasAreaAuraEffect",                          &LuaSpellInfo::HasAreaAuraEffect },
        { "HasOnlyDamageEffects",                       &LuaSpellInfo::HasOnlyDamageEffects },
        { "IsPositiveEffect",                           &LuaSpellInfo::IsPositiveEffect },
        { "HasEffect",                                  &LuaSpellInfo::HasEffect },
        { "HasAura",                                    &LuaSpellInfo::HasAura },
        { "IsAffected",                                 &LuaSpellInfo::IsAffected },
        { "IsAffectedBySpellMod",                       &LuaSpellInfo::IsAffectedBySpellMod },
        { "IsRankOf",                                   &LuaSpellInfo::IsRankOf },
        { "IsDifferentRankOf",                          &LuaSpellInfo::IsDifferentRankOf },
        { "IsHighRankOf",                               &LuaSpellInfo::IsHighRankOf },
        { "CanPierceImmuneAura",                        &LuaSpellInfo::CanPierceImmuneAura },
        { "CanDispelAura",                              &LuaSpellInfo::CanDispelAura },
        { "CanSpellProvideImmunityAgainstAura",         &LuaSpellInfo::CanSpellProvideImmunityAgainstAura },
        { "IsAuraExclusiveBySpecificWith",              &LuaSpellInfo::IsAuraExclusiveBySpecificWith },
        { "IsAuraExclusiveBySpecificPerCasterWith",     &LuaSpellInfo::IsAuraExclusiveBySpecificPerCasterWith },
        { "IsItemFitToSpellRequirements",               &LuaSpellInfo::IsItemFitToSpellRequirements },
        { "IsAbilityOfSkillType",                       &LuaSpellInfo::IsAbilityOfSkillType },
        { "NeedsToBeTriggeredByCaster",                 &LuaSpellInfo::NeedsToBeTriggeredByCaster },
        { "CheckTarget",                                &LuaSpellInfo::CheckTarget },
        { "CheckTargetCreatureType",                    &LuaSpellInfo::CheckTargetCreatureType },
        { "SpellCancelsAuraEffect",                     &LuaSpellInfo::SpellCancelsAuraEffect },
        { "GetEffectIndex",                             &LuaSpellInfo::GetEffectIndex },
        { "GetEffectType",                              &LuaSpellInfo::GetEffectType },
        { "GetEffectApplyAuraName",                     &LuaSpellInfo::GetEffectApplyAuraName },
        { "GetEffectAmplitude",                         &LuaSpellInfo::GetEffectAmplitude },
        { "GetEffectRealPointsPerLevel",                &LuaSpellInfo::GetEffectRealPointsPerLevel },
        { "GetEffectBasePoints",                        &LuaSpellInfo::GetEffectBasePoints },
        { "GetEffectValueMultiplier",                   &LuaSpellInfo::GetEffectValueMultiplier },
        { "GetEffectDamageMultiplier",                  &LuaSpellInfo::GetEffectDamageMultiplier },
        { "GetEffectBonusMultiplier",                   &LuaSpellInfo::GetEffectBonusMultiplier },
        { "GetEffectMiscValue",                         &LuaSpellInfo::GetEffectMiscValue },
        { "GetEffectMiscValueB",                        &LuaSpellInfo::GetEffectMiscValueB },
        { "GetEffectChainTarget",                       &LuaSpellInfo::GetEffectChainTarget },
        { "GetEffectItemType",                          &LuaSpellInfo::GetEffectItemType },
        { "GetEffectTriggerSpell",                      &LuaSpellInfo::GetEffectTriggerSpell },
        { "GetEffectSpellClassMask",                    &LuaSpellInfo::GetEffectSpellClassMask },
        { "GetEffectCalcValue",                         &LuaSpellInfo::GetEffectCalcValue },
        { "GetEffectCalcRadius",                        &LuaSpellInfo::GetEffectCalcRadius },
        { "GetEffectHasRadius",                         &LuaSpellInfo::GetEffectHasRadius },
        { "GetEffectProvidedTargetMask",                &LuaSpellInfo::GetEffectProvidedTargetMask },
        { "GetEffectImplicitTargetType",                &LuaSpellInfo::GetEffectImplicitTargetType },
        { "GetEffectUsedTargetObjectType",              &LuaSpellInfo::GetEffectUsedTargetObjectType },
        { "EffectIsEffect",                             &LuaSpellInfo::EffectIsEffect },
        { "EffectIsEffectType",                         &LuaSpellInfo::EffectIsEffectType },
        { "EffectIsAura",                               &LuaSpellInfo::EffectIsAura },
        { "EffectIsAuraType",                           &LuaSpellInfo::EffectIsAuraType },
        { "EffectIsTargetingArea",                      &LuaSpellInfo::EffectIsTargetingArea },
        { "EffectIsAreaAuraEffect",                     &LuaSpellInfo::EffectIsAreaAuraEffect },
        { "EffectIsUnitOwnedAuraEffect",                &LuaSpellInfo::EffectIsUnitOwnedAuraEffect },
        { "GetEffectTargetATarget",                     &LuaSpellInfo::GetEffectTargetATarget },
        { "GetEffectTargetASelectionCategory",          &LuaSpellInfo::GetEffectTargetASelectionCategory },
        { "GetEffectTargetAReferenceType",              &LuaSpellInfo::GetEffectTargetAReferenceType },
        { "GetEffectTargetAObjectType",                 &LuaSpellInfo::GetEffectTargetAObjectType },
        { "GetEffectTargetACheckType",                  &LuaSpellInfo::GetEffectTargetACheckType },
        { "GetEffectTargetADirectionType",              &LuaSpellInfo::GetEffectTargetADirectionType },
        { "GetEffectTargetAIsArea",                     &LuaSpellInfo::GetEffectTargetAIsArea },
        { "GetEffectTargetADirectionAngle",             &LuaSpellInfo::GetEffectTargetADirectionAngle },
        { "GetEffectTargetBTarget",                     &LuaSpellInfo::GetEffectTargetBTarget },
        { "GetEffectTargetBSelectionCategory",          &LuaSpellInfo::GetEffectTargetBSelectionCategory },
        { "GetEffectTargetBReferenceType",              &LuaSpellInfo::GetEffectTargetBReferenceType },
        { "GetEffectTargetBObjectType",                 &LuaSpellInfo::GetEffectTargetBObjectType },
        { "GetEffectTargetBCheckType",                  &LuaSpellInfo::GetEffectTargetBCheckType },
        { "GetEffectTargetBDirectionType",              &LuaSpellInfo::GetEffectTargetBDirectionType },
        { "GetEffectTargetBIsArea",                     &LuaSpellInfo::GetEffectTargetBIsArea },
        { "GetEffectTargetBDirectionAngle",             &LuaSpellInfo::GetEffectTargetBDirectionAngle }
    };
}
#endif
