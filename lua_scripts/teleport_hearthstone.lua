local ITEM_HEARTHSTONE = 6948

local destinations = {
    { map = 0, x = -8866.55, y = 673.10, z = 97.90, h = 5.40 },    -- Stormwind
    { map = 0, x = -4923.97, y = -940.72, z = 502.64, h = 5.40 },   -- Ironforge
    { map = 1, x = 9951.82, y = 2609.80, z = 1315.55, h = 4.13 },   -- Darnassus
    { map = 530, x = -3984.15, y = -13854.51, z = 114.80, h = 2.30 },-- Exodar
    { map = 530, x = -1838.16, y = 5301.79, z = -12.43, h = 5.90 },  -- Shattrath
    { map = 571, x = 5804.15, y = 586.04, z = 660.94, h = 1.92 },    -- Dalaran
    { map = 1, x = 1619.83, y = -4413.35, z = 15.18, h = 4.86 },     -- Theramore
    { map = 0, x = -1412.73, y = -2963.38, z = 93.95, h = 0.94 },    -- Booty Bay
}

local function OnHearthstoneUse(event, player, item, target)
    player:GossipClearMenu()
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\inv_misc_tournaments_symbol_lor:30:30:-10:0|t Stormwind", 1, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\inv_misc_tournaments_symbol_ironforge:30:30:-10:0|t Ironforge", 2, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\inv_misc_tournaments_symbol_darnassus:30:30:-10:0|t Darnassus", 3, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\inv_misc_tournaments_symbol_exodar:30:30:-10:0|t Exodar", 4, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\achievement_reputation_01:30:30:-10:0|t Shattrath", 5, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\achievement_reputation_04:30:30:-10:0|t Dalaran", 6, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\achievement_reputation_02:30:30:-10:0|t Theramore", 7, 0)
    player:GossipMenuAddItem(7, "|TInterface\\Icons\\achievement_reputation_08:30:30:-10:0|t Booty Bay", 8, 0)
    player:GossipSendMenu(1000, player, 0)
    return false
end

local function OnGossipSelect(event, player, receiver, sender, intid, code, menuId)
    if menuId ~= 1000 then
        return
    end
    local dest = destinations[intid]
    if dest then
        player:Teleport(dest.map, dest.x, dest.y, dest.z, dest.h)
    end
    player:GossipComplete()
end

RegisterItemEvent(ITEM_HEARTHSTONE, 2, OnHearthstoneUse)
RegisterPlayerGossipEvent(1000, 2, OnGossipSelect)
