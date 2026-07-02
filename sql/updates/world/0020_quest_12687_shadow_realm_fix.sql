-- Fix quest 12687 "Into the Realm of Shadows" - auto-enter Shadow Realm on accept
-- NPC 28653 (Death Knight Initiate) gossip to re-enter Shadow Realm
UPDATE `creature_template` SET `ScriptName` = 'npc_dk_shadow_realm_initiate' WHERE `entry` = 28653;
