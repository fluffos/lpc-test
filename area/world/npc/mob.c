inherit COMBAT;
inherit LIVING;

varargs void create(int i, int lv)
{
    mixed info;
    ::create();
    if (nullp(i))
    {
        i = 1 + random(7);
    }
    lv = lv || 1 + random(i * 10);
    info = MONSTER_D->info(i);
    set_living(info[0]);
    set("name", info[1]);
    set("unit", "位");
    set("lv", lv);
    if (clonep())
    {
        set("max_hp", info[2] + info[2] * lv / 10);
        set("hp", query("max_hp"));
        set("str", info[3] + info[3] * lv / 10);
        set("def", info[4] + info[4] * lv / 10);
        set("agi", info[5] + info[5] * lv / 10);

        set_heart_beat(1);
    }
}

void init()
{
    object me = this_player();

    if (interactive(me) && me->can_fight())
    {
        object ob = query_shadowing(this_object()) || this_object();
        ob->fight(me);
    }
}

object shadowto(object ob)
{
    set_living(geteuid(ob));
    return shadow(ob, 1);
}
