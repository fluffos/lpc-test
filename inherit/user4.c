// user4.c
#include <ansi.h>

inherit __DIR__ "user3";
inherit __DIR__ "combat"; // 战斗模块

varargs void create(string arg)
{
    ::create(arg);
    if (clonep())
    {
        int lv = random(100) + 1;
        set("lv", lv);
        set("max_hp", 10 * lv + random(10));
        set("hp", query("max_hp"));
        set("str", 4 * lv + random(10));
        set("def", 3 * lv + random(10));
        set("agi", 2 * lv + random(10));

        set_heart_beat(1);
    }
}

void write_prompt()
{
    write(sprintf("[%s|%s]", GRN + query("hp") + NOR, HIG + query("max_hp") + NOR));
}
