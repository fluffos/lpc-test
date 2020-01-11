#include <ansi.h>

int main(object me, string arg)
{
    if (!arg)
        arg = "...";

    arg = HIM "【聊天】" NOR HIY "玩家(" + geteuid(me) + ")：" NOR HIC + arg + NOR "\n";

    write(arg);
    shout(arg);

    return 1;
}
