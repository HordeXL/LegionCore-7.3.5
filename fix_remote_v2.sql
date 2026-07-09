-- ============================================================
-- Fix remote LegionCore DB errors (Batch 2)
-- Based on worldserver log analysis
-- ============================================================

-- ============================
-- 1. SMART_SCRIPT FIXES
-- ============================

-- 1a. Delete SmartAI for non-existent creature/GO templates
DELETE FROM smart_scripts WHERE (entryorguid, source_type) IN (
  (68286, 0), (75805, 0), (230253, 0), (268517, 0), (395280, 0), (9956200, 0), (14677644, 0)
);

-- 1b. Fix min/max swapped repeat timer params (repeatMin > repeatMax)
-- 77893: event_param3=1, event_param4=0 → set event_param4=1 (no behavior change)
UPDATE smart_scripts SET event_param4=1 WHERE entryorguid=77893 AND source_type=0 AND id=0 AND event_type=38 AND event_param3=1 AND event_param4=0;
-- 97087: event_param3=5000, event_param4=4300 → swap
UPDATE smart_scripts SET event_param3=4300, event_param4=5000 WHERE entryorguid=97087 AND source_type=0 AND id=2 AND event_type=60 AND event_param3=5000 AND event_param4=4300;
-- 105038: event_param3=120000, event_param4=12000 → swap
UPDATE smart_scripts SET event_param3=12000, event_param4=120000 WHERE entryorguid=105038 AND source_type=0 AND id=0 AND event_type=60 AND event_param3=120000 AND event_param4=12000;
-- 115751: event_param3=6000, event_param4=2000 → swap
UPDATE smart_scripts SET event_param3=2000, event_param4=6000 WHERE entryorguid=115751 AND source_type=0 AND id=0 AND event_type=0 AND event_param3=6000 AND event_param4=2000;
-- 128562: event_param3=16000, event_param4=0 → set event_param4=16000
UPDATE smart_scripts SET event_param4=16000 WHERE entryorguid=128562 AND source_type=0 AND id=0 AND event_type=60 AND event_param3=16000 AND event_param4=0;
-- 128656: event_param3=32000, event_param4=0 → set event_param4=32000
UPDATE smart_scripts SET event_param4=32000 WHERE entryorguid=128656 AND source_type=0 AND id=0 AND event_type=60 AND event_param3=32000 AND event_param4=0;
-- 128657: event_param3=32000, event_param4=0 → set event_param4=32000
UPDATE smart_scripts SET event_param4=32000 WHERE entryorguid=128657 AND source_type=0 AND id=0 AND event_type=60 AND event_param3=32000 AND event_param4=0;

-- 1c. Delete SmartAI for invalid event types (not supported for script type)
DELETE FROM smart_scripts WHERE entryorguid IN (25969, 109105) AND source_type=0 AND event_type=75;
DELETE FROM smart_scripts WHERE entryorguid=100836 AND source_type=0 AND event_type=42;
DELETE FROM smart_scripts WHERE entryorguid IN (241641, 244778) AND source_type=1 AND event_type=73;
DELETE FROM smart_scripts WHERE entryorguid=252158 AND source_type=1 AND event_type=72;
DELETE FROM smart_scripts WHERE entryorguid IN (260270, 267443) AND source_type=1 AND event_type=25;

