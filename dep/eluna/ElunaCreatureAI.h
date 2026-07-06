#ifndef _ELUNA_CREATURE_AI_H
#define _ELUNA_CREATURE_AI_H

#include "LuaEngine.h"
#include "ScriptedCreature.h"

struct ElunaCreatureAI : public ScriptedAI
{
    ElunaCreatureAI(Creature* creature) : ScriptedAI(creature) { }
    ~ElunaCreatureAI() { }
    void UpdateAI(uint32 diff) override { }
    void InitializeAI() override { }
    void JustRespawned() override { }
    void JustDied(Unit* killer) override { }
    void EnterCombat(Unit* who) override { }
    void MovementInform(uint32 type, uint32 id) override { }
};

#endif
