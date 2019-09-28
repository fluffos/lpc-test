// tower.c
inherit CLEAN_UP;
inherit DBASE;

varargs void create(int x, int y, int z)
{
    set("short", "勇者之塔 第 " + z + " 层");
    set("long", @LONG
    这里是封印着无穷无尽的魔物的勇者之塔，据说这座塔通天
彻地，没有人知道具体有多少层，也没有人真正的到达过终点。
LONG );
    set("exits", ([
        "up":__DIR__ "tower/" + x + "," + y + "," + (z + 1),
        "down":__DIR__ "tower/" + x + "," + y + "," + (z - 1),
    ]));
}
