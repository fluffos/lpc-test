inherit VERB;

#include <ansi.h>

protected void create()
{
    verb::create();
    setVerb("fight");
    setSynonyms("kill", "hit");
    setRules("LIV");
    setErrorMessage("你想和谁战斗？");
}

mixed can_fight_liv(mixed *data...)
{
    object me = this_player();
    // cecho(data);
    if (file_name(environment(me)) == START_ROOM)
    {
        return "这里禁止战斗。";
    }
    return me->can_fight() || HIY "你无法战斗。" NOR;
}

mixed direct_fight_liv(object ob, string arg)
{
    if (ob == this_player())
        return HIM "你真有想法，可惜你做不到自己和自己战斗。" NOR;
    return ob->can_fight();
}

int do_fight_liv(object ob, string arg)
{
    object me = this_player();

    msg("warning", "$ME大喝一声，对$YOU发起了攻击。", me, ob);
    me->fight(ob);

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : fight | hit | kill

战斗指令，可以向其它生物发起战斗。

HELP );
    return 1;
}
