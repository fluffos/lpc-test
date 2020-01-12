// 示例：2.1.1
int main(object me, string arg)
{
#ifdef FLUFFOS
    // MAX_INT、MIN_INT 为 fluffos 定义宏
    int a = MAX_INT, b = MIN_INT;
    // 赋值时做运算
    int c = MAX_INT + 1, d = MIN_INT - 1, e = d - 1;
    // 赋值超出取值范围（10倍）
    int f = 92233720368547758070, g = -92233720368547758080;
    // 输出
    printf("a = % d\nb = % d\nc = % d\nd = % d\ne = % d\nf = % d\ng = % d\n", a, b, c, d, e, f, g);
#endif
    return 1;
}