-- 1d. Delete SmartAI for non-existent spells as action param
DELETE FROM smart_scripts WHERE entryorguid=596 AND source_type=0 AND id=14 AND action_type=11 AND action_param1=6117;
DELETE FROM smart_scripts WHERE entryorguid=1538 AND source_type=0 AND id=0 AND action_type=11 AND action_param1=21562;
DELETE FROM smart_scripts WHERE entryorguid=1910 AND source_type=0 AND id=0 AND action_type=11 AND action_param1=331;
DELETE FROM smart_scripts WHERE entryorguid=3244 AND source_type=0 AND id=1 AND action_type=11 AND action_param1=50285;
DELETE FROM smart_scripts WHERE entryorguid=3246 AND source_type=0 AND id=1 AND action_type=11 AND action_param1=50285;
DELETE FROM smart_scripts WHERE entryorguid=3380 AND source_type=0 AND id=0 AND action_type=11 AND action_param1=689;
DELETE FROM smart_scripts WHERE entryorguid=45196 AND source_type=0 AND id=4 AND action_type=11 AND action_param1=33408;
DELETE FROM smart_scripts WHERE entryorguid=329601 AND source_type=0 AND id=14 AND action_type=11 AND action_param1=6673;
DELETE FROM smart_scripts WHERE entryorguid=34647 AND source_type=0 AND id=0 AND action_type=11 AND action_param1=35290;

-- 1e. Delete SmartAI using spell 0 (null)
DELETE FROM smart_scripts WHERE entryorguid=93926 AND source_type=0 AND id=1 AND action_type=11 AND action_param1=0;
DELETE FROM smart_scripts WHERE entryorguid=111343 AND source_type=0 AND id=2 AND action_type=11 AND action_param1=0;

-- 1f. Fix non-existent items in ADD_ITEM action
DELETE FROM smart_scripts WHERE entryorguid=11832 AND source_type=0 AND id=5 AND action_type=56 AND action_param1=90001;
DELETE FROM smart_scripts WHERE entryorguid=33837 AND source_type=0 AND id=0 AND action_type=56 AND action_param1=1212331;

-- 1g. Fix non-existent spell in trigger spell action
DELETE FROM smart_scripts WHERE entryorguid=20243 AND source_type=0 AND id=9 AND action_type=75 AND action_param1=39311;

-- 1h. Fix maxDist=0 for target_param1 (set to minimum valid distance)
UPDATE smart_scripts SET target_param1=5 WHERE entryorguid=22337 AND source_type=0 AND id=2 AND action_type=49 AND target_param1=0;
UPDATE smart_scripts SET target_param1=5 WHERE entryorguid=93838 AND source_type=0 AND id=4 AND action_type=75 AND target_param1=0;
UPDATE smart_scripts SET target_param1=5 WHERE entryorguid=93839 AND source_type=0 AND id=4 AND action_type=75 AND target_param1=0;
UPDATE smart_scripts SET target_param1=5 WHERE entryorguid=4779000 AND source_type=9 AND id=6 AND action_type=49 AND target_param1=0;
UPDATE smart_scripts SET target_param1=5 WHERE entryorguid=4808000 AND source_type=9 AND id=22 AND action_type=49 AND target_param1=0;

-- 1i. Fix ModelID/CreatureId conflict for MORPH action (clear model param to use creature entry only)
UPDATE smart_scripts SET action_param2=0 WHERE entryorguid=48080 AND source_type=0 AND id=3 AND action_type=3 AND action_param1>0 AND action_param2>0;

-- ============================
-- 2. QUEST ERRORS
-- ============================

-- 2a. Delete quest_offer_reward for non-existent quests
DELETE FROM quest_offer_reward WHERE ID IN (58124, 63771);

-- 2b. Delete quest_template_addon for non-existent quests
DELETE FROM quest_template_addon WHERE ID IN (0, 45222);

-- 2c. Fix ProvidedItemCount=0 → set to 1
UPDATE quest_template_addon SET ProvidedItemCount=1 WHERE ID IN (45761, 48035, 10766, 49077, 12802, 39674, 39655, 10634, 26481, 12755, 25217, 10636, 49846, 11416, 12068, 11414, 10708, 48034, 48065, 48042, 48038, 48027, 48040, 48041, 48039, 48037, 48036, 48029, 48028, 48056, 47750, 45061, 45758, 7061, 45759, 45760, 47745, 45405, 49860, 50338, 50337, 49864, 49813, 48954, 45762, 45755) AND ProvidedItemCount=0;

