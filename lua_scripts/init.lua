-- Eluna Lua Engine - Main initialization script
-- This script is loaded first when Eluna starts

print(">> Eluna Lua Engine initialized")

-- WORLD_EVENT_ON_STARTUP = 14
local function OnStartup(event)
    print("[Eluna] World server started")
end
RegisterServerEvent(14, OnStartup)

-- WORLD_EVENT_ON_SHUTDOWN = 15
local function OnShutdown(event)
    print("[Eluna] World server shutting down")
end
RegisterServerEvent(15, OnShutdown)
