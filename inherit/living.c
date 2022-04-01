// 生物对象公共方法
inherit OBJECT;
inherit VERB;

int is_living() { return 1; }

void set_living(string id)
{
    enable_commands();
    if (id)
    {
        set_living_name(id);
        seteuid(id);
    }
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
