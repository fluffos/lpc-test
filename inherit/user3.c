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
    case "success":
        receive(HIG + message + "\n" NOR);
        break;
    case "danger":
        receive(HIR + message + "\n" NOR);
        break;
    case "warning":
        receive(HIY + message + "\n" NOR);
        break;
    case "info":
        receive(HIC + message + "\n" NOR);
        break;
    case "MAP":
        receive(message);
        break;
    default:
        receive(HIW + message + "\n" NOR);
    }
}

void receive_snoop(string message)
{
    receive(HBBLU + message + NOR);
}
