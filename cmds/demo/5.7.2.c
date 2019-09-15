// 示例：5.7.2
int main(object me, string arg)
{
    // 取得游戏中所有已加载对象
    object *obs = objects();
    // 加载 test 对象
    object test_ob = load_object("/cmds/test");
    // 复制 test 对象
    object new_ob = new ("/cmds/test");

    printf("test_ob = %O\n", test_ob);

    foreach (object ob in obs)
    {
        printf("%O\n", ob);
    }

    printf("new_ob = %O\n", new_ob);

    return 1;
}
