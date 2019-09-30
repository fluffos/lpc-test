// hi.c
int main(object me, string arg)
{
    object ob;
    if (arg &&ob = find_player(arg))
    {
        if (ob == me)
        {
            msg("emote", "$ME热情的和$ME自己打招呼！", me);
        }
        else
        {
            msg("emote", "$ME热情的和$YOU打招呼！", me, ob);
        }
    }
    else
    {
        msg("emote", "$ME热情的和大家打招呼！", me);
    }

    return 1;
}
