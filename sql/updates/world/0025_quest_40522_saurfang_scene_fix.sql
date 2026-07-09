-- Fix quest 40522 "Fate of the Horde" - Saurfang (NPC 100636) gossip and scene trigger
-- Adds ScriptName to Saurfang and NPC 100442, configures gossip menus and conditions

-- Step 1: Set ScriptName for Saurfang (100636) to trigger scene on gossip
UPDATE creature_template SET ScriptName = 'npc_q40522_saurfang' WHERE entry = 100636;

-- Step 2: Set ScriptName for NPC 100442 (Grommash Hold interior scene trigger)
UPDATE creature_template SET ScriptName = 'npc_q44281_1' WHERE entry = 100442;

-- Step 3: Set ScriptName for Sylvanas (100866) - ensure C++ script is used for quest 40522 gossip
UPDATE creature_template SET ScriptName = 'npc_q40522_sylvanas' WHERE entry = 100866;

-- Step 4: Add gossip menu for Saurfang (100636) during quest 40522
DELETE FROM gossip_menu WHERE Entry = 19116 AND TextID = 28026;
INSERT INTO gossip_menu (Entry, TextID) VALUES (19116, 28026);

-- Step 5: Add gossip menu option for Saurfang - Report to Saurfang
DELETE FROM gossip_menu_option WHERE MenuID = 19116 AND OptionIndex = 0;
INSERT INTO gossip_menu_option (MenuID, OptionIndex, OptionText, OptionBroadcastTextID, OptionType, OptionNpcFlag, ActionMenuID, ActionPoiID, BoxCoded, BoxMoney, BoxText, BoxBroadcastTextID) VALUES
(19116, 0, 'I am ready to enter Grommash Hold.', 0, 1, 1, 0, 0, 0, 0, '', 0);

-- Step 6: Condition for Saurfang gossip option - only show when player has quest 40522
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 15 AND SourceGroup = 19116 AND SourceEntry = 0;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, `Comment`) VALUES
(15, 19116, 0, 0, 0, 9, 0, 40522, 0, 0, 0, 0, '', 'Legion Start Questline - Quest Taken Fate of the Horde');

-- Step 7: Remove old smart_scripts for NPC 100636 (if any were set by mistake)
DELETE FROM smart_scripts WHERE entryorguid = 100636;

-- Step 8: Ensure Saurfang has NPC flag GOSSIP (1) to show gossip icon
UPDATE creature_template SET npcflag = npcflag | 1 WHERE entry = 100636;

-- Step 9: Set NPC 100442 gossip flag to 0 (no gossip, just proximity trigger)
UPDATE creature_template SET npcflag = 0 WHERE entry = 100442;
