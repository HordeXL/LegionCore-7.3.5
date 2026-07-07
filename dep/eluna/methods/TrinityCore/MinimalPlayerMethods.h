#ifndef MINIMALPLAYERMETHODS_H
#define MINIMALPLAYERMETHODS_H

#include "GossipDef.h"

namespace LuaPlayer
{
    int GossipMenuAddItem(Eluna* E, Player* player)
    {
        uint32 _icon = E->CHECKVAL<uint32>(2);
        const char* msg = E->CHECKVAL<const char*>(3);
        uint32 _sender = E->CHECKVAL<uint32>(4);
        uint32 _intid = E->CHECKVAL<uint32>(5);
        bool _code = E->CHECKVAL<bool>(6, false);
        const char* _promptMsg = E->CHECKVAL<const char*>(7, "");
        uint32 _money = E->CHECKVAL<uint32>(8, 0);

        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, uint8(_icon), msg, _sender, _intid, _promptMsg, _money, 0, _code);
        return 0;
    }

    int GossipComplete(Eluna* /*E*/, Player* player)
    {
        player->PlayerTalkClass->SendCloseGossip();
        return 0;
    }

    int GossipSendMenu(Eluna* E, Player* player)
    {
        uint32 npc_text = E->CHECKVAL<uint32>(2);
        Object* sender = E->CHECKOBJ<Object>(3);
        if (sender->GetTypeId() == TYPEID_PLAYER)
        {
            uint32 menu_id = E->CHECKVAL<uint32>(4);
            player->PlayerTalkClass->GetGossipMenu().SetMenuId(menu_id);
        }

        player->PlayerTalkClass->SendGossipMenu(npc_text, sender->GET_GUID());
        return 0;
    }

    int GossipClearMenu(Eluna* /*E*/, Player* player)
    {
        player->PlayerTalkClass->ClearMenus();
        return 0;
    }

    int Teleport(Eluna* E, Player* player)
    {
        uint32 mapId = E->CHECKVAL<uint32>(2);
        float x = E->CHECKVAL<float>(3);
        float y = E->CHECKVAL<float>(4);
        float z = E->CHECKVAL<float>(5);
        float o = E->CHECKVAL<float>(6);

        player->SaveRecallPosition();

        E->Push(player->TeleportTo(mapId, x, y, z, o));
        return 1;
    }

    ElunaRegister<Player> PlayerMethods[] =
    {
        { "GossipMenuAddItem", &LuaPlayer::GossipMenuAddItem },
        { "GossipComplete", &LuaPlayer::GossipComplete },
        { "GossipSendMenu", &LuaPlayer::GossipSendMenu },
        { "GossipClearMenu", &LuaPlayer::GossipClearMenu },
        { "Teleport", &LuaPlayer::Teleport },
    };
};
#endif
