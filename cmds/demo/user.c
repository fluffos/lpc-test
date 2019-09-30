// 自定义 user 对象
#define CMD_PATH "/cmds/"
#define TEST_PATH "/cmds/test/"
#define GO_CMD "/cmds/go"

varargs void create(string arg)
{
    if (clonep())
    {
        enable_commands();
        add_action("command_hook", "", 1);
        seteuid(arg);
        set_living_name(arg);
        move_object(__DIR__ "kedian");
    }
}

int main(object me, string arg)
{
    object user;
    string file;

    if (base_name(me) == (file = file_name()))
    {
        debug("请不要重复操作。");
    }
    else
    {
        user = new(file, geteuid(me));
        exec(user, me);
        destruct(me);
    }

    return 1;
}

nomask int command_hook(string arg)
{
    string verb, cmd, test;
    object me, cmd_ob;

    verb = query_verb();
    cmd = CMD_PATH + verb;
    test = TEST_PATH + verb;
    me = this_object();

    if ((verb = trim(verb)) == "")
        return 0;

    if (!arg && (objectp(environment()) && stringp(environment()->query("exits/" + verb))))
    {
        call_other(GO_CMD, "main", me, verb);
    }
    else if (cmd_ob = load_object(cmd) || cmd_ob = load_object(test))
    {
        call_other(cmd_ob, "main", me, arg);
    }
    else
    {
        return notify_fail("指令不存在 ^_^\n");
    }

    return 1;
}

int move(mixed dest)
{
    move_object(dest);
    command("look");

    return 1;
}

int move_or_destruct(object dest)
{
    debug("突然一阵时空扭曲，你被传送到虚空。");
    move(VOID_OB);

    return 1;
}
