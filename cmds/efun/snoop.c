// snoop.c
int main(object me, string arg)
{
    string arg1, arg2;
    object snooper, snoopee;

    if (!arg)
    {
        cecho("指令格式：snoop snooper [snoopee]");
    }
    else if (sscanf(arg, "%s %s", arg1, arg2) == 2)
    {
        if (!objectp(snooper = find_player(arg1)))
        {
            cecho("没有找到 " + arg1 + " 这个玩家。");
        }
        else if (!objectp(snoopee = find_player(arg2)))
        {
            cecho("没有找到 " + arg2 + " 这个玩家。");
        }
        else if (snoop(snooper, snoopee))
        {
            cecho(arg1 + " 开始窃听 " + arg2 + "。");
        }
        else
        {
            cecho("窃听失败！");
        }
    }
    else
    {
        if (!objectp(snooper = find_player(arg)))
        {
            cecho("没有找到 " + arg + " 这个玩家。");
        }
        else if (snoop(snooper))
        {
            cecho("已关闭 " + arg + " 的所有监听。");
        }
        else
        {
            cecho("关闭失败！");
        }
    }

    return 1;
}
