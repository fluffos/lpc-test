// look 指令
#include <ansi.h>

string desc_of_objects(object *obs);
string look_all_inventory_of_room(object me, object env);
int look_living(object me, object ob);
int look_item(object me, object ob);

int main(object me, string arg)
{
    object ob, env = environment(me);
    string desc, *dirs;
    mapping exits;

    if (arg)
    {
        ob = present(arg, env);
        if (objectp(ob))
        {
            if (living(ob))
            {
                return look_living(me, ob);
            }
            else
            {
                return look_item(me, ob);
            }
        }
        debug("你瞅啥？");
    }
    else if (desc = env->query("short"))
    {
        desc = sprintf(HIC "%s\n" NOR "%s", desc, env->query("long"));

        if (mapp(exits = env->query("exits")))
        {
            dirs = keys(exits);

            if (sizeof(dirs) == 0)
                desc += "    这里没有任何明显的出路。\n";
            else if (sizeof(dirs) == 1)
                desc += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
            else
                desc += sprintf("    这里可移动的方向是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n", implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs) - 1]);
        }
        desc += look_all_inventory_of_room(me, env);
        write(desc);
    }
    else
    {
        debug("这里一片虚无，什么也没有。");
    }

    return 1;
}

string desc_of_objects(object *obs)
{
    if (obs && sizeof(obs) > 0)
    {
        int i;
        string str;
        mapping amount, unit;
        string short_name;
        string *ob;

        str = "    这里有：";
        amount = ([]);
        unit = ([]);

        for (i = 0; i < sizeof(obs); i++)
        {
            short_name = obs[i]->query("name");
            if (!short_name)
            {
                short_name = geteuid(obs[i]);
            }
            else
            {
                short_name += "(" + geteuid(obs[i]) + ")";
            }
            amount[short_name] += 1;
            unit[short_name] = obs[i]->query("unit") ? obs[i]->query("unit") : "个";
        }

        ob = sort_array(keys(amount), 1);

        for (i = 0; i < sizeof(ob); i++)
        {
            if (amount[ob[i]] > 1)
                str += amount[ob[i]] + unit[ob[i]] + ob[i] + " ";
            else
                str += ob[i] + " ";
        }
        return str + "\n";
    }

    return "";
}

string look_all_inventory_of_room(object me, object env)
{
    object *inv;
    object *obs;
    string str = "";

    if (!env || !me)
        return "";

    inv = all_inventory(env);
    if (!sizeof(inv))
        return str;

    obs = filter_array(inv, (: $(me) != $1 :));
    str += desc_of_objects(obs);

    return str;
}

int look_living(object me, object ob)
{
    string msg;
    string line = repeat_string("-*-", 12) + "\n";

    if (ob != this_player())
    {
        msg = "$ME看了看$YOU，好像对$YOU很感兴趣对样子。";
        msg("vision", msg, me, ob);
    }
    msg = line;
    msg += sprintf("  %-36s\n", "ＨＰ：" + ob->query("hp") + " / " + ob->query("max_hp"));
    msg += sprintf("  %-12s%-12s%-12s\n", "力量：" + ob->query("str"), "敏捷：" + ob->query("agi"), "防御：" + ob->query("def"));
    msg += line;
    tell_object(me, msg);

    return 1;
}

int look_item(object me, object ob)
{
    // todo

    return 1;
}
