#include <ansi.h>

int main(object me, string arg)
{
    int id;
    object ob;

    if (ob = new(arg))
    {
        sscanf(file_name(ob), "%*s#%s", id);
        write(HIG "新对象 " + arg + " 的编号是 " + id + "\n" NOR);
    }
    else
    {
        write(HIR + arg + "载入失败！\n" NOR);
    }

    return 1;
}
