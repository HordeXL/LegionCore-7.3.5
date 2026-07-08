/*
 * Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
 * Copyright (C) 2025 - LegionCore adaptation
 * This program is free software licensed under GPL version 3
 * Please see the included DOCS/LICENSE.md for more information
 */

#ifndef _ELUNA_CREATURE_AI_H
#define _ELUNA_CREATURE_AI_H

#include "LuaEngine.h"
#include "ScriptedCreature.h"
#include "ElunaMgr.h"

inline Eluna* GetCreatureEluna(Creature* me)
{
    return sElunaMgr->Get(ElunaInfoKey(me->GetMapId(), me->GetInstanceId()));
}

#if defined ELUNA_TRINITY || defined ELUNA_AZEROTHCORE
typedef ScriptedAI NativeScriptedAI;
#elif defined ELUNA_CMANGOS || ELUNA_MANGOS
class CreatureAI;
typedef CreatureAI NativeScriptedAI;
#elif defined ELUNA_VMANGOS
class BasicAI;
typedef BasicAI NativeScriptedAI;
#endif

struct ElunaCreatureAI : NativeScriptedAI
{
    bool justSpawned;
    std::vector< std::pair<uint32, uint32> > movepoints;
#if !defined ELUNA_TRINITY && !defined ELUNA_AZEROTHCORE
#define me  m_creature
#endif

    ElunaCreatureAI(Creature* creature) : NativeScriptedAI(creature), justSpawned(true)
    {
    }
    ~ElunaCreatureAI() { }

    void UpdateAI(uint32 diff) override
    {
        if (!movepoints.empty())
        {
            for (auto& point : movepoints)
            {
                if (!GetCreatureEluna(me)->MovementInform(me, point.first, point.second))
                    NativeScriptedAI::MovementInform(point.first, point.second);
            }
            movepoints.clear();
        }

        if (!GetCreatureEluna(me)->UpdateAI(me, diff))
        {
            if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC))
                NativeScriptedAI::UpdateAI(diff);
        }
    }

    void EnterCombat(Unit* target) override
    {
        if (!GetCreatureEluna(me)->EnterCombat(me, target))
            NativeScriptedAI::EnterCombat(target);
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType damageType) override
    {
        uint32 dmg = damage;
        if (!GetCreatureEluna(me)->DamageTaken(me, attacker, dmg))
        {
            NativeScriptedAI::DamageTaken(attacker, damage, damageType);
        }
    }

    void JustDied(Unit* killer) override
    {
        if (!GetCreatureEluna(me)->JustDied(me, killer))
            NativeScriptedAI::JustDied(killer);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!GetCreatureEluna(me)->KilledUnit(me, victim))
            NativeScriptedAI::KilledUnit(victim);
    }

    void JustSummoned(Creature* summon) override
    {
        if (!GetCreatureEluna(me)->JustSummoned(me, summon))
            NativeScriptedAI::JustSummoned(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        if (!GetCreatureEluna(me)->SummonedCreatureDespawn(me, summon))
            NativeScriptedAI::SummonedCreatureDespawn(summon);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        movepoints.push_back(std::make_pair(type, id));
    }

    void AttackStart(Unit* target) override
    {
        if (!GetCreatureEluna(me)->AttackStart(me, target))
            NativeScriptedAI::AttackStart(target);
    }

    void EnterEvadeMode() override
    {
        if (!GetCreatureEluna(me)->EnterEvadeMode(me))
            NativeScriptedAI::EnterEvadeMode();
    }

    void JustRespawned() override
    {
        if (!GetCreatureEluna(me)->JustRespawned(me))
            NativeScriptedAI::JustRespawned();
    }

    void JustReachedHome() override
    {
        if (!GetCreatureEluna(me)->JustReachedHome(me))
            NativeScriptedAI::JustReachedHome();
    }

    void ReceiveEmote(Player* player, uint32 emoteId) override
    {
        if (!GetCreatureEluna(me)->ReceiveEmote(me, player, emoteId))
            NativeScriptedAI::ReceiveEmote(player, emoteId);
    }

    void CorpseRemoved(uint32& respawnDelay) override
    {
        if (!GetCreatureEluna(me)->CorpseRemoved(me, respawnDelay))
            NativeScriptedAI::CorpseRemoved(respawnDelay);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!GetCreatureEluna(me)->MoveInLineOfSight(me, who))
            NativeScriptedAI::MoveInLineOfSight(who);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (!GetCreatureEluna(me)->SpellHit(me, caster, spell))
            NativeScriptedAI::SpellHit(caster, spell);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (!GetCreatureEluna(me)->SpellHitTarget(me, target, spell))
            NativeScriptedAI::SpellHitTarget(target, spell);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (!GetCreatureEluna(me)->OnSummoned(me, summoner))
            NativeScriptedAI::IsSummonedBy(summoner);
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) override
    {
        if (!GetCreatureEluna(me)->SummonedCreatureDies(me, summon, killer))
            NativeScriptedAI::SummonedCreatureDies(summon, killer);
    }

    void OwnerAttacked(Unit* target) override
    {
        if (!GetCreatureEluna(me)->OwnerAttacked(me, target))
            NativeScriptedAI::OwnerAttacked(target);
    }

#if !defined ELUNA_TRINITY && !defined ELUNA_AZEROTHCORE
#undef me
#endif
};

#endif
