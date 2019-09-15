// 示例：7.2.2
#define F(f) f
#define STR(s) #s

int main(object me, string arg)
{
    debug(F("mud.ren"));
    // 不能使用，debug(F(mud.ren)); 会报错！
    debug(STR(mud.ren));
    debug(STR("mud.ren"));

    return 1;
}
