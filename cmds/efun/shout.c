#include <ansi.h>

int main(object me, string arg)
{
    if (!arg)
        arg = "...";

    arg = HIM "【聊天】" NOR HIY + me->query("name") + "(" + geteuid(me) + "@" + MUD_NAME + ")：" NOR HIC + arg + NOR "\n";
     // 同步消息到QQ群
    if (me->query_temp("step") > 2)
    {
        "/system/daemons/qq_d"->msg(remove_ansi(arg));
    }

    write(arg);
    shout(arg);

    return 1;
}
