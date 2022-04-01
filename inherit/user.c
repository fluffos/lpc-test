/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-03-31 15:04:35
 * @LastEditTime: 2022-04-01 14:33:36
 * @LastEditors: 雪风
 * @Description: 自定义 user 对象
 *  https://bbs.mud.ren
 */
inherit LIVING;

#define CMD_PATH "/cmds/"
#define TEST_PATH "/cmds/test/"
#define EFUN_PATH "/cmds/efun/"
#define DEMO_PATH "/cmds/demo/"
#define GO_CMD "/cmds/go"

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
        add_action("command_hook", "", 1);
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

nomask int command_hook(string arg)
{
    string verb, cmd, test, efun_cmd, demo;
    object me, cmd_ob;

    verb = query_verb();
    cmd = CMD_PATH + verb;
    test = TEST_PATH + verb;
    efun_cmd = EFUN_PATH + verb;
    demo = DEMO_PATH + verb;
    me = this_object();

    if ((verb = trim(verb)) == "")
        return 0;

    if (!arg && (objectp(environment()) && stringp(environment()->query("exits/" + verb))))
    {
        call_other(GO_CMD, "main", me, verb);
    }
    else if (cmd_ob = load_object(cmd) || cmd_ob = load_object(test) || cmd_ob = load_object(efun_cmd) || cmd_ob = load_object(demo))
    {
        return (int)cmd_ob->main(me, arg);
    }
    else
    {
        mixed err = parse_sentence(arg ? verb + " " + arg : verb, 0);
        if (intp(err))
        {
            switch (err)
            {
            case 1: // verb 匹配成功
                return 1;
            default:
                return 0;
            }
        }
        return notify_fail(err);
    }

    return 1;
}

int move_or_destruct(object dest)
{
    debug("突然一阵时空扭曲，你被传送到虚空。");
    move(VOID_OB);

    return 1;
}
