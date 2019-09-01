#include <ansi.h>

int main(object me, string arg)
{
    string str1, str2;
    object ob1, ob2;
    function fun;

    if (!arg || sscanf(arg, "%s to %s", str1, str2) != 2)
    {
        return notify_fail(HIY "指令格式：move_object /path/ob1 to /path/ob2\n" NOR);
    }

    if (!(ob1 = load_object(str1)))
    {
        return notify_fail(HIR "没有找到对象: " + str1 + "\n" NOR);
    }

    if (!(ob2 = load_object(str2)))
    {
        return notify_fail(HIR "没有找到对象: " + str2 + "\n" NOR);
    }

    fun = bind((: move_object :), ob1);
    evaluate(fun, ob2);
    write(HIG "对象 " + str1 + " 当前环境：" + str2 + "\n" NOR);

    return 1;
}
