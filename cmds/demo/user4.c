// user4.c
#include <ansi.h>

inherit __DIR__ "user3";
inherit DBASE;              // 数据模块
inherit __DIR__ "F_COMBAT"; // 战斗模块

varargs void create(string arg)
{
    ::create(arg);
    if (clonep())
    {
        set("max_hp", 50 + random(50));
        set("hp", query("max_hp"));
        set("str", 40 + random(10));
        set("def", 30 + random(10));
        set("agi", 20 + random(10));
        set("gender", random(2) ? "男" : "女");
        set_heart_beat(1);
    }
}

void heart_beat()
{
    // 死亡相关控制
    if (query("hp") <= 0)
    {
        die();
    }
    // 行动相关控制
    if (is_fighting())
    {
        // 战斗吧，皮卡丘
        attack();
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

int id(string id)
{
    return geteuid() == id;
}
