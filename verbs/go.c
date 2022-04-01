inherit VERB;

#include <ansi.h>

protected void create()
{
    verb::create();
    setVerb("go");
    setSynonyms("move");
    setRules("STR", "into STR");
    setErrorMessage("你想去哪儿？");
}

int can_go_str(mixed *data...)
{
    return 1;
}

mixed do_go_str(string exit, string arg)
{
    object me = this_player();
    object env = environment(me);
    object dest;
    mapping exits;

    if (!mapp(exits = env->query("exits")) || undefinedp(exit = exits[arg]))
    {
        if (query_verb() == "go")
            debug("这个方向没有出路。");
    }
    else if (!objectp(dest = load_object(exit)))
    {
        debug(sprintf("目标区域无法加载，无法向 %s 移动。", exit));
    }
    else if (me->is_fighting())
    {
        debug("你逃跑失败了~");
    }
    else
    {
        msg("info", "$ME离开了这里！", me, environment(me), ({me}));
        me->move(dest);
        msg("info", "$ME走了过了！", me, environment(me), ({me}));
    }
}
