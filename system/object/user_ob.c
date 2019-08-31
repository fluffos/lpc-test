#define CMD_PATH "/cmds/"
#define TEST_PATH "/cmds/test/"

int command_hook(string arg);

void setup(string arg)
{
    enable_commands();
    add_action("command_hook", "", 1);
    set_living_name(arg);
    move_object(VOID_OB);
}

int command_hook(string arg)
{
    string cmd, test;
    object cmd_ob;

    cmd = CMD_PATH + query_verb();
    test = TEST_PATH + query_verb();

    if (cmd_ob = load_object(cmd) || cmd_ob = load_object(test))
    {
        return (int)cmd_ob->main(this_object(), arg);
    }
    else
    {
        return notify_fail("指令不存在 T_T\n");
    }
}
