/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef GROUPMETHODS_H
#define GROUPMETHODS_H

/***
 * Inherits all methods from: none
 */
namespace LuaGroup
{
    /**
     * Returns 'true' if the [Player] is the [Group] leader
     *
     * @param ObjectGuid guid : guid of a possible leader
     * @return bool isLeader
     */
    int IsLeader(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Group] is full
     *
     * @return bool isFull
     */
    int IsFull(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Group] is a LFG group
     *
     * @return bool isLFGGroup
     */
    int IsLFGGroup(Eluna* /*E*/)
{
    return 1;
}
    
    /**
     * Returns 'true' if the [Group] is a raid [Group]
     *
     * @return bool isRaid
     */
    int IsRaidGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Group] is a battleground [Group]
     *
     * @return bool isBG
     */
    int IsBGGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is a member of this [Group]
     *
     * @param ObjectGuid guid : guid of a player
     * @return bool isMember
     */
    int IsMember(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player] is an assistant of this [Group]
     *
     * @param ObjectGuid guid : guid of a player
     * @return bool isAssistant
     */
    int IsAssistant(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Player]s are in the same subgroup in this [Group]
     *
     * @param [Player] player1 : first [Player] to check
     * @param [Player] player2 : second [Player] to check
     * @return bool sameSubGroup
     */
    int SameSubGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the subgroup has free slots in this [Group]
     *
     * @param uint8 subGroup : subGroup ID to check
     * @return bool hasFreeSlot
     */
    int HasFreeSlotSubGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds a new member to the [Group]
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param [Player] player : [Player] to add to the group
     * @return bool added : true if member was added
     */
    int AddMember(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns true if the [Group] is a battlefield group, false otherwise
     *
     * @return bool isBFGroup
     */
    int IsBFGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a table with the [Player]s in this [Group]
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @return table groupPlayers : table of [Player]s
     */
    int GetMembers(Eluna* E, Group* group)
    {
        lua_newtable(E->L);
        int tbl = lua_gettop(E->L);
        uint32 i = 0;

#if ELUNA_EXPANSION < EXP_RETAIL
        for (GroupReference* itr = group->GetFirstMember(); itr; itr = itr->next())
        {
            Player* member = itr->getSource();
#else
        for (GroupReference* itr = group->GetFirstMember(); itr; itr = itr->next())
        {
            Player* member = itr->getSource();
#endif
            if (!member || !member->GetSession())
                continue;

            E->Push(member);
            lua_rawseti(E->L, tbl, ++i);
        }

        lua_settop(E->L, tbl); // push table to top of stack
        return 1;
    }

    /**
     * Returns [Group] leader GUID
     *
     * @return ObjectGuid leaderGUID
     */
    int GetLeaderGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Group]'s GUID
     *
     * @return ObjectGuid groupGUID
     */
    int GetGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns a [Group] member's GUID by their name
     *
     * @param string name : the [Player]'s name
     * @return ObjectGuid memberGUID
     */
    int GetMemberGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the member count of this [Group]
     *
     * @return uint32 memberCount
     */
    int GetMembersCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player]'s subgroup ID of this [Group]
     *
     * @param ObjectGuid guid : guid of the player
     * @return uint8 subGroupID : a valid subgroup ID or MAX_RAID_SUBGROUPS+1
     */
    int GetMemberGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Group] members' flags
     *
     * @table
     * @columns [GroupMemberFlags, ID]
     * @values [MEMBER_FLAG_ASSISTANT, 1]
     * @values [MEMBER_FLAG_MAINTANK, 2]
     * @values [MEMBER_FLAG_MAINASSIST, 4]
     *
     * @param ObjectGuid guid : guid of the player
     * @return uint8 flags
     */
    int GetMemberFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the leader of this [Group]
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param ObjectGuid guid : guid of the new leader
     */
    int SetLeader(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sends a specified [WorldPacket] to this [Group]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to send
     * @param bool ignorePlayersInBg : ignores [Player]s in a battleground
     * @param ObjectGuid ignore : ignore a [Player] by their GUID
     */
    int SendPacket(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes a [Player] from this [Group] and returns 'true' if successful
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @table
     * @columns [RemoveMethod, ID]
     * @values [GROUP_REMOVEMETHOD_DEFAULT, 0]
     * @values [GROUP_REMOVEMETHOD_KICK, 1]
     * @values [GROUP_REMOVEMETHOD_LEAVE, 2]
     * @values [GROUP_REMOVEMETHOD_KICK_LFG, 3]
     *
     * @param ObjectGuid guid : guid of the player to remove
     * @param [RemoveMethod] method : method used to remove the player
     * @return bool removed
     */
    int RemoveMember(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Disbands this [Group]
     *
     * In multistate, this method is only available in the WORLD state
     *
     */
    int Disband(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Converts this [Group] to a raid [Group]
     *
     * In multistate, this method is only available in the WORLD state
     *
     */
    int ConvertToRaid(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the member's subGroup
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param ObjectGuid guid : guid of the player to move
     * @param uint8 groupID : the subGroup's ID
     */
    int SetMembersGroup(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the target icon of an object for the [Group]
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param uint8 icon : the icon (Skull, Square, etc)
     * @param ObjectGuid target : GUID of the icon target, 0 is to clear the icon
     * @param ObjectGuid setter : GUID of the icon setter
     */
    int SetTargetIcon(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Converts the [Group] to a LFG group
     *
     * In multistate, this method is only available in the WORLD state
     */
    int ConvertToLFG(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets or removes a flag for a [Group] member
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @table
     * @columns [GroupMemberFlags, ID]
     * @values [MEMBER_FLAG_ASSISTANT, 1]
     * @values [MEMBER_FLAG_MAINTANK, 2]
     * @values [MEMBER_FLAG_MAINASSIST, 4]
     *
     * @param ObjectGuid target : GUID of the target
     * @param bool apply : add the `flag` if `true`, remove the `flag` otherwise
     * @param [GroupMemberFlags] flag : the flag to set or unset
     */
    int SetMemberFlag(Eluna* /*E*/)
{
    return 1;
}

    ElunaRegister<Group> GroupMethods[] =
    {
        // Getters
        { "GetMembers", &LuaGroup::GetMembers, METHOD_REG_WORLD }, // World state method only in multistate
        { "GetLeaderGUID", &LuaGroup::GetLeaderGUID },
        { "GetGUID", &LuaGroup::GetGUID },
        { "GetMemberGroup", &LuaGroup::GetMemberGroup },
        { "GetMemberGUID", &LuaGroup::GetMemberGUID },
        { "GetMembersCount", &LuaGroup::GetMembersCount },
        { "GetMemberFlags", &LuaGroup::GetMemberFlags },

        // Setters
        { "SetLeader", &LuaGroup::SetLeader, METHOD_REG_WORLD }, // World state method only in multistate
        { "SetMembersGroup", &LuaGroup::SetMembersGroup, METHOD_REG_WORLD }, // World state method only in multistate
        { "SetTargetIcon", &LuaGroup::SetTargetIcon, METHOD_REG_WORLD }, // World state method only in multistate
        { "SetMemberFlag", &LuaGroup::SetMemberFlag, METHOD_REG_WORLD }, // World state method only in multistate

        // Boolean
        { "IsLeader", &LuaGroup::IsLeader },
        { "AddMember", &LuaGroup::AddMember, METHOD_REG_WORLD }, // World state method only in multistate
        { "RemoveMember", &LuaGroup::RemoveMember, METHOD_REG_WORLD }, // World state method only in multistate
        { "Disband", &LuaGroup::Disband, METHOD_REG_WORLD }, // World state method only in multistate
        { "IsFull", &LuaGroup::IsFull },
        { "IsLFGGroup", &LuaGroup::IsLFGGroup },
        { "IsRaidGroup", &LuaGroup::IsRaidGroup },
        { "IsBGGroup", &LuaGroup::IsBGGroup },
        { "IsBFGroup", &LuaGroup::IsBFGroup },
        { "IsMember", &LuaGroup::IsMember },
        { "IsAssistant", &LuaGroup::IsAssistant },
        { "SameSubGroup", &LuaGroup::SameSubGroup },
        { "HasFreeSlotSubGroup", &LuaGroup::HasFreeSlotSubGroup },

        // Other
        { "SendPacket", &LuaGroup::SendPacket },
        { "ConvertToLFG", &LuaGroup::ConvertToLFG, METHOD_REG_WORLD }, // World state method only in multistate
        { "ConvertToRaid", &LuaGroup::ConvertToRaid, METHOD_REG_WORLD } // World state method only in multistate
    };
};

#endif
