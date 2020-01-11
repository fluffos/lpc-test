inherit DBASE;

void create(int x, int y, int z)
{
    set("short", "客店二楼");
    set("long", @LONG
    这里是客店二楼的走廊，不时有风尘仆仆的旅客进进出出，
如果需要开房请到楼下的掌柜处付钱。
LONG);
    set("exits", ([
        "down":__DIR__ "0,0,0",
    ]));
}
