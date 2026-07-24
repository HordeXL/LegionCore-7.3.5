-- ============================================================================
-- Fix: Anduin (100429) gossip option completes quest 40517
-- C++ Script: npc_100429_anduin_dh_questline
-- ============================================================================

-- Set C++ ScriptName
UPDATE `creature_template` SET `ScriptName` = 'npc_100429_anduin_dh_questline' WHERE `entry` = 100429;

-- Remove all gossip-select smart_scripts (handled by C++ now)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 100429 AND `event_type` = 62;

-- Register Anduin as quest ender for quest 40517
DELETE FROM `creature_questender` WHERE `id` = 100429 AND `quest` = 40517;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (100429, 40517);

-- Conditions for gossip OptionIndex 0 (letter): show when quest 40517 is active
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 19075 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 19075, 0, 0, 0, 9, 0, 40517, 0, 0, 0, 0, '', 'Legion Start Questline - Incomplete Quest (40517) Speedbarge Dive'),
(15, 19075, 0, 0, 0, 41, 0, 40517, 111585, 1, 1, 0, '', 'Legion Start Questline - Not yet warned Anduin for Quest (40517) Speedbarge Dive');

-- ============================================================================
-- Fix: Allari (100675) gossip option triggers scene for quest 40593
-- C++ Script: npc_100675_allari_quest_40593
-- ============================================================================

-- Set C++ ScriptName
UPDATE `creature_template` SET `ScriptName` = 'npc_100675_allari_quest_40593' WHERE `entry` = 100675;

-- Remove old smart_scripts (handled by C++ now)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 100675;
