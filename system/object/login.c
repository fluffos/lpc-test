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

    if (!(arg = filter(arg, (: $1 > 96 && $1 < 123 :))))
    {
        write("名称只能是英文字母（a~z）请重新输入：");
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
    write("请输入你的英文名(限a~z，无关字符会过滤掉)：");
    input_to("setup");
}
