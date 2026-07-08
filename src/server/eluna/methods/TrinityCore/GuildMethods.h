/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef GUILDMETHODS_H
#define GUILDMETHODS_H

/***
 * Inherits all methods from: none
 */
namespace LuaGuild
{
    /**
     * Returns a table with the [Player]s in this [Guild]
     *
     * Only the players that are online and on some map.
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @return table guildPlayers : table of [Player]s
     */
    int GetMembers(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the member count of this [Guild]
     *
     * @return uint32 memberCount
     */
    int GetMemberCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Finds and returns the [Guild] leader by their GUID if logged in
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @return [Player] leader
     */
    int GetLeader(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns [Guild] leader GUID
     *
     * @return ObjectGuid leaderGUID
     */
    int GetLeaderGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Guild]s entry ID
     *
     * @return uint32 entryId
     */
    int GetId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Guild]s name
     *
     * @return string guildName
     */
    int GetName(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Guild]s current Message Of The Day
     *
     * @return string guildMOTD
     */
    int GetMOTD(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Guild]s current info
     *
     * @return string guildInfo
     */
    int GetInfo(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the leader of this [Guild]
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param [Player] leader : the [Player] leader to change
     */
    int SetLeader(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the information of the bank tab specified
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param uint8 tabId : the ID of the tab specified
     * @param string info : the information to be set to the bank tab
     */
    int SetBankTabText(Eluna* /*E*/)
{
    return 1;
}

    // SendPacketToGuild(packet)
    /**
     * Sends a [WorldPacket] to all the [Player]s in the [Guild]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
     */
    int SendPacket(Eluna* /*E*/)
{
    return 1;
}

    // SendPacketToRankedInGuild(packet, rankId)
    /**
     * Sends a [WorldPacket] to all the [Player]s at the specified rank in the [Guild]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
     * @param uint8 rankId : the rank ID
     */
    int SendPacketToRanked(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Disbands the [Guild]
     *
     * In multistate, this method is only available in the WORLD state
     *
     */
    int Disband(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds the specified [Player] to the [Guild] at the specified rank.
     *
     * If no rank is specified, defaults to none.
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param [Player] player : the [Player] to be added to the guild
     * @param uint8 rankId : the rank ID
     */
    int AddMember(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes the specified [Player] from the [Guild].
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param [Player] player : the [Player] to be removed from the guild
     * @param bool isDisbanding : default 'false', should only be set to 'true' if the guild is triggered to disband
     */
    int DeleteMember(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Promotes/demotes the [Player] to the specified rank.
     *
     * In multistate, this method is only available in the WORLD state
     *
     * @param [Player] player : the [Player] to be promoted/demoted
     * @param uint8 rankId : the rank ID
     */
    int SetMemberRank(Eluna* /*E*/)
{
    return 1;
}
    
    ElunaRegister<Guild> GuildMethods[] =
    {
        // Getters
        { "GetMembers", &LuaGuild::GetMembers, METHOD_REG_WORLD }, // World state method only in multistate
        { "GetLeader", &LuaGuild::GetLeader, METHOD_REG_WORLD }, // World state method only in multistate
        { "GetLeaderGUID", &LuaGuild::GetLeaderGUID },
        { "GetId", &LuaGuild::GetId },
        { "GetName", &LuaGuild::GetName },
        { "GetMOTD", &LuaGuild::GetMOTD },
        { "GetInfo", &LuaGuild::GetInfo },
        { "GetMemberCount", &LuaGuild::GetMemberCount },

        // Setters
        { "SetBankTabText", &LuaGuild::SetBankTabText, METHOD_REG_WORLD }, // World state method only in multistate
        { "SetMemberRank", &LuaGuild::SetMemberRank, METHOD_REG_WORLD }, // World state method only in multistate
        { "SetLeader", &LuaGuild::SetLeader, METHOD_REG_WORLD }, // World state method only in multistate

        // Other
        { "SendPacket", &LuaGuild::SendPacket },
        { "SendPacketToRanked", &LuaGuild::SendPacketToRanked },
        { "Disband", &LuaGuild::Disband, METHOD_REG_WORLD }, // World state method only in multistate
        { "AddMember", &LuaGuild::AddMember, METHOD_REG_WORLD }, // World state method only in multistate
        { "DeleteMember", &LuaGuild::DeleteMember, METHOD_REG_WORLD } // World state method only in multistate
    };
};
#endif
