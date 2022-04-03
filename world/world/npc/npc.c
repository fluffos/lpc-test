inherit COMBAT;
inherit LIVING;

void create()
{
    ::create();
    set_living("npc");
    set("name", "白银城冒险者");
    set("unit", "位");
    if (clonep())
    {
        int lv = random(100) + 1;
        set("lv", lv);
        set("max_hp", 5 * lv + random(50));
        set("hp", query("max_hp"));
        set("str", 4 * lv + random(40));
        set("def", 3 * lv + random(30));
        set("agi", 2 * lv + random(20));
        set("gender", random(2) ? "男" : "女");
        set_heart_beat(1);
    }
}
