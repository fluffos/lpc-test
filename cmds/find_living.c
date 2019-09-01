#include <ansi.h>

int main(object me, string arg)
{
    object ob = find_living(arg);
    if (ob)
        write(HIG + arg + " => " + ob + "\n" NOR);
    else
        write(HIR "没有找到名字是 " + arg + " 的对象！\n" NOR);
    return 1;
}
