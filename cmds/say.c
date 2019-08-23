#include <ansi.h>

int main(object me, string arg)
{
    string id;
    if (!arg)
        arg = "...。";

    arg = HIC + arg + NOR + "\n";
    sscanf(file_name(me), "%*s#%s", id);

    write("你说到：" + arg);
    say(HIY "玩家" + id + "说到：" NOR + arg);

    return 1;
}
