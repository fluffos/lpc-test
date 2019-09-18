// 示例：5.7.5.2
inherit "/cmds/demo/5.7.5";

int main(object me, string arg)
{
    debug("直接继承变量!");
    debug(s2);
    debug(s3);
    debug("直接继承方法!");
    test2();
    test3();
    // 可以修改变量的值
    set_s1("我是 5.7.5.2 通过方法修改的 s1");
    s2 = "我是 5.7.5.2 直接修改 s2";
    s3 = "我是 5.7.5.2 直接修改 s3";
    test();

    return 1;
}
