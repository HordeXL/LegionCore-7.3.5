/*
 * Eluna Compatibility Implementation for LegionCore
 */

#include "ElunaCompatLegion.h"
#include "Player.h"
#include "Creature.h"
#include "SpellInfo.h"

bool LegionCompat::HasSpellCooldown(Creature* creature, uint32 spellId)
{
    return creature->HasSpellCooldown(spellId);
}

bool LegionCompat::HasSpellCooldown(Player* player, uint32 spellId)
{
    return player->HasSpellCooldown(spellId);
}

bool LegionCompat::HasSpellCooldown(Creature* creature, SpellInfo const* spellInfo)
{
    return creature->HasSpellCooldown(spellInfo->Id);
}

bool LegionCompat::HasSpellCooldown(Player* player, SpellInfo const* spellInfo)
{
    return player->HasSpellCooldown(spellInfo->Id);
}

uint32 LegionCompat::GetRemainingCooldown(Player* player, SpellInfo const* spellInfo)
{
    return static_cast<uint32>(player->GetSpellCooldownDelay(spellInfo->Id));
}
