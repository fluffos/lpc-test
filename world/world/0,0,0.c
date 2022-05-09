// 0,0,0.c
inherit DBASE;

string look_door();

void create()
{
    set("short", "下午镇营地");
    set("long", @LONG
    这里是白银城冒险者清理过的下午镇营地，微弱的篝火照亮了黑暗。远处篝火无法照亮的黑暗里潜藏着无尽的危险。
这里还有一个传送门(door)，使用它可以传送到一个特别的世界。
LONG );
    set("exits", ([
        "east":__DIR__ "1,0,0",
        "north":__DIR__ "0,1,0",
        "south":__DIR__ "0,-1,0",
        "west":__DIR__ "-1,0,0",
    ]));
    set("items", ([
        "door" : (: look_door :),
    ]));
}

void init()
{
    add_action(function(string arg) {
        object me = this_player();
        if (me->query_temp("step") < 3)
            return notify_fail("你当前状态无法传送，输入 tutorial 3 后方可使用此传送门。\n");
        return me->move("/world/area");
    }, ({"in", "enter"}));
}

string look_door()
{
    object me = this_player();

    if (me->query_temp("step") < 3)
        return "这个传送门闪着微光，还在蓄积能量中，暂时无法传送(in)。";
    else
        return "这个传送门闪着耀眼的光芒，你可以试试传送(in)功能。";
}