-- 2d. Fix quest 40817: RewardItem1=0 → set RewardAmount1=0
UPDATE quest_template SET RewardAmount1=0 WHERE ID=40817 AND RewardItem1=0 AND RewardAmount1=1;

-- 2e. Fix quests with RewardCurrencyQty1=0 → set to 1
UPDATE quest_template SET RewardCurrencyQty1=1 WHERE ID IN (33749, 33750) AND RewardCurrencyID1=738 AND RewardCurrencyQty1=0;
UPDATE quest_template SET RewardCurrencyQty1=1 WHERE ID=46179 AND RewardCurrencyID1=6 AND RewardCurrencyQty1=0;

-- 2f. Fix quest 40017: SourceSpellID 40016 doesn't exist
UPDATE quest_template_addon SET SourceSpellID=0 WHERE ID=40017 AND SourceSpellID=40016;

-- 2g. Add Exploration/Event SpecialFlags for quests using SPELL_EFFECT_QUEST_COMPLETE
UPDATE quest_template_addon SET SpecialFlags=SpecialFlags|2 WHERE ID IN (45546, 45636, 46033, 46835, 47956, 47954, 47829, 48064, 47957, 47958, 48030, 48031, 48032, 48033, 48602, 48603, 48937, 60003, 60004, 60005, 60008, 60006);

-- 2h. Fix quest_start_scripts quests missing SpecialFlags
UPDATE quest_template_addon SET SpecialFlags=SpecialFlags|2 WHERE ID IN (14395, 24904, 44106, 24967, 44137, 42370, 37729, 37530, 14276, 14272, 14283, 39733, 40112, 39988, 40388, 40312, 39579, 40216, 38913, 39735, 40568, 39837, 38624, 39864, 39592, 38612, 38613, 38614, 38615, 42371, 14279, 38687, 41763, 42517);

-- 2i. Add repeatable flag for daily quests
UPDATE quest_template_addon SET SpecialFlags=SpecialFlags|1 WHERE ID IN (944172, 944173) AND (SpecialFlags & 1 = 0);

-- 2j. Fix quest_objectives with non-existing spell in ObjectID
UPDATE quest_objectives SET ObjectID=0 WHERE QuestID=25139 AND ObjectID=56641;

-- ============================
-- 3. CREATURE ERRORS
-- ============================

-- 3a. Delete wrong creature_model_info entries (wrong gender for display)
DELETE FROM creature_model_info WHERE DisplayID IN (39360, 21263, 20688, 20698, 39464, 20690, 39949);

-- 3b. Fix creature InhabitType values
UPDATE creature_template SET InhabitType=7 WHERE entry IN (734361, 734363, 734362, 73436, 734360) AND InhabitType=15;
UPDATE creature_template SET InhabitType=3 WHERE entry IN (43717, 43790) AND InhabitType=8;

-- 3c. Fix speed_walk=0 for creature 522111
UPDATE creature_template SET speed_walk=1 WHERE entry=522111 AND speed_walk=0;

-- ============================
-- 4. SCRIPT TEXT ERRORS
-- ============================

-- 4a. Fix creature_text with non-existing BroadcastTextID
DELETE FROM creature_text WHERE Entry=49869 AND GroupID=0 AND ID=0 AND BroadcastTextID=111351;
DELETE FROM creature_text WHERE Entry=99146 AND GroupID=0 AND ID=0 AND BroadcastTextID=199896;

-- 4b. Fix creature_text with invalid Chat Type (100)
DELETE FROM creature_text WHERE Entry=23141 AND GroupID=0 AND `Type`=100;

