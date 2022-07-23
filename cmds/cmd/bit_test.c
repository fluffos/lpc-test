int main(object me, string arg)
{
    int m, n;

    if (arg && sscanf(arg, "%d %d", m, n) == 2)
    {
        if (n < 1)
        {
            return notify_fail("最小位为 1 ！\n");
        }

        printf("数值 %d 的第 %d 位是 ", m, n);
        cecho(bitCheck(m, n));
        printf("数值 %d 的第 %d 位设置为 1 后结果是 ", m, n);
        cecho(bitSet(m, n));
        printf("数值 %d 的第 %d 位设置为 0 后结果是 ", m, n);
        cecho(bitClear(m, n));
    }
    else
    {
        return notify_fail("格式：bit_test m n\n");
    }

    return 1;
}
