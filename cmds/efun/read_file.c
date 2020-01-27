// 查看源文件
int main(object me, string arg)
{
    if (!arg)
        return notify_fail("指令格式 : read_file <档案名>\n      如 : read_file /cmds/demo/2.1.1\n");

    sscanf(arg, "%s.c", arg);
    arg = arg + ".c";
    if (file_size(arg) < 0)
    {
        return notify_fail("目录下没有找到这个档案，你可以使用 get_dir 或 ls 查看列表\n");
    }
    else
    {
        write(read_file(arg));
    }

    return 1;
}
