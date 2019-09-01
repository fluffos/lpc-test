#include <ansi.h>

int main(object me, string arg)
{
    string id;
    if (!arg)
        arg = "...。";
    sscanf(file_name(me), "%*s#%s", id);

    arg = HIM "【聊天】" NOR HIY "玩家" + id + "：" NOR HIC + arg + NOR "\n";

    write(arg);
    shout(arg);

    return 1;
}
