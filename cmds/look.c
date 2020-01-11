// look 指令
#include <ansi.h>

string desc_of_objects(object *obs);
string look_all_inventory_of_room(object me, object env);

int main(object me, string arg)
{
    object env = environment(me);
    string desc, *dirs;
    mapping exits;

    if (arg)
        return notify_fail("暂时不支持查看指定的对象\n");

    if (objectp(env))
    {
        if (desc = env->query("short"))
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
    }
    else
    {
        debug("你现在不在任何环境中。");
    }

    return 1;
}

string desc_of_objects(object *obs)
{
    if (obs && sizeof(obs) > 0)
    {
        int i;
        string str;
        mapping list, unit;
        string short_name;
        string *ob;

        str = "    这里有：";
        list = ([]);
        unit = ([]);

        for (i = 0; i < sizeof(obs); i++)
        {
            short_name = geteuid(obs[i]);

            list[short_name] += obs[i]->query_temp("amount") ? obs[i]->query_temp("amount") : 1;
            unit[short_name] = obs[i]->query("unit") ? obs[i]->query("unit") : "个";
        }

        ob = sort_array(keys(list), 1);

        for (i = 0; i < sizeof(ob); i++)
        {
            if (list[ob[i]] > 1)
                str += list[ob[i]] + unit[ob[i]] + ob[i] + " ";
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
