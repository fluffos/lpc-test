## LPC-TEST

LPC 开发测试 LIB，推荐配合 fluffos v2019 使用，使用 fluffos v2017 和旧版 mudos 也能正常运行。

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

```
.
├── README.md
├── area                    游戏地区
│   ├── tower.c
│   ├── world
│   │   ├── 0,0,0.c
│   │   └── 5,2,0.c
│   └── world.c
├── cmds                    游戏指令
│   ├── demo                教程演示指令,请输入 demo/xxx 运行
│   │   └── ...
│   ├── efun                教程 efun 指令
│   │   └── ...
│   ├── test                个人测试目录
│   │   └── test.c
│   └── ...
├── config.cfg              旧版运行时配置文件
├── config.ini              新版运行时配置文件（v2019）
├── data                    存档目录
├── include                 头文件目录
│   ├── ansi.h              颜色控制头文件
│   └── globals.h           全局包含头文件
├── inherit                 功能继承模块
│   ├── clean_up.c
│   ├── combat.c            战斗模块
│   ├── dbase.c             数据存档模块
│   ├── user.c
│   ├── user2.c
│   ├── user3.c
│   └── user4.c
├── log                     日志目录
│   ├── author_stats
│   ├── debug.log           游戏运行日志
│   ├── domain_stats
│   ├── error_handler       编译错误追踪日志
│   └── log_error           错误及警告日志
├── mudos.exe               旧版驱动，兼容性测试用
├── system                  系统目录
│   ├── daemons             守护进程
│   │   ├── combat_d.c      战斗守护进程
│   │   └── virtual_d.c     虚拟对象守护进程
│   ├── kernel              核心文件
│   │   ├── master.c        主控文件
│   │   └── simul_efun.c    模拟外部函数文件
│   └── object              核对对象
│       ├── login.c         连线对象
│       ├── user.c          玩家对象
│       └── void.c
├── tree.txt
└── www                     WEBSOCKET
    └── ...
```

### 运行

推荐使用 FluffOS v2019 最新版编译的驱动运行，启动方式：

    driver config.ini

如果要后台显示更多信息，可使用以下方式启动：

    driver config.ini -fdebug

如果使用 FluffOS v2017 驱动，请运行：

    driver config.cfg
