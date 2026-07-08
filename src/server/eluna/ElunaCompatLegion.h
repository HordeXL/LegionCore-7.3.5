/*
 * Eluna Compatibility Header for LegionCore (UWOW-based)
 * Provides missing types and APIs for the Eluna Lua Engine.
 */

#ifndef _ELUNA_COMPAT_LEGION_H
#define _ELUNA_COMPAT_LEGION_H

#include "Common.h"
#include "Utilities/Duration.h"

// ProcFlagsInit - In newer TrinityCore this is a class, in older cores it's a uint32
typedef uint32 ProcFlagsInit;

// TeamId constants (not always defined in older TrinityCore forks)
#ifndef TEAM_ALLIANCE
#define TEAM_ALLIANCE            0
#define TEAM_HORDE               1
#define TEAM_NEUTRAL             2
#endif

// SpellHistory compatibility - In newer TrinityCore SpellHistory is a separate class,
// in this LegionCore cooldowns are managed directly on Player/Creature
// These inline methods use forward-declared types and are only called after full includes
namespace LegionCompat
{
    inline bool HasSpellCooldown(class Creature* creature, uint32 spellId);
    inline bool HasSpellCooldown(class Player* player, uint32 spellId);
    inline bool HasSpellCooldown(class Creature* creature, class SpellInfo const* spellInfo);
    inline bool HasSpellCooldown(class Player* player, class SpellInfo const* spellInfo);
    inline uint32 GetRemainingCooldown(class Player* player, class SpellInfo const* spellInfo);
} // namespace LegionCompat

#endif // _ELUNA_COMPAT_LEGION_H
