int main(object me, string arg)
{
    string str;
    int n;

    if (arg && sscanf(arg, "%s %d", str, n) == 2)
    {
        if (n < 1)
        {
            return notify_fail("最小位为 1 ！\n");
        }

        printf("字符串 %s 的第 %d 位是 %d\n", str, n, test_bit(arg, n - 1));
        for (int i = 60; i > 0; i--)
        {
            write(test_bit(str, i - 1));
        }
        write("\n");
    }
    else
    {
        return notify_fail("格式：test_bit str n\n");
    }

    return 1;
}
