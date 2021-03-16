// 查看/cmds/demo/目录下源文件
int main(object me, string arg)
{
    if (!arg)
        return notify_fail("指令格式 : cat <档案名>\n      如 : cat 2.1.1\n");

    sscanf(arg, "%s.c", arg);
    arg = "/cmds/demo/" + arg + ".c";
    if (file_size(arg) < 0)
    {
        return notify_fail("没有找到这个实例，如果你要查看其他文件源码，可以使用 efun/read_file\n");
    }
    else
    {
        write(read_file(arg));
    }

    return 1;
}
