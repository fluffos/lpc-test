inherit DBASE;
inherit COMBAT;
inherit LIVING;

void create()
{
    set_living("npc");
    set("name", "白银城冒险者");
    set("unit", "位");
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
