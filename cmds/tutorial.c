#include <ansi.h>

#define USER "/inherit/user"
#define USER2 "/inherit/user2"
#define USER3 "/inherit/user3"
#define USER4 "/inherit/user4"

int main(object me, string arg)
{
    object user;

    if (!arg)
    {
        if (!me->query_temp("step"))
        {
            debug("欢迎光临！\n");
            debug("你当前玩家对象是：" + me);
            debug("你当前所在环境是：" + environment(me));
            debug("你也可以看看你的对象代码和所在环境的代码都有什么内容。");
            debug("你可以输入 look 看看四周！");
            debug("现在你无路可走，也不能说话，使用 tutorial user 看看会发生什么吧。");
        }
        else
        {
            debug("你当前玩家对象是：" + me);
            debug("你当前所在环境是：" + environment(me));
        }
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
            debug("你当前玩家对象是：" + user);
            debug("你当前所在环境是：" + environment(user));
            debug("现在你在新的环境中了，可以输入出口方向移动了。");
            debug("你可以使用更多指令了，如：say shout");
            debug("\n相关教程：https://bbs.mud.ren/threads/47\n");
            debug("但是移动必须输入完整的方向，非常不方便呀，使用 tutorial user2 试试吧。");
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
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + user);
            debug("你可以更方便的移动了，使用更多指令了，如：chat who l");
            debug("\n相关教程参考：https://bbs.mud.ren/threads/48\n");
            debug("如果想变得更智能，使用 tutorial user3 试试吧。");
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
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + user);
            debug("你的人物可以偷窥别人了，也可以使用更智能的消息显示了。");
            debug("\n相关教程参考：https://bbs.mud.ren/threads/53\n");
            debug("如果想体验战斗，使用 tutorial user4 试试吧。");
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
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + user);
            debug("你现在可以战斗了，试试和其他玩家 fight 吧。");
            debug("\n相关教程参考：https://bbs.mud.ren/threads/54\n");
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
    }

    return 1;
}
