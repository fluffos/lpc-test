#include <ansi.h>

int main(object me, string arg)
{
    object ob;
    function fun;

    if (!arg)
    {
        print_r(all_inventory(me));
        return 1;
    }

    if (!(ob = load_object(arg)))
    {
        return notify_fail(HIR "没有找到对象: " + arg + "\n" NOR);
    }

    print_r(all_inventory(ob));
    return 1;
}
