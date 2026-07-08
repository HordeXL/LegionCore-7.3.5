/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef PLAYERMETHODS_H
#define PLAYERMETHODS_H

#if ELUNA_EXPANSION == EXP_RETAIL
#include "ChatPackets.h"
#endif
#include "LuaValue.h"
#include "ChatPackets.h"
#include "NPCPackets.h"
#include "PartyPackets.h"
#include "Unit.h"
#include <boost/callable_traits/args.hpp>

/***
 * Inherits all methods from: [Object], [WorldObject], [Unit]
 */
namespace LuaPlayer
{
    /**
     * Returns 'true' if the [Player] can Titan Grip the specific [Item], 'false' otherwise.
     * @param [Item] item : an instance of an item
     * @return bool canTitanGrip
     */
    int CanTitanGrip(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has a talent by ID in specified spec, 'false' otherwise.
     *
     * @param uint32 spellId : talent spellId to check
     * @param uint8 spec : specified spec. 0 for primary, 1 for secondary.
     * @return bool hasTalent
     */
    int HasTalent(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has completed the specified achievement, 'false' otherwise.
     *
     * @param uint32 achievementId
     * @return bool hasAchieved
     */
    int HasAchieved(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has an active [Quest] by specific ID, 'false' otherwise.
     *
     * @param uint32 questId
     * @return bool hasQuest
     */
    int HasQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has a skill by specific ID, 'false' otherwise.
     *
     * @param uint32 skill
     * @return bool hasSkill
     */
    int HasSkill(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has a [Spell] by specific ID, 'false' otherwise.
     *
     * @param uint32 spellId
     * @return bool hasSpell
     */
    int HasSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if [Player] has specified login flag
     *
     * @param uint32 flag
     * @return bool hasLoginFlag
     */
    int HasAtLoginFlag(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if [Player] has [Quest] for [GameObject]
     *
     * @param int32 entry : entry of a [GameObject]
     * @return bool hasQuest
     */
    int HasQuestForGO(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has a title by specific ID, 'false' otherwise.
     *
     * @param uint32 titleId
     * @return bool hasTitle
     */
    int HasTitle(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has the given amount of item entry specified, 'false' otherwise.
     *
     * @param uint32 itemId : entry of the item
     * @param uint32 count = 1 : amount of items the player needs should have
     * @param bool check_bank = false : determines if the item can be in player bank
     * @return bool hasItem
     */
    int HasItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has a quest for the item entry specified, 'false' otherwise.
     *
     * @param uint32 entry : entry of the item
     * @return bool hasQuest
     */
    int HasQuestForItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] can use the item or item entry specified, 'false' otherwise.
     *
     * @proto canUse = (item)
     * @proto canUse = (entry)
     * @param [Item] item : an instance of an item
     * @param uint32 entry : entry of the item
     * @return bool canUse
     */
    int CanUseItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Spell] specified by ID is currently on cooldown for the [Player], 'false' otherwise.
     *
     * @param uint32 spellId
     * @return bool hasSpellCooldown
     */
    int HasSpellCooldown(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] can share [Quest] specified by ID, 'false' otherwise.
     *
     * @param uint32 entryId
     * @return bool hasSpellCooldown
     */
    int CanShareQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] can currently communicate through chat, 'false' otherwise.
     *
     * @return bool canSpeak
     */
    int CanSpeak(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has permission to uninvite others from the current group, 'false' otherwise.
     *
     * @return bool canUninviteFromGroup
     */
    int CanUninviteFromGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] can fly, 'false' otherwise.
     *
     * @return bool canFly
     */
    int CanFly(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently in water, 'false' otherwise.
     *
     * @return bool isInWater
     */
    int IsInWater(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently moving, 'false' otherwise.
     *
     * @return bool isMoving
     */
    int IsMoving(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently flying, 'false' otherwise.
     *
     * @return bool isFlying
     */
    int IsFlying(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is in a [Group], 'false' otherwise.
     *
     * @return bool isInGroup
     */
    int IsInGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is in a [Guild], 'false' otherwise.
     *
     * @return bool isInGuild
     */
    int IsInGuild(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is a Game Master, 'false' otherwise.
     *
     * Note: This is only true when GM tag is activated! For alternative see [Player:GetGMRank]
     *
     * @return bool isGM
     */
    int IsGM(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is in an arena team specified by type, 'false' otherwise.
     *
     * @param uint32 type
     * @return bool isInArenaTeam
     */
    int IsInArenaTeam(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is immune to everything.
     *
     * @return bool isImmune
     */
    int IsImmuneToDamage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] satisfies all requirements to complete the quest entry.
     *
     * @param uint32 entry
     * @return bool canComplete
     */
    int CanCompleteQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] satisfies all requirements to complete the repeatable quest entry.
     *
     * @param uint32 entry
     * @return bool canComplete
     */
    int CanCompleteRepeatableQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] satisfies all requirements to turn in the quest.
     *
     * @param uint32 entry
     * @return bool canReward
     */
    int CanRewardQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is a part of the Horde faction, 'false' otherwise.
     *
     * @return bool isHorde
     */
    int IsHorde(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is a part of the Alliance faction, 'false' otherwise.
     *
     * @return bool isAlliance
     */
    int IsAlliance(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is 'Do Not Disturb' flagged, 'false' otherwise.
     *
     * @return bool isDND
     */
    int IsDND(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is 'Away From Keyboard' flagged, 'false' otherwise.
     *
     * @return bool isAFK
     */
    int IsAFK(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently falling, 'false' otherwise.
     *
     * @return bool isFalling
     */
    int IsFalling(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player]s [Group] is visible for the other specific [Player].
     *
     * @param [Player] player
     * @return bool isGroupVisible
     */
    int IsGroupVisibleFor(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently in the same raid as another [Player] by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isInSameRaidWith
     */
    int IsInSameRaidWith(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently in the same [Group] as another [Player] by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isInSameGroupWith
     */
    int IsInSameGroupWith(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is eligible for Honor or XP gain by [Unit] specified, 'false' otherwise.
     *
     * @param [Unit] unit
     * @return bool isHonorOrXPTarget
     */
    int IsHonorOrXPTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] can see anoter [Player] specified by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isVisibleForPlayer
     */
    int IsVisibleForPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] has GM invisibility active
     *
     * @return bool isGMVisible
     */
    int IsGMVisible(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] has taxi cheat activated, 'false' otherwise.
     *
     * @return bool isTaxiCheater
     */
    int IsTaxiCheater(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] has the GM chat flag active
     *
     * @return bool isGMChatActive
     */
    int IsGMChat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is accepting whispers, 'false' otherwise.
     *
     * @return bool isAcceptingWhispers
     */
    int IsAcceptingWhispers(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently rested, 'false' otherwise.
     *
     * @return bool isRested
     */
    int IsRested(Eluna* E, Player* player)
    {
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is currently in a [BattleGround] queue, 'false' otherwise.
     *
     * @return bool inBattlegroundQueue
     */
    int InBattlegroundQueue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently in an arena, 'false' otherwise.
     *
     * @return bool inArena
     */
    int InArena(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is currently in a [BattleGround], 'false' otherwise.
     *
     * @return bool inBattleGround
     */
    int InBattleground(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] can block incomming attacks, 'false' otherwise.
     *
     * @return bool canBlock
     */
    int CanBlock(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] can parry incomming attacks, 'false' otherwise.
     *
     * @return bool canParry
     */
    int CanParry(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] has received the reward for a specific [Quest] ID
     *
     * @param uint32 questId
     * @return bool isQuestRewarded
     */
    int HasReceivedQuestReward(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] is currently flagged for outdoors PvP
     *
     * @return bool isPvPActive
     */
    int IsOutdoorPvPActive(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] is currently immune to environmental damage
     *
     * @return bool isImmuneToEnv
     */
    int IsImmuneToEnvironmentalDamage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] is currently in a random LFG dungeon
     *
     * @return bool isInRandomLFG
     */
    int InRandomLfgDungeon(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] is currently queued in LFG
     *
     * @return bool isUsingLFG
     */
    int IsUsingLfg(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] is never visible for other [Unit]s
     *
     * @return bool isNeverVisible
     */
    int IsNeverVisible(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] has any pending dungeon bind
     *
     * @return bool hasPendingBind
     */
    int HasPendingBind(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] is a recruiter
     *
     * @return bool isARecruiter
     */
    int IsARecruiter(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] has been recruited
     *
     * @return bool isRecruited
     */
    int IsRecruited(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns whether or not the [Player] recruited the other [Player]
     *
     * @param [Player] recruit
     * @return bool hasRecruited : returns 'true' if the [Player] recruited the other [Player], false otherwise
     */
    int HasRecruited(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the amount of available specs the [Player] currently has
     *
     * @return uint8 specCount
     */
    int GetSpecsCount(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns the [Player]s active spec ID
     *
     * @return uint32 specId
     */
    int GetActiveSpec(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the normal phase of the player instead of the actual phase possibly containing GM phase
     *
     * @return uint32 phasemask
     */
    int GetPhaseMaskForSpawn(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Returns the [Player]s current amount of Arena Points
     *
     * In retail Arena Points are now called Conquest.
     *
     * @return uint32 arenaPoints
     */
    int GetArenaPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current amount of Honor Points
     *
     * Honor Points are now a currency in retail
     *
     * @return uint32 honorPoints
     */
    int GetHonorPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current shield block value
     *
     * @return uint32 blockValue
     */
    int GetShieldBlockValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s cooldown delay by specified [Spell] ID
     *
     * @param uint32 spellId
     * @return uint32 spellCooldownDelay
     */
    int GetSpellCooldownDelay(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current latency in MS
     *
     * @return uint32 latency
     */
    int GetLatency(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the faction ID the [Player] is currently flagged as champion for
     *
     * @return uint32 championingFaction
     */
    int GetChampioningFaction(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Player]s original sub group
     *
     * @return uint8 subGroup
     */
    int GetOriginalSubGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Player]s original [Group] object
     *
     * @return [Group] group
     */
    int GetOriginalGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a random Raid Member [Player] object within radius specified of [Player]
     *
     * @param float radius
     * @return [Player] player
     */
    int GetNextRandomRaidMember(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Player]s current sub group
     *
     * @return uint8 subGroup
     */
    int GetSubGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Group] invitation
     *
     * @return [Group] group
     */
    int GetGroupInvite(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns rested experience bonus
     *
     * @param uint32 xp
     * @return uint32 xpBonus
     */
    int GetXPRestBonus(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current [BattleGround] type ID
     *
     * @return [BattleGroundTypeId] typeId
     */
    int GetBattlegroundTypeId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current [BattleGround] ID
     *
     * @return uint32 battleGroundId
     */
    int GetBattlegroundId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s reputation rank of faction specified
     *
     * @param uint32 faction
     * @return [ReputationRank] rank
     */
    int GetReputationRank(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current level of intoxication
     *
     * @return uint16 drunkValue
     */
    int GetDrunkValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns skill temporary bonus value
     *
     * @param uint32 skill
     * @return int16 bonusVal
     */
    int GetSkillTempBonusValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns skill permanent bonus value
     *
     * @param uint32 skill
     * @return int16 bonusVal
     */
    int GetSkillPermBonusValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns skill value without bonus'
     *
     * @param uint32 skill
     * @return uint16 pureVal
     */
    int GetPureSkillValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns base skill value
     *
     * @param uint32 skill
     * @return uint16 baseVal
     */
    int GetBaseSkillValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns skill value
     *
     * @param uint32 skill
     * @return uint16 val
     */
    int GetSkillValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns max value of specified skill without bonus'
     *
     * @param uint32 skill
     * @return uint16 pureVal
     */
    int GetPureMaxSkillValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns max value of specified skill
     *
     * @param uint32 skill
     * @return uint16 val
     */
    int GetMaxSkillValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns mana bonus from amount of intellect
     *
     * @return float bonus
     */
    int GetManaBonusFromIntellect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns health bonus from amount of stamina
     *
     * @return float bonus
     */
    int GetHealthBonusFromStamina(Eluna* E, Player* player)
    {
        E->Push(player->GetHealthBonusFromStamina());
        return 1;
    }

    /**
     * Returns raid or dungeon difficulty
     *
     * @param bool isRaid = true : argument is TrinityCore only
     * @return int32 difficulty
     */
    int GetDifficulty(Eluna* E, Player* player)
    {
        [[maybe_unused]] bool isRaid = E->CHECKVAL<bool>(2, true);

#if ELUNA_EXPANSION < EXP_RETAIL
        E->Push(player->GetDifficulty(isRaid));
#else
        E->Push(player->GetMap()->GetDifficultyID());
#endif
        return 1;
    }

    /**
     * Returns the [Player]s current guild rank
     *
     * @return uint32 guildRank
     */
    int GetGuildRank(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the [Player]s free talent point amount
     *
     * @return uint32 freeTalentPointAmt
     */
    int GetFreeTalentPoints(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Returns the name of the [Player]s current [Guild]
     *
     * @return string guildName
     */
    int GetGuildName(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the amount of reputation the [Player] has with the faction specified
     *
     * @param uint32 faction
     * @return int32 reputationAmt
     */
    int GetReputation(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Unit] target combo points are on
     *
     * @return [Unit] target
     */
    int GetComboTarget(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Player]'s combo points
     *
     * @return uint8 comboPoints
     */
    int GetComboPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the amount of time the [Player] has spent ingame
     *
     * @return uint32 inGameTime
     */
    int GetInGameTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the status of the [Player]s [Quest] specified by entry ID
     *
     * @param uint32 questId
     * @return [QuestStatus] questStatus
     */
    int GetQuestStatus(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player]s [Quest] specified by entry ID has been rewarded, 'false' otherwise.
     *
     * @param uint32 questId
     * @return bool questRewardStatus
     */
    int GetQuestRewardStatus(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Quest] required [Creature] or [GameObject] count
     *
     * @param uint32 quest : entry of a quest
     * @param int32 entry : entry of required [Creature]
     * @return uint16 count
     */
    int GetReqKillOrCastCurrentCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the quest level of the [Player]s [Quest] specified by object
     *
     * @param uint32 questId
     * @return [QuestStatus] questRewardStatus
     */
    int GetQuestLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a [Player]s [Item] object by gear slot specified
     *
     * @param uint8 slot
     * @return [Item] item
     */
    int GetEquippedItemBySlot(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current resting bonus
     *
     * @return float restBonus
     */
    int GetRestBonus(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns active GM chat tag
     *
     * @return uint8 tag
     */
    int GetChatTag(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns an item in given bag on given slot.
     *
     * <pre>
     * Possible and most commonly used combinations:
     *
     * bag = 255
     * slots 0-18 equipment
     * slots 19-22 equipped bag slots
     * slots 23-38 backpack
     * slots 39-66 bank main slots
     * slots 67-74 bank bag slots
     * slots 86-117 keyring
     *
     * bag = 19-22
     * slots 0-35 for equipped bags
     *
     * bag = 67-74
     * slots 0-35 for bank bags
     * </pre>
     *
     * @param uint8 bag : the bag the [Item] is in, you can get this with [Item:GetBagSlot]
     * @param uint8 slot : the slot the [Item] is in within the bag, you can get this with [Item:GetSlot]
     * @return [Item] item : [Item] or nil
     */
    int GetItemByPos(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns an [Item] from the player by guid.
     *
     * The item can be equipped, in bags or in bank.
     *
     * @param ObjectGuid guid : an item guid
     * @return [Item] item
     */
    int GetItemByGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a mailed [Item] by guid.
     *
     * @param ObjectGuid guid : an item guid
     * @return [Item] item
     */
    int GetMailItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns an [Item] from the player by entry.
     *
     * The item can be equipped, in bags or in bank.
     *
     * @param uint32 entryId
     * @return [Item] item
     */
    int GetItemByEntry(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the database textID of the [WorldObject]'s gossip header text for the [Player]
     *
     * @param [WorldObject] object
     * @return uint32 textId : key to npc_text database table
     */
    int GetGossipTextId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s currently selected [Unit] object
     *
     * @return [Unit] unit
     */
    int GetSelection(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s GM Rank
     *
     * @return [AccountTypes] gmRank
     */
    int GetGMRank(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s amount of money in copper
     *
     * @return uint32 coinage
     */
    int GetCoinage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current [Guild] ID
     *
     * @return uint32 guildId
     */
    int GetGuildId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s [TeamId]
     *
     * @return [TeamId] teamId
     */
    int GetTeam(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns amount of the specified [Item] the [Player] has.
     *
     * @param uint32 entry : entry of the item
     * @param bool checkinBank = false : also counts the items in player's bank if true
     * @return uint32 itemamount
     */
    int GetItemCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s lifetime Honorable Kills
     *
     * @return uint32 lifeTimeKils
     */
    int GetLifetimeKills(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s IP address
     *
     * @return string ip
     */
    int GetPlayerIP(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s time played at current level
     *
     * @return uint32 currLevelPlayTime
     */
    int GetLevelPlayedTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s total time played
     *
     * @return uint32 totalPlayTime
     */
    int GetTotalPlayedTime(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s [Guild] object
     *
     * @return [Guild] guild
     */
    int GetGuild(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s [Group] object
     *
     * @return [Group] group
     */
    int GetGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s account ID
     *
     * @return uint32 accountId
     */
    int GetAccountId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s account name
     *
     * @return string accountName
     */
    int GetAccountName(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s [Corpse] object
     *
     * @return [Corpse] corpse
     */
    int GetCorpse(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s database locale index
     *
     * @return int localeIndex
     */
    int GetDbLocaleIndex(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s game client locale
     *
     * @return [LocaleConstant] locale
     */
    int GetDbcLocale(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s recruit-a-friend recruiter account ID
     *
     * @return uint32 recruiterId
     */
    int GetRecruiterId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s selected [Player] or nil.
     *
     * @return [Player] selection
     */
    int GetSelectedPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s selected [Unit].
     *
     * @return [Unit] selection
     */
    int GetSelectedUnit(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the closest [GameObject] to the [Player].
     *
     * @return [GameObject] gameobject
     */
    int GetNearbyGameObject(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the amount of mails in the [Player]s mailbox
     *
     * @return uint32 count
     */
    int GetMailCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s current experience points
     *
     * @return uint32 xp
     */
    int GetXP(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s required experience points for next level
     *
     * @return uint32 xp
     */
    int GetXPForNextLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Locks the player controls and disallows all movement and casting.
     *
     * @param bool apply = true : lock if true and unlock if false
     */
    int SetPlayerLock(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s login flag to the flag specified
     *
     * @param uint32 flag
     */
    int SetAtLoginFlag(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s sheathe state to the state specified
     *
     * @param uint32 sheatheState
     */
    int SetSheath(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s intoxication level to the level specified
     *
     * @param uint8 drunkValue
     */
    int SetDrunkValue(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s faction standing to that of the race specified
     *
     * @param uint8 raceId
     */
    int SetFactionForRace(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets (increases) skill of the [Player]
     *
     * @param uint16 id
     * @param uint16 step
     * @param uint16 currVal
     * @param uint16 maxVal
     */
    int SetSkill(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s guild rank to the rank specified
     *
     * @param uint8 rank
     */
    int SetGuildRank(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Sets the [Player]s free talent points to the amount specified for the current spec
     *
     * @param uint32 talentPointAmt
     */
    int SetFreeTalentPoints(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Sets the [Player]s reputation amount for the faction specified
     *
     * @param uint32 factionId
     * @param int32 reputationValue
     */
    int SetReputation(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets [Quest] state
     *
     * @param uint32 entry : entry of a quest
     * @param uint32 status
     */
    int SetQuestStatus(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s rest bonus to the amount specified
     *
     * @param float restBonus
     */
    int SetRestBonus(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggles whether the [Player] accepts whispers or not
     *
     * @param bool acceptWhispers = true
     */
    int SetAcceptWhispers(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggles PvP Death
     *
     * @param bool on = true
     */
    int SetPvPDeath(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggles whether the [Player] has GM visibility on or off
     *
     * @param bool gmVisible = true
     */
    int SetGMVisible(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggles whether the [Player] has taxi cheat enabled or not
     *
     * @param bool taxiCheat = true
     */
    int SetTaxiCheat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggle Blizz (GM) tag
     *
     * @param bool on = true
     */
    int SetGMChat(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggles the [Player]s GM mode on or off
     *
     * @param bool setGmMode = true
     */
    int SetGameMaster(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s gender to gender specified
     *
     * @table
     * @columns [Gender, ID]
     * @values [GENDER_MALE, 0]
     * @values [GENDER_FEMALE, 1]
     *
     * @param [Gender] gender
     */
    int SetGender(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s Arena Points to the amount specified
     *
     * In retail Area Points are now called Conquest
     *
     * @param uint32 arenaPoints
     */
    int SetArenaPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s Honor Points to the amount specified
     *
     * @param uint32 honorPoints
     */
    int SetHonorPoints(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_CATA
    /**
     * Sets the [Player]s amount of Lifetime Honorable Kills to the value specified
     *
     * @param uint32 honorableKills
     */
    int SetLifetimeKills(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Sets the [Player]s amount of money to copper specified
     *
     * @param uint32 copperAmt
     */
    int SetCoinage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s home location to the location specified
     *
     * @param float x : X Coordinate
     * @param float y : Y Coordinate
     * @param float z : Z Coordinate
     * @param uint32 mapId : Map ID
     * @param uint32 areaId : Area ID
     */
    int SetBindPoint(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds the specified title to the [Player]s list of known titles
     *
     * @param uint32 titleId
     */
    int SetKnownTitle(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds the specified achievement to the [Player]s
     *
     * @param uint32 achievementid
     */
    int SetAchievement(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggle the [Player]s FFA flag
     *
     * @param bool applyFFA = true
     */
    int SetFFA(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player]s movement to the provided movement type
     *
     * @table
     * @columns [movementType, ID]
     * @values [MOVE_ROOT, 1]
     * @values [MOVE_UNROOT, 2]
     * @values [MOVE_WATER_WALK, 3]
     * @values [MOVE_LAND_WALK, 4]
     *
     * @param int32 movementType
     */
    int SetMovement(Eluna* /*E*/)
{
    return 1;
}
#if ELUNA_EXPANSION < EXP_CATA
    /**
     * Resets the [Player]s pets talent points
     */
    int ResetPetTalents(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Reset the [Player]s completed achievements
     */
    int ResetAchievements(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Shows the mailbox window to the player from specified guid.
     *
     * @param ObjectGuid guid = playerguid : guid of the mailbox window sender
     */
    int SendShowMailBox(Eluna* E, Player* player)
    {
        ObjectGuid guid = E->CHECKVAL<ObjectGuid>(2, player->GET_GUID());

        player->GetSession()->SendShowMailBox(guid);
        return 0;
    }

    /**
     * Adds or detracts from the [Player]s current Arena Points
     *
     * In retail Area Points are now called Conquest. Will use this function for both
     *
     * @param int32 amount
     */
    int ModifyArenaPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds or detracts from the [Player]s current Honor Points
     *
     * In retail Honor Points are now a currency.
     *
     * @param int32 amount
     */
    int ModifyHonorPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Saves the [Player] to the database
     */
    int SaveToDB(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a summon request to the player from the given summoner
     *
     * @param [Unit] summoner
     */
    int SummonPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Mutes the [Player] for the amount of seconds specified
     *
     * @param uint32 muteTime
     */
    int Mute(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Rewards the given quest entry for the [Player] if he has completed it.
     *
     * @param uint32 entry : quest entry
     */
    int RewardQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends an auction house window to the [Player] from the [Unit] specified
     *
     * @param [Unit] sender
     */
    int SendAuctionMenu(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a flightmaster window to the [Player] from the [Creature] specified
     *
     * @param [Creature] sender
     */
    int SendTaxiMenu(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a spirit resurrection request to the [Player]
     */
    int SendSpiritResurrect(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a tabard vendor window to the [Player] from the [WorldObject] specified
     *
     * @param [WorldObject] sender
     */
    int SendTabardVendorActivate(Eluna* /*E*/)
{
    return 1;
}
    int SendShowBank(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a vendor window to the [Player] from the [WorldObject] specified.
     *
     * @param [WorldObject] sender
     */
    int SendListInventory(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a trainer window to the [Player] from the [Creature] specified
     *
     * @param [Creature] sender
     */
    int SendTrainerList(Eluna* /*E*/)
{
    return 1;
}
    int SendGuildInvite(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends an update for the world state to the [Player]
     *
     * @param uint32 field
     * @param uint32 value
     */
    int SendUpdateWorldState(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Forces the [Player] to log out
     *
     * @param bool saveToDb = true
     */
    int LogoutPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Forcefully removes the [Player] from a [BattleGround] raid group
     */
    int RemoveFromBattlegroundRaid(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Unbinds the [Player] from his instances except the one he currently is in.
     *
     * Difficulty is not used on classic.
     *
     * @param uint32 map = true
     * @param uint32 difficulty = 0
     */
    int UnbindInstance(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Unbinds the [Player] from his instances except the one he currently is in.
     */
    int UnbindAllInstances(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Forces the [Player] to leave a [BattleGround]
     *
     * @param bool teleToEntry = true
     */
    int LeaveBattleground(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Repairs [Item] at specified position.
     *
     * @param uint16 position
     * @param bool cost = true
     * @param float discountMod = 1.0
     */
    int DurabilityRepair(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Repairs all [Item]s.
     *
     * @param bool takeCost = true
     * @param float discountMod = 1.0
     * @param bool guidBank = false
     */
    int DurabilityRepairAll(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets durability loss for an [Item] in the specified slot
     *
     * @param int32 slot
     */
    int DurabilityPointLossForEquipSlot(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets durability loss on all [Item]s equipped
     *
     * If inventory is true, sets durability loss for [Item]s in bags
     *
     * @param int32 points
     * @param bool inventory = true
     */
    int DurabilityPointsLossAll(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets durability loss for the specified [Item]
     *
     * @param [Item] item
     * @param int32 points
     */
    int DurabilityPointsLoss(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Damages specified [Item]
     *
     * @param [Item] item
     * @param double percent
     */
    int DurabilityLoss(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Damages all [Item]s equipped. If inventory is true, damages [Item]s in bags
     *
     * @param double percent
     * @param bool inventory = true
     */
    int DurabilityLossAll(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Kills the [Player]
     */
    int KillPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Forces the [Player] to leave a [Group]
     */
    int RemoveFromGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]s accumulated talent reset cost
     *
     * @return uint32 resetCost
     */
    int ResetTalentsCost(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Resets the [Player]s talents
     *
     * @param bool noCost = true
     */
    int ResetTalents(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes the [Spell] from the [Player]
     *
     * @param uint32 entry : entry of a [Spell]
     */
    int RemoveSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Clears the [Player]s combo points
     */
    int ClearComboPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds combo points to the [Player]
     *
     * @param [Unit] target
     * @param int8 count
     */
    int AddComboPoints(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Gives [Quest] monster talked to credit
     *
     * @param uint32 entry : entry of a [Creature]
     * @param [Creature] creature
     */
    int TalkedToCreature(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Gives [Quest] monster killed credit
     *
     * @param uint32 entry : entry of a [Creature]
     */
    int KilledMonsterCredit(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Completes a [Quest] if in a [Group]
     *
     * @param uint32 quest : entry of a quest
     * @param [WorldObject] obj
     */
    int GroupEventHappens(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Completes the [Quest] if a [Quest] area is explored, or completes the [Quest]
     *
     * @param uint32 quest : entry of a [Quest]
     */
    int AreaExploredOrEventHappens(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the given [Quest] entry failed for the [Player].
     *
     * @param uint32 entry : entry of a [Quest]
     */
    int FailQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the given quest entry incomplete for the [Player].
     *
     * @param uint32 entry : quest entry
     */
    int IncompleteQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Completes the given quest entry for the [Player] and tries to satisfy all quest requirements.
     *
     * The player should have the quest to complete it.
     *
     * @param uint32 entry : quest entry
     */
    int CompleteQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Tries to add the given quest entry for the [Player].
     *
     * @param uint32 entry : quest entry
     */
    int AddQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes the given quest entry from the [Player].
     *
     * @param uint32 entry : quest entry
     */
    int RemoveQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends whisper text from the [Player]
     *
     * @param string text
     * @param uint32 lang : language the [Player] will speak
     * @param [Player] receiver : is the [Player] that will receive the whisper, if TrinityCore
     * @param ObjectGuid guid : is the GUID of a [Player] that will receive the whisper, not TrinityCore
     */
    int Whisper(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a text emote from the [Player]
     *
     * @param string emoteText
     */
    int TextEmote(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends yell text from the [Player]
     *
     * @param string text : text for the [Player] to yells
     * @param uint32 lang : language the [Player] will speak
     */
    int Yell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends say text from the [Player]
     *
     * @param string text : text for the [Player] to say
     * @param uint32 lang : language the [Player] will speak
     */
    int Say(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Gives the [Player] experience
     *
     * @param uint32 xp : experience to give
     * @param [Unit] victim = nil
     */
    int GiveXP(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggle the [Player]s 'Do Not Disturb' flag
     */
    int ToggleDND(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Toggle the [Player]s 'Away From Keyboard' flag
     */
    int ToggleAFK(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Equips the given item or item entry to the given slot. Returns the equipped item or nil.
     *
     * @table
     * @columns [EquipSlot, ID]
     * @values [EQUIPMENT_SLOT_HEAD, 0]
     * @values [EQUIPMENT_SLOT_NECK, 1]
     * @values [EQUIPMENT_SLOT_SHOULDERS, 2]
     * @values [EQUIPMENT_SLOT_BODY, 3]
     * @values [EQUIPMENT_SLOT_CHEST, 4]
     * @values [EQUIPMENT_SLOT_WAIST, 5]
     * @values [EQUIPMENT_SLOT_LEGS, 6]
     * @values [EQUIPMENT_SLOT_FEET, 7]
     * @values [EQUIPMENT_SLOT_WRISTS, 8]
     * @values [EQUIPMENT_SLOT_HANDS, 9]
     * @values [EQUIPMENT_SLOT_FINGER1, 10]
     * @values [EQUIPMENT_SLOT_FINGER2, 11]
     * @values [EQUIPMENT_SLOT_TRINKET1, 12]
     * @values [EQUIPMENT_SLOT_TRINKET2, 13]
     * @values [EQUIPMENT_SLOT_BACK, 14]
     * @values [EQUIPMENT_SLOT_MAINHAND, 15]
     * @values [EQUIPMENT_SLOT_OFFHAND, 16]
     * @values [EQUIPMENT_SLOT_RANGED, 17]
     * @values [EQUIPMENT_SLOT_TABARD, 18]
     *
     * @table
     * @columns [BagSlot, ID]
     * @values [INVENTORY_SLOT_BAG_START, 19]
     * @values [INVENTORY_SLOT_BAG_END, 23]
     *
     * @proto equippedItem = (item, slot)
     * @proto equippedItem = (entry, slot)
     * @param [Item] item : item to equip
     * @param uint32 entry : entry of the item to equip
     * @param uint32 slot : equipment slot to equip the item to The slot can be [EquipmentSlots] or [InventorySlots]
     * @return [Item] equippedItem : item or nil if equipping failed
     */
    int EquipItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the player can equip the given [Item] or item entry to the given slot, false otherwise.
     *
     * @proto canEquip = (item, slot)
     * @proto canEquip = (entry, slot)
     * @param [Item] item : item to equip
     * @param uint32 entry : entry of the item to equip
     * @param uint32 slot : equipment slot to test
     * @return bool canEquip
     */
    int CanEquipItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes a title by ID from the [Player]s list of known titles
     *
     * @param uint32 titleId
     */
    int UnsetKnownTitle(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Advances all of the [Player]s weapon skills to the maximum amount available
     */
    int AdvanceSkillsToMax(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Advances all of the [Player]s skills to the amount specified
     *
     * @param uint32 skillStep
     */
    int AdvanceAllSkills(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Advances a [Player]s specific skill to the amount specified
     *
     * @param uint32 skillId
     * @param uint32 skillStep
     */
    int AdvanceSkill(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Teleports a [Player] to the location specified
     *
     * @param uint32 mappId
     * @param float xCoord
     * @param float yCoord
     * @param float zCoord
     * @param float orientation
     */
    int Teleport(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds or detracts from the [Player]s current lifetime kill count
     *
     * @param int32 kills : Positive number to add, negative number to detract
     */
#if ELUNA_EXPANSION < EXP_RETAIL
    int AddLifetimeKills(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Adds the given amount of the specified item entry to the player.
     *
     * @param uint32 entry : entry of the item to add
     * @param uint32 itemCount = 1 : amount of the item to add
     * @return [Item] item : the item that was added or nil
     */
    int AddItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes the given amount of the specified [Item] from the player.
     *
     * @proto (item, itemCount)
     * @proto (entry, itemCount)
     * @param [Item] item : item to remove
     * @param uint32 entry : entry of the item to remove
     * @param uint32 itemCount = 1 : amount of the item to remove
     */
    int RemoveItem(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Removes specified amount of lifetime kills
     *
     * @param uint32 val : kills to remove
     */
    int RemoveLifetimeKills(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Resets cooldown of the specified spell
     *
     * @param uint32 spellId
     * @param bool update = true
     */
    int ResetSpellCooldown(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Resets cooldown of the specified category
     *
     * @param uint32 category
     * @param bool update = true
     */
    int ResetTypeCooldowns(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Resets all of the [Player]'s cooldowns
     */
    int ResetAllCooldowns(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a Broadcast Message to the [Player]
     *
     * @param string message
     */
    int SendBroadcastMessage(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Sends an Area Trigger Message to the [Player]
     *
     * @param string message
     */
    int SendAreaTriggerMessage(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Sends a Notification to the [Player]
     *
     * @param string message
     */
    int SendNotification(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a [WorldPacket] to the [Player]
     *
     * @param [WorldPacket] packet
     * @param bool selfOnly = true
     */
    int SendPacket(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends addon message to the [Player] receiver
     *
     * @param string prefix
     * @param string message
     * @param [ChatMsg] channel
     * @param [Player] receiver
     *
     */
    int SendAddonMessage(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Kicks the [Player] from the server
     */
    int KickPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds or subtracts from the [Player]s money in copper
     *
     * @param int32 copperAmt : negative to remove, positive to add
     */
    int ModifyMoney(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Teaches the [Player] the [Spell] specified by entry ID
     *
     * @param uint32 spellId
     */
    int LearnSpell(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Learn the [Player] the talent specified by talent_id and talentRank
     *
     * @param uint32 talent_id
     * @param uint32 talentRank
     */
    int LearnTalent(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Remove cooldowns on spells that have less than 10 minutes of cooldown from the [Player], similarly to when you enter an arena.
     */
    int RemoveArenaSpellCooldowns(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Resurrects the [Player].
     *
     * @param float healthPercent = 100.0f
     * @param bool ressSickness = false
     */
    int ResurrectPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds a new item to the gossip menu shown to the [Player] on next call to [Player:GossipSendMenu].
     *
     * sender and intid are numbers which are passed directly to the gossip selection handler. Internally they are partly used for the database gossip handling.<br />
     * code specifies whether to show a box to insert text to. The player inserted text is passed to the gossip selection handler.<br />
     * money specifies an amount of money the player needs to have to click the option. An error message is shown if the player doesn't have enough money.<br />
     * Note that the money amount is only checked client side and is not removed from the player either. You will need to check again in your code before taking action.
     *
     * See also: [Player:GossipSendMenu], [Player:GossipAddQuests], [Player:GossipComplete], [Player:GossipClearMenu]
     *
     * @param uint32 icon : number that specifies used icon
     * @param string msg : label on the gossip item
     * @param uint32 sender : number passed to gossip handlers
     * @param uint32 intid : number passed to gossip handlers
     * @param bool code = false : show text input on click if true
     * @param string popup = nil : if non empty string, a popup with given text shown on click
     * @param uint32 money = 0 : required money in copper
     */
    int GossipMenuAddItem(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Closes the [Player]s currently open Gossip Menu.
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipAddQuests], [Player:GossipSendMenu], [Player:GossipClearMenu]
     */
    int GossipComplete(Eluna* /*E*/, Player* player)
    {
        player->PlayerTalkClass->SendCloseGossip();
        return 0;
    }

    /**
     * Sends the current gossip items of the player to him as a gossip menu with header text from the given textId.
     *
     * If sender is a [Player] then menu_id is mandatory, otherwise it is not used for anything.
     * menu_id is the ID used to trigger the OnGossipSelect registered for players. See [Global:RegisterPlayerGossipEvent]
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipAddQuests], [Player:GossipComplete], [Player:GossipClearMenu]
     *
     * @proto (npc_text, sender)
     * @proto (npc_text, sender, menu_id)
     * @param uint32 npc_text : entry ID of a header text in npc_text database table, common default is 100
     * @param [Object] sender : object acting as the source of the sent gossip menu
     * @param uint32 menu_id : if sender is a [Player] then menu_id is mandatory
     */
    int GossipSendMenu(Eluna* E, Player* player)
    {
        uint32 npc_text = E->CHECKVAL<uint32>(2);
        Object* sender = E->CHECKOBJ<Object>(3);
        if (sender->GetTypeId() == TYPEID_PLAYER)
        {
            uint32 menu_id = E->CHECKVAL<uint32>(4);
            player->PlayerTalkClass->GetGossipMenu().SetMenuId(menu_id);
        }

        player->PlayerTalkClass->SendGossipMenu(npc_text, sender->GET_GUID());
        return 0;
    }

    /**
     * Clears the [Player]s current gossip item list.
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipSendMenu], [Player:GossipAddQuests], [Player:GossipComplete]
     *
     *     Note: This is needed when you show a gossip menu without using gossip hello or select hooks which do this automatically.
     *     Usually this is needed when using [Player] is the sender of a Gossip Menu.
     */
    int GossipClearMenu(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Attempts to start the taxi/flying to the given pathID
     *
     * @param uint32 pathId : pathId from DBC or [Global:AddTaxiPath]
     */
    int StartTaxi(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends POI to the location on your map
     *
     * @param float x
     * @param float y
     * @param uint32 icon : map icon to show
     * @param uint32 flags
     * @param uint32 data
     * @param string iconText
     */
    int GossipSendPOI(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds the gossip items to the [Player]'s gossip for the quests the given [WorldObject] can offer to the player.
     *
     * @param [WorldObject] source : a questgiver with quests
     */
    int GossipAddQuests(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Shows a quest accepting window to the [Player] for the given quest.
     *
     * @param uint32 questId : entry of a quest
     * @param bool activateAccept = true : auto finish the quest
     */
    int SendQuestTemplate(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Converts [Player]'s corpse to bones
     */
    int SpawnBones(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Loots [Player]'s bones for insignia
     *
     * @param [Player] looter
     */
    int RemovedInsignia(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Makes the [Player] invite another player to a group.
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param [Player] invited : player to invite to group
     * @return bool success : true if the player was invited to a group
     */
    int GroupInvite(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Creates a new [Group] with the creator [Player] as leader.
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param [Player] invited : player to add to group
     * @return [Group] createdGroup : the created group or nil
     */
    int GroupCreate(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Starts a cinematic for the [Player]
     *
     * @param uint32 CinematicSequenceId : entry of a cinematic
     */
    int SendCinematicStart(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Starts a movie for the [Player]
     *
     * @param uint32 MovieId : entry of a movie
     */
    int SendMovieStart(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Binds the [Player] to their current instance.
     */
    int BindToInstance(Eluna* /*E*/)
{
    return 1;
}
#endif
    /**
     * Adds a talent to the [Player] for the specified spec and learning status.
     *
     * @param uint32 spellId : ID of the spell for the talent
     * @param uint8 spec : The spec to which the talent applies
     * @param bool learning = true : Whether the talent is being learned
     * @return bool success : True if the talent was added, false otherwise
     */
    int AddTalent(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Grants kill credit for a specific [Craeture] or [GameObject].
     *
     * @param uint32 entryId : the ID of the [Creature] or [GameObject] to award credit for.
     */
    int KillGOCredit(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Grants a player kill credit.
     */
    int KilledPlayerCredit(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes a quest from the rewarded quests for the [Player].
     *
     * @param uint32 questId : the ID of the quest to remove.
     */
    int RemoveRewardedQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes an active quest from the [Player].
     *
     * @param uint32 questId : the ID of the quest to remove.
     */
    int RemoveActiveQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Summons a pet for the [Player].
     *
     * @table
     * @columns [Summon Type, ID]
     * @values [SUMMON_PET, 0]
     * @values [HUNTER_PET, 1]
     *
     * @param uint32 entryId : the ID of the pet to summon.
     * @param float x
     * @param float y
     * @param float z
     * @param float o
     * @param uint32 petType
     * @param uint32 despawnTime
     */
    int SummonPet(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes the [Player]'s active pet.
     *
     * @table
     * @columns [Save mode, ID, Comment]
     * @values [PET_SAVE_AS_DELETED, -1, "Not saved"]
     * @values [PET_SAVE_AS_CURRENT, 0, "In current slot (with the player)"]
     * @values [PET_SAVE_FIRST_STABLE_SLOT, 1, ""]
     * @values [PET_SAVE_SECOND_STABLE_SLOT, 2, ""]
     * @values [PET_SAVE_THIRD_STABLE_SLOT, 3, ""]
     * @values [PET_SAVE_LAST_STABLE_SLOT, 4, ""]
     *
     * @param int saveMode = -1
     * @param bool returnReagent = false
     *
     */
    int RemovePet(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Runs a command as the [Player].
     *
     * @param string command : the command to run
     */
    int RunCommand(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION == EXP_RETAIL
    /**
     * Add item appearance to the [Player].
     *
     * @param uint32 itemId : the ID of the item to add appearance from
     */
    int AddItemAppearance(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Add transmog set appearances to the [Player].
     *
     * @param uint32 transmogSetId : the ID of the set to add all appearances from
     */
    int AddTransmogSet(Eluna* /*E*/)
{
    return 1;
}
#endif

    ElunaRegister<Player> PlayerMethods[] =
    {
        // Getters
        { "GetSelection", &LuaPlayer::GetSelection },
        { "GetGMRank", &LuaPlayer::GetGMRank },
        { "GetGuildId", &LuaPlayer::GetGuildId },
        { "GetCoinage", &LuaPlayer::GetCoinage },
        { "GetTeam", &LuaPlayer::GetTeam },
        { "GetItemCount", &LuaPlayer::GetItemCount },
        { "GetGroup", &LuaPlayer::GetGroup },
        { "GetGuild", &LuaPlayer::GetGuild },
        { "GetAccountId", &LuaPlayer::GetAccountId },
        { "GetAccountName", &LuaPlayer::GetAccountName },
        { "GetArenaPoints", &LuaPlayer::GetArenaPoints },
        { "GetHonorPoints", &LuaPlayer::GetHonorPoints },
        { "GetLifetimeKills", &LuaPlayer::GetLifetimeKills },
        { "GetPlayerIP", &LuaPlayer::GetPlayerIP },
        { "GetLevelPlayedTime", &LuaPlayer::GetLevelPlayedTime },
        { "GetTotalPlayedTime", &LuaPlayer::GetTotalPlayedTime },
        { "GetItemByPos", &LuaPlayer::GetItemByPos },
        { "GetItemByEntry", &LuaPlayer::GetItemByEntry },
        { "GetItemByGUID", &LuaPlayer::GetItemByGUID },
        { "GetMailItem", &LuaPlayer::GetMailItem },
        { "GetReputation", &LuaPlayer::GetReputation },
        { "GetEquippedItemBySlot", &LuaPlayer::GetEquippedItemBySlot },
        { "GetQuestLevel", &LuaPlayer::GetQuestLevel },
        { "GetChatTag", &LuaPlayer::GetChatTag },
        { "GetRestBonus", &LuaPlayer::GetRestBonus },
        { "GetReqKillOrCastCurrentCount", &LuaPlayer::GetReqKillOrCastCurrentCount },
        { "GetQuestStatus", &LuaPlayer::GetQuestStatus },
        { "GetInGameTime", &LuaPlayer::GetInGameTime },
        { "GetComboPoints", &LuaPlayer::GetComboPoints },
        { "GetComboTarget", &LuaPlayer::GetComboTarget },
        { "GetGuildName", &LuaPlayer::GetGuildName },
        { "GetActiveSpec", &LuaPlayer::GetActiveSpec },
        { "GetSpellCooldownDelay", &LuaPlayer::GetSpellCooldownDelay },
        { "GetGuildRank", &LuaPlayer::GetGuildRank },
        { "GetDifficulty", &LuaPlayer::GetDifficulty },
        { "GetHealthBonusFromStamina", &LuaPlayer::GetHealthBonusFromStamina },
        { "GetManaBonusFromIntellect", &LuaPlayer::GetManaBonusFromIntellect },
        { "GetMaxSkillValue", &LuaPlayer::GetMaxSkillValue },
        { "GetPureMaxSkillValue", &LuaPlayer::GetPureMaxSkillValue },
        { "GetSkillValue", &LuaPlayer::GetSkillValue },
        { "GetBaseSkillValue", &LuaPlayer::GetBaseSkillValue },
        { "GetPureSkillValue", &LuaPlayer::GetPureSkillValue },
        { "GetSkillPermBonusValue", &LuaPlayer::GetSkillPermBonusValue },
        { "GetSkillTempBonusValue", &LuaPlayer::GetSkillTempBonusValue },
        { "GetReputationRank", &LuaPlayer::GetReputationRank },
        { "GetDrunkValue", &LuaPlayer::GetDrunkValue },
        { "GetBattlegroundId", &LuaPlayer::GetBattlegroundId },
        { "GetBattlegroundTypeId", &LuaPlayer::GetBattlegroundTypeId },
        { "GetXPRestBonus", &LuaPlayer::GetXPRestBonus },
        { "GetGroupInvite", &LuaPlayer::GetGroupInvite },
        { "GetSubGroup", &LuaPlayer::GetSubGroup },
        { "GetNextRandomRaidMember", &LuaPlayer::GetNextRandomRaidMember },
        { "GetOriginalGroup", &LuaPlayer::GetOriginalGroup },
        { "GetOriginalSubGroup", &LuaPlayer::GetOriginalSubGroup },
        { "GetChampioningFaction", &LuaPlayer::GetChampioningFaction },
        { "GetLatency", &LuaPlayer::GetLatency },
        { "GetRecruiterId", &LuaPlayer::GetRecruiterId },
        { "GetDbLocaleIndex", &LuaPlayer::GetDbLocaleIndex },
        { "GetDbcLocale", &LuaPlayer::GetDbcLocale },
        { "GetCorpse", &LuaPlayer::GetCorpse },
        { "GetGossipTextId", &LuaPlayer::GetGossipTextId },
        { "GetQuestRewardStatus", &LuaPlayer::GetQuestRewardStatus },
        { "GetShieldBlockValue", &LuaPlayer::GetShieldBlockValue },
        { "GetMailCount", &LuaPlayer::GetMailCount },
        { "GetXP", &LuaPlayer::GetXP },
        { "GetXPForNextLevel", &LuaPlayer::GetXPForNextLevel },
#if ELUNA_EXPANSION < EXP_RETAIL
        { "GetPhaseMaskForSpawn", &LuaPlayer::GetPhaseMaskForSpawn },
        { "GetFreeTalentPoints", &LuaPlayer::GetFreeTalentPoints },
        { "GetSpecsCount", &LuaPlayer::GetSpecsCount },
#else
        { "GetPhaseMaskForSpawn", METHOD_REG_NONE },
        { "GetFreeTalentPoints", METHOD_REG_NONE },
        { "GetSpecsCount", METHOD_REG_NONE },
#endif

        // Setters
        { "AdvanceSkillsToMax", &LuaPlayer::AdvanceSkillsToMax },
        { "AdvanceSkill", &LuaPlayer::AdvanceSkill },
        { "AdvanceAllSkills", &LuaPlayer::AdvanceAllSkills },
        { "SetCoinage", &LuaPlayer::SetCoinage },
        { "SetKnownTitle", &LuaPlayer::SetKnownTitle },
        { "UnsetKnownTitle", &LuaPlayer::UnsetKnownTitle },
        { "SetBindPoint", &LuaPlayer::SetBindPoint },
        { "SetArenaPoints", &LuaPlayer::SetArenaPoints },
        { "SetHonorPoints", &LuaPlayer::SetHonorPoints },
        { "SetGameMaster", &LuaPlayer::SetGameMaster },
        { "SetGMChat", &LuaPlayer::SetGMChat },
        { "SetTaxiCheat", &LuaPlayer::SetTaxiCheat },
        { "SetGMVisible", &LuaPlayer::SetGMVisible },
        { "SetPvPDeath", &LuaPlayer::SetPvPDeath },
        { "SetAcceptWhispers", &LuaPlayer::SetAcceptWhispers },
        { "SetRestBonus", &LuaPlayer::SetRestBonus },
        { "SetQuestStatus", &LuaPlayer::SetQuestStatus },
        { "SetReputation", &LuaPlayer::SetReputation },
        { "SetGuildRank", &LuaPlayer::SetGuildRank },
        { "SetMovement", &LuaPlayer::SetMovement },
        { "SetSkill", &LuaPlayer::SetSkill },
        { "SetFactionForRace", &LuaPlayer::SetFactionForRace },
        { "SetDrunkValue", &LuaPlayer::SetDrunkValue },
        { "SetAtLoginFlag", &LuaPlayer::SetAtLoginFlag },
        { "SetPlayerLock", &LuaPlayer::SetPlayerLock },
        { "SetGender", &LuaPlayer::SetGender },
        { "SetSheath", &LuaPlayer::SetSheath },
        { "SetFFA", &LuaPlayer::SetFFA },
#if ELUNA_EXPANSION < EXP_RETAIL
        { "AddLifetimeKills", &LuaPlayer::AddLifetimeKills },
        { "SetLifetimeKills", &LuaPlayer::SetLifetimeKills },
        { "SetFreeTalentPoints", &LuaPlayer::SetFreeTalentPoints },
#else
        { "AddLifetimeKills", METHOD_REG_NONE },
        { "SetLifetimeKills", METHOD_REG_NONE },
        { "SetFreeTalentPoints", METHOD_REG_NONE },
#endif

        // Boolean
        { "IsInGroup", &LuaPlayer::IsInGroup },
        { "IsInGuild", &LuaPlayer::IsInGuild },
        { "IsGM", &LuaPlayer::IsGM },
        { "IsImmuneToDamage", &LuaPlayer::IsImmuneToDamage },
        { "IsAlliance", &LuaPlayer::IsAlliance },
        { "IsHorde", &LuaPlayer::IsHorde },
        { "HasTitle", &LuaPlayer::HasTitle },
        { "HasItem", &LuaPlayer::HasItem },
        { "Teleport", &LuaPlayer::Teleport },
        { "AddItem", &LuaPlayer::AddItem },
        { "IsInArenaTeam", &LuaPlayer::IsInArenaTeam },
        { "CanCompleteQuest", &LuaPlayer::CanCompleteQuest },
        { "CanEquipItem", &LuaPlayer::CanEquipItem },
        { "IsFalling", &LuaPlayer::IsFalling },
        { "ToggleAFK", &LuaPlayer::ToggleAFK },
        { "ToggleDND", &LuaPlayer::ToggleDND },
        { "IsAFK", &LuaPlayer::IsAFK },
        { "IsDND", &LuaPlayer::IsDND },
        { "IsAcceptingWhispers", &LuaPlayer::IsAcceptingWhispers },
        { "IsGMChat", &LuaPlayer::IsGMChat },
        { "IsTaxiCheater", &LuaPlayer::IsTaxiCheater },
        { "IsGMVisible", &LuaPlayer::IsGMVisible },
        { "HasQuest", &LuaPlayer::HasQuest },
        { "InBattlegroundQueue", &LuaPlayer::InBattlegroundQueue },
        { "IsImmuneToEnvironmentalDamage", &LuaPlayer::IsImmuneToEnvironmentalDamage },
        { "CanSpeak", &LuaPlayer::CanSpeak },
        { "HasAtLoginFlag", &LuaPlayer::HasAtLoginFlag },
        { "InRandomLfgDungeon", &LuaPlayer::InRandomLfgDungeon },
        { "HasPendingBind", &LuaPlayer::HasPendingBind },
        { "HasAchieved", &LuaPlayer::HasAchieved },
        { "SetAchievement", &LuaPlayer::SetAchievement },
        { "CanUninviteFromGroup", &LuaPlayer::CanUninviteFromGroup },
        { "IsRested", &LuaPlayer::IsRested },
        { "IsNeverVisible", &LuaPlayer::IsNeverVisible },
        { "IsVisibleForPlayer", &LuaPlayer::IsVisibleForPlayer },
        { "IsUsingLfg", &LuaPlayer::IsUsingLfg },
        { "HasQuestForItem", &LuaPlayer::HasQuestForItem },
        { "HasQuestForGO", &LuaPlayer::HasQuestForGO },
        { "CanShareQuest", &LuaPlayer::CanShareQuest },
        { "HasReceivedQuestReward", &LuaPlayer::HasReceivedQuestReward },
        { "HasTalent", &LuaPlayer::HasTalent },
        { "IsInSameGroupWith", &LuaPlayer::IsInSameGroupWith },
        { "IsInSameRaidWith", &LuaPlayer::IsInSameRaidWith },
        { "IsGroupVisibleFor", &LuaPlayer::IsGroupVisibleFor },
        { "HasSkill", &LuaPlayer::HasSkill },
        { "IsHonorOrXPTarget", &LuaPlayer::IsHonorOrXPTarget },
        { "CanParry", &LuaPlayer::CanParry },
        { "CanBlock", &LuaPlayer::CanBlock },
        { "CanTitanGrip", &LuaPlayer::CanTitanGrip },
        { "InBattleground", &LuaPlayer::InBattleground },
        { "InArena", &LuaPlayer::InArena },
        { "IsOutdoorPvPActive", &LuaPlayer::IsOutdoorPvPActive },
        { "IsARecruiter", &LuaPlayer::IsARecruiter },
        { "CanUseItem", &LuaPlayer::CanUseItem },
        { "HasSpell", &LuaPlayer::HasSpell },
        { "HasSpellCooldown", &LuaPlayer::HasSpellCooldown },
        { "IsInWater", &LuaPlayer::IsInWater },
        { "CanFly", &LuaPlayer::CanFly },
        { "IsMoving", &LuaPlayer::IsMoving },
        { "IsFlying", &LuaPlayer::IsFlying },
        { "CanCompleteRepeatableQuest", &LuaPlayer::CanCompleteRepeatableQuest },
        { "CanRewardQuest", &LuaPlayer::CanRewardQuest },
        { "HasRecruited", &LuaPlayer::HasRecruited },
        { "IsRecruited", &LuaPlayer::IsRecruited },

        // Gossip
        { "GossipMenuAddItem", &LuaPlayer::GossipMenuAddItem },
        { "GossipSendMenu", &LuaPlayer::GossipSendMenu },
        { "GossipComplete", &LuaPlayer::GossipComplete },
        { "GossipClearMenu", &LuaPlayer::GossipClearMenu },

        // Other
        { "SendBroadcastMessage", &LuaPlayer::SendBroadcastMessage },
        { "SendNotification", &LuaPlayer::SendNotification },
        { "SendPacket", &LuaPlayer::SendPacket },
        { "SendAddonMessage", &LuaPlayer::SendAddonMessage },
        { "ModifyMoney", &LuaPlayer::ModifyMoney },
        { "LearnSpell", &LuaPlayer::LearnSpell },
        { "LearnTalent", &LuaPlayer::LearnTalent },
        { "RemoveArenaSpellCooldowns", &LuaPlayer::RemoveArenaSpellCooldowns },
        { "RemoveItem", &LuaPlayer::RemoveItem },
        { "ResurrectPlayer", &LuaPlayer::ResurrectPlayer },
        { "EquipItem", &LuaPlayer::EquipItem },
        { "ResetSpellCooldown", &LuaPlayer::ResetSpellCooldown },
        { "ResetTypeCooldowns", &LuaPlayer::ResetTypeCooldowns },
        { "ResetAllCooldowns", &LuaPlayer::ResetAllCooldowns },
        { "GiveXP", &LuaPlayer::GiveXP },
        { "RemovePet", &LuaPlayer::RemovePet },
        { "SummonPet", &LuaPlayer::SummonPet },
        { "Say", &LuaPlayer::Say },
        { "Yell", &LuaPlayer::Yell },
        { "TextEmote", &LuaPlayer::TextEmote },
        { "Whisper", &LuaPlayer::Whisper },
        { "CompleteQuest", &LuaPlayer::CompleteQuest },
        { "IncompleteQuest", &LuaPlayer::IncompleteQuest },
        { "FailQuest", &LuaPlayer::FailQuest },
        { "AddQuest", &LuaPlayer::AddQuest },
        { "RemoveQuest", &LuaPlayer::RemoveQuest },
        { "RemoveActiveQuest", &LuaPlayer::RemoveActiveQuest },
        { "RemoveRewardedQuest", &LuaPlayer::RemoveRewardedQuest },
        { "AreaExploredOrEventHappens", &LuaPlayer::AreaExploredOrEventHappens },
        { "GroupEventHappens", &LuaPlayer::GroupEventHappens },
        { "KilledMonsterCredit", &LuaPlayer::KilledMonsterCredit },
        { "KilledPlayerCredit", &LuaPlayer::KilledPlayerCredit },
        { "KillGOCredit", &LuaPlayer::KillGOCredit },
        { "TalkedToCreature", &LuaPlayer::TalkedToCreature },
        { "AddComboPoints", &LuaPlayer::AddComboPoints },
        { "ClearComboPoints", &LuaPlayer::ClearComboPoints },
        { "RemoveSpell", &LuaPlayer::RemoveSpell },
        { "ResetTalents", &LuaPlayer::ResetTalents },
        { "ResetTalentsCost", &LuaPlayer::ResetTalentsCost },
        { "AddTalent", &LuaPlayer::AddTalent },
        { "RemoveFromGroup", &LuaPlayer::RemoveFromGroup },
        { "KillPlayer", &LuaPlayer::KillPlayer },
        { "DurabilityLossAll", &LuaPlayer::DurabilityLossAll },
        { "DurabilityLoss", &LuaPlayer::DurabilityLoss },
        { "DurabilityPointsLoss", &LuaPlayer::DurabilityPointsLoss },
        { "DurabilityPointsLossAll", &LuaPlayer::DurabilityPointsLossAll },
        { "DurabilityPointLossForEquipSlot", &LuaPlayer::DurabilityPointLossForEquipSlot },
        { "DurabilityRepairAll", &LuaPlayer::DurabilityRepairAll },
        { "DurabilityRepair", &LuaPlayer::DurabilityRepair },
        { "ModifyHonorPoints", &LuaPlayer::ModifyHonorPoints },
        { "ModifyArenaPoints", &LuaPlayer::ModifyArenaPoints },
        { "LeaveBattleground", &LuaPlayer::LeaveBattleground },
        { "UnbindInstance", &LuaPlayer::UnbindInstance },
        { "UnbindAllInstances", &LuaPlayer::UnbindAllInstances },
        { "RemoveFromBattlegroundRaid", &LuaPlayer::RemoveFromBattlegroundRaid },
        { "ResetAchievements", &LuaPlayer::ResetAchievements },
        { "KickPlayer", &LuaPlayer::KickPlayer },
        { "LogoutPlayer", &LuaPlayer::LogoutPlayer },
        { "SendTrainerList", &LuaPlayer::SendTrainerList },
        { "SendListInventory", &LuaPlayer::SendListInventory },
        { "SendShowBank", &LuaPlayer::SendShowBank },
        { "SendTabardVendorActivate", &LuaPlayer::SendTabardVendorActivate },
        { "SendSpiritResurrect", &LuaPlayer::SendSpiritResurrect },
        { "SendTaxiMenu", &LuaPlayer::SendTaxiMenu },
        { "SendUpdateWorldState", &LuaPlayer::SendUpdateWorldState },
        { "RewardQuest", &LuaPlayer::RewardQuest },
        { "SendAuctionMenu", &LuaPlayer::SendAuctionMenu },
        { "SendShowMailBox", &LuaPlayer::SendShowMailBox },
        { "StartTaxi", &LuaPlayer::StartTaxi },
        { "GossipSendPOI", &LuaPlayer::GossipSendPOI },
        { "GossipAddQuests", &LuaPlayer::GossipAddQuests },
        { "SendQuestTemplate", &LuaPlayer::SendQuestTemplate },
        { "SpawnBones", &LuaPlayer::SpawnBones },
        { "RemovedInsignia", &LuaPlayer::RemovedInsignia },
        { "SendGuildInvite", &LuaPlayer::SendGuildInvite },
        { "Mute", &LuaPlayer::Mute },
        { "SummonPlayer", &LuaPlayer::SummonPlayer },
        { "SaveToDB", &LuaPlayer::SaveToDB },
        { "GroupInvite", &LuaPlayer::GroupInvite, METHOD_REG_WORLD }, // World state method only in multistate
        { "GroupCreate", &LuaPlayer::GroupCreate, METHOD_REG_WORLD }, // World state method only in multistate
        { "SendCinematicStart", &LuaPlayer::SendCinematicStart },
        { "SendMovieStart", &LuaPlayer::SendMovieStart },
        { "RunCommand", &LuaPlayer::RunCommand },
#if ELUNA_EXPANSION < EXP_RETAIL
        { "SendAreaTriggerMessage", &LuaPlayer::SendAreaTriggerMessage },
        { "RemoveLifetimeKills", &LuaPlayer::RemoveLifetimeKills },
        { "ResetPetTalents", &LuaPlayer::ResetPetTalents },
        { "BindToInstance", &LuaPlayer::BindToInstance },
        { "AddItemAppearance", METHOD_REG_NONE },
        { "AddTransmogSet", METHOD_REG_NONE },
#else
        { "SendAreaTriggerMessage", METHOD_REG_NONE },
        { "RemoveLifetimeKills", METHOD_REG_NONE },
        { "ResetPetTalents", METHOD_REG_NONE },
        { "BindToInstance", METHOD_REG_NONE },
        { "AddItemAppearance", &LuaPlayer::AddItemAppearance },
        { "AddTransmogSet", &LuaPlayer::AddTransmogSet },
#endif

        // Not implemented methods
        { "GetHonorStoredKills", METHOD_REG_NONE }, // classic only
        { "GetRankPoints", METHOD_REG_NONE }, // classic only
        { "GetHonorLastWeekStandingPos", METHOD_REG_NONE }, // classic only

        { "SetHonorStoredKills", METHOD_REG_NONE }, // classic only
        { "SetRankPoints", METHOD_REG_NONE }, // classic only
        { "SetHonorLastWeekStandingPos", METHOD_REG_NONE }, // classic only

        { "CanFlyInZone", METHOD_REG_NONE }, // not implemented

        { "UpdateHonor", METHOD_REG_NONE }, // classic only
        { "ResetHonor", METHOD_REG_NONE }, // classic only
        { "ClearHonorInfo", METHOD_REG_NONE }, // classic only
        { "GainSpellComboPoints", METHOD_REG_NONE }, // not implemented
        { "GossipMenuAddItemData", METHOD_REG_NONE } // not implemented
    };
};
#endif
