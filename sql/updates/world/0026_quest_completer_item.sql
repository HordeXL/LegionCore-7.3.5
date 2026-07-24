-- 任务完成卷轴 — 物品脚本绑定
-- 物品数据来自 DB2 + item_template 表补充
-- 注意：item_template 表在服务端启动时被读取，用于创建 DB2 中不存在的自定义物品

DELETE FROM `item_script_names` WHERE `Id` = 200000;

INSERT INTO `item_script_names` (`Id`, `ScriptName`)
VALUES (200000, 'item_quest_completer');

-- 物品模板数据（供 ObjectMgr::LoadItemTemplates 中的自定义加载逻辑使用）
-- 当物品 ID 200000 不在 DB2 中时，服务端会从下面这条记录创建物品数据
DELETE FROM `item_template` WHERE `entry` = 200000;

INSERT INTO `item_template` (`entry`, `class`, `name`, `displayid`, `Quality`, `Flags`, `Flags2`,
    `BuyCount`, `BuyPrice`, `SellPrice`, `InventoryType`, `AllowableClass`, `AllowableRace`,
    `ItemLevel`, `RequiredLevel`, `maxcount`, `stackable`, `Material`)
VALUES (200000, 0, '任务完成卷轴', 44462, 5, 0, 0, 1, 0, 0, 0, -1, -1, 1, 1, 0, 1, 0);