private
void test1()
{
    printf("%s\n", "A:我是 private test1。");
}

protected
void test2()
{
    printf("%s\n", "A:我是 protected test2。");
}

public
void test3()
{
    printf("%s\n", "A:我是 public test3。");
}

void test4()
{
    printf("%s\n", "A:我还是 public test4。");
}

void test()
{
    printf("%s\n", "A:我是 public 并且 nomask test。");
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
