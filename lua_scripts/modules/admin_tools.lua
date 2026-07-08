-- Admin Tools Module
-- Provides administrative commands for server management

-- .announce command - Broadcast a message to all players
local function AnnounceCommand(event, player, command)
    local msg = command:sub(10) -- remove ".announce "
    if #msg > 0 then
        SendWorldMessage("|cffFF0000[Announcement]:|r " .. msg)
    end
    return false
end
RegisterPlayerEvent(42, AnnounceCommand) -- 42 = ON_COMMAND_EVENT (varies by core)

-- .info command - Display server information
local function InfoCommand(event, player, command)
    if command == ".info" then
        player:SendBroadcastMessage("Server: LegionCore 7.3.5")
        player:SendBroadcastMessage("Players online: " .. #GetPlayersInWorld())
        return false
    end
end
RegisterPlayerEvent(42, InfoCommand)

print("[Eluna] Admin Tools module loaded")
