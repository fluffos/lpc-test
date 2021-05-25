int main(object me, string arg)
{
    object env, dest;
    mapping exits;
    string exit;

    if (!arg)
    {
        debug("你要往哪个方向走？");
    }
    else if (objectp(me))
    {
        env = environment(me);
        if (!env)
        {
            debug("你哪里也去不了。");
        }
        else if (!mapp(exits = env->query("exits")) || undefinedp(exit = exits[arg]))
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

    return 1;
}
