print(">>Script: TeleportStone loading...OK")

local DALARAN_MAP = 1220
local DALARAN_X = 13.5218
local DALARAN_Y = 72.9852
local DALARAN_Z = 55.6183
local SHRINE_ALLIANCE_MAP = 870
local SHRINE_ALLIANCE_X = 1622.6
local SHRINE_ALLIANCE_Y = 519.6
local SHRINE_ALLIANCE_Z = 384.5
local SHRINE_HORDE_MAP = 870
local SHRINE_HORDE_X = 1524.6
local SHRINE_HORDE_Y = 181.0
local SHRINE_HORDE_Z = 377.6

print(">> ITEM_EVENT_ON_USE =", ITEM_EVENT_ON_USE)
print(">> GOSSIP_EVENT_ON_SELECT =", GOSSIP_EVENT_ON_SELECT)

RegisterItemEvent(6948, ITEM_EVENT_ON_USE, function(event, player, item, target)
    print(">> TeleportStone: ITEM_EVENT_ON_USE FIRED! Player:", player:GetName())

    player:GossipClearMenu()
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\inv_misc_rune_01:30:30:-2:0|tTeleport to Dalaran", 1, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\inv_misc_rune_02:30:30:-2:0|tTeleport to Shrine", 2, 0)
    player:GossipSendMenu(1, player, 1000)
    print(">> TeleportStone: Gossip menu sent!")

    return false
end)

RegisterPlayerGossipEvent(1000, GOSSIP_EVENT_ON_SELECT, function(event, player, sender, action, menuId)
    print(">> TeleportStone: GOSSIP_EVENT_ON_SELECT FIRED! Action:", action)

    if action == 1 then
        print(">> TeleportStone: Teleporting to Dalaran")
        player:Teleport(DALARAN_MAP, DALARAN_X, DALARAN_Y, DALARAN_Z, 1.0)
    elseif action == 2 then
        print(">> TeleportStone: Teleporting to Shrine")
        player:Teleport(SHRINE_ALLIANCE_MAP, SHRINE_ALLIANCE_X, SHRINE_ALLIANCE_Y, SHRINE_ALLIANCE_Z, 1.0)
    end

    player:GossipComplete()
    print(">> TeleportStone: Gossip completed!")
    return false
end)
