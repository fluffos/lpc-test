// user3.c
#include <ansi.h>
inherit __DIR__ "user2";

void receive_message(string type, string message)
{
    // 可以在此判断是否显示消息等
    switch (type)
    {
    case "emote":
        receive(HIM + message + "\n" NOR);
        break;

    default:
        receive(HIW + message + "\n" NOR);
    }
}

void receive_snoop(string message)
{
    receive(HBBLU + message + NOR);
}

void write_prompt()
{
    write(ctime() + " > ");
}

void net_dead()
{
    say(HIR "玩家(" + geteuid() + ")断线了。\n" NOR);
    destruct();
}
