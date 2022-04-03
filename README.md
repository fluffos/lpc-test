## LPC-TEST

LPC 开发测试 LIB，配合 fluffos v2019 以上版本使用。

本 LIB 和 fluffos 自带的 testsuite 不同点是 testsuite 主要是驱动功能测试，本 LIB 除了基础 LPC语言教程代码(`/cmds/demo/`)外，另外提供具体游戏开发的功能模块演示，比如：玩家基础功能、游戏地图、虚拟迷宫、战斗和怪物变身等等，用更少的代码理解游戏开发的功能实现。

```
                                 _\\|//_
                                (' . . ')
┌-----------------------------ooO-(_)-Ooo-----------------------------------┐
|  ★ 欢迎光临,旅行者。
|  ★
|  ★ LPMUD 启动文件加载顺序：
|  ★ 1. simul_efun (运行时配置文件中指定)
|  ★ 2. master (运行时配置文件中指定)
|  ★ 注意：所有文件都会自动#include <globals.h> (运行时配置文件中指定)
|  ★
|  ★ MASTER 对象必须实现以下 apply 方法：
|  ★    get_root_uid - author_file - get_bb_uid - domain_file - creator_file
|  ★
|  ★ 玩家连线流程：
|  ★ 1. 调用 MASTER 对象的 object connect(int port) 方法
|  ★ 2. 调用 object connect(int port) 方法传回对象的 object logon(void) 方法
|  ★
|  ★ 所有对象加载时都会调用 MASTER 对象的以下 apply 方法：
|  ★    domain_file、author_file、creator_file
|  ★ 所有对象加载时都会调用对象本身的 void create(void) 方法（如果有）
└---------------------------------------------------------------------------┘
本项目为 LPMUD 开发学习用，配套教程：https://bbs.mud.ren/threads/3
```

### 目录结构

以下为项目中所有文件的说明，目前结构比较简单，文件也不多，但演示了游戏开发的多数功能模块。

```
.
├── README.md
├── cmds                    游戏指令
│   ├── demo                教程演示指令,请输入 demo/xxx 运行
│   │   └── ...
│   ├── efun                教程 efun 指令
│   │   └── ...
│   ├── test                个人测试目录，你可以把自己的测试指令放在这里
│   │   └── test.c
│   └── ...
├── config.cfg              运行时配置文件精简版（FluffOS v2019）
├── config.ini              运行时配置文件注释版（FluffOS v2019）
├── data                    存档目录
├── include                 头文件目录
│   ├── ansi.h              颜色控制头文件
│   ├── globals.h           全局包含头文件
│   └── ...                 （其它为驱动内置头文件）
├── inherit                 功能继承模块
│   ├── area.c              区域环境功能模块
│   ├── clean_up.c          自动内存回收功能模块
│   ├── combat.c            战斗功能模块
│   ├── dbase.c             数据存档模块
│   ├── living.c            生物对象公共模块
│   ├── maze.c              迷宫环境功能实现模块
│   ├── object.c            实体对象公共模块
│   ├── room.c              普通环境功能模块
│   ├── user.c              玩家对象（实现指令功能模块）
│   ├── user2.c             玩家对象（实现指令别名功能模块）
│   ├── user3.c             玩家对象（实现智能消息功能模块）
│   ├── user4.c             玩家对象（实现战斗功能模块）
│   ├── user5.c             玩家对象（实现存档功能模块）
│   └── verb.c              自然语法解析指令功能模块
├── log                     日志目录
│   ├── author_stats
│   ├── debug.log           游戏运行日志
│   ├── domain_stats
│   ├── error_handler       编译错误追踪日志
│   └── log_error           错误及警告日志
├── system                  系统目录
│   ├── daemons             守护进程
│   │   ├── combat_d.c      战斗守护进程
│   │   ├── monster_d.c     魔物守护进程
│   │   ├── qq_d.c          QQ群消息守护进程(socket使用演示)
│   │   └── virtual_d.c     虚拟对象守护进程
│   ├── etc                 系统配置目录
│   ├── kernel              核心文件
│   │   ├── master.c        主控文件
│   │   └── simul_efun.c    模拟外部函数文件
│   └── object              核对对象
│       ├── login.c         连线对象
│       ├── user.c          玩家对象
│       └── void.c
├── tmp                     临时文件目录
├── verbs                   自然语法指令目录
├── world                   游戏地区
│   ├── area.c              区域模式环境
│   ├── maze.c              迷宫
│   ├── tower.c             通天塔
│   ├── world               世界特别地区
│   │   ├── npc             NPC（包括魔物）
│   │   ├── 0,0,0.c
│   │   └── 5,2,0.c
│   └── world.c             世界地区
└── www                     WEBSOCKET
    └── ...
```

### 运行

请使用 FluffOS 最新版本的驱动运行，启动方式：

    driver config.ini

如果要后台显示更多信息，可使用以下方式启动：

    driver config.ini -fdebug

如果要追踪游戏运行信息，可使用以下方式启动：

    driver config.ini --tracing trace_driver.json

### 提示

在游戏中可以收到QQ群消息，也可以发送消息到QQ群（302388378），如有任何困难，可以直接chat xxx 求帮助。


    .__                                             .__       .___
    |  |__   ____   _____   ______  _  _____________|  |    __| _/
    |  |  \ /  _ \ /     \_/ __ \ \/ \/ /  _ \_  __ \  |   / __ |
    |   Y  (  <_> )  Y Y  \  ___/\     (  <_> )  | \/  |__/ /_/ |
    |___|  /\____/|__|_|  /\___  >\/\_/ \____/|__|  |____/\____ |
        \/             \/     \/                              \/
