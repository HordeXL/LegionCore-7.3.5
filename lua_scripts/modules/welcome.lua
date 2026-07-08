-- Welcome Module
-- Shows welcome message to players on login

-- PLAYER_EVENT_ON_LOGIN = 3
local function OnLogin(event, player, firstLogin)
    if firstLogin then
        player:SendBroadcastMessage("|cff00FF00欢迎来到 LegionCore 7.3.5|r")
        player:SendBroadcastMessage("|cffFFD700输入 .help 查看可用命令|r")
    else
        player:SendBroadcastMessage("|cff00BFFF欢迎回来, " .. player:GetName() .. "!|r")
    end
end
RegisterPlayerEvent(3, OnLogin)
