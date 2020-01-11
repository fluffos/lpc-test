#include <ansi.h>

#define USER "/inherit/user"
#define USER2 "/inherit/user2"
#define USER3 "/inherit/user3"
#define USER4 "/inherit/user4"

int main(object me, string arg)
{
    object user;

    if (!me->query_temp("step"))
    {
        debug("欢迎光临！\n");
        debug("你当前玩家对象是：" + me);
        debug("你当前所在环境是：" + environment(me));
        debug("你可以使用 look 看看四周！");
        debug("你也可以看看你的对象代码和所在环境的代码都有什么内容。\n");
        debug("是的，现在你无路可走，使用 tutorial user 试试吧。");
    }

    if (arg == "user")
    {
        if (me->query_temp("step") != 1)
        {
            user = new (USER, geteuid(me));
            user->set_temp("step", 1);
            exec(user, me);
            destruct(me);
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + me);
            debug("你当前所在环境是：" + environment(me));
            debug("现在你在新的环境中了，而且可以移动了。");
            debug("但是移动必须输入完整的方向，非常不方便呀，使用 tutorial user 试试吧。");
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
    }

    if (arg == "user2")
    {
        if (me->query_temp("step") != 2)
        {
            user = new (USER2, geteuid(me));
            user->set_temp("step", 2);
            exec(user, me);
            destruct(me);
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
    }

    if (arg == "user3")
    {
        if (me->query_temp("step") != 3)
        {
            user = new (USER3, geteuid(me));
            user->set_temp("step", 3);
            exec(user, me);
            destruct(me);
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
    }

    if (arg == "user4")
    {
        if (me->query_temp("step") != 4)
        {
            user = new (USER4, geteuid(me));
            user->set_temp("step", 4);
            exec(user, me);
            destruct(me);
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
    }

    return 1;
}
