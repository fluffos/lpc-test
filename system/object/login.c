/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: login_ob.c
Description: 玩家登录连线对象
Author: xuefeng
Version: v1.0
Date: 2019-04-18
*****************************************************************************/
#define WELCOME "/README"

void setup(string arg)
{
    object from, to;

    if (!arg || arg == "")
    {
        write("ID不能为空，请重新输入：");
        input_to("setup");
    }
    else
    {
        from = this_object();
        to = new(USER_OB, arg);
        exec(to, from);
    }
}

void logon()
{
    write(read_file(WELCOME));
    write("请输入你的ID：");
    input_to("setup");
}
