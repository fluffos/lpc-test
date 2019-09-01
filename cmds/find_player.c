#include <ansi.h>

int main(object me, string arg)
{
    object ob = find_player(arg);
    if (ob)
        write(HIG + arg + " => " + ob + "\n" NOR);
    else
        write(HIR "没有找到名字是 " + arg + " 的玩家！\n" NOR);
    return 1;
}
