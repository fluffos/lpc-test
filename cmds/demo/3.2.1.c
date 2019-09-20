// 示例：3.2.1
int main(object me, string arg)
{
    // 数组合并运算
    int *a, *b, *c;
    a = ({1, 2, 3});
    b = ({3, 2, 1});
    c = a + b;
    c -= ({3});
    printf("c = %O\n", c);
    return 1;
}
