-- 为 playerbot 账号创建角色
-- 每个账号创建2个角色：联盟(战士class=1)和部落(战士class=1)
-- 后续机器人会自动创建更多角色

-- 先获取最大guid
SET @max_guid = (SELECT COALESCE(MAX(guid), 0) FROM characters.characters);

-- playerbot1 (id=3) 创建角色
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 3, 'Bot1A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 3, 'Bot1B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot2 (id=4)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 4, 'Bot2A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 4, 'Bot2B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot3 (id=5)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 5, 'Bot3A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 5, 'Bot3B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot4 (id=6)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 6, 'Bot4A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 6, 'Bot4B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot5 (id=7)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 7, 'Bot5A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 7, 'Bot5B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot6 (id=8)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 8, 'Bot6A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 8, 'Bot6B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot7 (id=9)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 9, 'Bot7A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 9, 'Bot7B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot8 (id=10)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 10, 'Bot8A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 10, 'Bot8B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot9 (id=11)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 11, 'Bot9A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 11, 'Bot9B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');
SET @max_guid = @max_guid + 2;

-- playerbot10 (id=12)
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, playerFlags, position_x, position_y, position_z, map, instance_id, orientation, taximask, online, cinematic, totaltime, leveltime, created_time, logout_time, extra_flags, at_login, zone, death_expire_time, health, mana, latency, exploredZones, equipmentCache, knownTitles, actionBars, petslot)
VALUES
(@max_guid+1, 12, 'Bot10A1', 0, 1, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, ''),
(@max_guid+2, 12, 'Bot10B1', 1, 2, 1, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8960, 872, 650, 0, 0, 0, '', 0, 0, 0, 0, UNIX_TIMESTAMP(), 0, 0, 0, 0, 0, 100, 0, 0, '', '', '', 0, '');