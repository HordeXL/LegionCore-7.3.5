/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef UNITMETHODS_H
#define UNITMETHODS_H

#include "ChatPackets.h"

/***
 * Inherits all methods from: [Object], [WorldObject]
 */
namespace LuaUnit
{
    /**
    * Sets a mechanic immunity for the [Unit].
    *
    * @table
    * @columns [Mechanic, ID, Comment]
    * @values [MECHANIC_NONE, 0,  ""]
    * @values [MECHANIC_CHARM, 1,  ""]
    * @values [MECHANIC_DISORIENTED, 2,  ""]
    * @values [MECHANIC_DISARM, 3,  ""]
    * @values [MECHANIC_DISTRACT, 4,  ""]
    * @values [MECHANIC_FEAR, 5,  ""]
    * @values [MECHANIC_GRIP, 6,  ""]
    * @values [MECHANIC_ROOT, 7,  ""]
    * @values [MECHANIC_SLOW_ATTACK, 8,  ""]
    * @values [MECHANIC_SILENCE, 9,  ""]
    * @values [MECHANIC_SLEEP, 10, ""]
    * @values [MECHANIC_SNARE, 11, ""]
    * @values [MECHANIC_STUN, 12, ""]
    * @values [MECHANIC_FREEZE, 13, ""]
    * @values [MECHANIC_KNOCKOUT, 14, ""]
    * @values [MECHANIC_BLEED, 15, ""]
    * @values [MECHANIC_BANDAGE, 16, ""]
    * @values [MECHANIC_POLYMORPH, 17, ""]
    * @values [MECHANIC_BANISH, 18, ""]
    * @values [MECHANIC_SHIELD, 19, ""]
    * @values [MECHANIC_SHACKLE, 20, ""]
    * @values [MECHANIC_MOUNT, 21, ""]
    * @values [MECHANIC_INFECTED, 22, ""]
    * @values [MECHANIC_TURN, 23, ""]
    * @values [MECHANIC_HORROR, 24, ""]
    * @values [MECHANIC_INVULNERABILITY, 25, ""]
    * @values [MECHANIC_INTERRUPT, 26, ""]
    * @values [MECHANIC_DAZE, 27, ""]
    * @values [MECHANIC_DISCOVERY, 28, ""]
    * @values [MECHANIC_IMMUNE_SHIELD, 29, "Divine (Blessing) Shield/Protection and Ice Block"]
    * @values [MECHANIC_SAPPED, 30, ""]
    * @values [MECHANIC_ENRAGED, 31, ""]
    *
    * @param int32 immunity : new value for the immunity mask
    * @param bool apply = true : if true, the immunity is applied, otherwise it is removed
    */
    int SetImmuneTo(Eluna* /*E*/)
{
    return 1;
}
    /**
     * The [Unit] tries to attack a given target
     *
     * @param [Unit] who : [Unit] to attack
     * @param bool meleeAttack = false: attack with melee or not
     * @return didAttack : if the [Unit] did not attack
     */
    int Attack(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] stops attacking its target
     *
     * @return bool isAttacking : if the [Unit] wasn't attacking already
     */
    int AttackStop(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is standing.
     *
     * @return bool isStanding
     */
    int IsStandState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is mounted.
     *
     * @return bool isMounted
     */
    int IsMounted(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is rooted.
     *
     * @return bool isRooted
     */
    int IsRooted(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] has full health.
     *
     * @return bool hasFullHealth
     */
    int IsFullHealth(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is in an accessible place for the given [Creature].
     *
     * @param [WorldObject] obj
     * @param float radius
     * @return bool isAccessible
     */
    int IsInAccessiblePlaceFor(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] an auctioneer.
     *
     * @return bool isAuctioneer
     */
    int IsAuctioneer(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] a guild master.
     *
     * @return bool isGuildMaster
     */
    int IsGuildMaster(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] an innkeeper.
     *
     * @return bool isInnkeeper
     */
    int IsInnkeeper(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] a trainer.
     *
     * @return bool isTrainer
     */
    int IsTrainer(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] is able to show a gossip window.
     *
     * @return bool hasGossip
     */
    int IsGossip(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is a taxi master.
     *
     * @return bool isTaxi
     */
    int IsTaxi(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is a spirit healer.
     *
     * @return bool isSpiritHealer
     */
    int IsSpiritHealer(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] is a spirit guide.
     *
     * @return bool isSpiritGuide
     */
    int IsSpiritGuide(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] is a tabard designer.
     *
     * @return bool isTabardDesigner
     */
    int IsTabardDesigner(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] provides services like vendor, training and auction.
     *
     * @return bool isTabardDesigner
     */
    int IsServiceProvider(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is a spirit guide or spirit healer.
     *
     * @return bool isSpiritService
     */
    int IsSpiritService(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is alive.
     *
     * @return bool isAlive
     */
    int IsAlive(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is dead.
     *
     * @return bool isDead
     */
    int IsDead(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is dying.
     *
     * @return bool isDying
     */
    int IsDying(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is a banker.
     *
     * @return bool isBanker
     */
    int IsBanker(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is a vendor.
     *
     * @return bool isVendor
     */
    int IsVendor(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] is a battle master.
     *
     * @return bool isBattleMaster
     */
    int IsBattleMaster(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] is a charmed.
     *
     * @return bool isCharmed
     */
    int IsCharmed(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is an armorer and can repair equipment.
     *
     * @return bool isArmorer
     */
    int IsArmorer(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Returns true if the [Unit] is attacking a player.
     *
     * @return bool isAttackingPlayer
     */
    int IsAttackingPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] flagged for PvP.
     *
     * @return bool isPvP
     */
    int IsPvPFlagged(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is on a [Vehicle].
     *
     * @return bool isOnVehicle
     */
    int IsOnVehicle(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is in combat.
     *
     * @return bool inCombat
     */
    int IsInCombat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is under water.
     *
     * @return bool underWater
     */
    int IsUnderWater(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is in water.
     *
     * @return bool inWater
     */
    int IsInWater(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is not moving.
     *
     * @return bool notMoving
     */
    int IsStopped(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is a quest giver.
     *
     * @return bool questGiver
     */
    int IsQuestGiver(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit]'s health is below the given percentage.
     *
     * @param int32 healthpct : percentage in integer from
     * @return bool isBelow
     */
    int HealthBelowPct(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit]'s health is above the given percentage.
     *
     * @param int32 healthpct : percentage in integer from
     * @return bool isAbove
     */
    int HealthAbovePct(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] has an aura from the given spell entry.
     *
     * @param uint32 spell : entry of the aura spell
     * @return bool hasAura
     */
    int HasAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is casting a spell
     *
     * @return bool isCasting
     */
    int IsCasting(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] has the given unit state.
     *
     * @param [UnitState] state : an unit state
     * @return bool hasState
     */
    int HasUnitState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is visible, false otherwise.
     *
     * @return bool isVisible
     */
    int IsVisible(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is moving, false otherwise.
     *
     * @return bool isMoving
     */
    int IsMoving(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Unit] is flying, false otherwise.
     *
     * @return bool isFlying
     */
    int IsFlying(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s owner.
     *
     * @return [Unit] owner
     */
    int GetOwner(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s owner's GUID.
     *
     * @return ObjectGuid ownerGUID
     */
    int GetOwnerGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s mount's modelID.
     *
     * @return uint32 mountId : displayId of the mount
     */
    int GetMountId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s creator's GUID.
     *
     * @return ObjectGuid creatorGUID
     */
    int GetCreatorGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s charmer's GUID.
     *
     * @return ObjectGuid charmerGUID
     */
    int GetCharmerGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the GUID of the [Unit]'s charmed entity.
     *
     * @return ObjectGuid charmedGUID
     */
    int GetCharmGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the GUID of the [Unit]'s pet.
     *
     * @return ObjectGuid petGUID
     */
    int GetPetGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the GUID of the [Unit]'s charmer or owner.
     *
     * @return ObjectGuid controllerGUID
     */
    int GetControllerGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the GUID of the [Unit]'s charmer or owner or its own GUID.
     *
     * @return ObjectGuid controllerGUID
     */
    int GetControllerGUIDS(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Unit]'s specified stat
     *
     * @param uint32 statType
     * @return float stat
     */
    int GetStat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s base spell power
     *
     * @param uint32 spellSchool
     * @return uint32 spellPower
     */
    int GetBaseSpellPower(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s current victim target or nil.
     *
     * @return [Unit] victim
     */
    int GetVictim(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the currently casted [Spell] of given type or nil.
     *
     * @table
     * @columns [CurrentSpellTypes, ID]
     * @values [CURRENT_MELEE_SPELL, 0]
     * @values [CURRENT_GENERIC_SPELL, 1]
     * @values [CURRENT_CHANNELED_SPELL, 2]
     * @values [CURRENT_AUTOREPEAT_SPELL, 3]
     *
     * @param [CurrentSpellTypes] spellType
     * @return [Spell] castedSpell
     */
    int GetCurrentSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s current stand state.
     *
     * @return uint8 standState
     */
    int GetStandState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s current display ID.
     *
     * @return uint32 displayId
     */
    int GetDisplayId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s native/original display ID.
     *
     * @return uint32 displayId
     */
    int GetNativeDisplayId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s level.
     *
     * @return uint8 level
     */
    int GetLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s health amount.
     *
     * @return uint32 healthAmount
     */
    int GetHealth(Eluna* /*E*/)
{
    return 1;
}

    Powers PowerSelectorHelper(Eluna* E, Unit* unit, int powerType = -1)
    {
        if (powerType == -1)
            return unit->getPowerType();

        if (powerType < 0 || powerType >= int(MAX_POWERS))
            luaL_argerror(E->L, 2, "valid Powers expected");

        return (Powers)powerType;
    }

    /**
     * Returns the [Unit]'s power amount for given power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return uint32 powerAmount
     */
    int GetPower(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s max power amount for given power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return uint32 maxPowerAmount
     */
    int GetMaxPower(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s power percent for given power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return float powerPct
     */
    int GetPowerPct(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s current power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @return [Powers] powerType
     */
    int GetPowerType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s max health.
     *
     * @return uint32 maxHealth
     */
    int GetMaxHealth(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s health percent.
     *
     * @return float healthPct
     */
    int GetHealthPct(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s gender.
     *
     * @return uint8 gender : 0 for male, 1 for female and 2 for none
     */
    int GetGender(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s race ID.
     *
     * @return [Races] race
     */
    int GetRace(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s class ID.
     *
     * @return [Classes] class
     */
    int GetClass(Eluna* /*E*/)
{
    return 1;
}

    /**
    * Returns the race mask
    *
    * @return uint32 racemask
    */
    int GetRaceMask(Eluna* /*E*/)
{
    return 1;
}

    /**
    * Returns the class mask
    *
    * @return uint32 classmask
    */
    int GetClassMask(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s creature type ID (enumerated in CreatureType.dbc).
     *
     * @table
     * @columns [CreatureType, ID]
     * @values [CREATURE_TYPE_BEAST, 1]
     * @values [CREATURE_TYPE_DRAGONKIN, 2]
     * @values [CREATURE_TYPE_DEMON, 3]
     * @values [CREATURE_TYPE_ELEMENTAL, 4]
     * @values [CREATURE_TYPE_GIANT, 5]
     * @values [CREATURE_TYPE_UNDEAD, 6]
     * @values [CREATURE_TYPE_HUMANOID, 7]
     * @values [CREATURE_TYPE_CRITTER, 8]
     * @values [CREATURE_TYPE_MECHANICAL, 9]
     * @values [CREATURE_TYPE_NOT_SPECIFIED, 10]
     * @values [CREATURE_TYPE_TOTEM, 11]
     * @values [CREATURE_TYPE_NON_COMBAT_PET, 12]
     * @values [CREATURE_TYPE_GAS_CLOUD, 13]
     *
     * @return [CreatureType] creatureType
     */
    int GetCreatureType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s class' name in given or default locale or nil.
     *
     * @table
     * @columns [Locale, ID]
     * @values [LOCALE_enUS, 0]
     * @values [LOCALE_koKR, 1]
     * @values [LOCALE_frFR, 2]
     * @values [LOCALE_deDE, 3]
     * @values [LOCALE_zhCN, 4]
     * @values [LOCALE_zhTW, 5]
     * @values [LOCALE_esES, 6]
     * @values [LOCALE_esMX, 7]
     * @values [LOCALE_ruRU, 8]
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE
     * @return string className : class name or nil
     */
    int GetClassAsString(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s race's name in given or default locale or nil.
     *
     * @table
     * @columns [Locale, ID]
     * @values [LOCALE_enUS, 0]
     * @values [LOCALE_koKR, 1]
     * @values [LOCALE_frFR, 2]
     * @values [LOCALE_deDE, 3]
     * @values [LOCALE_zhCN, 4]
     * @values [LOCALE_zhTW, 5]
     * @values [LOCALE_esES, 6]
     * @values [LOCALE_esMX, 7]
     * @values [LOCALE_ruRU, 8]
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE : locale to return the race name in
     * @return string raceName : race name or nil
     */
    int GetRaceAsString(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s faction ID.
     *
     * @return uint32 faction
     */
    int GetFaction(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Aura] of the given spell on the [Unit], or nil if not found.
     * Optionally filters by caster, item caster, and required effect mask.
     *
     * @param uint32 spellId : the spell ID to look up
     * @param ObjectGuid caster = ObjectGuid::Empty : the GUID of the caster to filter by, or empty for any caster
     * @param ObjectGuid itemCaster = ObjectGuid::Empty : the GUID of the item caster to filter by, or empty for any
     * @param uint8 reqEffMask = 0 : bitmask of effects that must be present, or 0 for any
     * @return [Aura] aura : the aura object or nil
     */
    int GetAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the owned [Aura] of the given spell on the [Unit], or nil if not found.
     * Similar to GetAura but searches owned auras and optionally excludes a specific [Aura].
     *
     * @param uint32 spellId : the spell ID to look up
     * @param ObjectGuid caster = ObjectGuid::Empty : the GUID of the caster to filter by, or empty for any caster
     * @param ObjectGuid itemCaster = ObjectGuid::Empty : the GUID of the item caster to filter by, or empty for any
     * @param uint8 reqEffMask = 0 : bitmask of effects that must be present, or 0 for any
     * @param [Aura] exceptAura = nil : an [Aura] to exclude from the search, or nil for none
     * @return [Aura] aura : the aura object or nil
     */
    int GetOwnedAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a table containing friendly [Unit]'s within given range of the [Unit].
     *
     * @param float range = 533.333 : search radius
     * @return table friendyUnits : table filled with friendly units
     */
    int GetFriendlyUnitsInRange(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a table containing unfriendly [Unit]'s within given range of the [Unit].
     *
     * @param float range = 533.333 : search radius
     * @return table unfriendyUnits : table filled with unfriendly units
     */
    int GetUnfriendlyUnitsInRange(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Unit]'s [Vehicle] methods
     *
     * @return [Vehicle] vehicle
     */
    int GetVehicleKit(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Unit]'s [Vehicle] object
     *
     * @return [Vehicle] vehicle
     */
    int GetVehicle(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the Critter Guid
     *
     * @return ObjectGuid critterGuid
     */
    int GetCritterGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit]'s speed of given [UnitMoveType].
     *
     * @table
     * @columns [UnitMoveType, ID]
     * @values [MOVE_WALK, 0]
     * @values [MOVE_RUN, 1]
     * @values [MOVE_RUN_BACK, 2]
     * @values [MOVE_SWIM, 3]
     * @values [MOVE_SWIM_BACK, 4]
     * @values [MOVE_TURN_RATE, 5]
     * @values [MOVE_FLIGHT, 6]
     * @values [MOVE_FLIGHT_BACK, 7]
     * @values [MOVE_PITCH_RATE, 8]
     *
     * @param [UnitMoveType] type
     * @return float speed
     */
    int GetSpeed(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the current movement type for this [Unit].
     *
     * @table
     * @columns [MovementGeneratorType, ID, Comment]
     * @values [IDLE_MOTION_TYPE, 0,  ""]
     * @values [RANDOM_MOTION_TYPE, 1,  ""]
     * @values [WAYPOINT_MOTION_TYPE, 2,  ""]
     * @values [MAX_DB_MOTION_TYPE, 3,  ""]
     * @values [ANIMAL_RANDOM_MOTION_TYPE, 3,  "TC"]
     * @values [CONFUSED_MOTION_TYPE, 4,  ""]
     * @values [CHASE_MOTION_TYPE, 5,  ""]
     * @values [HOME_MOTION_TYPE, 6,  ""]
     * @values [FLIGHT_MOTION_TYPE, 7,  ""]
     * @values [POINT_MOTION_TYPE, 8,  ""]
     * @values [FLEEING_MOTION_TYPE, 9,  ""]
     * @values [DISTRACT_MOTION_TYPE, 10, ""]
     * @values [ASSISTANCE_MOTION_TYPE, 11, ""]
     * @values [ASSISTANCE_DISTRACT_MOTION_TYPE, 12, ""]
     * @values [TIMED_FLEEING_MOTION_TYPE, 13, ""]
     * @values [FOLLOW_MOTION_TYPE, 14, ""]
     * @values [EFFECT_MOTION_TYPE, 15, "mangos"]
     * @values [ROTATE_MOTION_TYPE, 15, "TC"]
     * @values [EFFECT_MOTION_TYPE, 16, "TC"]
     * @values [NULL_MOTION_TYPE, 17, "TC"]
     *
     * @return [MovementGeneratorType] movementType
     */
    int GetMovementType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s owner GUID to given GUID.
     *
     * @param ObjectGuid guid : new owner guid
     */
    int SetOwnerGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s PvP on or off.
     *
     * @param bool apply = true : true if set on, false if off
     */
    int SetPvP(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s sheath state.
     *
     * @table
     * @columns [SheathState, ID, Comment]
     * @values [SHEATH_STATE_UNARMED, 0, "non prepared weapon"]
     * @values [SHEATH_STATE_MELEE, 1, "prepared melee weapon"]
     * @values [SHEATH_STATE_RANGED, 2, "prepared ranged weapon"]
     *
     * @param [SheathState] sheathState : valid SheathState
     */
    int SetSheath(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s name internally.
     *
     * @param string name : new name
     */
    int SetName(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s speed of given [UnitMoveType] to given rate.
     * If forced, packets sent to clients forcing the visual change.
     *
     * @table
     * @columns [UnitMoveType, ID]
     * @values [MOVE_WALK, 0]
     * @values [MOVE_RUN, 1]
     * @values [MOVE_RUN_BACK, 2]
     * @values [MOVE_SWIM, 3]
     * @values [MOVE_SWIM_BACK, 4]
     * @values [MOVE_TURN_RATE, 5]
     * @values [MOVE_FLIGHT, 6]
     * @values [MOVE_FLIGHT_BACK, 7]
     * @values [MOVE_PITCH_RATE, 8]
     *
     * @param [UnitMoveType] type
     * @param float rate
     * @param bool forced = false
     */
    int SetSpeed(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s faction.
     *
     * @param uint32 faction : new faction ID
     */
    int SetFaction(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s level.
     *
     * @param uint8 level : new level
     */
    int SetLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s health.
     *
     * @param uint32 health : new health
     */
    int SetHealth(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s max health.
     *
     * @param uint32 maxHealth : new max health
     */
    int SetMaxHealth(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s power amount for the given power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @param uint32 amount : new power amount
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     */
    int SetPower(Eluna* /*E*/)
{
    return 1;
}

    /**
     * modifies the [Unit]'s power amount for the given power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @param int32 amount : amount to modify
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     */
    int ModifyPower(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s max power amount for the given power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @param uint32 maxPower : new max power amount
     */
    int SetMaxPower(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s power type.
     *
     * @table
     * @columns [Powers, ID, Comment]
     * @values [POWER_MANA, 0, ""]
     * @values [POWER_RAGE, 1, ""]
     * @values [POWER_FOCUS, 2, ""]
     * @values [POWER_ENERGY, 3, ""]
     * @values [POWER_HAPPINESS, 4, ""]
     * @values [POWER_RUNE, 5, ""]
     * @values [POWER_RUNIC_POWER, 6, ""]
     * @values [MAX_POWERS, 7, ""]
     * @values [POWER_ALL, 127, "default for class?"]
     * @values [POWER_HEALTH, 0xFFFFFFFE, "-2 as signed value"]
     *
     * @param [Powers] type : a valid power type
     */
    int SetPowerType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s modelID.
     *
     * @param uint32 displayId
     */
    int SetDisplayId(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Sets the [Unit]'s native/default modelID.
     *
     * @param uint32 displayId
     */
    int SetNativeDisplayId(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Sets the [Unit]'s facing/orientation.
     *
     * @param uint32 orientation
     */
    int SetFacing(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit] to face the given [WorldObject]'s direction.
     *
     * @param [WorldObject] target
     */
    int SetFacingToObject(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets creator GUID
     *
     * @param ObjectGuid guid
     */
    int SetCreatorGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets pet GUID
     *
     * @param ObjectGuid guid
     */
    int SetPetGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggles (Sets) [Unit]'s water walking
     *
     * @param bool enable = true
     */
    int SetWaterWalk(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s stand state
     *
     * @param uint8 state : stand state
     */
    int SetStandState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit] in combat with the `enemy` [Unit].
     *
     * @param [Unit] enemy : the [Unit] to start combat with
     */
    int SetInCombatWith(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s FFA flag on or off.
     *
     * @param bool apply = true
     */
    int SetFFA(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]'s sanctuary flag on or off.
     *
     * @param bool apply = true
     */
    int SetSanctuary(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Unit]s critter GUID field.
     *
     * @param [ObjectGuid] guid
     */
    int SetCritterGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets whether or not the [Unit] is stunned.
     *
     * @param bool stunned = true
     */
    int SetStunned(Eluna* E, Unit* unit)
    {
        bool apply = E->CHECKVAL<bool>(2, true);
        unit->SetControlled(apply, UNIT_STATE_STUNNED);
        return 0;
    }

    /**
     * Roots the [Unit] to the ground, if 'false' specified, unroots the [Unit].
     *
     * @param bool apply = true
     */
    int SetRooted(Eluna* E, Unit* unit)
    {
        bool apply = E->CHECKVAL<bool>(2, true);

        unit->SetControlled(apply, UNIT_STATE_ROOT);
        return 0;
    }

    /**
     * Confuses the [Unit], if 'false' specified, the [Unit] is no longer confused.
     *
     * @param bool apply = true
     */
    int SetConfused(Eluna* E, Unit* unit)
    {
        bool apply = E->CHECKVAL<bool>(2, true);

        unit->SetControlled(apply, UNIT_STATE_CONFUSED);
        return 0;
    }

    /**
     * Fears the [Unit], if 'false' specified, the [Unit] is no longer feared.
     *
     * @param bool apply = true
     */
    int SetFeared(Eluna* E, Unit* unit)
    {
        bool apply = E->CHECKVAL<bool>(2, true);

        unit->SetControlled(apply, UNIT_STATE_FLEEING);
        return 0;
    }

    /**
     * Sets whether or not the [Unit] can fly.
     *
     * @param bool canFly = true
     */
    int SetCanFly(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets whether or not the [Unit] is visible.
     *
     * @param bool visible = true
     */
    int SetVisible(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Mounts the [Unit] on the given displayID/modelID.
     *
     * @param uint32 displayId
     */
    int Mount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Dismounts the [Unit].
     */
    int Dismount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] perform the given emote.
     *
     * @param uint32 emoteId
     */
    int PerformEmote(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] perform the given emote continuously.
     *
     * @param uint32 emoteId
     */
    int EmoteState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns calculated percentage from Health
     *
     * @return int32 percentage
     */
    int CountPctFromCurHealth(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns calculated percentage from Max Health
     *
     * @return int32 percentage
     */
    int CountPctFromMaxHealth(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends chat message to [Player]
     *
     * @param uint8 type : chat, whisper, etc
     * @param uint32 lang : language to speak
     * @param string msg
     * @param [Player] target
     */
    int SendChatMessageToPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Stops the [Unit]'s movement
     */
    int MoveStop(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit]'s movement expires and clears movement
     *
     * @param bool reset = true : cleans movement
     */
    int MoveExpire(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Clears the [Unit]'s movement
     *
     * @param bool reset = true : clean movement
     */
    int MoveClear(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will be idle
     */
    int MoveIdle(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will move at random
     *
     * @param float radius : limit on how far the [Unit] will move at random
     */
    int MoveRandom(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will move to its set home location
     */
    int MoveHome(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will follow the target
     *
     * @param [Unit] target : target to follow
     * @param float dist = 0 : distance to start following
     * @param float angle = 0
     */
    int MoveFollow(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will chase the target
     *
     * @param [Unit] target : target to chase
     * @param float dist = 0 : distance start chasing
     * @param float angle = 0
     */
    int MoveChase(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will move confused
     */
    int MoveConfused(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will flee
     *
     * @param [Unit] target
     * @param uint32 time = 0 : flee delay
     */
    int MoveFleeing(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will move to the coordinates
     *
     * @param uint32 id : unique waypoint Id
     * @param float x
     * @param float y
     * @param float z
     * @param bool genPath = true : if true, generates path
     */
    int MoveTo(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] jump to the coordinates
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float zSpeed : start velocity
     * @param float maxHeight : maximum height
     * @param uint32 id = 0 : unique movement Id
     */
    int MoveJump(Eluna* /*E*/)
{
    return 1;
}

    /**
     * The [Unit] will whisper the message to a [Player]
     *
     * @param string msg : message for the [Unit] to emote
     * @param uint32 lang : language for the [Unit] to speak
     * @param [Player] receiver : specific [Unit] to receive the message
     * @param bool bossWhisper = false : is a boss whisper
     */
    int SendUnitWhisper(Eluna* /*E*/)
{
    return 1;
}
    /**
     * The [Unit] will emote the message
     *
     * @param string msg : message for the [Unit] to emote
     * @param [Unit] receiver = nil : specific [Unit] to receive the message
     * @param bool bossEmote = false : is a boss emote
     */
    int SendUnitEmote(Eluna* /*E*/)
{
    return 1;
}
    /**
     * The [Unit] will say the message
     *
     * @param string msg : message for the [Unit] to say
     * @param uint32 language : language for the [Unit] to speak
     */
    int SendUnitSay(Eluna* /*E*/)
{
    return 1;
}
    /**
     * The [Unit] will yell the message
     *
     * @param string msg : message for the [Unit] to yell
     * @param uint32 language : language for the [Unit] to speak
     */
    int SendUnitYell(Eluna* /*E*/)
{
    return 1;
}
    /**
     * Unmorphs the [Unit] setting it's display ID back to the native display ID.
     */
    int DeMorph(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] cast the spell on the target.
     *
     * @param [Unit] target = nil : can be self or another unit
     * @param uint32 spell : entry of a spell
     * @param bool triggered = false : if true the spell is instant and has no cost
     */
    int CastSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Casts the [Spell] at target [Unit] with custom basepoints or casters.
     * See also [Unit:CastSpell].
     *
     * @param [Unit] target = nil
     * @param uint32 spell
     * @param bool triggered = false
     * @param int32 bp0 = nil : custom basepoints for [Spell] effect 1. If nil, no change is made
     * @param int32 bp1 = nil : custom basepoints for [Spell] effect 2. If nil, no change is made
     * @param int32 bp2 = nil : custom basepoints for [Spell] effect 3. If nil, no change is made
     * @param [Item] castItem = nil
     * @param ObjectGuid originalCaster = ObjectGuid()
     */
    int CastCustomSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] cast the spell to the given coordinates, used for area effect spells.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param uint32 spell : entry of a spell
     * @param bool triggered = true : if true the spell is instant and has no cost
     */
    int CastSpellAoF(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Clears the [Unit]'s combat
     */
    int ClearInCombat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Stops the [Unit]'s current spell cast
     *
     * @param uint32 spell = 0 : entry of a spell
     */
    int StopSpellCast(Eluna* E, Unit* unit)
    {
        uint32 spellId = E->CHECKVAL<uint32>(2, 0);
        unit->CastStop(spellId);
        return 0;
    }

    /**
     * Interrupts [Unit]'s spell state, casting, etc.
     *
     * if spell is not interruptible, it will return
     *
     * @param int32 spellType : type of spell to interrupt
     * @param bool delayed = true : skips if the spell is delayed
     */
    int InterruptSpell(Eluna* E, Unit* unit)
    {
        int spellType = E->CHECKVAL<int>(2);
        bool delayed = E->CHECKVAL<bool>(3, true);
        switch (spellType)
        {
            case 0:
                spellType = CURRENT_MELEE_SPELL;
                break;
            case 1:
                spellType = CURRENT_GENERIC_SPELL;
                break;
            case 2:
                spellType = CURRENT_CHANNELED_SPELL;
                break;
            case 3:
                spellType = CURRENT_AUTOREPEAT_SPELL;
                break;
            default:
                return luaL_argerror(E->L, 2, "valid CurrentSpellTypes expected");
        }

        unit->InterruptSpell((CurrentSpellTypes)spellType, delayed);
        return 0;
    }

    /**
     * Adds the [Aura] of the given spell entry on the given target from the [Unit].
     *
     * @param uint32 spell : entry of a spell
     * @param [Unit] target : aura will be applied on the target
     * @return [Aura] aura
     */
    int AddAura(Eluna* E, Unit* unit)
    {
        uint32 spell = E->CHECKVAL<uint32>(2);
        Unit* target = E->CHECKOBJ<Unit>(3);

#if ELUNA_EXPANSION < EXP_RETAIL
        SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(spell);
#else
        SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(spell);
#endif
        if (!spellEntry)
            return 1;

        E->Push(unit->AddAura(spell, target));
        return 1;
    }

    /**
     * Removes [Aura] of the given spell entry from the [Unit].
     *
     * @param uint32 spell : entry of a spell
     */
    int RemoveAura(Eluna* E, Unit* unit)
    {
        uint32 spellId = E->CHECKVAL<uint32>(2);
        unit->RemoveAurasDueToSpell(spellId);
        return 0;
    }

    /**
     * Removes all [Aura]'s from the [Unit].
     *
     *     Note: talents and racials are also auras, use with caution
     */
    int RemoveAllAuras(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes all positive visible [Aura]'s from the [Unit].
     */
    int RemoveArenaAuras(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds the given unit state for the [Unit].
     *
     * @param [UnitState] state
     */
    int AddUnitState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes the given unit state from the [Unit].
     *
     * @param [UnitState] state
     */
    int ClearUnitState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] teleport to given coordinates within same map.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float o : orientation
     */
    int NearTeleport(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] damage the target [Unit]
     *
     * @table
     * @columns [SpellSchools, ID]
     * @values [SPELL_SCHOOL_NORMAL, 0]
     * @values [SPELL_SCHOOL_HOLY, 1]
     * @values [SPELL_SCHOOL_FIRE, 2]
     * @values [SPELL_SCHOOL_NATURE, 3]
     * @values [SPELL_SCHOOL_FROST, 4]
     * @values [SPELL_SCHOOL_SHADOW, 5]
     * @values [SPELL_SCHOOL_ARCANE, 6]
     * @values [MAX_SPELL_SCHOOL, 7]
     *
     * @param [Unit] target : [Unit] to damage
     * @param uint32 damage : amount to damage
     * @param bool durabilityloss = true : if false, the damage does not do durability damage
     * @param [SpellSchools] school = MAX_SPELL_SCHOOL : school the damage is done in or MAX_SPELL_SCHOOL for direct damage
     * @param uint32 spell = 0 : spell that inflicts the damage
     */
    int DealDamage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] heal the target [Unit] with given spell
     *
     * @param [Unit] target : [Unit] to heal
     * @param uint32 spell : spell that causes the healing
     * @param uint32 amount : amount to heal
     * @param bool critical = false : if true, heal is logged as critical
     */
    int DealHeal(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Unit] kill the target [Unit]
     *
     * @param [Unit] target : [Unit] to kill
     * @param bool durLoss = true : when true, the target's items suffer durability loss
     */
    int Kill(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Restores the [Unit]s display ID to default
     */
    int RestoreDisplayId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Restores the [Unit]s faction to default
     */
    int RestoreFaction(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes all bind sight auras from the [Unit].
     */
    int RemoveBindSightAuras(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes all charm auras from the [Unit].
     */
    int RemoveCharmAuras(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Enables or disables whether or not the [Unit] can melee auto attack.
     *
     * @param bool disable = true : True to disable melee attack, false to enable
     */
    int DisableMelee(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Unit] can have stat modifiers applied.
     *
     * @return bool canModifyStats
     */
    int CanModifyStats(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Modifies a flat amount of a specific stat of the [Unit]
     *
     * @table
     * @columns [UnitModifierType, ID]
     * @values [BASE_VALUE, 0]
     * @values [TOTAL_VALUE, 1]
     *
     * @param uint32 statType : The stat to modify
     * @param [UnitModifierType] modType : The type of modifier to apply
     * @param float value : The value to apply to the stat
     * @param bool apply = true : True applies a positive modifier, false applies a negative
     */
    int AddFlatStatModifier(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Modifies a percentage amount of a specific stat of the [Unit]
     *
     * @table
     * @columns [UnitModifierType, ID]
     * @values [BASE_PCT, 0]
     * @values [TOTAL_PCT, 1]
     *
     * @param uint32 statType : The stat to modify
     * @param [UnitModifierType] modType : The type of modifier to apply
     * @param float value : The value to apply to the stat
     */
    int AddPctStatModifier(Eluna* /*E*/)
{
    return 1;
}

    ElunaRegister<Unit> UnitMethods[] =
    {
        // Getters
        { "GetLevel", &LuaUnit::GetLevel },
        { "GetHealth", &LuaUnit::GetHealth },
        { "GetDisplayId", &LuaUnit::GetDisplayId },
        { "GetNativeDisplayId", &LuaUnit::GetNativeDisplayId },
        { "GetPower", &LuaUnit::GetPower },
        { "GetMaxPower", &LuaUnit::GetMaxPower },
        { "GetPowerType", &LuaUnit::GetPowerType },
        { "GetMaxHealth", &LuaUnit::GetMaxHealth },
        { "GetHealthPct", &LuaUnit::GetHealthPct },
        { "GetPowerPct", &LuaUnit::GetPowerPct },
        { "GetGender", &LuaUnit::GetGender },
        { "GetRace", &LuaUnit::GetRace },
        { "GetClass", &LuaUnit::GetClass },
        { "GetRaceMask", &LuaUnit::GetRaceMask },
        { "GetClassMask", &LuaUnit::GetClassMask },
        { "GetRaceAsString", &LuaUnit::GetRaceAsString },
        { "GetClassAsString", &LuaUnit::GetClassAsString },
        { "GetAura", &LuaUnit::GetAura },
        { "GetOwnedAura", &LuaUnit::GetOwnedAura },
        { "GetFaction", &LuaUnit::GetFaction },
        { "GetCurrentSpell", &LuaUnit::GetCurrentSpell },
        { "GetCreatureType", &LuaUnit::GetCreatureType },
        { "GetMountId", &LuaUnit::GetMountId },
        { "GetOwner", &LuaUnit::GetOwner },
        { "GetFriendlyUnitsInRange", &LuaUnit::GetFriendlyUnitsInRange },
        { "GetUnfriendlyUnitsInRange", &LuaUnit::GetUnfriendlyUnitsInRange },
        { "GetOwnerGUID", &LuaUnit::GetOwnerGUID },
        { "GetCreatorGUID", &LuaUnit::GetCreatorGUID },
        { "GetMinionGUID", &LuaUnit::GetPetGUID },
        { "GetCharmerGUID", &LuaUnit::GetCharmerGUID },
        { "GetCharmGUID", &LuaUnit::GetCharmGUID },
        { "GetPetGUID", &LuaUnit::GetPetGUID },
        { "GetCritterGUID", &LuaUnit::GetCritterGUID },
        { "GetControllerGUID", &LuaUnit::GetControllerGUID },
        { "GetControllerGUIDS", &LuaUnit::GetControllerGUIDS },
        { "GetStandState", &LuaUnit::GetStandState },
        { "GetVictim", &LuaUnit::GetVictim },
        { "GetSpeed", &LuaUnit::GetSpeed },
        { "GetStat", &LuaUnit::GetStat },
        { "GetBaseSpellPower", &LuaUnit::GetBaseSpellPower },
        { "GetVehicleKit", &LuaUnit::GetVehicleKit },
        { "GetVehicle", &LuaUnit::GetVehicle },
        { "GetMovementType", &LuaUnit::GetMovementType },

        // Setters
        { "SetFaction", &LuaUnit::SetFaction },
        { "SetLevel", &LuaUnit::SetLevel },
        { "SetHealth", &LuaUnit::SetHealth },
        { "SetMaxHealth", &LuaUnit::SetMaxHealth },
        { "SetPower", &LuaUnit::SetPower },
        { "SetMaxPower", &LuaUnit::SetMaxPower },
        { "SetPowerType", &LuaUnit::SetPowerType },
        { "SetDisplayId", &LuaUnit::SetDisplayId },
        { "SetFacing", &LuaUnit::SetFacing },
        { "SetFacingToObject", &LuaUnit::SetFacingToObject },
        { "SetSpeed", &LuaUnit::SetSpeed },
        { "SetStunned", &LuaUnit::SetStunned },
        { "SetRooted", &LuaUnit::SetRooted },
        { "SetConfused", &LuaUnit::SetConfused },
        { "SetFeared", &LuaUnit::SetFeared },
        { "SetPvP", &LuaUnit::SetPvP },
#if ELUNA_EXPANSION < EXP_RETAIL
        { "SetNativeDisplayId", &LuaUnit::SetNativeDisplayId },
#else
        { "SetNativeDisplayId", METHOD_REG_NONE },
#endif
        { "SetFFA", &LuaUnit::SetFFA },
        { "SetSanctuary", &LuaUnit::SetSanctuary },
        { "SetCanFly", &LuaUnit::SetCanFly },
        { "SetVisible", &LuaUnit::SetVisible },
        { "SetOwnerGUID", &LuaUnit::SetOwnerGUID },
        { "SetName", &LuaUnit::SetName },
        { "SetSheath", &LuaUnit::SetSheath },
        { "SetCreatorGUID", &LuaUnit::SetCreatorGUID },
        { "SetMinionGUID", &LuaUnit::SetPetGUID },
        { "SetPetGUID", &LuaUnit::SetPetGUID },
        { "SetCritterGUID", &LuaUnit::SetCritterGUID },
        { "SetWaterWalk", &LuaUnit::SetWaterWalk },
        { "SetStandState", &LuaUnit::SetStandState },
        { "SetInCombatWith", &LuaUnit::SetInCombatWith },
        { "ModifyPower", &LuaUnit::ModifyPower },
        { "SetImmuneTo", &LuaUnit::SetImmuneTo },

        // Boolean
        { "IsAlive", &LuaUnit::IsAlive },
        { "IsDead", &LuaUnit::IsDead },
        { "IsDying", &LuaUnit::IsDying },
        { "IsPvPFlagged", &LuaUnit::IsPvPFlagged },
        { "IsInCombat", &LuaUnit::IsInCombat },
        { "IsBanker", &LuaUnit::IsBanker },
        { "IsBattleMaster", &LuaUnit::IsBattleMaster },
        { "IsCharmed", &LuaUnit::IsCharmed },
        { "IsArmorer", &LuaUnit::IsArmorer },
        { "IsAttackingPlayer", &LuaUnit::IsAttackingPlayer },
        { "IsInWater", &LuaUnit::IsInWater },
        { "IsUnderWater", &LuaUnit::IsUnderWater },
        { "IsAuctioneer", &LuaUnit::IsAuctioneer },
        { "IsGuildMaster", &LuaUnit::IsGuildMaster },
        { "IsInnkeeper", &LuaUnit::IsInnkeeper },
        { "IsTrainer", &LuaUnit::IsTrainer },
        { "IsGossip", &LuaUnit::IsGossip },
        { "IsTaxi", &LuaUnit::IsTaxi },
        { "IsSpiritHealer", &LuaUnit::IsSpiritHealer },
        { "IsSpiritGuide", &LuaUnit::IsSpiritGuide },
        { "IsTabardDesigner", &LuaUnit::IsTabardDesigner },
        { "IsServiceProvider", &LuaUnit::IsServiceProvider },
        { "IsSpiritService", &LuaUnit::IsSpiritService },
        { "HealthBelowPct", &LuaUnit::HealthBelowPct },
        { "HealthAbovePct", &LuaUnit::HealthAbovePct },
        { "IsMounted", &LuaUnit::IsMounted },
        { "AttackStop", &LuaUnit::AttackStop },
        { "Attack", &LuaUnit::Attack },
        { "IsVisible", &LuaUnit::IsVisible },
        { "IsMoving", &LuaUnit::IsMoving },
        { "IsFlying", &LuaUnit::IsFlying },
        { "IsStopped", &LuaUnit::IsStopped },
        { "HasUnitState", &LuaUnit::HasUnitState },
        { "IsQuestGiver", &LuaUnit::IsQuestGiver },
        { "IsInAccessiblePlaceFor", &LuaUnit::IsInAccessiblePlaceFor },
        { "IsVendor", &LuaUnit::IsVendor },
        { "IsRooted", &LuaUnit::IsRooted },
        { "IsFullHealth", &LuaUnit::IsFullHealth },
        { "HasAura", &LuaUnit::HasAura },
        { "IsCasting", &LuaUnit::IsCasting },
        { "IsStandState", &LuaUnit::IsStandState },
        { "IsOnVehicle", &LuaUnit::IsOnVehicle },
        { "CanModifyStats", &LuaUnit::CanModifyStats },

        // Other
        { "AddAura", &LuaUnit::AddAura },
        { "RemoveAura", &LuaUnit::RemoveAura },
        { "RemoveAllAuras", &LuaUnit::RemoveAllAuras },
        { "RemoveArenaAuras", &LuaUnit::RemoveArenaAuras },
        { "ClearInCombat", &LuaUnit::ClearInCombat },
        { "DeMorph", &LuaUnit::DeMorph },
        { "SendUnitWhisper", &LuaUnit::SendUnitWhisper },
        { "SendUnitEmote", &LuaUnit::SendUnitEmote },
        { "SendUnitSay", &LuaUnit::SendUnitSay },
        { "SendUnitYell", &LuaUnit::SendUnitYell },
        { "CastSpell", &LuaUnit::CastSpell },
        { "CastCustomSpell", &LuaUnit::CastCustomSpell },
        { "CastSpellAoF", &LuaUnit::CastSpellAoF },
        { "Kill", &LuaUnit::Kill },
        { "StopSpellCast", &LuaUnit::StopSpellCast },
        { "InterruptSpell", &LuaUnit::InterruptSpell },
        { "SendChatMessageToPlayer", &LuaUnit::SendChatMessageToPlayer },
        { "PerformEmote", &LuaUnit::PerformEmote },
        { "EmoteState", &LuaUnit::EmoteState },
        { "CountPctFromCurHealth", &LuaUnit::CountPctFromCurHealth },
        { "CountPctFromMaxHealth", &LuaUnit::CountPctFromMaxHealth },
        { "Dismount", &LuaUnit::Dismount },
        { "Mount", &LuaUnit::Mount },
        { "RestoreDisplayId", &LuaUnit::RestoreDisplayId },
        { "RestoreFaction", &LuaUnit::RestoreFaction },
        { "RemoveBindSightAuras", &LuaUnit::RemoveBindSightAuras },
        { "RemoveCharmAuras", &LuaUnit::RemoveCharmAuras },
        { "ClearUnitState", &LuaUnit::ClearUnitState },
        { "AddUnitState", &LuaUnit::AddUnitState },
        { "DisableMelee", &LuaUnit::DisableMelee },
        { "NearTeleport", &LuaUnit::NearTeleport },
        { "MoveIdle", &LuaUnit::MoveIdle },
        { "MoveRandom", &LuaUnit::MoveRandom },
        { "MoveHome", &LuaUnit::MoveHome },
        { "MoveFollow", &LuaUnit::MoveFollow },
        { "MoveChase", &LuaUnit::MoveChase },
        { "MoveConfused", &LuaUnit::MoveConfused },
        { "MoveFleeing", &LuaUnit::MoveFleeing },
        { "MoveTo", &LuaUnit::MoveTo },
        { "MoveJump", &LuaUnit::MoveJump },
        { "MoveStop", &LuaUnit::MoveStop },
        { "MoveExpire", &LuaUnit::MoveExpire },
        { "MoveClear", &LuaUnit::MoveClear },
        { "DealDamage", &LuaUnit::DealDamage },
        { "DealHeal", &LuaUnit::DealHeal },
        { "AddFlatStatModifier", &LuaUnit::AddFlatStatModifier },
        { "AddPctStatModifier", &LuaUnit::AddPctStatModifier },

        // Not implemented methods
        { "SummonGuardian", METHOD_REG_NONE } // not implemented
    };
};
#endif
