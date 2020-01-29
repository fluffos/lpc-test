// 更新文件指令（重新载入对象）
int main(object me, string file)
{
    object ob, env = environment(me);

    if (!file)
    {
        return notify_fail("指令：update /文件路径/文件名\n例如：update /cmds/shutdown \n");
    }

    if (file == "here")
    {
        if (env)
            file = file_name(env);
        else
            return notify_fail("你不在任何环境中。\n");
    }

    if (file == VOID_OB)
    {
        return notify_fail("你不能在 VOID_OB 里编译 VOID_OB。\n");
    }

    write("编译[" + file + "]:");

    if (ob = find_object(file))
    {
        destruct(ob);
    }

    if (objectp(load_object(file)))
    {
        write("成功!\n");
    }
    else
    {
        write("失败，对象不存在!\n");
    }

    return 1;
}
