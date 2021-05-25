inherit DBASE;
inherit COMBAT;
inherit LIVING;

void create(int i)
{
    mixed info;
    if (nullp(i))
    {
        i = 1 + random(7);
    }
    info = MONSTER_D->info(i);
    set_living(info[0]);
    set("name", info[1]);
    set("unit", "位");
    if (clonep())
    {
        set("max_hp", info[2]);
        set("hp", query("max_hp"));
        set("str", info[3]);
        set("def", info[4]);
        set("agi", info[5]);

        set_heart_beat(1);
    }
}

void init()
{
    object me = this_player();

    if (interactive(me) && me->can_fight())
    {
        fight(me);
    }
}
