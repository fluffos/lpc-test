// tower.c
inherit CLEAN_UP;
inherit DBASE;

varargs void create(int x, int y, int z)
{
    set("short", "大沙漠 - 坐标(" + x + "," + y + "," + z + ")");
    set("long", @LONG
    大漠孤烟直, 长河落日圆，这里一片空旷，除了漫天黄沙，几乎一无所有。
LONG);
    set("exits", ([
        "north":__DIR__ "world/" + x + "," + (y + 1) + "," + z,
        "south":__DIR__ "world/" + x + "," + (y - 1) + "," + z,
        "west":__DIR__ "world/" + (x - 1) + "," + y + "," + z,
        "east":__DIR__ "world/" + (x + 1) + "," + y + "," + z,
    ]));
}
