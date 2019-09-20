// 示例：6.2.2

int main(object me, string arg)
{
    int *a, *b = ({1});
    a = copy(b);
    a[0] = 2;
    printf("a = %O\nb = %O\n", a, b);

    return 1;
}
