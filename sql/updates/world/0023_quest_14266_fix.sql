-- Quest 14266 fix: use Charge on Bloodfang Worgen (35118) to complete without killing
-- Requires C++ change in gilneas.cpp: npc_rampaging_worgenAI::SpellHit gives KilledMonsterCredit(35118) for quest 14266

-- Update the monster objective from Practice Target (44175) to Bloodfang Worgen (35118)
UPDATE `quest_objectives` SET `ObjectID` = 35118 WHERE `ID` = 263471 AND `QuestID` = 14266;

-- Remove auto-complete start scripts (7 SCRIPT_COMMAND_QUEST_EXPLORED entries)
DELETE FROM `quest_start_scripts` WHERE `id` = 14266;

-- Clear StartScript reference in quest_template
UPDATE `quest_template` SET `StartScript` = 0 WHERE `ID` = 14266;
