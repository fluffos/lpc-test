// user4.c
#include <ansi.h>

inherit __DIR__ "user3";
inherit __DIR__ "combat"; // 战斗模块

varargs void create(string arg)
{
    ::create(arg);
    if (clonep())
    {
        set("max_hp", 50 + random(50));
        set("hp", query("max_hp"));
        set("str", 40 + random(40));
        set("def", 30 + random(30));
        set("agi", 20 + random(20));

        set_heart_beat(1);
    }
}

void write_prompt()
{
    write(sprintf("[%s|%s]", GRN + query("hp") + NOR, HIG + query("max_hp") + NOR));
}

void net_dead()
{
    say(HIR "玩家(" + geteuid() + ")断线了。\n" NOR);
    destruct(this_object());
}
