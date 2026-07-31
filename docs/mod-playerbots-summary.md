# mod-playerbots 仓库汇总

> 来源：https://github.com/mod-playerbots/mod-playerbots

## 项目概述

基于 **AzerothCore** 的玩家机器人模块，源自 IKE3 的 mangosbot。

| 项目 | 数据 |
|------|------|
| Stars | 899 |
| Forks | 514 |
| 语言 | C++ |
| 许可证 | GPL-2.0 |
| Open Issues | 239 |
| 描述 | AzerothCore Playerbots Module |

## 核心功能

| 功能 | 说明 |
|------|------|
| **角色机器人** | 将账号下的其他角色作为机器人登录，组队、升级、交互 |
| **随机机器人** | 模拟真实玩家在世界中游荡、做任务、打怪，营造 MMO 氛围 |
| **副本/战场** | 机器人能打大部分团队副本和战场，支持特定 Boss 策略 |
| **性能** | 支持数千个机器人同时运行 |

## 技术架构

- 基于 **AzerothCore** 的模块系统，需要专用 fork 编译
- 机器人通过 **聊天命令** 控制（`.playerbot bot <command>`）
- 提供 **Unbot Addon** 插件，支持 GUI 操作
- 支持三种机器人 AI 模式：野外、队伍、战场/竞技场
- 测试分支：`test-staging`（包含最新功能，可能不稳定）

## 安装方式

```bash
git clone https://github.com/mod-playerbots/azerothcore-wotlk.git --branch=Playerbot
cd azerothcore-wotlk/modules
git clone https://github.com/mod-playerbots/mod-playerbots.git --branch=master
```

## 相关资源

- [安装指南 Wiki](https://github.com/mod-playerbots/mod-playerbots/wiki/Installation-Guide)
- [故障排除](https://github.com/mod-playerbots/mod-playerbots/wiki/Troubleshooting)
- [插件和子模块](https://github.com/mod-playerbots/mod-playerbots/wiki/Playerbot-Addons-and-Sub%E2%80%90Modules)
- [Discord 社区](https://discord.gg/NQm5QShwf9)
- [IKE3 原版文档](https://ike3.github.io/mangosbot-docs/)

## 与 LegionCore PlayerBot 的关系

**两者是独立的实现：**

| 维度 | mod-playerbots | LegionCore PlayerBot |
|------|---------------|---------------------|
| 基础框架 | AzerothCore (WotLK 3.3.5) | LegionCore (7.3.5) |
| 社区活跃度 | 高（899 Stars, 持续维护） | 低（本项目独有） |
| 功能完整性 | 功能丰富，支持自动升级/任务/副本 | 基础功能（创建、登录、AI行为）已实现 |
| 代码结构 | 模块化，独立于核心 | 深度集成在核心代码中 |