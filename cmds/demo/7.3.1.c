// 示例：7.3.1
#define X 11

int main(object me, string arg)
{
#ifdef FLUFFOS
    cecho("driver 是 FLUFFOS!");
#else
    cecho("driver 是 MUDOS!");
#endif

#if X < 1 || X > 10
    cecho("X = " + X);
#else
    cecho("...");
#endif

#ifdef __PACKAGE_DB__
    cecho("支持数据库！");
#endif

    return 1;
}
