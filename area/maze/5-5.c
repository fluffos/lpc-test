inherit DBASE;

void create()
{
    object ob = new ("/area/world/npc/mob", 9);
    ob->move(this_object());

    set("short", "巨人王庭大厅");
    set("long", @LONG
    这里是巨人王庭内部大厅，一位强大的暗天使恶灵在这里守护着传说中的亵渎石板。
LONG );
    set("exits", ([
        "east":__DIR__ "6-5",
        "north":__DIR__ "5-6",
        "south":__DIR__ "5-4",
        "west":__DIR__ "4-5",
    ]));
}
