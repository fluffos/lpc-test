inherit "/cmds/5.1.1";

protected
void test1()
{
    printf("%s\n", "B:我是 protected test1。");
}

protected
void test4()
{
    printf("%s\n", "B:我覆盖了A中的 test4。");
}

int main(object me, string arg)
{
    test1();
    test2();
    test3();
    test4();
    test();
    return 1;
}

void create()
{
    debug_message("create 5.1.2");
}
