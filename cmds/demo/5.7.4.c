// 示例：5.7.4
inherit "/cmds/demo/5.7.4.1";
inherit "/cmds/demo/5.7.4.2";

int main(object me, string arg)
{
    // 直接调用继承对象中的方法
    test1();
    test2();
    // 直接使用继承对象的全局变量
    debug(s1);
    debug(s2);

    return 1;
}
