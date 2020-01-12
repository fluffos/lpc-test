// 示例：2.1.7
int main(object me, string arg)
{
    string *str = ({"www", "mud", "ren"});
#ifdef FLUFFOS
    int *arr = allocate(1 + random(9), (: $1 :));
#else
    int *arr = allocate(1 + random(9));
#endif
    // @代表参数是数组，使用除@以外的格式循环输出数组的每个元素
    printf("str = %@-4s\n", str);
    printf("str[0] = %s, str[1] = %s, str[2] = %s\n", str[0], str[1], str[2]);
    printf("arr = %@','-2d\n", arr);

    return 1;
}
