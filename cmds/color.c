#include <ansi.h>
inherit CLEAN_UP;

int main(object me, string arg)
{
    int *rgb = ({0x00, 0x33, 0x66, 0x99, 0xcc, 0xff});

    printf("ANSI颜色测试：\n");
    for (int i = 30; i < 50; i++)
    {
        printf(SGR(i) "%d. 你好ABC■■■" NOR, i);
        if (i % 5)
        {
            write("\t");
        }
        else
        {
            write("\n");
        }
    }

    printf("\n\n256颜色测试：\n");
    for (int i = 0; i < 256; i++)
    {
        printf(FCC(i) "%3d. 你好ABC" NOR, i);
        if (i % 5)
        {
            write("\t");
        }
        else
        {
            write("\n");
        }
    }

    printf("\nRGB颜色测试：\n");
    for (int r = 0; r < sizeof(rgb); r++)
    {
        for (int g = 0; g < sizeof(rgb); g++)
        {
            for (int b = 0; b < sizeof(rgb); b++)
            {
                printf(RGB(rgb[r], rgb[g], rgb[b]) "%'0'2x%'0'2x%'0'2x\t" NOR, rgb[r], rgb[g], rgb[b]);
            }
            write("\n");
        }
        write("\n");
    }

    return 1;
}

int help()
{
    write("color 指令用来测试客户端可支持的颜色模式。\n");
    return 1;
}
