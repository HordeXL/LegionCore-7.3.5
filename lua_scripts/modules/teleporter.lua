-- Teleporter Module
-- Simple teleport command using gossip menu

-- .tele command - Opens teleport menu
local function TeleCommand(event, player, command)
    if command == ".tele" then
        -- Create gossip menu
        player:GossipClearMenu()
        player:GossipMenuAddItem(0, "|TInterface\\Icons\\spell_magic_lesserinvis:30|t暴风城", 0, 1)
        player:GossipMenuAddItem(0, "|TInterface\\Icons\\spell_magic_lesserinvis:30|t奥格瑞玛", 0, 2)
        player:GossipMenuAddItem(0, "|TInterface\\Icons\\spell_magic_lesserinvis:30|t达拉然", 0, 3)
        player:GossipMenuAddItem(0, "|TInterface\\Icons\\spell_magic_lesserinvis:30|t沙塔斯", 0, 4)
        player:GossipMenuAddItem(0, "|TInterface\\Icons\\spell_magic_lesserinvis:30|t锦绣谷", 0, 5)
        player:GossipSendMenu(1, player, 1) -- menuId 1
        return false
    end
end
RegisterPlayerEvent(42, TeleCommand)

-- Handle gossip selection
local function TeleGossipSelect(event, player, creature, sender, action)
    if sender ~= 1 then return end -- not our menu

    local locations = {
        { -9065.0, 434.0, 93.0, 0 },    -- Stormwind
        { 1577.0, -4398.0, 15.0, 0 },   -- Orgrimmar
        { 5804.0, 624.0, 647.0, 0 },    -- Dalaran
        { -1838.0, 5301.0, -12.0, 0 },  -- Shattrath
        { 1627.0, 575.0, 476.0, 0 },    -- Vale of Eternal Blossoms
    }

    if action >= 1 and action <= #locations then
        local loc = locations[action]
        player:Teleport(0, loc[1], loc[2], loc[3], loc[4])
        player:SendBroadcastMessage("|cff00ff00已传送!|r")
    end

    player:GossipComplete()
end
RegisterPlayerGossipEvent(1, 2, TeleGossipSelect) -- GOSSIP_EVENT_ON_SELECT

print("[Eluna] Teleporter module loaded")
