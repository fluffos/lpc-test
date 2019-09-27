inherit DBASE;

void create()
{
    set("short", "客店二楼");
    set("long", @LONG
    这里是客店二楼的走廊，不时有睡意朦胧的旅客进进出出
到楼下的掌柜处付了钱再上来睡觉。
LONG);
    set("exits", ([
        "down":__DIR__ "kedian",
    ]));
}
