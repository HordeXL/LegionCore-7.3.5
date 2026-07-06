#ifndef _ELUNA_INSTANCE_DATA_H
#define _ELUNA_INSTANCE_DATA_H

#include "LuaEngine.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"

class ElunaInstanceAI : public InstanceData
{
private:
    std::string lastSaveData;

public:
    ElunaInstanceAI(Map* map) : InstanceData(map ? map->ToInstanceMap() : nullptr) { }

    void Load(const char* data) override { lastSaveData = data ? data : ""; }
    std::string GetSaveData() override { return lastSaveData; }
    uint32 GetData(uint32 key) const override { return 0; }
    void SetData(uint32 key, uint32 value) override { }
    uint64 GetData64(uint32 key) override { return 0; }
    void SetData64(uint32 key, uint64 value) override { }
    void Reload() { }
    void Update(uint32 diff) override { }
    bool IsEncounterInProgress() const override { return false; }
    void OnPlayerEnter(Player* player) override { }
    void OnGameObjectCreate(GameObject* gameobject) override { }
    void OnCreatureCreate(Creature* creature) override { }
};

#endif
