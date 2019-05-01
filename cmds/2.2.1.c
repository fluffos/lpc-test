// 示例：2.2.1
int main(object me, string arg)
{
    buffer bf = read_buffer("/include/globals.h", 0, 1000);
    buffer BF = read_buffer("/cmds/2.2.1.c", 0, 1000);

    bf += BF;
    for (int i = 0; i < sizeof(bf); i++)
    {
        printf("%c", bf[i]);
    }

    return 1;
}
