// 示例：2.1.6
int main(object me, string arg)
{
    string s = "www.mud.ren";

    printf("s = %s\n", s);

    printf("s[4..4] = %s\n", s[4..4]);
    printf("s[4] = %c\n",s[4]);
    printf("s[4] = %d\n",s[4]);
    printf("s[4..6] = %s\n", s[4..6]);

    printf("s[0..20] = %s\n", s[0..20]);
    printf("s[7..] = %s\n", s[7..]);

    printf("s[4..<1] = %s\n", s[4..<1]);
    printf("s[<7..<5] = %s\n", s[<7..<5]);

    printf("s[1..0] = %s\n", s[1..0]);
    printf("s[20..30] = %s\n", s[20..30]);
    printf("s[<5..<7] = %s\n", s[<5..<7]);

    return 1;
}
