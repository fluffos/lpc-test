#include <ansi.h>

int main(object me, string arg)
{
    if (arg && file_size(arg) != -1)
    {
        print_r(get_dir(arg));
    }
    else
    {
        print_r(get_dir("/"));
    }

    return 1;
}
