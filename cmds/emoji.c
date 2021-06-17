// emoji.c

int main(object me, string arg)
{
    int x = 0x1f300;
    int i;

    for (i = 0; i < 16; i++)
    {
        printf("\t %x", i);
    }
    for (i = 0; i < 976; i++)
    {
        if (i % 16 == 0)
        {
            printf("\n%x\t", x);
        }
        printf("%c\t", x);
        x++;
    }
    write("\n");
    for (i = 0; i < 16; i++)
    {
        printf("\t %x", i);
    }
    write("\n");

    return 1;
}
