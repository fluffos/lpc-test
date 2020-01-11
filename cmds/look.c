// look 指令
#include <ansi.h>

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
