int main(object me, string arg)
{
    string str;
    int i, n;

    if (arg && sscanf(arg, "%s %d", str, n) == 2)
    {
        arg = clear_bit(str, n - 1);
        cecho(str);
        // 输出位
        for (i = 60; i > 0; i--)
        {
            write(test_bit(str, i - 1));
        }
        write("\n");
        cecho(arg);
        for (i = 60; i > 0; i--)
        {
            write(test_bit(arg, i - 1));
        }
        write("\n");
    }

    return 1;
}
