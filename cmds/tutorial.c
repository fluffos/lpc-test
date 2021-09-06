#include <ansi.h>

#define USER "/inherit/user"
#define USER2 "/inherit/user2"
#define USER3 "/inherit/user3"
#define USER4 "/inherit/user4"
#define USER5 "/inherit/user5"

int main(object me, string arg)
{
    object user;

    if (!arg && !me->query_temp("step"))
    {
        debug("欢迎光临！\n");
        debug("你当前玩家对象是：" + file_name(me));
        debug("你当前所在环境是：" + file_name(environment(me)));
        debug("你也可以使用`efun/read_file`看看你的对象代码和所在环境的代码都有什么内容。");
        debug("你可以输入 look 看看四周！");
        debug("现在你无路可走，也不能说话，使用 tutorial user 看看会发生什么吧。");
        return 1;
    }

    switch (arg)
    {
    case "user":
        if (me->query_temp("step") != 1)
        {
            user = new (USER, geteuid(me));
            user->set_temp("step", 1);
            exec(user, me);
            destruct(me);
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + file_name(user));
            debug("你当前所在环境是：" + file_name(environment(user)));
            debug("现在你在新的环境中了，再次输入 look 看看吧。");
            debug("你可以使用更多指令了，如：say shout shutdown 等等");
            debug("你可以使用 east south west north 移动啦");
            debug("\n相关教程：https://bbs.mud.ren/threads/47\n");
            debug("现在移动必须输入完整的方向，非常不方便，使用 tutorial user2 试试吧。");
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
        break;
    case "user2":
        if (me->query_temp("step") != 2)
        {
            user = new (USER2, geteuid(me));
            user->set_temp("step", 2);
            exec(user, me);
            destruct(me);
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + file_name(user));
            debug("你可以更方便的移动了: e s w n");
            debug("你还可以使用更多指令了，如：chat who i l ls");
            debug("\n相关教程参考：https://bbs.mud.ren/threads/48\n");
            debug("如果想看到更多信息，使用 tutorial user3 试试吧。");
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
        break;
    case "user3":
        if (me->query_temp("step") != 3)
        {
            user = new (USER3, geteuid(me));
            user->set_temp("step", 3);
            exec(user, me);
            destruct(me);
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + file_name(user));
            debug("你的人物可以使用更智能的消息显示了，对其他玩家输入 hi 试试，或者看看某个对象吧。");
            debug("你的人物还可以偷窥别人了，对其他玩家输入 snoop 试试。");
            debug("\n相关教程参考：https://bbs.mud.ren/threads/53\n");
            debug("如果想体验战斗，使用 tutorial user4 试试吧。");
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
        break;
    case "user4":
        if (me->query_temp("step") != 4)
        {
            user = new (USER4, geteuid(me));
            user->set_temp("step", 4);
            exec(user, me);
            destruct(me);
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + file_name(user));
            debug("你现在有 HP 了，可以战斗了，试试和其他生物 fight 吧。");
            debug("\n相关教程参考：https://bbs.mud.ren/threads/54\n");
            debug("如果想测试玩家存档功能，使用 tutorial user5 试试吧。");
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
        break;
    case "user5":
        if (me->query_temp("step") != 5)
        {
            user = new (USER5, geteuid(me));
            user->set_temp("step", 5);
            exec(user, me);
            destruct(me);
            debug("恭喜，成功啦！\n");
            debug("你当前玩家对象是：" + file_name(user));
            debug("你现在可以使用存档和读档功能了。");
            debug("\n相关教程参考：https://bbs.mud.ren/threads/46\n");
        }
        else
        {
            debug("你当前就在此状态，无需重复操作！");
        }
        break;

    default:
        debug("你当前玩家对象是：" + file_name(me));
        debug("你当前所在环境是：" + file_name(environment(me)));
        if (arg)
        {
            debug("你输入的 " + arg + " 不被支持，请使用 user1~5。");
        }

        break;
    }

    return 1;
}
