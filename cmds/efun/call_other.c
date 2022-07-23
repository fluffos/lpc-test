// call_other.c
int main(object me, string arg)
{
    object ob;
    string arg1, arg2, err;

    if (!wizardp(me))
    {
        return 0;
    }

    if (!arg || sscanf(arg,"%s %s",arg1, arg2) != 2)
    {
        cecho("指令格式： call_other /path/target function [arg1 arg2 ...]");
    }
    else if (ob = load_object(arg1))
    {
        if (err = catch(call_other(ob, explode(arg2, " "))))
        {
            cecho("运行报错啦~>详细错误信息请看日志记录<：\n" + err);
        }
    }
    else
    {
        cecho("没有找到对象 " + arg1);
    }

    return 1;
}
