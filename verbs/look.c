inherit VERB;

#include <ansi.h>

int look_room(object me, object env);
string desc_of_objects(object *obs);
string list_all_inventory_of_object(object me, object env);
int look_living(object me, object ob);

protected void create()
{
    verb::create();
    setVerb("look");
    setSynonyms("l");
    setRules("", "STR", "OBJ", "at STR", "at OBJ", "on OBJ", "in OBJ", "inside OBJ",
             "at OBJ in OBJ", "OBJ inside OBJ", "at OBJ on OBJ", "at STR on OBJ");
    setErrorMessage("你想看什么?");
}

mixed can_look()
{
    object env = environment(this_player());
    if (!env || !env->query("short") && !env->is_area())
        return "你的四周灰蒙蒙地一片，什么也没有。";
    else
        return 1;
}

mixed can_verb_rule(mixed *data...)
{
    // debug_message(sprintf("can_verb_rule : %O", data));
    return can_look();
}

mixed can_verb_word_str(mixed *data...)
{
    // debug_message(sprintf("can_verb_word_str : %O", data));
    return can_look();
}

mixed direct_look_obj(object ob, string id)
{
    return environment(this_player()) == environment(ob);
}

mixed direct_verb_rule(mixed *data...)
{
    // debug_message(sprintf("direct_verb_rule : %O", data));
    return can_look();
}

mixed direct_verb_word_obj(mixed *data...)
{
    // debug_message(sprintf("direct_verb_word_obj : %O", data));
    return can_look();
}

mixed do_look()
{
    object me = this_player();
    object env = environment(me);

    return look_room(me, env);
}

mixed do_look_at_obj(object ob)
{
    object me = this_player();

    if (living(ob))
    {
        look_living(me, ob);
    }
    else
    {
        printf("%s\n", ob->long());
    }

    return 1;
}

mixed do_look_at_obj_in_obj(object ob1, object ob2, string id1, string id2)
{
    printf("%s\n", ob1->long());
    return 1;
}

mixed do_look_obj(object ob)
{
    return do_look_at_obj(ob);
}

mixed do_look_in_obj(object ob)
{
    if (sizeof(all_inventory(ob)))
    {
        cecho(sprintf("%s里有:\n%s", ob->short(), list_all_inventory_of_object(ob, ob)));
    }
    else
    {
        cecho(sprintf("%s里什么也没有。", ob->short()));
    }

    return 1;
}

mixed do_look_at_str(string str, string arg)
{
    object me = this_player();
    object env = environment(me);
    mapping exits = env->query("exits");
    object ob;
    mixed item_desc;

    if (str == "here")
    {
        return do_look();
    }
    else if (stringp(exits[str]))
        return look_room(me, load_object(exits[str]));
    else if (mapp(exits[str]))
        cecho("此方向是区域环境，无法观察。");
    else if (item_desc = env->query("items/" + str))
        cecho(evaluate(item_desc));
    else if (ob = present(arg, env))
        return do_look_obj(ob);
    else
        cecho(getErrorMessage());

    return 1;
}

mixed do_look_str(string str, string arg)
{
    return do_look_at_str(str, arg);
}

mixed do_verb_rule(mixed *data...)
{
    cecho(sprintf("do_verb_rule : %O", data));
    return 1;
}

// 查看环境(此方法推荐放在环境中)
int look_room(object me, object env)
{
    string str, *dirs;
    mapping exits;

    if (env->is_area())
    {
        return env->do_look(me);
    }

    str = sprintf(HIC + "%s" + NOR + " <%s>\n%s" + NOR,
                  env->query("short"), file_name(env), env->query("long"));

    if (mapp(exits = env->query("exits")))
    {
        dirs = keys(exits);

        if (sizeof(dirs) == 0)
            str += "    这里没有任何明显的出路。\n";
        else if (sizeof(dirs) == 1)
            str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
        else
            str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                           implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs) - 1]);
    }
    else
    {
        str += "    这里没有任何出路。\n";
    }
    str += list_all_inventory_of_object(me, env);
    tell_object(me, str);
    return 1;
}

string desc_of_objects(object *obs)
{
    int i;
    string str;
    mapping list, unit;
    string short_name;
    string *ob;

    if (obs && sizeof(obs) > 0)
    {
        str = "";
        list = ([]);
        unit = ([]);

        for (i = 0; i < sizeof(obs); i++)
        {
            short_name = obs[i]->short();

            list[short_name] += obs[i]->query_temp("amount") ? obs[i]->query_temp("amount") : 1;
            unit[short_name] = obs[i]->query("unit") ? obs[i]->query("unit") : "个";
        }

        ob = sort_array(keys(list), 1);
        for (i = 0; i < sizeof(ob); i++)
        {
            str += "  ";
            if (list[ob[i]] > 1)
                str += list[ob[i]] + unit[ob[i]] + ob[i] + "\n";
            else
                str += ob[i] + "\n";
        }
        return str;
    }

    return "";
}

string list_all_inventory_of_object(object me, object env)
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
    msg = sprintf("%s 是一位 %d 级的%s性生物。\n", ob->short(), ob->query("lv"), ob->query("gender") || "??");
    msg += line;
    msg += sprintf("  %-36s\n", "ＨＰ：" + ob->query("hp") + " / " + ob->query("max_hp"));
    msg += sprintf("  %-12s%-12s%-12s\n", "力量：" + ob->query("str"), "敏捷：" + ob->query("agi"), "防御：" + ob->query("def"));
    msg += line;
    tell_object(me, msg);

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : look ｜ l

最基本的look指令，让你睁眼看世界，可以查看对象了解信息。

当存在多个同名对象时，比如有4个NPC，你要查看指定对象可以使用以下格式：

    l 1st n 或 l n 1
    l 2nd n 或 l n 2
    l 3rd n 或 l n 3
    l 4th n 或 l n 4

HELP );
    return 1;
}
