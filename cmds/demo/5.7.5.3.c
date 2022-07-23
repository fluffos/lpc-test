// 示例：5.7.5.3
inherit "/cmds/demo/5.7.5";

int main(object me, string arg)
{
    cecho("示例5.7.5.3");

    s2 = "我是示例5.7.5.3 的 protected 类型变量";
    s3 = "我是示例5.7.5.3 的 public 类型变量";

    ::main(me, arg);

    return 1;
}
