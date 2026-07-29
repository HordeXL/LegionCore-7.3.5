/*
 Navicat Premium Dump SQL

 Source Server         : LegionCore
 Source Server Type    : MySQL
 Source Server Version : 50732 (5.7.32)
 Source Host           : localhost:3304
 Source Schema         : auth

 Target Server Type    : MySQL
 Target Server Version : 50732 (5.7.32)
 File Encoding         : 65001

 Date: 28/07/2026 15:26:38
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for account
-- ----------------------------
DROP TABLE IF EXISTS `account`;
CREATE TABLE `account`  (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `username` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `sha_pass_hash` varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `sessionkey` varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `v` varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `s` varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `email` varchar(254) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '127.0.0.1',
  `first_ip` varchar(15) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '127.0.0.1',
  `access_ip` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `failed_logins` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `email_blocked` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `locked` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `lock_country` varchar(2) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '00',
  `last_login` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `last_email` timestamp NULL DEFAULT NULL,
  `online` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `expansion` tinyint(3) UNSIGNED NOT NULL DEFAULT 6,
  `mutetime` bigint(20) NOT NULL DEFAULT 0,
  `locale` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `os` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `recruiter` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `invite` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `lang` enum('tw','cn','en','ua','ru') CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT 'en',
  `referer` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `unsubscribe` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0',
  `dt_vote` timestamp NULL DEFAULT NULL,
  `mutereason` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `muteby` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `AtAuthFlag` smallint(3) UNSIGNED NOT NULL DEFAULT 0,
  `coins` int(11) NOT NULL DEFAULT 0,
  `hwid` bigint(20) UNSIGNED NOT NULL DEFAULT 0,
  `balans` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `karma` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `activate` tinyint(1) UNSIGNED NOT NULL DEFAULT 1,
  `verify` tinyint(1) UNSIGNED NOT NULL DEFAULT 0,
  `tested` tinyint(1) UNSIGNED NOT NULL DEFAULT 0,
  `donate` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `phone` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `phone_hash` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `telegram_lock` tinyint(1) UNSIGNED NOT NULL DEFAULT 0,
  `telegram_id` int(11) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `username`(`username`) USING BTREE,
  INDEX `recruiter`(`recruiter`) USING BTREE,
  INDEX `id`(`id`) USING BTREE,
  INDEX `username_idx`(`username`) USING BTREE,
  INDEX `hwid`(`hwid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2 CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = 'Account System' ROW_FORMAT = COMPACT;

-- ----------------------------
-- Records of account
-- ----------------------------
INSERT INTO `account` VALUES (1, '1@1', '7AFF4A54859D4BCA70EF16167B472D561BEE5E5673EE05EA03DACC8AD14A3B7F', '', '', '', '', '2026-07-28 15:26:11', '127.0.0.1', '127.0.0.1', 0, 0, 0, 0, '00', '0000-00-00 00:00:00', NULL, 0, 6, 0, 0, '', 0, '', 'en', '', '0', NULL, '', '', 0, 0, 0, 0, 0, 1, 0, 0, 0, '', '', 0, 0);

SET FOREIGN_KEY_CHECKS = 1;
