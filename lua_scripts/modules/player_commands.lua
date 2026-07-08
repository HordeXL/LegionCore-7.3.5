-- Player Commands Module

-- .dismount command
local function DismountCommand(event, player, command)
    if command == ".dismount" then
        if player:IsMounted() then
            player:Dismount()
            player:SendBroadcastMessage("|cff00ff00已下马|r")
        else
            player:SendBroadcastMessage("|cffffff00你没有骑乘坐骑|r")
        end
        return false
    end
end
RegisterPlayerEvent(42, DismountCommand)

-- .bank command - Open bank
local function BankCommand(event, player, command)
    if command == ".bank" then
        player:SendShowBank(player)
        return false
    end
end
RegisterPlayerEvent(42, BankCommand)

print("[Eluna] Player Commands module loaded")
