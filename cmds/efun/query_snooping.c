// query_snooping.c
int main(object me, string arg)
{
    object snooper, snoopee;

    if (!arg)
    {
        cecho("指令格式：query_snooping snooper");
    }
    else
    {
        if (!objectp(snooper = find_player(arg)))
        {
            cecho("没有找到 " + arg + " 这个玩家，无法查看信息。");
        }
        else if (objectp(snoopee = query_snooping(snooper)))
        {
            printf("玩家 %O 正在监听玩家 %O。\n", snooper, snoopee);
        }
        else
        {
            cecho("玩家 " + arg + " 没有监听任何人。");
        }
    }

    return 1;
}
