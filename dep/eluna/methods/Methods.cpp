/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

// Eluna
#include "LuaEngine.h"
#include "ElunaEventMgr.h"
#include "ElunaIncludes.h"
#include "ElunaTemplate.h"
#include "ElunaUtility.h"

// Phase B: TrinityCore method bindings (LegionCore-adapted)
// Each file is tested individually for LegionCore API compatibility.
// Files with too many API differences are added incrementally.

#include "ObjectMethods.h"
#include "CorpseMethods.h"
#include "BigIntMethods.h"

void RegisterMethods(Eluna* E)
{
    // Phase B-3: Object (29 bindings - getters/setters, safe for LegionCore)
    ElunaTemplate<Object>::Register(E, "Object");
    ElunaTemplate<Object>::SetMethods(E, LuaObject::ObjectMethods);

    // Phase B-5: Corpse (5 bindings - simple methods)
    ElunaTemplate<Corpse>::Register(E, "Corpse");
    ElunaTemplate<Corpse>::SetMethods(E, LuaCorpse::CorpseMethods);

    // Phase B-5: BigInt (22+22+14 = 58 bindings - pure math, no TC API dependency)
    ElunaTemplate<long long>::Register(E, "int64");
    ElunaTemplate<long long>::SetMethods(E, LuaBigInt::LongLongMethods);

    ElunaTemplate<unsigned long long>::Register(E, "uint64");
    ElunaTemplate<unsigned long long>::SetMethods(E, LuaBigInt::ULongLongMethods);

    ElunaTemplate<ObjectGuid>::Register(E, "Guid");
    ElunaTemplate<ObjectGuid>::SetMethods(E, LuaBigInt::ObjectGuidMethods);
}
