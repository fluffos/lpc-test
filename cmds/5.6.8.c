// 示例：5.6.8
inherit "/cmds/5.6.6";
inherit "/cmds/5.6.7";

string s = "我是示例 5.6.8!";

int main(object me, string arg)
{
    test();
    test2();
    printf("%s\n", s);

    return 1;
}
