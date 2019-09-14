// 示例：5.4.1.c
void input(string arg)
{
    if (!arg || arg == "")
    {
        write("内容不能为空，请重新输入：");
        input_to("input");
    }
    else
    {
        write("你输入的内容是：" + arg + "\n");
        write("请输入英文字符：");
        get_char("getchar");
    }
}

void getchar(string arg)
{
    // 注意，这里还应该加上非英文字符判断，否则获取的可能不是你期望的
    if (!arg || arg == "")
    {
        write("字符不能为空，请重新输入：");
        input_to("getchar");
    }
    else
    {
        write("你输入的字符是：" + arg + "\n");
    }
}

int main(object me, string arg)
{
    write("请输入内容：");
    input_to("input");

    return 1;
}
