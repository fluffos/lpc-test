#include <ansi.h>

int main(object me, string arg)
{
    if (query_ip_number(me) != "127.0.0.1")
    {
        return 0;
    }
    if (!arg)
    {
        return notify_fail(HIR "指令格式： ed <file> \n" NOR);
    }
    else if (file_size(arg) < 0)
    {
        return notify_fail(HIR "文件 " + arg + " 不存在\n" NOR);
    }
    else
    {
        ed(arg);
    }

    return 1;
}
