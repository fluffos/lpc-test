// user4.c
inherit DBASE;
inherit __DIR__ "user3";

varargs void create(string arg)
{
    ::create(arg);
    if (clonep())
    {
        set("hp", 50 + random(50));
        set("str", 40 + random(10));
        set("def", 30 + random(10));
        set("agi", 20 + random(10));
        set("gender", random(2) ? "男" : "女");
    }
}

void heart_beat()
{

}
