// 示例：5.6.1
int main(object me, string arg)
{
    // 取得游戏中所有已加载对象
    object *obs = objects();

    // 循环输出对象数组中的对象
    foreach (object ob in obs)
    {
        printf("%O\n", ob);
    }

    return 1;
}
