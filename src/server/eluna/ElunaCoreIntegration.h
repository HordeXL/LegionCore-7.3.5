/*
 * Eluna Core Integration Header
 * Provides inline methods for core classes to interact with Eluna.
 * Include this header LAST in .cpp files that need Eluna integration.
 */
#ifndef _ELUNA_CORE_INTEGRATION_H
#define _ELUNA_CORE_INTEGRATION_H

#include "ElunaMgr.h"
#include "ElunaLoader.h"
#include "ElunaConfig.h"
#include "ElunaCreatureAI.h"
#include "ElunaInstanceAI.h"
#include "Creature.h"
#include "Map.h"
#include "MapManager.h"

// Inline GetEluna helpers for core classes
inline Eluna* GetMapEluna(Map* map)
{
    ElunaInfoKey key(map->GetId(), map->GetInstanceId());
    return sElunaMgr->GetEluna(key);
}

inline bool CreatureHasElunaAI(Creature* creature)
{
    if (!sElunaConfig->IsElunaEnabled())
        return false;

    ElunaInfoKey key(creature->GetMapId(), creature->GetInstanceId());
    Eluna* eluna = sElunaMgr->GetEluna(key);
    if (!eluna)
        return false;

    // Check if any creature events are bound for this creature's entry
    auto binding = eluna->GetBinding<Hooks::CreatureEvents>(Hooks::REGTYPE_CREATURE);
    if (!binding)
        return false;

    // Simple check: does this creature have any registered event handlers?
    return binding->HasBindingsFor(creature->GetEntry());
}

#endif // _ELUNA_CORE_INTEGRATION_H
