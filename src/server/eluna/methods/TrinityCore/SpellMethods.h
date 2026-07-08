/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef SPELLMETHODS_H
#define SPELLMETHODS_H

/***
 * An instance of a spell, created when the spell is cast by a [Unit].
 *
 * Inherits all methods from: none
 */
namespace LuaSpell
{
    /**
     * Returns `true` if the [Spell] is automatically repeating, `false` otherwise.
     *
     * @return bool isAutoRepeating
     */
    int IsAutoRepeat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Unit] that casted the [Spell].
     *
     * @return [Unit] caster
     */
    int GetCaster(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the cast time of the [Spell].
     *
     * @return int32 castTime
     */
    int GetCastTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the entry ID of the [Spell].
     *
     * @return uint32 entryId
     */
    int GetEntry(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the power cost of the [Spell].
     *
     * @return uint32 powerCost
     */
    int GetPowerCost(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell duration of the [Spell].
     *
     * @return int32 duration
     */
    int GetDuration(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target destination coordinates of the [Spell].
     *
     * @return float x : x coordinate of the [Spell]
     * @return float y : y coordinate of the [Spell]
     * @return float z : z coordinate of the [Spell]
     */
    int GetTargetDest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the target [Object] of the [Spell].
     *
     * The target can be any of the following [Object] types:
     * - [Player]
     * - [Creature]
     * - [GameObject]
     * - [Item]
     * - [Corpse]
     *
     * @return [Object] target
     */
    int GetTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Spell] to automatically repeat.
     *
     * @param bool repeat : set variable to 'true' for spell to automatically repeat
     */
    int SetAutoRepeat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Casts the [Spell].
     *
     * @param bool skipCheck = false : skips initial checks to see if the [Spell] can be casted or not, this is optional
     */
    int Cast(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Cancels the [Spell].
     */
    int Cancel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Finishes the [Spell].
     */
    int Finish(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [SpellInfo] of the spell that created this [Spell].
     *
     * @return [SpellInfo] spellInfo
     */
    int GetSpellInfo(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] is triggered, `false` otherwise.
     *
     * @return bool isTriggered
     */
    int IsTriggered(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] is ignoring cooldowns, `false` otherwise.
     *
     * @return bool isIgnoringCooldowns
     */
    int IsIgnoringCooldowns(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] proc is disabled, `false` otherwise.
     *
     * @return bool isProcDisabled
     */
    int IsProcDisabled(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] channel is active, `false` otherwise.
     *
     * @return bool isChannelActive
     */
    int IsChannelActive(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] is an auto action reset spell, `false` otherwise.
     *
     * @return bool isAutoActionResetSpell
     */
    int IsAutoActionResetSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] is positive, `false` otherwise.
     *
     * @return bool isPositive
     */
    int IsPositive(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] is deletable, `false` otherwise.
     *
     * @return bool isDeletable
     */
    int IsDeletable(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] is interruptable, `false` otherwise.
     *
     * @return bool isInterruptable
     */
    int IsInterruptable(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] needs to be sent to the client, `false` otherwise.
     *
     * @return bool isNeedSendToClient
     */
    int IsNeedSendToClient(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns `true` if the [Spell] was triggered by the given [SpellInfo], `false` otherwise.
     *
     * @param [SpellInfo] spellInfo : the aura spell info to check against
     * @return bool isTriggeredByAura
     */
    int IsTriggeredByAura(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the original caster [Unit] of the [Spell].
     *
     * @return [Unit] originalCaster
     */
    int GetOriginalCaster(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the current state of the [Spell].
     *
     * @return uint32 state
     */
    int GetState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the delay start time of the [Spell].
     *
     * @return uint64 delayStart
     */
    int GetDelayStart(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the delay moment of the [Spell].
     *
     * @return uint64 delayMoment
     */
    int GetDelayMoment(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the rune state of the [Spell].
     *
     * @return uint8 runeState
     */
    int GetRuneState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the number of unit targets for the given effect index of the [Spell].
     *
     * @param uint8 effIndex : the effect index to check
     * @return int32 count
     */
    int GetUnitTargetCountForEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the number of GameObject targets for the given effect index of the [Spell].
     *
     * @param uint8 effIndex : the effect index to check
     * @return int32 count
     */
    int GetGameObjectTargetCountForEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the number of item targets for the given effect index of the [Spell].
     *
     * @param uint8 effIndex : the effect index to check
     * @return int32 count
     */
    int GetItemTargetCountForEffect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Calculates the damage for the given effect index of the [Spell].
     *
     * @param uint8 effIndex : the effect index to calculate damage for
     * @return int32 damage
     */
    int CalculateDamage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the state of the [Spell].
     *
     * @param uint32 state : the state to set
     */
    int SetState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the delay start time of the [Spell].
     *
     * @param uint64 time : the delay start time to set
     */
    int SetDelayStart(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the rune state of the [Spell].
     *
     * @param uint8 value : the rune state to set
     */
    int SetRuneState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets whether the [Spell] is currently being executed.
     *
     * @param bool yes : set to 'true' if the spell is currently being executed
     */
    int SetExecutedCurrently(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets whether the [Spell] is referenced from the current spell.
     *
     * @param bool yes : set to 'true' if the spell is referenced from the current spell
     */
    int SetReferencedFromCurrent(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets a spell value modifier on the [Spell].
     *
     * @param uint8 mod : the [SpellValueMod] to set
     * @param int32 value : the value to set
     */
    int SetSpellValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Updates the [Spell]'s pointers. Must be used after time delays on non-triggered spell casts.
     *
     * @return bool success
     */
    int UpdatePointers(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Cleans up the target list of the [Spell].
     */
    int CleanupTargetList(Eluna* /*E*/)
{
    return 1;
}

    ElunaRegister<Spell> SpellMethods[] =
    {
        // Getters
        { "GetCaster",                          &LuaSpell::GetCaster },
        { "GetOriginalCaster",                  &LuaSpell::GetOriginalCaster },
        { "GetCastTime",                        &LuaSpell::GetCastTime },
        { "GetEntry",                           &LuaSpell::GetEntry },
        { "GetDuration",                        &LuaSpell::GetDuration },
        { "GetPowerCost",                       &LuaSpell::GetPowerCost },
        { "GetTargetDest",                      &LuaSpell::GetTargetDest },
        { "GetTarget",                          &LuaSpell::GetTarget },
        { "GetState",                           &LuaSpell::GetState },
        { "GetDelayStart",                      &LuaSpell::GetDelayStart },
        { "GetDelayMoment",                     &LuaSpell::GetDelayMoment },
        { "GetRuneState",                       &LuaSpell::GetRuneState },
        { "GetUnitTargetCountForEffect",        &LuaSpell::GetUnitTargetCountForEffect },
        { "GetGameObjectTargetCountForEffect",  &LuaSpell::GetGameObjectTargetCountForEffect },
        { "GetItemTargetCountForEffect",        &LuaSpell::GetItemTargetCountForEffect },
        { "GetSpellInfo",                       &LuaSpell::GetSpellInfo },
        { "CalculateDamage",                    &LuaSpell::CalculateDamage },
        // Setters
        { "SetAutoRepeat",                      &LuaSpell::SetAutoRepeat },
        { "SetSpellValue",                      &LuaSpell::SetSpellValue },
        { "SetState",                           &LuaSpell::SetState },
        { "SetDelayStart",                      &LuaSpell::SetDelayStart },
        { "SetRuneState",                       &LuaSpell::SetRuneState },
        { "SetExecutedCurrently",               &LuaSpell::SetExecutedCurrently },
        { "SetReferencedFromCurrent",           &LuaSpell::SetReferencedFromCurrent },
        // Booleans
        { "IsAutoRepeat",                       &LuaSpell::IsAutoRepeat },
        { "IsTriggered",                        &LuaSpell::IsTriggered },
        { "IsIgnoringCooldowns",                &LuaSpell::IsIgnoringCooldowns },
        { "IsProcDisabled",                     &LuaSpell::IsProcDisabled },
        { "IsChannelActive",                    &LuaSpell::IsChannelActive },
        { "IsAutoActionResetSpell",             &LuaSpell::IsAutoActionResetSpell },
        { "IsPositive",                         &LuaSpell::IsPositive },
        { "IsDeletable",                        &LuaSpell::IsDeletable },
        { "IsInterruptable",                    &LuaSpell::IsInterruptable },
        { "IsNeedSendToClient",                 &LuaSpell::IsNeedSendToClient },
        { "IsTriggeredByAura",                  &LuaSpell::IsTriggeredByAura },
        { "UpdatePointers",                     &LuaSpell::UpdatePointers },
        // Other
        { "Cancel",                             &LuaSpell::Cancel },
        { "Cast",                               &LuaSpell::Cast },
        { "Finish",                             &LuaSpell::Finish },
        { "CleanupTargetList",                  &LuaSpell::CleanupTargetList },
    };
};
#endif
