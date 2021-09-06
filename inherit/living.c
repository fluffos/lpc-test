// 生物对象共同继承

void set_living(string id)
{
    enable_commands();
    if (id)
    {
        set_living_name(id);
        seteuid(id);
    }
}

// present() - 通过 id 查找对象
int id(string id)
{
    return geteuid() == id;
}

// NPC消息界面
// catch_tell()
// void catch_tell(string msg)
// {
//     debug_message(this_object() + msg);
// }

// 方便移动对象到指定环境
int move(mixed dest)
{
    move_object(dest);

    if (interactive(this_object()))
    {
        command("look");
    }

    return 1;
}

// 生物执行指令接口
int command(string cmd)
{
    return efun::command(cmd);
}
