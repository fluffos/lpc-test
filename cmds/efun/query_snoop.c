// query_snoop.c
int main(object me, string arg)
{
    object snooper, snoopee;

    if (!arg)
    {
        debug("指令格式：query_snoop snoopee");
    }
    else
    {
        if (!objectp(snoopee = find_player(arg)))
        {
            debug("没有找到 " + arg + " 这个玩家，无法查看信息。");
        }
        else if (objectp(snooper = query_snoop(snoopee)))
        {
            printf("玩家 %O 正在被玩家 %O 监听。\n", snoopee, snooper);
        }
        else
        {
            debug("玩家 " + arg + " 没有被任何人监听。");
        }
    }
    return 1;
}