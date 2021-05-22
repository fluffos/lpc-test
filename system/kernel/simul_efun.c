#include <ansi.h>
#include "simul_efun/json.c"

// 随机颜色输出，调试用
void debug(mixed arg)
{
    string *color = ({HIB, HIC, HIG, HIM, HIR, HIW, HIY});

    if (objectp(arg))
    {
        arg = file_name(arg);
    }

    write(element_of(color) + arg + NOR "\n");
}

// 判断是否为中文
int is_chinese(string str)
{
    if (!str)
        return 0;

    return pcre_match(str, "^\\p{Han}+$");
}

// 对象代称，不指定参数为返回当前玩家的代称
varargs string pronoun(mixed arg, int type)
{
    if (!objectp(arg))
    {
        return "你";
    }
    else
    {
        arg = arg->query("gender");
        switch (type)
        {
        case 1:
            return "自己";
        case 2:
            return "你";
        case 3:
        default:
            switch (arg)
            {
            case "男":
                return "他";
            case "女":
                return "她";
            default:
                return "它";
            }
        }
    }
}

// 目标广播
varargs void boardcast(string type, string msg, object me, object you, object *others, object *exclude)
{
    string my_name, my_msg, your_name, your_msg, other_msg;

    if (!msg || !objectp(me))
        return;
    my_name = me->query("name") || capitalize(geteuid(me));

    // 对 me 显示的消息
    my_msg = replace_string(msg, "$ME", pronoun());
    // 对 others 显示的消息
    other_msg = replace_string(msg, "$ME", my_name);
    // 对 you 的消息处理
    if (objectp(you) && living(you))
    {
        your_name = you->query("name") || capitalize(geteuid(you));
        // 对 me 显示的消息
        my_msg = replace_string(my_msg, "$YOU", your_name, 1);
        my_msg = replace_string(my_msg, "$YOU", pronoun(you));
        // 对 you 显示的消息
        your_msg = replace_string(msg, "$ME", my_name, 1);
        your_msg = replace_string(your_msg, "$ME", pronoun(me));
        your_msg = replace_string(your_msg, "$YOU", pronoun());
        // 对 others 显示的消息
        other_msg = replace_string(other_msg, "$YOU", your_name);
        // 对 you 送出信息
        if (!arrayp(exclude) || member_array(you, exclude) == -1)
            message(type, your_msg, you);
    }
    // 对 me 送出信息
    if (!arrayp(exclude) || member_array(me, exclude) == -1)
        message(type, my_msg, me);
    // 对其他人送出信息
    if (arrayp(others))
    {
        exclude = (exclude || ({})) + (you ? ({me, you}) : ({me}));
        message(type, other_msg, others, exclude);
    }
}

// 区域广播
varargs void msg(string type, string msg, object me, object you, object *exclude)
{
    object *others = all_inventory(environment(me));
    boardcast(type, msg, me, you, others, exclude);
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

// 读取文件按行返回数组
string *update_file(string file)
{
    string *arr;
    string str;
    int i;

    str = read_file(file);
    if (!str) {
        return ({});
    }
    arr = explode(str, "\n");
    for (i = 0; i < sizeof(arr); i++) {
        if (arr[i][0] == '#') {
            arr[i] = 0;
        }
    }
    arr -= ({ 0 });
    return arr;
}
