// environment.c
int main(object me, string arg)
{
    object ob, env;

    if (!arg)
    {
        if (env = environment(me))
        {
            cecho("你在 " + file_name(env) + " 中");
        }
        else
        {
            cecho("你没在任何环境中");
        }
    }
    else if (ob = find_object(arg))
    {
        if (env = environment(ob))
        {
            cecho("对象 " + arg + " 在 " + file_name(env) + " 中");
        }
        else
        {
            cecho("对象没在任何环境中");
        }
    }
    else
    {
        cecho("没有找到对象 " + arg);
    }

    return 1;
}
