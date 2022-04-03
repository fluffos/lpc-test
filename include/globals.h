/***
 * @Author: 雪风@mud.ren
 * @Date: 2022-03-31 13:18:32
 * @LastEditTime: 2022-03-31 13:18:32
 * @LastEditors: 雪风
 * @Description: The global include file is included automatically
 * @ https://bbs.mud.ren
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#endif
// 核对对象
#define LOGIN_OB "/system/object/login"
#define USER_OB "/system/object/user"
#define VOID_OB "/system/object/void"
// 守护进程（服务）
#define COMBAT_D "/system/daemons/combat_d"
#define MONSTER_D "/system/daemons/monster_d"
#define VIRTUAL_D "/system/daemons/virtual_d"
// 功能模块
#define CLEAN_UP "/inherit/clean_up"
#define COMBAT "/inherit/combat"
#define DBASE "/inherit/dbase"
#define LIVING "/inherit/living"
#define OBJECT "/inherit/object"
#define VERB "/inherit/verb"
#define AREA "/inherit/area"
#define MAZE "/inherit/maze"
#define ROOM "/inherit/room"
// 存档目录
#define DATA_DIR "/data/"
#define LOG_DIR "/log/"
// 预加载列表
#define PRELOAD "/system/etc/preload"
// 出生地
#define START_ROOM "/world/world/0,0,0"

#endif
