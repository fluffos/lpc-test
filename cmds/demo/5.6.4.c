// 示例：5.6.4
inherit "/cmds/test/5.6.4.1";
inherit "/cmds/test/5.6.4.2";

int main(object me, string arg)
{
    test1();
    test2();
    // 直接使用继承对象的全局变量
    printf("%s\n", s1);
    printf("%s\n", s2);

    return 1;
}
