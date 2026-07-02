-- Fix quest 12755 "The Bloody Courier" - player should receive disguise buff 53081 on accept
-- NPC 28914 (The Bloody Courier) gives this quest, spell 53081 disguises as Scarlet Courier
DELETE FROM `quest_template_addon` WHERE `ID` = 12755;
INSERT INTO `quest_template_addon` (`ID`, `SourceSpellID`) VALUES (12755, 53081);
