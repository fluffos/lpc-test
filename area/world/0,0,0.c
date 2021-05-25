// 0,0,0.c
inherit DBASE;

void create()
{
    set("short", "下午镇营地");
    set("long", @LONG
    这里是白银城冒险者清理过的下午镇营地，微弱的篝火照亮了黑暗。远处篝火无法照亮的黑暗里潜藏着无尽的危险。
LONG );
    set("exits", ([
        "east":__DIR__ "1,0,0",
        "north":__DIR__ "0,1,0",
        "south":__DIR__ "0,-1,0",
        "west":__DIR__ "-1,0,0",
    ]));
}
