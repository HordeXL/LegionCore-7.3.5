-- 为 PLAYERBOT13 ~ PLAYERBOT22 创建角色（账号 id=13~22）
-- 每个账号创建 10 个角色（不同种族/职业），共 100 个角色
-- 使用 world.ai_playerbot_names 中的名称

-- 先获取最大 guid
SET @max_guid = (SELECT COALESCE(MAX(guid), 0) FROM characters.characters);
SET @spawn_x = -8960.0;
SET @spawn_y = 872.0;
SET @spawn_z = 650.0;

-- 账号13: PLAYERBOT13
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 13, 'Llane', 0, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 13, 'Thran', 1, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 13, 'Lyria', 2, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 13, 'GranVivehach', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 13, 'Kelstrum', 4, 4, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 13, 'Dannal', 5, 5, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 13, 'Torm', 6, 6, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 13, 'Sark', 7, 8, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 13, 'Kerra', 8, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 13, 'Harutt', 9, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号14: PLAYERBOT14
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 14, 'Krang', 0, 8, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 14, 'Frang', 1, 8, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 14, 'Tarshaw', 2, 2, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 14, 'Grezz', 3, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 14, 'Sorek', 4, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 14, 'Zelmak', 5, 11, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 14, 'Alyissia', 6, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 14, 'Kyra', 7, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 14, 'Ariasta', 8, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 14, 'Sildanair', 9, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号15: PLAYERBOT15
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 15, 'Christina', 0, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 15, 'Killium', 1, 1, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 15, 'Heldana', 2, 5, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 15, 'Bromm', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 15, 'Kairn', 4, 6, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 15, 'Olga', 5, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 15, 'Hannah', 6, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 15, 'Averan', 7, 4, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 15, 'Jorren', 8, 8, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 15, 'Koreg', 9, 5, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号16: PLAYERBOT16
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 16, 'Mav', 0, 1, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 16, 'Harene', 1, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 16, 'Ellen', 2, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 16, 'Sagart', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 16, 'Kylar', 4, 4, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 16, 'Rendow', 5, 5, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 16, 'Karia', 6, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 16, 'Murg', 7, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 16, 'Arras', 8, 8, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 16, 'Daen', 9, 6, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号17: PLAYERBOT17
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 17, 'Kaleigh', 0, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 17, 'Vesna', 1, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 17, 'Annalise', 2, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 17, 'Marn', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 17, 'Gunter', 4, 8, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 17, 'Harken', 5, 5, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 17, 'Mikka', 6, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 17, 'Kale', 7, 6, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 17, 'Miri', 8, 2, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 17, 'Shao', 9, 11, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号18: PLAYERBOT18
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 18, 'Rillin', 0, 1, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 18, 'Kels', 1, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 18, 'Tosan', 2, 5, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 18, 'Melli', 3, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 18, 'Olana', 4, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 18, 'Brom', 5, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 18, 'Sula', 6, 8, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 18, 'Gloria', 7, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 18, 'Gretta', 8, 6, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 18, 'Kerra', 9, 2, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号19: PLAYERBOT19
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 19, 'Malen', 0, 1, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 19, 'Toryl', 1, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 19, 'Rok', 2, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 19, 'Ael', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 19, 'Veen', 4, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 19, 'Kara', 5, 5, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 19, 'Dorn', 6, 6, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 19, 'Grim', 7, 8, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 19, 'Tess', 8, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 19, 'Lorn', 9, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号20: PLAYERBOT20
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 20, 'Marn', 0, 1, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 20, 'Kylar', 1, 4, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 20, 'Hannah', 2, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 20, 'Brom', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 20, 'Melli', 4, 5, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 20, 'Olana', 5, 8, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 20, 'Sula', 6, 6, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 20, 'Gloria', 7, 2, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 20, 'Gretta', 8, 11, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 20, 'Kerra', 9, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号21: PLAYERBOT21
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 21, 'Malen', 0, 1, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 21, 'Toryl', 1, 4, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 21, 'Rok', 2, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 21, 'Ael', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 21, 'Veen', 4, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 21, 'Kara', 5, 5, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 21, 'Dorn', 6, 6, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 21, 'Grim', 7, 8, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 21, 'Tess', 8, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 21, 'Lorn', 9, 2, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);
SET @max_guid = @max_guid + 10;

-- 账号22: PLAYERBOT22
INSERT INTO characters.characters (guid, account, name, slot, race, class, gender, level, position_x, position_y, position_z, map, taximask, online, created_time, exploredZones, equipmentCache, knownTitles, petslot, specialization) VALUES
(@max_guid+1, 22, 'Marn', 0, 1, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+2, 22, 'Kylar', 1, 4, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+3, 22, 'Hannah', 2, 10, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+4, 22, 'Brom', 3, 3, 1, 0, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+5, 22, 'Melli', 4, 5, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+6, 22, 'Olana', 5, 8, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+7, 22, 'Sula', 6, 6, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+8, 22, 'Gloria', 7, 2, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+9, 22, 'Gretta', 8, 11, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0),
(@max_guid+10, 22, 'Kerra', 9, 1, 1, 1, 110, @spawn_x, @spawn_y, @spawn_z, 0, '', 0, UNIX_TIMESTAMP(), '', '', '', '', 0);