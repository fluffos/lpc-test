#include <ansi.h>

// 数字字符串转数字
int atoi(string str)
{
    int v;

    if (!stringp(str) || !sscanf(str, "%d", v))
        return 0;

    return v;
}

// 数组打印
varargs void print_r(mixed *arr, int step)
{
    int i, j;
    if (sizeof(arr))
    {
        write(YEL "({\n" NOR);

        for (i = 0; i < sizeof(arr); i++)
        {
            if (arrayp(arr[i]))
            {
                step++;
                for (j = 0; j < step; j++)
                {
                    write("    ");
                }
                write(i + " => ");
                print_r(arr[i], step);
                step--;
            }
            else
            {
                for (j = 0; j <= step; j++)
                {
                    write("    ");
                }
                write(i + " => " + arr[i] + "\n");
            }
        }

        for (j = 0; j < step; j++)
        {
            write("    ");
        }
        write(YEL "})\n" NOR);
    }
    else
    {
        write(YEL "({ })\n" NOR);
    }
}
