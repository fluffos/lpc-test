#include <ansi.h>

int main(object me, string arg)
{
    object ob;
    string arg1, arg2, err;

    if (!arg || sscanf(arg,"%s %s",arg1, arg2) != 2)
    {
        return notify_fail(HIY "指令格式： call_other /path/target function [arg1 arg2 ...]\n" NOR);
    }
    else if (ob = load_object(arg1))
    {
        if (err = catch(call_other(ob, explode(arg2, " "))))
        {
            return notify_fail(HIR "运行报错啦~>详细错误信息请看日志记录<：\n" + err + NOR);
        }
    }
    else
    {
        return notify_fail(HIR "没有找到对象 " + arg1 + NOR "\n");
    }

    return 1;
}
