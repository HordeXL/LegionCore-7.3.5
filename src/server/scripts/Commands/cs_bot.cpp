/*
 * .bot command script for PlayerBot management.
 */

#include "Chat.h"
#include "Group.h"
#include "GroupMgr.h"
#include "PlayerBotMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "World.h"

#ifdef PLAYERBOT

static Classes GetClassByText(std::string text)
{
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    if (text == "zs" || text == "warrior" || text == "1" || text == "战士")
        return Classes::CLASS_WARRIOR;
    if (text == "qs" || text == "paladin" || text == "2" || text == "圣骑士")
        return Classes::CLASS_PALADIN;
    if (text == "lr" || text == "hunter" || text == "3" || text == "猎人")
        return Classes::CLASS_HUNTER;
    if (text == "dz" || text == "rogue" || text == "4" || text == "盗贼")
        return Classes::CLASS_ROGUE;
    if (text == "ms" || text == "priest" || text == "5" || text == "牧师")
        return Classes::CLASS_PRIEST;
    if (text == "dk" || text == "deathknight" || text == "6" || text == "死亡骑士")
        return Classes::CLASS_DEATH_KNIGHT;
    if (text == "sm" || text == "shaman" || text == "7" || text == "萨满")
        return Classes::CLASS_SHAMAN;
    if (text == "fs" || text == "mage" || text == "8" || text == "法师")
        return Classes::CLASS_MAGE;
    if (text == "ss" || text == "warlock" || text == "9" || text == "术士")
        return Classes::CLASS_WARLOCK;
    if (text == "ws" || text == "monk" || text == "10" || text == "武僧")
        return Classes::CLASS_MONK;
    if (text == "xd" || text == "druid" || text == "11" || text == "德鲁伊")
        return Classes::CLASS_DRUID;
    if (text == "dh" || text == "demonhunter" || text == "12" || text == "恶魔猎手")
        return Classes::CLASS_DEMON_HUNTER;
    return Classes::CLASS_NONE;
}

static Player* FindBotPlayerByName(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    SessionMap const& sessions = sWorld->GetAllSessions();
    for (auto const& itr : sessions)
    {
        WorldSession* session = itr.second.get();
        if (!session || !session->IsBotSession())
            continue;
        Player* player = session->GetPlayer();
        if (!player)
            continue;
        std::string playerName = player->GetName();
        std::transform(playerName.begin(), playerName.end(), playerName.begin(), ::tolower);
        if (playerName == name)
            return player;
    }
    return nullptr;
}

static bool AddBotToPlayerGroup(Player* owner, Player* bot)
{
    if (!owner || !bot)
        return false;
    if (owner->GetGUID() == bot->GetGUID())
        return false;
    if (bot->GetGroup() || bot->GetGroupInvite())
        return false;
    if (owner->GetMapId() != bot->GetMapId())
        return false;
    if (owner->GetDistance(bot) > 200.0f)
        return false;

    Group* group = owner->GetGroup();
    if (!group)
    {
        group = new Group();
        group->Create(owner);
        sGroupMgr->AddGroup(group);
    }
    if (group->IsFull())
        return false;
    return group->AddMember(bot);
}

