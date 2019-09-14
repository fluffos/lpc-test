// 示例：5.3.1.c
int main(object me, string arg)
{
    // 移动当前对象到指令 test 中
    move_object("/cmds/test/test");

    printf("当前对象所在环境：%O\n", environment());
    printf("当前玩家所在环境：%O\n", environment(me));

    // 移动当前对象到当前玩家所在环境中
    move_object(environment(me));

    printf("当前对象所在环境的所有对象：\n");
    foreach (object ob in all_inventory(environment()))
    {
        printf(" - %O\n", ob);
    }
    printf("当前对象所在环境中的第一个对象：%O\n", first_inventory(environment()));
    printf("当前对象所在环境的下一个对象：%O\n", next_inventory());

    // 移动当前对象到当前玩家中
    move_object(me);

    printf("当前玩家所在环境的所有对象：\n");
    foreach (object ob in all_inventory(environment(me)))
    {
        printf(" - %O\n", ob);
    }
    printf("当前玩家中的所有对象：\n");
    foreach (object ob in all_inventory(me))
    {
        printf(" - %O\n", ob);
    }
    printf("当前玩家所在环境的所有对象（包括玩家中的对象）：\n");
    foreach (object ob in deep_inventory(environment(me)))
    {
        printf(" - %O\n", ob);
    }
    printf("当前对象所在环境：%O\n", environment());

    return 1;
}