-- 4c. Fix creature_text with invalid Emote
UPDATE creature_text SET Emote=0 WHERE Entry=58202 AND Emote=100;
UPDATE creature_text SET Emote=0 WHERE Entry=58785 AND GroupID=1 AND Emote=31005;
UPDATE creature_text SET Emote=0 WHERE Entry=58785 AND GroupID=2 AND Emote=31007;
UPDATE creature_text SET Emote=0 WHERE Entry=58785 AND GroupID=3 AND Emote=31025;
UPDATE creature_text SET Emote=0 WHERE Entry=58785 AND GroupID=4 AND Emote=31009;
UPDATE creature_text SET Emote=0 WHERE Entry=58785 AND GroupID=5 AND Emote=31025;

-- 4d. Fix creature_text with non-existing SpellID
UPDATE creature_text SET SpellID=0 WHERE Entry=79902 AND GroupID=2 AND ID=0 AND SpellID=155163;
UPDATE creature_text SET SpellID=0 WHERE Entry=85137 AND GroupID=2 AND ID=0 AND SpellID=155163;

-- ============================
-- 5. LOOT ERRORS
-- ============================

-- 5a. Fix reference_loot_template broken references
DELETE FROM reference_loot_template WHERE Entry IN (24070, 86279, 35041);

-- 5b. Fix gameobject_loot_template currency with group set
UPDATE gameobject_loot_template SET groupid=0 WHERE Entry=40870 AND Item=138623;

-- 5c. Delete broken item_loot_template currency entry
DELETE FROM item_loot_template WHERE Entry=119000 AND Item=392;

-- ============================
-- 6. GOSSIP ERRORS
-- ============================

-- 6a. Fix gossip_menu_option icon/handler mismatches
-- GOSSIP_ICON_SHIPMENT (=28) → OptionType should be GOSSIP_OPTION_GARRISON_SHIPMENT (=22)
UPDATE gossip_menu_option SET OptionType=22 WHERE OptionNPC=28 AND OptionType!=22;
-- GOSSIP_ICON_CLASS_HALL_UPGRADE (=32) → OptionType should be GOSSIP_OPTION_CLASS_HALL_UPGRADE (=25)
UPDATE gossip_menu_option SET OptionType=25 WHERE OptionNPC=32 AND OptionType!=25;

-- ============================
-- 7. CONDITION ERRORS
-- ============================

-- 7a. Delete zoneID conditions using subzone instead of zone
DELETE FROM conditions WHERE ConditionTypeOrReference=23 AND ConditionValue1 IN (6457, 5287) AND ConditionValue2 IN (6457, 5287);

-- 7b. Delete conditions with non-existing event
DELETE FROM conditions WHERE ConditionTypeOrReference=12 AND ConditionValue1=327;

-- ============================
-- 8. SPELL PROC ERRORS
-- ============================

-- 8a. Fix spell_proc missing spellPhaseMask for required typeMask
UPDATE spell_proc SET spellPhaseMask=1 WHERE spellId IN (209493, 206333, 209706, 208081, 198300, 164545, 164547, 213708) AND spellPhaseMask=0;

-- 8b. Delete invalid spell_proc entry 216974 (missing chance, ratePerMinute, typeMask)
DELETE FROM spell_proc WHERE spellId=216974;

-- ============================
-- 9. OTHER ERRORS
-- ============================

-- 9a. Fix lfg_entrances wrong dungeon coordinates
DELETE FROM lfg_entrances WHERE dungeonId=852;

-- 9b. Fix Pool Id 10150 and 10153 (broken child pools of 9901)
DELETE FROM pool_pool WHERE pool_id IN (10150, 10153);

-- 9c. Fix event_scripts with unsupported gameobject types (RESPAWN_GAMEOBJECT command=17)
DELETE FROM event_scripts WHERE id IN (11424, 13666) AND command=17;

-- 9d. Fix spell_scripts with non-SCRIPT_EFFECT spell (effect 0 is not SCRIPT_EFFECT)
DELETE FROM spell_scripts WHERE id=179915 AND effIndex=0;

-- 9e. Fix gossip_menu_option with non-existing action_poi_id
DELETE FROM gossip_menu_option WHERE MenuID=19634 AND OptionIndex=0 AND ActionPoiID=19637;
