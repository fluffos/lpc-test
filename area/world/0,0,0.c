// user.c
inherit DBASE;

void create()
{
    set("short", "龙门客栈");
    set("long", @LONG
    这是一家价钱低廉的客栈，生意却是非常兴隆。外地游客
多选择这里落脚，你可以在这里打听到各地的风土人情。店小
二里里外外忙得团团转，接待着南腔北调的客人。
LONG );
    set("exits", ([
        "up":__DIR__ "0,0,1",
        "out":__DIR__ "0,1,0",
    ]));
}
