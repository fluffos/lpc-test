#include <ansi.h>

int main(object me, string arg)
{
    if (arg)
    {
        if (file_size(arg) == -2)
        {
            if (arg[strlen(arg) - 1] != '/') arg += "/";
            print_r(get_dir(arg));
        }
        else if (file_size(arg) == -1)
        {
            return notify_fail(HIR "目录不存在或你无权读取。\n" NOR);
        }
        else
        {
            print_r(get_dir(arg, -1));
        }
    }
    else
    {
        print_r(get_dir("/"));
    }

    return 1;
}
