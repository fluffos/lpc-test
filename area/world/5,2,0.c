// 5.2.0.c
inherit ROOM;

void create()
{
    set("short", "神弃之地 - 坐标(5,2,0)");
    set("long", @LONG
    这里是下午镇郊外，几位提着兽皮灯笼的白银城冒险者正在这里探索。
LONG );
    set("objects",([
        __DIR__ "npc/npc" : 1 + random(3),
    ]));
    set("exits", ([
        "east":__DIR__ "6,2,0",
        "north":__DIR__ "5,3,0",
        "south":__DIR__ "5,1,0",
        "west":__DIR__ "4,2,0",
    ]));
    setup();
}
