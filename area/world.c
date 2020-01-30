// world.c
inherit CLEAN_UP;
inherit DBASE;

varargs void create(int x, int y, int z)
{
    if (x > -3 && x < 3 && y > -3 && y < 3)
    {
        set("short", "下午镇 - 坐标(" + x + "," + y + "," + z + ")");
        set("long", @LONG
    这里是下午镇废墟，曾经的居民早已不知去向，只有不变的黑夜和潜藏的危险。
LONG);
    }
    else
    {
        set("short", "神弃之地 - 坐标(" + x + "," + y + "," + z + ")");
        set("long", @LONG
    这里是被众神遗弃的地方，这里的天空没有太阳，没有月亮，没有星星，只有不变的黑夜
和撕裂着一切的闪电。
LONG);
    }

    set("exits", ([
        "north":__DIR__ "world/" + x + "," + (y + 1) + "," + z,
        "south":__DIR__ "world/" + x + "," + (y - 1) + "," + z,
        "west":__DIR__ "world/" + (x - 1) + "," + y + "," + z,
        "east":__DIR__ "world/" + (x + 1) + "," + y + "," + z,
    ]));
}
