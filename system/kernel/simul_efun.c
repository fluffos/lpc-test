#include <ansi.h>

#ifndef FLUFFOS

mixed abs(mixed n)
{
    if (!floatp(n) && !intp(n))
        return 0;

    return (n < 0) ? -n : n;
}

mixed element_of(mixed *arr)
{
    return arr[random(sizeof(arr))];
}

#endif

void debug(mixed arg)
{
    string *color = ({HIB, HIC, HIG, HIM, HIR, HIW, HIY});

    if (objectp(arg))
    {
        arg = file_name(arg);
    }

    write(element_of(color) + arg + NOR "\n");
}

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
                // 兼容 MUDOS
                if (objectp(arr[i]))
                {
                    arr[i] = file_name(arr[i]);
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

//检查state的第pos位是否为1
int bitCheck(int state, int pos)
{
    return state & (1 << (pos - 1));
}

//将state的第pos位的值设为1
int bitSet(int state, int pos)
{
    return state | (1 << (pos - 1));
}

//将state的第pos位的值设为0
int bitClear(int state, int pos)
{
    return state & (~(1 << (pos - 1)));
}