class bot_commandscript : public CommandScript
{
public:
    bot_commandscript() : CommandScript("bot_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> botCommandTable =
        {
            { "team",       SEC_PLAYER,         false,  &HandleBotTeamCommand,        "" },
            { "invite",     SEC_PLAYER,         false,  &HandleBotInviteCommand,      "" },
            { "dismiss",    SEC_PLAYER,         false,  &HandleBotDismissCommand,     "" },
            { "login",      SEC_ADMINISTRATOR,  false,  &HandleBotLoginCommand,       "" },
            { "logout",     SEC_ADMINISTRATOR,  false,  &HandleBotLogoutCommand,      "" },
            { "info",       SEC_ADMINISTRATOR,  false,  &HandleBotInfoCommand,        "" },
            { "max",        SEC_ADMINISTRATOR,  false,  &HandleBotMaxCommand,         "" },
            { "spawn",      SEC_ADMINISTRATOR,  false,  &HandleBotSpawnCommand,       "" },
            { "reload",     SEC_ADMINISTRATOR,  false,  &HandleBotReloadCommand,      "" }
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "bot",        SEC_PLAYER,         false,  NULL,                          "", botCommandTable }
        };
        return commandTable;
    }

    // 玩家级：.bot team [数量] - 快速组队，从附近在线 bot 补齐队伍
    static bool HandleBotTeamCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;

        uint32 targetCount = 5;
        if (*args)
        {
            int n = atoi(args);
            if (n > 0 && n <= 5)
                targetCount = uint32(n);
        }

        Group* group = player->GetGroup();
        uint32 currentCount = group ? group->GetMembersCount() : 1;

        std::vector<std::pair<float, Player*>> candidates;
        SessionMap const& sessions = sWorld->GetAllSessions();
        for (auto const& itr : sessions)
        {
            WorldSession* session = itr.second.get();
            if (!session || !session->IsBotSession())
                continue;
            Player* bot = session->GetPlayer();
            if (!bot || bot->GetGroup() || bot->GetGroupInvite())
                continue;
            if (bot->GetMapId() != player->GetMapId())
                continue;
            if (!bot->isAlive())
                continue;
            float dist = player->GetDistance(bot);
            if (dist > 200.0f)
                continue;
            candidates.push_back({ dist, bot });
        }

        std::sort(candidates.begin(), candidates.end(),
            [](auto const& a, auto const& b) { return a.first < b.first; });

        uint32 added = 0;
        for (auto const& cand : candidates)
        {
            if (currentCount + added >= targetCount)
                break;
            if (AddBotToPlayerGroup(player, cand.second))
                ++added;
        }

        handler->PSendSysMessage("已拉取 %u 个机器人入队（队伍 %u/%u）", added, currentCount + added, targetCount);
        return true;
    }

    // 玩家级：.bot invite <名称> - 邀请指定 bot 入队
    static bool HandleBotInviteCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;
        if (!*args)
            return false;

        std::string name(args);
        Player* bot = FindBotPlayerByName(name);
        if (!bot)
        {
            handler->PSendSysMessage("未找到在线机器人：%s", name.c_str());
            return true;
        }
        if (AddBotToPlayerGroup(player, bot))
            handler->PSendSysMessage("已将机器人 %s 加入队伍", bot->GetName());
        else
            handler->PSendSysMessage("无法将机器人 %s 加入队伍", bot->GetName());
        return true;
    }

    // 玩家级：.bot dismiss - 队伍内所有 bot 离队
    static bool HandleBotDismissCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player)
            return false;
        Group* group = player->GetGroup();
        if (!group)
            return false;

        uint32 dismissed = 0;
        Group::MemberSlotList const& members = group->GetMemberSlots();
        for (Group::MemberSlot const& slot : members)
        {
            if (slot.Guid == player->GetGUID())
                continue;
            Player* member = ObjectAccessor::FindPlayer(slot.Guid);
            if (!member || !member->GetSession() || !member->GetSession()->IsBotSession())
                continue;
            Player::RemoveFromGroup(group, member->GetGUID(), GROUP_REMOVEMETHOD_LEAVE);
            ++dismissed;
        }
        handler->PSendSysMessage("已让 %u 个机器人离队", dismissed);
        return true;
    }

    // GM：.bot login [数量] - 上线机器人到指定数量（无参数 = 补满上限）
    static bool HandleBotLoginCommand(ChatHandler* handler, char const* args)
    {
        if (*args)
        {
            int n = atoi(args);
            if (n > 0)
                sPlayerBotMgr->SetMax(n);
        }
        sPlayerBotMgr->AllPlayerBotRandomLogin();
        handler->PSendSysMessage("已请求机器人上线，当前上限 %d", sPlayerBotMgr->m_MaxOnlineBot);
        return true;
    }

    // GM：.bot logout - 全部机器人下线
    static bool HandleBotLogoutCommand(ChatHandler* handler, char const* args)
    {
        sPlayerBotMgr->AllPlayerBotLogout();
        handler->PSendSysMessage("已请求全部机器人下线");
        return true;
    }

    // GM：.bot info - 查看在线统计
    static bool HandleBotInfoCommand(ChatHandler* handler, char const* args)
    {
        uint32 alliance = sPlayerBotMgr->GetOnlineBotCount(TeamId::TEAM_ALLIANCE, true);
        uint32 horde = sPlayerBotMgr->GetOnlineBotCount(TeamId::TEAM_HORDE, true);
        handler->PSendSysMessage("机器人在线：联盟 %u / 部落 %u / 当前上限 %d",
            alliance, horde, sPlayerBotMgr->m_MaxOnlineBot);
        return true;
    }

    // GM：.bot max <数量> - 设置在线 bot 上限
    static bool HandleBotMaxCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->PSendSysMessage("当前机器人上限：%d", sPlayerBotMgr->m_MaxOnlineBot);
            return true;
        }
        int n = atoi(args);
        if (n <= 0)
            return false;
        sPlayerBotMgr->SetMax(n);
        handler->PSendSysMessage("已设置机器人上限：%d（配置 PlayerBot.MaxOnlineCount 持久生效）", n);
        return true;
    }

    // GM：.bot spawn <职业> - 按职业创建新 bot 角色
    static bool HandleBotSpawnCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;
        Classes prof = GetClassByText(args);
        if (prof == Classes::CLASS_NONE)
        {
            handler->PSendSysMessage("无效职业：%s（支持 zs/qs/lr/dz/ms/dk/sm/fs/ss/ws/xd/dh 或 1-12）", args);
            return true;
        }
        sPlayerBotMgr->AddNewPlayerBotByClass(1, prof);
        handler->PSendSysMessage("已请求创建职业 %u 的机器人", uint32(prof));
        return true;
    }

    // GM：.bot reload - 重新加载 bot 账号/角色信息
    static bool HandleBotReloadCommand(ChatHandler* handler, char const* args)
    {
        sPlayerBotMgr->LoadPlayerBotBaseInfo();
        handler->PSendSysMessage("已重新加载机器人账号/角色信息");
        return true;
    }
};

void AddSC_bot_commandscript()
{
    new bot_commandscript();
}

#endif
