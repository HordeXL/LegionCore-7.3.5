-- =============================================
-- Comprehensive Fix Script for Remote Server
-- =============================================

-- 1. DELETE smart_scripts with entryorguid=0 (creature entry 0 doesn't exist)
DELETE FROM smart_scripts WHERE entryorguid=0 AND source_type=0;

-- 2. FIX infinite loop: 1519 source_type=10, id=1 linking to self
UPDATE smart_scripts SET link=2 WHERE entryorguid=1519 AND source_type=10 AND id=1;

-- 3. FIX infinite loop: 101846 source_type=0, id=18 linking to self (link=18 -> link=19)
UPDATE smart_scripts SET link=19 WHERE entryorguid=101846 AND source_type=0 AND id=18;

-- 4. DELETE invalid action types (0 and 255)
DELETE FROM smart_scripts WHERE entryorguid=80140 AND source_type=0 AND id=0;
DELETE FROM smart_scripts WHERE entryorguid=91892 AND source_type=0 AND id=1;
DELETE FROM smart_scripts WHERE entryorguid=108326 AND source_type=0 AND id=0;

-- 5. FIX min/max params swapped: swap event_param1/event_param2 when min > max for UPDATE_IC/OOC/UPDATE/HEALT_PCT
-- 79490 id=7 event_type=0 (UPDATE_IC) event_param1=4 event_param2=0
UPDATE smart_scripts SET event_param1=0, event_param2=4 WHERE entryorguid=79490 AND source_type=0 AND id=7;
-- 95834 id=2 event_type=60 (UPDATE) event_param1=1000 event_param2=0
UPDATE smart_scripts SET event_param1=0, event_param2=1000 WHERE entryorguid=95834 AND source_type=0 AND id=2;
-- 95842 id=2 event_type=60 (UPDATE) event_param1=3000 event_param2=0
UPDATE smart_scripts SET event_param1=0, event_param2=3000 WHERE entryorguid=95842 AND source_type=0 AND id=2;
-- 97087 id=2 event_type=60 (UPDATE) event_param1=500 event_param2=0
UPDATE smart_scripts SET event_param1=0, event_param2=500 WHERE entryorguid=97087 AND source_type=0 AND id=2;
-- 395820 id=4 event_type=0 (UPDATE_IC) event_param1=8000 event_param2=1000
UPDATE smart_scripts SET event_param1=1000, event_param2=8000 WHERE entryorguid=395820 AND source_type=0 AND id=4;
-- 14677644 id=0 event_type=0 (UPDATE_IC) event_param1=400 event_param2=0
UPDATE smart_scripts SET event_param1=0, event_param2=400 WHERE entryorguid=14677644 AND source_type=0 AND id=0;

-- 6. FIX min/max for source_type=9 entries
-- 111357 id=2 event_param1=10000 event_param2=1000 (event UPDATE_IC)
UPDATE smart_scripts SET event_param1=1000, event_param2=10000 WHERE entryorguid=111357 AND source_type=9 AND id=2;
-- 2977500 id=10 event_type=19 (ACCEPTED_QUEST) event_param1=2000 event_param2=200
UPDATE smart_scripts SET event_param1=200, event_param2=2000 WHERE entryorguid=2977500 AND source_type=9 AND id=10;
-- 4460800 id=0 event_type=0 (UPDATE_IC) event_param1=2000 event_param2=1000
UPDATE smart_scripts SET event_param1=1000, event_param2=2000 WHERE entryorguid=4460800 AND source_type=9 AND id=0;
-- 11555700 id=8 event_type=0 (UPDATE_IC) event_param1=8000 event_param2=5000
UPDATE smart_scripts SET event_param1=5000, event_param2=8000 WHERE entryorguid=11555700 AND source_type=9 AND id=8;
-- 11005194 id=0 event_type=0 action_type=5 event_param1=4000 event_param2=3000
UPDATE smart_scripts SET event_param1=3000, event_param2=4000 WHERE entryorguid=11005194 AND source_type=9 AND id=0;
-- 11005194 id=3 event_type=0 action_type=5 event_param1=5000 event_param2=4000
UPDATE smart_scripts SET event_param1=4000, event_param2=5000 WHERE entryorguid=11005194 AND source_type=9 AND id=3;
-- 11005194 id=4 event_type=0 action_type=11 event_param1=7000 event_param2=4000
UPDATE smart_scripts SET event_param1=4000, event_param2=7000 WHERE entryorguid=11005194 AND source_type=9 AND id=4;
-- 11005194 id=5 event_type=0 action_type=11 event_param1=5000 event_param2=4000
UPDATE smart_scripts SET event_param1=4000, event_param2=5000 WHERE entryorguid=11005194 AND source_type=9 AND id=5;
-- 11005224 id=0 event_type=0 action_type=11 event_param1=6000 event_param2=2000
UPDATE smart_scripts SET event_param1=2000, event_param2=6000 WHERE entryorguid=11005224 AND source_type=9 AND id=0;
-- 11005224 id=1 event_type=0 action_type=11 event_param1=9000 event_param2=4000
UPDATE smart_scripts SET event_param1=4000, event_param2=9000 WHERE entryorguid=11005224 AND source_type=9 AND id=1;
-- 11005224 id=2 event_type=0 action_type=11 event_param1=8000 event_param2=2000
UPDATE smart_scripts SET event_param1=2000, event_param2=8000 WHERE entryorguid=11005224 AND source_type=9 AND id=2;
-- 11005224 id=3 event_type=0 action_type=11 event_param1=9000 event_param2=4000
UPDATE smart_scripts SET event_param1=4000, event_param2=9000 WHERE entryorguid=11005224 AND source_type=9 AND id=3;
-- 11005239 id=1 event_type=0 action_type=11 event_param1=8000 event_param2=6000
UPDATE smart_scripts SET event_param1=6000, event_param2=8000 WHERE entryorguid=11005239 AND source_type=9 AND id=1;
-- 11005239 id=2 event_type=0 action_type=11 event_param1=6000 event_param2=5000
UPDATE smart_scripts SET event_param1=5000, event_param2=6000 WHERE entryorguid=11005239 AND source_type=9 AND id=2;
-- 11005239 id=3 event_type=0 action_type=11 event_param1=12000 event_param2=4000
UPDATE smart_scripts SET event_param1=4000, event_param2=12000 WHERE entryorguid=11005239 AND source_type=9 AND id=3;
-- 11005273 id=1 event_type=0 action_type=11 event_param1=3000 event_param2=2000
UPDATE smart_scripts SET event_param1=2000, event_param2=3000 WHERE entryorguid=11005273 AND source_type=9 AND id=1;
-- 11005273 id=4 event_type=0 action_type=5 event_param1=4000 event_param2=2000
UPDATE smart_scripts SET event_param1=2000, event_param2=4000 WHERE entryorguid=11005273 AND source_type=9 AND id=4;

-- 7. FIX maxDist=0 issues (target_param1 for SMART_TARGET_CREATURE_DISTANCE etc.)
-- 22337 id=2 event_type=54 (JUST_SUMMONED) action_type=49 (ATTACK) target_type=?? 
-- The issue is target_param1=0 for ATTACK_INVOKER - set default value
-- 93838/93839: target_param1 maxDist issues - entries have action_type=75 with maxDist=0
-- These need target_type/target_param adjustments

-- 8. FIX quest_template_addon SpecialFlags for exploration/event quests
UPDATE quest_template_addon SET SpecialFlags = SpecialFlags | 2 WHERE ID IN (26232, 29100, 29219, 30515, 38035, 46213, 46941);
-- For quests without addon entry, insert one
INSERT IGNORE INTO quest_template_addon (ID, SpecialFlags) VALUES (45222, 2);

-- 9. DELETE script_texts entries that conflict with creature_text (duplicate entry IDs)
-- Remove specific creature entries that have same IDs as global entries
DELETE FROM script_texts WHERE entry IN (-1000001, -1000002, -1000003, -1000004, -1000005) AND npc_entry = 49869;
-- Remove duplicate entries for Drakos (27654) conflicts with Urom (27655)
DELETE FROM script_texts WHERE entry IN (-1578000, -1578001, -1578002, -1578003, -1578004) AND npc_entry = 27655;
DELETE FROM script_texts WHERE entry IN (-1578012, -1578013, -1578014, -1578015, -1578016) AND npc_entry = 27654;
-- Remove duplicate entries for Anvilward (15420) conflicts with npc_entry=0
DELETE FROM script_texts WHERE entry IN (-1000209, -1000210) AND npc_entry = 0;
-- Remove duplicate entries for DK Initiate (28406) conflicts with Special Surprise (29032)
DELETE FROM script_texts WHERE entry IN (-1609080, -1609081, -1609082, -1609083, -1609084, -1609085, -1609086, -1609087) AND npc_entry = 28406;
