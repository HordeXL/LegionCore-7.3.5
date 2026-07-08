-- GM Tools Module
-- Provides Game Master functionality

local GM_LEVEL = 1 -- Minimum GM level required

-- .gohome command - Teleport the player to their hearthstone location
local function GoHome(event, player, command)
    if command ~= ".gohome" then return end
    if player:GetGMRank() < GM_LEVEL then
        player:SendBroadcastMessage("|cffff0000你没有权限使用此命令|r")
        return false
    end
    player:SetHomebindToCurrentArea()
    player:SendBroadcastMessage("|cff00ff00已设置炉石位置为当前位置|r")
    return false
end
RegisterPlayerEvent(42, GoHome)

-- .taxi command - Unlock all taxi paths (GM only)
local function UnlockTaxi(event, player, command)
    if command ~= ".taxi" then return end
    if player:GetGMRank() < 3 then
        player:SendBroadcastMessage("|cffff0000你没有权限使用此命令|r")
        return false
    end
    player:LearnTaxiNodes()
    player:SendBroadcastMessage("|cff00ff00已解锁所有飞行路径|r")
    return false
end
RegisterPlayerEvent(42, UnlockTaxi)

print("[Eluna] GM Tools module loaded")
