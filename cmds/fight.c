int main(object me, string arg)
{
    object ob;

    if (file_name(environment(me)) == VOID_OB)
    {
        return notify_fail("这里禁止战斗。\n");
    }
    if (!arg || !objectp(ob = present(arg, environment(me))))
    {
        debug("你想攻击谁？");
    }
    else if (ob == me)
    {
        debug("你不能攻击自己。");
    }
    else if (ob->is_fighting(me))
    {
        debug("加油！加油！加油！");
    }
    else
    {
        msg("warning", "$ME大喝一声，对$YOU发起了攻击。", me, ob);
        me->fight(ob);
    }

    return 1;
}
