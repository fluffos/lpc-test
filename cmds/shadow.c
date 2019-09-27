#include <ansi.h>

int main(object me, string arg)
{
    string msg, str1, str2;
    object ob1, ob2;
    function fun;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： shadow /path/target 或者 shadow /path/ob1 on /path/ob2\n" NOR);
    }

    sscanf(arg, "%s on %s", str1, str2);

    if (str2)
    {
        if (!(ob1 = load_object(str1)))
        {
            return notify_fail(HIR "没有找到对象 " + str1 + "\n" NOR);
        }

        if (!(ob2 = load_object(str2)))
        {
            return notify_fail(HIR "没有找到对象 " + str2 + "\n" NOR);
        }

        fun = bind((: shadow, ob2 :), ob1);
        if(catch(evaluate(fun)))
        {
            return notify_fail(HIR "投影失败，可能对象 " + str1 + " 已经投影了其它对象或正在被其它对象投影，或者在某个环境中\n" NOR);
        }
        msg = HIG "对象 " + str1 + " 投影 " + str2 + " 成功\n" NOR;
    }
    else
    {
        if (!(ob1 = load_object(arg)))
        {
            return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
        }
        if (ob2 = query_shadowing(ob1))
        {
            msg = HIG + arg + " 投影的对象是 " + file_name(ob2) + "\n" NOR;
        }
        else
        {
            return notify_fail(HIR + arg + " 没有投影任何对象\n" NOR);
        }
    }

    write(msg);

    return 1;
}
