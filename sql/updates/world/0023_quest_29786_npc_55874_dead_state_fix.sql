-- Fix NPC 55874 (Zhao-Ren's corpse) appearing alive and attacking after quest 29786 "Battle for the Skies"
-- Phase 8 spawn of Zhao-Ren's dead body shows after the boss fight (phase 4 -> phase 8)
-- 
-- Problems:
-- 1. faction=14 (neutral/hostile) -> attacks players
-- 2. No creature_template_addon -> default bytes1=0 (standing alive visual)
-- 3. unit_flags3=0 -> no feign death visual
-- 4. No flags to prevent interaction
--
-- Required fixes:
-- 1. faction=35 (friendly NPC, won't attack)
-- 2. Add creature_template_addon with bytes1=7 (UNIT_STAND_STATE_DEAD)
-- 3. Set unit_flags3=0x2000 (UNIT_FLAG3_FEIGN_DEATH) for death visual
-- 4. Set unit_flags to include NON_ATTACKABLE | IMMUNE_TO_PC/IMMUNE_TO_NPC | NOT_SELECTABLE

-- Step 1: Update creature_template - change faction and flags
UPDATE `creature_template` 
SET `faction` = 35,
    `unit_flags` = `unit_flags` | 0x02000302,  -- NOT_SELECTABLE(0x02000000) | IMMUNE_TO_PC(0x00000100) | IMMUNE_TO_NPC(0x00000200) | NON_ATTACKABLE(0x00000002)
    `unit_flags3` = `unit_flags3` | 0x00002000  -- UNIT_FLAG3_FEIGN_DEATH
WHERE `entry` = 55874;

-- Step 2: Add/Update creature_template_addon - set dead stand state
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`)
VALUES (55874, 0, 0, 7, 0, 0, '')
ON DUPLICATE KEY UPDATE `bytes1` = 7, `bytes2` = 0, `emote` = 0;
