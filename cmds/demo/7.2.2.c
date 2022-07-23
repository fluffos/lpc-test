// 示例：7.2.2
#define F(f) f
#define STR(s) #s

int main(object me, string arg)
{
    cecho(F("mud.ren"));
    // 不能使用，cecho(F(mud.ren)); 会报错！
#ifdef FLUFFOS
    cecho(STR(mud.ren));
    cecho(STR("mud.ren"));
#endif
    return 1;
}
