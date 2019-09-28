#include <ansi.h>

int main(object me, string arg)
{
    object ob, env;

    if (!arg)
    {
        if (env = environment(me))
        {
            debug("你在 " + file_name(env) + " 中");
        }
        else
        {
            debug("你没在任何环境中");
        }
    }
    else if (ob = find_object(arg))
    {
        if (env = environment(ob))
        {
            debug("对象 " + arg + " 在 " + file_name(env) + " 中");
        }
        else
        {
            debug("对象没在任何环境中");
        }
    }
    else
    {
        debug("没有找到对象 " + arg);
    }

    return 1;
}
