// 示例：5.7.5
private string s1;
protected string s2;
public string s3;

void create()
{
    s1 = "我是示例5.7.5 的 private 类型变量";
    s2 = "我是示例5.7.5 的 protected 类型变量";
    s3 = "我是示例5.7.5 的 public 类型变量";
}

private void test1()
{
    debug("调用 test1 方法");
    debug("我是示例5.7.5 的 private 类型函数");
}

protected void test2()
{
    debug("调用 test2 方法");
    debug("我是示例5.7.5 的 protected 类型函数");
}

public void test3()
{
    debug("调用 test3 方法");
    debug("我是示例5.7.5 的 public 类型函数");
}

void test()
{
    debug("调用 test 方法");
    debug(s1);
    debug(s2);
    debug(s3);
}

int main(object me, string arg)
{
    debug("调用 main 方法");
    test();
    test1();
    test2();
    test3();

    return 1;
}

void set_s1(string s)
{
    s1 = s;
}

string get_s1()
{
    return s1;
}
