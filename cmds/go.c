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
            debug("你哪里也去不了。\n");
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
        else
        {
            me->move(dest);
        }
    }

    return 1;
}
