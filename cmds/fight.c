int main(object me, string arg)
{
    object ob;

    if (!me->can_fight())
    {
        return notify_fail("你还没有学会战斗。\n");
    }
    if (file_name(environment(me)) == START_ROOM)
    {
        return notify_fail("这里禁止战斗。\n");
    }
    if (!arg || !objectp(ob = present(arg, environment(me))))
    {
        return notify_fail("你想攻击谁？\n");
    }
    if (ob == me)
    {
        return notify_fail("你不能攻击自己。\n");
    }
    if (!ob->can_fight())
    {
        return notify_fail("对方还不会战斗。\n");
    }
    if (ob->is_fighting(me))
    {
        return notify_fail("加油！加油！加油！\n");
    }

    msg("warning", "$ME大喝一声，对$YOU发起了攻击。", me, ob);
    me->fight(ob);

    return 1;
}

int help()
{
    write(@LONG
指令格式: fight 目标id
指令说明:
    此命令让你可以向目标发动攻击，注意需要进入tutorial user4模式才有效。
LONG );
    return  1;
}
