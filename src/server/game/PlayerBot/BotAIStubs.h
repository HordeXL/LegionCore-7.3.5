#ifndef BOT_AI_STUBS_H
#define BOT_AI_STUBS_H

// Full stub definitions for AI classes when PLAYERBOT_AI=0
// These are ONLY included when the real AI headers are not available

#include "Player.h"
#include "UnitAI.h"

class BotFieldAI : public UnitAI {
public:
    static BotFieldAI* CreateBotFieldAIByPlayerClass(Player*) { return nullptr; }
    void SetDrivingPVP(bool) {}
    void SetWarfareTarget(Unit*) {}
    void SetCruxMovement(Position&) {}
    bool HasTeleport() { return false; }
    explicit BotFieldAI(Player* player) : UnitAI(player) {}
};

class BotGroupAI : public UnitAI {
public:
    static BotGroupAI* CreateBotGroupAIByPlayerClass(Player*) { return nullptr; }
    explicit BotGroupAI(Player* player) : UnitAI(player) {}
    bool HasTeleport() { return false; }
    void UpdateTeleport(uint32) {}
    void SetTeleportToMaster(bool) {}
    void SetTeleportToMaster() {}
};

class BotDuelAI : public UnitAI {
public:
    static BotDuelAI* CreateBotDuelAIByPlayerClass(Player*) { return nullptr; }
    void ResetBotAI() {}
    explicit BotDuelAI(Player* player) : UnitAI(player) {}
};

class BotArenaAI : public UnitAI {
public:
    static BotArenaAI* CreateBotArenaAIByPlayerClass(Player*) { return nullptr; }
    explicit BotArenaAI(Player* player) : UnitAI(player) {}
};

class BotBGAI : public UnitAI {
public:
    static BotBGAI* CreateBotBGAIByPlayerClass(Player*) { return nullptr; }
    explicit BotBGAI(Player* player) : UnitAI(player) {}
};

class BotBGAIMovement {
public:
    void MovementTo(float, float, float) {}
};

class BotUtility {
public:
    static void RemoveArenaBotSpellsByPlayer(Player*) {}
};

class BotAITeleport {
public:
    void SetTeleport(Player*, float) {}
    void SetTeleport(uint32, Position&) {}
    void Update(uint32, BotBGAIMovement*) {}
};

class AIWaypointsMgr;
class PlayerBotTalkMgr;
class FieldBotMgr;
class PlayerBotSetting;

#endif // BOT_AI_STUBS_H
