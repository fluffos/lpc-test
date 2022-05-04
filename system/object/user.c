#define CMD_PATH "/cmds/cmd/"
#define DEMO_PATH "/cmds/demo/"
#define TEST_PATH "/cmds/test/"

varargs void create(string arg)
{
    if (clonep())
    {
        enable_commands();
        add_action("command_hook", "", 1);
        seteuid(arg);
        set_living_name(arg);
        move_object(VOID_OB);
    }
}

int command_hook(string arg)
{
    string verb, cmd, demo, test;
    object cmd_ob;

    verb = query_verb();
    cmd = CMD_PATH + verb;
    demo = DEMO_PATH + verb;
    test = TEST_PATH + verb;

    if (cmd_ob = load_object(cmd) || cmd_ob = load_object(test) || cmd_ob = load_object(demo))
    {
        return (int)cmd_ob->main(this_object(), arg);
    }
    else
    {
        return notify_fail("指令不存在，你可以输入 tutorial 寻求帮助。\n");
    }
}

void net_dead()
{
    destruct();
}
