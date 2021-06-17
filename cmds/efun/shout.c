#include <ansi.h>

int main(object me, string arg)
{
    if (!arg)
        arg = "...";

    arg = HIM "【聊天】" NOR HIY "玩家(" + geteuid(me) + "@" + MUD_NAME + ")：" NOR HIC + arg + NOR "\n";
    "/system/daemons/qq_d"->msg(remove_ansi(arg)); // 同步消息到QQ群
    write(arg);
    shout(arg);

    return 1;
}
