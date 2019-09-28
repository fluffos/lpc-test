inherit __DIR__ "user2";

int main(object me, string arg)
{
    object user;

    if (base_name(me) == file_name(this_object()))
    {
        debug("请不要重复操作。");
    }
    else
    {
        user = new (__FILE__, geteuid(me));
        exec(user, me);
        destruct(me);
    }

    return 1;
}

void receive_message(string type, string message)
{
    receive(message);
}

void receive_snoop(string message)
{
    receive(message);
}

void write_prompt()
{
    write(ctime() + " > ");
}

void net_dead()
{
    say("玩家(" + geteuid() + ")断线了。\n");
}
