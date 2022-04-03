/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-04-02 17:41:08
 * @LastEditTime: 2022-04-02 20:23:11
 * @LastEditors: 雪风
 * @Description:
 *  https://bbs.mud.ren
 */
inherit VERB;

#include <ansi.h>
#include <type.h>

protected void create()
{
    verb::create();
    setVerb("go");
    setSynonyms("move");
    setRules("STR", "into STR");
    setErrorMessage("你想去哪儿？");
}

mixed can_go_str(string dir, string str)
{
    object me = this_player();
    object env = environment(me);
    object dest;
    mapping exits;
    mixed exit;

    if (!me->query("area_info") && (!mapp(exits = env->query("exits")) || undefinedp(exit = exits[dir])))
    {
        return RED "这个方向没有出路。" NOR;
    }

    if (me->is_fighting())
    {
        return YEL "你逃跑失败了~" NOR;
    }

    switch (typeof(exit))
    {
    case T_STRING:
        if (!objectp(dest = load_object(exit)))
        {
            return sprintf("目标环境异常，无法向 %s 移动。", exit);
        }
        break;
    case T_MAPPING:
        if (undefinedp(exit["filename"]) || undefinedp(exit["x_axis"]) || undefinedp(exit["y_axis"]))
        {
            return sprintf("目标方向异常，无法向 %s 移动。", dir);
        }
        if (!objectp(dest = load_object(exit["filename"])))
        {
            return sprintf("目标环境异常，无法向 %s 移动。\n", exit["filename"]);
        }
        break;
    default:
        return env->is_area() || "这个方向的出口有问题，请联系巫师处理。";
    }

    return 1;
}

int do_go_str(string dir, string str)
{
    object me = this_player();
    object env = environment(me);
    mapping exits = env->query("exits");
    mixed exit;
    object dest;

    if (env->is_area())
        return env->area_go(me, dir);

    exit = exits[dir];
    dest = stringp(exit) ? load_object(exit) : load_object(exit["filename"]);

    if (dest->is_area())
    {
        dest->area_move(me, exit["x_axis"], exit["y_axis"]);
    }
    else
    {
        msg("info", "$ME离开了这里！", me, environment(me), ({me}));
        me->move(dest);
        msg("info", "$ME走了过了！", me, environment(me), ({me}));
    }

    return 1;
}
