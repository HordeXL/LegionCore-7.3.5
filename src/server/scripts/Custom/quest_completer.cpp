/*
 * 任务完成卷轴 — Quest Completer Item
 * 右键点击列出所有未完成的任务，选择后自动完成并发放奖励
 */

#include "ScriptMgr.h"
#include "GossipDef.h"
#include "Player.h"
#include "Item.h"
#include "QuestData.h"
#include "QuestDef.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"
#include "Log.h"

// 物品 ID
#define QUEST_COMPLETER_ITEM_ENTRY    200000

// Gossip 动作定义
#define GOSSIP_ACTION_NEVERMIND       (GOSSIP_ACTION_INFO_DEF + 1)

class item_quest_completer : public ItemScript
{
public:
    item_quest_completer() : ItemScript("item_quest_completer") { }

    // 阶段 1: 右键点击物品 — 构建 Gossip 菜单
    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/) override
    {
        if (!player || !item)
            return false;

        // 战斗中不可用
        if (player->isInCombat())
        {
            player->GetSession()->SendNotification("你处于战斗状态!");
            return true;
        }

        // 清空之前的菜单
        player->PlayerTalkClass->ClearMenus();

        // 遍历任务日志插槽，收集未完成的任务
        uint32 questCount = 0;
        for (uint8 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
        {
            uint32 questId = player->GetQuestSlotQuestId(i);
            if (questId == 0)
                continue;

            if (player->GetQuestStatus(questId) != QUEST_STATUS_INCOMPLETE)
                continue;

            // 跳过不存在的任务模板
            Quest const* quest = sQuestDataStore->GetQuestTemplate(questId);
            if (!quest)
                continue;

            // 添加 Gossip 选项
            player->PlayerTalkClass->GetGossipMenu().AddMenuItem(
                -1,                                         // menuItemId (auto)
                GOSSIP_ICON_DOT,                            // 图标
                quest->LogTitle,                            // 任务名称
                0,                                          // sender
                questId,                                    // action = questId
                "",                                         // boxMessage
                0                                           // boxMoney
            );

            ++questCount;
        }

        // 没有未完成的任务
        if (questCount == 0)
        {
            player->PlayerTalkClass->SendCloseGossip();
            player->GetSession()->SendNotification("你没有未完成的任务!");
            return true;
        }

        // 添加"取消"选项
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(
            -1,
            GOSSIP_ICON_DOT,
            "Nevermind",
            0,
            GOSSIP_ACTION_NEVERMIND,
            "",
            0
        );

        // 发送 Gossip 菜单给玩家
        player->PlayerTalkClass->SendGossipMenu(
            1,                                              // titleTextId (默认)
            item->GetGUID()                                 // objectGUID (物品)
        );

        return true;
    }

    // 阶段 2: 从 Gossip 菜单选择任务
    bool OnGossipSelect(Player* player, Item* item, uint32 /*sender*/, uint32 action) override
    {
        if (!player || !item)
            return false;

        // 选择"取消"
        if (action == GOSSIP_ACTION_NEVERMIND)
        {
            player->PlayerTalkClass->SendCloseGossip();
            return true;
        }

        uint32 questId = action;

        // 验证任务存在且玩家确实处于未完成状态
        Quest const* quest = sQuestDataStore->GetQuestTemplate(questId);
        if (!quest || player->GetQuestStatus(questId) != QUEST_STATUS_INCOMPLETE)
        {
            player->PlayerTalkClass->SendCloseGossip();
            player->GetSession()->SendNotification("未找到该任务或任务已完成!");
            return true;
        }

        // 完成该任务 (标记所有目标已完成)
        player->CompleteQuest(questId);

        // 发放奖励
        player->RewardQuest(quest, 0, player, true);

        // 记录日志
        LogQuestCompletion(player, quest);

        // 通知玩家
        player->GetSession()->SendNotification("任务「%s」已完成!", quest->LogTitle.c_str());

        // 关闭菜单
        player->PlayerTalkClass->SendCloseGossip();

        return true;
    }

private:
    // 阶段 3: 记录任务完成日志
    void LogQuestCompletion(Player* player, Quest const* quest)
    {
        if (!player || !quest)
            return;

        uint32 questId = quest->GetQuestId();

        // 查询任务领取 NPC
        uint32 questGiverNpc = sQuestDataStore->GetQuestStarterCreature(questId);

        // 查询交任务 NPC
        uint32 questTurninNpc = 0;
        {
            QuestRelationBounds bounds = sQuestDataStore->GetCreatureQuestInvolvedRelationBoundsByQuest(questId);
            if (bounds.first != bounds.second)
                questTurninNpc = bounds.first->second;
        }

        // 拼接任务目标描述
        std::string objectivesStr;
        for (auto const& objective : quest->GetObjectives())
        {
            if (!objective.Description.empty())
            {
                if (!objectivesStr.empty())
                    objectivesStr += "; ";
                objectivesStr += objective.Description;
            }
        }

        // 检测玩家阵营
        std::string faction = (player->GetTeamId() == TEAM_ALLIANCE) ? "联盟" : "部落";

        // 检查是否已记录过 (去重)
        bool alreadyLogged = false;
        {
            auto result = WorldDatabase.PQuery(
                "SELECT `id` FROM `任务完成记录` WHERE `quest_id` = %u LIMIT 1",
                questId
            );
            if (result && result->Fetch())
                alreadyLogged = true;
        }

        if (!alreadyLogged)
        {
            WorldDatabase.PExecute(
                "INSERT INTO `任务完成记录` (`quest_id`, `quest_name`, `quest_giver_npc`, `quest_objectives`, `quest_turnin_npc`, `player_name`, `faction`) "
                "VALUES (%u, '%s', %u, '%s', %u, '%s', '%s')",
                questId,
                quest->LogTitle.c_str(),
                questGiverNpc,
                objectivesStr.c_str(),
                questTurninNpc,
                player->GetName(),
                faction.c_str()
            );
        }
    }
};

void AddSC_quest_completer()
{
    new item_quest_completer();
}