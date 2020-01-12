// 示例：7.3.1
#define X 11

int main(object me, string arg)
{
#ifdef FLUFFOS
    debug("driver 是 FLUFFOS!");
#else
    debug("driver 是 MUDOS!");
#endif

#if X < 1 || X > 10
    debug("X = " + X);
#else
    debug("...");
#endif

#ifdef __PACKAGE_DB__
    debug("支持数据库！");
#endif

    return 1;
}
