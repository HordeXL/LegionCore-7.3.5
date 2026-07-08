-- Eluna 功能测试模块
-- 输入 .eluna 验证 Eluna 是否正常工作

local function ElunaTestCommand(event, player, command)
    if command == ".eluna" then
        player:SendBroadcastMessage("|cff00ff00====================================|r")
        player:SendBroadcastMessage("|cff00ff00      Eluna Lua Engine 测试        |r")
        player:SendBroadcastMessage("|cff00ff00====================================|r")
        player:SendBroadcastMessage("|cff00ff00[✓] Eluna 已加载并正常运行|r")
        player:SendBroadcastMessage("|cffffffff当前时间: |r" .. os.date("%Y-%m-%d %H:%M:%S"))
        player:SendBroadcastMessage("|cffffffff玩家名称: |r" .. player:GetName())
        player:SendBroadcastMessage("|cffffffff玩家等级: |r" .. player:GetLevel())
        player:SendBroadcastMessage("|cffffffff地图 ID: |r" .. player:GetMapId())
        player:SendBroadcastMessage("|cffffffff坐标: |r" .. string.format("%.1f, %.1f, %.1f", player:GetX(), player:GetY(), player:GetZ()))
        player:SendBroadcastMessage("|cff00ff00====================================|r")
        return false
    end
end
RegisterPlayerEvent(42, ElunaTestCommand)

print("[Eluna] Eluna Test module loaded - 输入 .eluna 测试")
