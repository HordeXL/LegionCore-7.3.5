#include "Hooks.h"
#include "HookHelpers.h"
#include "LuaEngine.h"
#include "BindingMap.h"
#include "ElunaEventMgr.h"
#include "ElunaIncludes.h"
#include "ElunaTemplate.h"

using namespace Hooks;

void Eluna::OnTimedEvent(int funcRef, uint32 delay, uint32 calls, WorldObject* obj)
{
    lua_rawgeti(L, LUA_REGISTRYINDEX, funcRef);
    Push(funcRef);
    Push(delay);
    Push(calls);
    Push(obj);
    ExecuteCall(4, 0);
    CleanUpStack(4);
}

void Eluna::OnLuaStateClose()
{
}

void Eluna::OnLuaStateOpen()
{
}
