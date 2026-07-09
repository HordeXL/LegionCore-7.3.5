-- Fix quest 40522 "Fate of the Horde" - complete when selecting either gossip option from Sylvanas (NPC 100866)
-- Replaces incomplete smart_scripts from 0005_legion_intro_quest_fixes.sql with full chains for both options

DELETE FROM smart_scripts WHERE entryorguid = 100866 AND source_type = 0;
INSERT INTO smart_scripts (entryorguid, id, link, event_type, event_param1, event_param2, action_type, action_param1, action_param2, action_param3, target_type, `comment`) VALUES
-- Option 0: "As you wish, my lord."
(100866, 1, 2, 62, 19176, 0, 11, 199039, 16, 0, 7, 'Option 0 - Cast Sylvanas Highlord RP'),
(100866, 2, 5, 61, 0, 0, 1, 0, 0, 0, 7, 'Option 0 - Say text'),
(100866, 5, 6, 61, 0, 0, 33, 100541, 0, 0, 7, 'Option 0 - Kill credit 100541'),
(100866, 6, 0, 61, 0, 0, 223, 40522, 0, 0, 7, 'Option 0 - Complete quest 40522'),
-- Option 1: "There are demons among your ranks."
(100866, 3, 4, 62, 19176, 1, 85, 226700, 0, 0, 7, 'Option 1 - Cast demon attack scene'),
(100866, 4, 7, 61, 0, 0, 33, 100541, 0, 0, 7, 'Option 1 - Kill credit 100541'),
(100866, 7, 8, 61, 0, 0, 33, 100552, 0, 0, 7, 'Option 1 - Kill credit 100552'),
(100866, 8, 9, 61, 0, 0, 33, 100934, 0, 0, 7, 'Option 1 - Kill credit 100934'),
(100866, 9, 10, 61, 0, 0, 33, 100985, 0, 0, 7, 'Option 1 - Kill credit 100985'),
(100866, 10, 0, 61, 0, 0, 223, 40522, 0, 0, 7, 'Option 1 - Complete quest 40522');
