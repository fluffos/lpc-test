/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-03-31 15:04:35
 * @LastEditTime: 2022-05-11 15:13:34
 * @LastEditors: 雪风
 * @Description: 自定义 user 对象
 *  https://bbs.mud.ren
 */
#include <ansi.h>
inherit LIVING;

varargs void create(string arg)
{
    if (clonep())
    {
        string *name1 = ({"赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈", "褚", "卫", "蒋", "沈", "韩", "杨"});
        string *name2 = ({"春", "夏", "秋", "冬", "风", "花", "雪", "月", "天", "地", "玄", "黄", "宇", "宙", "洪", "荒"});

        ::create();
        set_living(arg);
        set("gender", random(2) ? "男" : "女");
        set("name", element_of(name1) + element_of(name2));
        move_object(START_ROOM);
    }
    else
    {
        // 自动加载VERB指令
        map(get_dir("/verbs/*.c"), function(string file) {
                return "/verbs/" + file;
        })->load();
    }
}

void net_dead()
{
    say(HIR "玩家(" + geteuid() + ")离开了游戏。\n" NOR);
    destruct();
}
