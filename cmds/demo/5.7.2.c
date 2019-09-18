// 示例：5.7.2
int main(object me, string arg)
{
    // 复制 test 对象
    object new_ob = new("/cmds/test/test");

    // 取得游戏中所有已加载的复制对象
    object *obs = objects((:clonep:));

    printf("%O\n", obs);
    printf("new_ob = %O\n", new_ob);

    return 1;
}
