-- Fix quest 29422 "Huo, the Spirit of Fire" (上古火灵燧焰)
-- The quest objective was Type 0 (MONSTER/kill) for creature 54787 (Huo),
-- but Huo is a friendly NPC that cannot be killed.
-- 
-- Root cause: Using the quest item (72583) doesn't trigger quest completion
-- because the item's spell data from client DB2 lacks the required
-- SPELL_EFFECT_KILL_CREDIT or SPELL_EFFECT_QUEST_COMPLETE for Huo,
-- and there's no server-side script.
--
-- Fix:
-- 1. Change quest_objective Type from 0 (MONSTER) to 3 (TALKTO)
--    so the quest objective is credited when interacting with Huo.
-- 2. Add SmartAI for Huo that gives quest credit when:
--    a) A spell hits Huo (catches item usage spell, matching retail flow)
--    b) Player talks to Huo (fallback mechanism)

-- Step 1: Change quest_objective from MONSTER(0) to TALKTO(3)
-- In retail: player uses Huo's Offerings on Huo -> quest auto-completes
-- TALKTO lets TalkedToCreature() process the objective when SmartAI gives credit
UPDATE `quest_objectives` SET `Type` = 3 WHERE `ID` = 252007 AND `QuestID` = 29422;

-- Step 2: Enable SmartAI for creature 54787 (Huo)
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 54787;

-- Step 3: Add SmartAI scripts for Huo
-- Entry 1/2: On any spell hit on Huo (e.g. using quest item on targeted Huo),
--            give quest kill credit -> triggers TalkedToCreature -> completes objective
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
(54787, 0, 0, 0, 8, 0, 100, 0, 0, 0, 0, 0, 33, 54787, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Huo - On Spell Hit (any) - Give quest credit for quest 29422'),
-- Entry 2/2: On gossip hello (player talks to Huo), give quest credit as fallback
(54787, 0, 1, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 54787, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Huo - On Gossip Hello (fallback) - Give quest credit for quest 29422');
