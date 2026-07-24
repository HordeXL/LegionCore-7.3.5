-- 将"任务完成卷轴"(物品ID: 200000)添加到所有种族/职业的出生背包
-- race=0, class=0 表示对所有种族和职业生效

DELETE FROM `playercreateinfo_item` WHERE `itemid` = 200000;

INSERT INTO `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`, `BonusListID`)
VALUES (0, 0, 200000, 1, '');
