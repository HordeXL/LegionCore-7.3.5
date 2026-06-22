-- ============================================================
-- LegionCore 7.3.5 Hotfix — 2026-06-20
-- 1. 兽栏NPC选项补充
-- 2. 字符集转换后清理（如有必要）
-- ============================================================

-- ------------------------------------------------------------
-- 1. 为缺失的 gossip_menu 添加兽栏选项 (OptionType=14)
-- ------------------------------------------------------------
INSERT IGNORE INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `OptionNpcflag2`, `BoxCurrency`)
VALUES
    -- MenuID 0 已有兽栏选项 (OptionIndex=12)，无需重复添加

    -- MenuID 5283 — 第1个选项
    (5283, 1, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 7889 — 第1个选项
    (7889, 1, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 8805 — 第1个选项
    (8805, 1, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 9212 — 第1个选项
    (9212, 1, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 9499 — 第0个选项
    (9499, 0, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 9572 — 第0个选项
    (9572, 0, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 9821 — 第3个选项（已有 vendor + battle pet heal 在 1, 2）
    (9821, 3, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 9864 — 第0个选项
    (9864, 0, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 12106 — 第2个选项
    (12106, 2, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 14991 — 第3个选项
    (14991, 3, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 21580 — 第3个选项
    (21580, 3, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0),

    -- MenuID 100550 — 第2个选项
    (100550, 2, 0, 'I\'d like to stable my pet here', 14, 4194304, 0, 0, 0, 0, '', 0, 0, 0, 0);

-- ------------------------------------------------------------
-- 2. 检查已有数据表的字符集是否正确
--    如果需要转换所有表中仍为 latin1 的列，请运行下面的查询
--    注意：以下语句会扫描并转换所有数据库的所有剩余 latin1 列
-- ------------------------------------------------------------
/*
SELECT CONCAT(
    'ALTER TABLE `', TABLE_SCHEMA, '`.`', TABLE_NAME, '`',
    ' MODIFY COLUMN `', COLUMN_NAME, '` `', COLUMN_NAME, '` ',
    COLUMN_TYPE, ' CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;'
) AS alter_statement
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA IN ('auth', 'characters', 'world', 'hotfixes')
  AND COLLATION_NAME IS NOT NULL
  AND COLLATION_NAME NOT LIKE 'utf8%'
ORDER BY TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME;
*/
