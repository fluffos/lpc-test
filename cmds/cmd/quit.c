int main(object me, string arg)
{
    say("玩家(" + geteuid(me) + ")退出了游戏。\n");
    destruct(me);

    return 1;
}
