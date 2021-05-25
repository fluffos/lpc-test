/**
 * The global include file is included automatically
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#endif

#define LOGIN_OB "/system/object/login"
#define USER_OB "/system/object/user"
#define VOID_OB "/system/object/void"

#define COMBAT_D "/system/daemons/combat_d"
#define MONSTER_D "/system/daemons/monster_d"
#define VIRTUAL_D "/system/daemons/virtual_d"

#define CLEAN_UP "/inherit/clean_up"
#define COMBAT "/inherit/combat"
#define DBASE "/inherit/dbase"
#define LIVING "/inherit/living"
#define ROOM "/inherit/room"
#define MAZE "/inherit/maze"

#define DATA_DIR "/data/"
#define LOG_DIR "/log/"

#define PRELOAD "/system/etc/preload"

#define START_ROOM "/area/world/0,0,0"

#endif
