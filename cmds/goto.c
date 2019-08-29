// goto.c
#include <ansi.h>

int main(object me, string arg)
{
    if (arg && load_object(arg))
    {
        function fun = bind((: move_object :), me);
        evaluate(fun, arg);

        arg = HIG "位置报告：" + file_name(environment(me)) + "\n" NOR;
    }
    else
    {
        arg = HIR "目标位置不存在！\n" NOR;
    }

    write(arg);

    return 1;
}
