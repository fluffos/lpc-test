// 自定义 user 对象
inherit DBASE;
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
        set_living(arg);
        set("gender", random(2) ? "男" : "女");
        add_action("command_hook", "", 1);
        move_object(START_ROOM);
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
        // return notify_fail("指令不存在 ^_^\n");
        return 0;
    }

    return 1;
}

int move_or_destruct(object dest)
{
    debug("突然一阵时空扭曲，你被传送到虚空。");
    move(VOID_OB);

    return 1;
}
