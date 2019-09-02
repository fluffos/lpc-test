#include <ansi.h>

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        destruct(this_object());
    }
    else if (ob = find_object(arg))
    {
        destruct(ob);
    }
    else
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    return 1;
}
