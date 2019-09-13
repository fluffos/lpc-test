#define CMD_PATH "/cmds/"
#define TEST_PATH "/cmds/test/"

int command_hook(string arg);

varargs void create(string arg)
{
    if (clonep())
    {
        enable_commands();
        add_action("command_hook", "", 1);
        set_living_name(arg);
        move_object(VOID_OB);
    }
}

mixed process_input(string verb)
{
    if (strsrch(verb, "chat") == 0)
    {
        return replace_string(verb, "chat", "shout", 0, 1);
    }

    return 0;
}

void receive_message(string type, string message)
{
    receive(message);
}

void receive_snoop(string message)
{
    receive(message);
}

void write_prompt(void)
{
    write(ctime() + " > ");
}

void net_dead( void )
{
    say("玩家 " + this_object() + " 断线了\n");
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
