// 生物对象公共方法
inherit OBJECT;
inherit VERB;

#define CMD_PATH "/cmds/cmd/"
#define DEMO_PATH "/cmds/demo/"
#define EFUN_PATH "/cmds/efun/"
#define TEST_PATH "/cmds/test/"

int is_living() { return 1; }

void set_living(string id)
{
    enable_commands();
    if (id)
    {
        set_living_name(id);
        seteuid(id);
    }
    add_action("command_hook", "", 1);
}

// NPC消息界面 catch_tell()
// void catch_tell(string msg)
// {
//     debug_message(this_object() + msg);
// }

// 生物执行指令接口
int command(string cmd)
{
    return efun::command(cmd);
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

    if (!arg && (objectp(environment()) && environment()->query("exits/" + verb)))
    {
        me->command("go " + verb);
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
