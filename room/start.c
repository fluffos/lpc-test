void init()
{
    add_action("do_action", "action");
}

int do_action(string arg)
{
    write("action arg = " + arg + "\n");
    return 1;
}
