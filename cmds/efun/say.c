#include <ansi.h>

int main(object me, string arg)
{
    if (!arg)
        arg = "...。";

    arg = HIC + arg + NOR + "\n";

    write("你说到：" + arg);
    say(HIY + me->query("name") + "(" + geteuid(me) + ")说到：" NOR + arg);

    return 1;
}
