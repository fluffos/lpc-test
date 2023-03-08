#include <ansi.h>

#define USER1 "/inherit/user1"
#define USER2 "/inherit/user2"
#define USER3 "/inherit/user3"
#define USER4 "/inherit/user4"
#define USER5 "/inherit/user5"
#define USER6 "/inherit/user6"

int main(object me, string arg)
{
    object user;

    if (!arg && !me->query_temp("step"))
    {
        cecho("欢迎光临！\n");
        cecho("你当前玩家对象是：" + sprintf("%O", me));
        cecho("你当前所在环境是：" + file_name(environment(me)));
        cecho("提示：现在你不能动、不能看、不能说，输入 tutorial 1 看看会发生什么吧。");
        return 1;
    }

    switch (arg)
    {
    case "1":
        if (me->query_temp("step") != 1)
        {
            user = new (USER1, geteuid(me));
            user->set_temp("step", 1);
            exec(user, me);
            destruct(me);
            cecho("恭喜，成功啦！\n");
            cecho("你当前玩家对象是：" + sprintf("%O", user));
            cecho("你当前所在环境是：" + file_name(environment(user)));
            cecho("提示：现在你在新的环境中了，输入 look 或 l 看看吧。");
            cecho("提示：你可以使用更多指令了，如 say shout shutdown 等");
            cecho("提示：你可以使用 east south west north 移动啦");
            cecho("\n相关教程：https://bbs.mud.ren/threads/47\n");
            cecho("提示：现在移动必须输入完整的方向，非常不方便，输入 tutorial 2 试试吧。");
        }
        else
        {
            cecho("你当前就在此状态，无需重复操作！");
        }
        break;
    case "2":
        if (me->query_temp("step") != 2)
        {
            user = new (USER2, geteuid(me));
            user->set_temp("step", 2);
            exec(user, me);
            destruct(me);
            cecho("恭喜，成功啦！\n");
            cecho("你当前玩家对象是：" + sprintf("%O", user));
            cecho("提示：你可以更方便的移动了: e s w n");
            cecho("提示：你还可以使用更多指令了，如 chat、who、i、ls");
            cecho("\n相关教程参考：https://bbs.mud.ren/threads/48\n");
            cecho("提示：你现在有很多消息看不到，不信可以输入 hi 试试");
            cecho("提示：如果想看到更多信息，输入 tutorial 3 试试吧。");
        }
        else
        {
            cecho("你当前就在此状态，无需重复操作！");
        }
        break;
    case "3":
        if (me->query_temp("step") != 3)
        {
            user = new (USER3, geteuid(me));
            user->set_temp("step", 3);
            exec(user, me);
            destruct(me);
            cecho("恭喜，成功啦！\n");
            cecho("你当前玩家对象是：" + sprintf("%O", user));
            cecho("提示：你的人物可以看到更多消息了，包括其它玩家从你身边走过的提示等等");
            cecho("提示：现在开始，你可以看到QQ群消息了，有问题直接在游戏中 chat 和群中玩家交流吧");
            cecho("提示：你的人物还可以偷窥别人了，对其他玩家输入 snoop 试试。");
            cecho("\n相关教程参考：https://bbs.mud.ren/threads/53\n");
            cecho("提示：如果想体验战斗，输入 tutorial 4 试试吧。");
        }
        else
        {
            cecho("你当前就在此状态，无需重复操作！");
        }
        break;
    case "4":
        if (me->query_temp("step") != 4)
        {
            user = new (USER4, geteuid(me));
            user->set_temp("step", 4);
            exec(user, me);
            destruct(me);
            cecho("恭喜，成功啦！\n");
            cecho("你当前玩家对象是：" + sprintf("%O", user));
            cecho("提示：你现在有 HP 了，可以战斗了，试试和其他生物 fight 吧。");
            cecho("\n相关教程参考：https://bbs.mud.ren/threads/54\n");
            cecho("提示：如果想测试玩家存档功能，使用 tutorial 5 试试吧。");
        }
        else
        {
            cecho("你当前就在此状态，无需重复操作！");
        }
        break;
    case "5":
        if (me->query_temp("step") != 5)
        {
            user = new (USER5, geteuid(me));
            user->set_temp("step", 5);
            exec(user, me);
            destruct(me);
            cecho("恭喜，成功啦！\n");
            cecho("你当前玩家对象是：" + sprintf("%O", user));
            cecho("提示：你现在可以使用存档和读档功能了。");
            cecho("\n相关教程参考：https://bbs.mud.ren/threads/46\n");
            cecho("提示：系统暂未提供存档读档指令，你可以使用`eval`管理指令测试功能。");
            cecho("  如：eval me->save() 或 eval me->load()");
        }
        else
        {
            cecho("你当前就在此状态，无需重复操作！");
        }
        break;
    case "6":
        if (me->query_temp("step") != 6)
        {
            user = new (USER6, geteuid(me));
            user->set_temp("step", 6);
            exec(user, me);
            destruct(me);
            cecho("恭喜，成功啦！\n");
            cecho("你当前玩家对象是：" + sprintf("%O", user));
            cecho("提示：你现在拥有更多能力了，如播放客户端的声音等。");
            cecho("提示：如果你使用的是mudlet客户端，进入传送门后会听到美妙的音乐。");
        }
        else
        {
            cecho("你当前就在此状态，无需重复操作！");
        }
        break;

    default:
        cecho("你当前玩家对象是：" + sprintf("%O", me));
        cecho("你当前所在环境是：" + file_name(environment(me)));
        if (arg)
        {
            cecho("你输入的 " + arg + " 不被支持，请使用 1~6。");
        }

        break;
    }

    return 1;
}
