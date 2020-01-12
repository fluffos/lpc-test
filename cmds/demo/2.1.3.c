// 示例：2.1.3
int main(object me, string arg)
{
#ifdef FLUFFOS
    float fa = MAX_FLOAT;
    // 最小值定义有错
    float fi = MIN_FLOAT;

    printf("fa = %f\nfi = %f\n", fa, fi);
#endif
    return 1;
}
