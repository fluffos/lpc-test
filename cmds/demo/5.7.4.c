// 示例：5.7.4
inherit "/cmds/demo/5.7.4.1";
inherit "/cmds/demo/5.7.4.2";

int main(object me, string arg)
{
    test1();
    test2();
    // 直接使用继承对象的全局变量
    printf("%s\n", s1);
    printf("%s\n", s2);

    return 1;
}
