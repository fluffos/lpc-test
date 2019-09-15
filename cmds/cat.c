// 查看/cmds/目录下源文件
int main(object me, string arg)
{
    if (!arg)
        return notify_fail("指令格式 : cat <档案名>\n      如 : cat demo/2.1.1\n");

    sscanf(arg, "%s.c", arg);
    arg = "/cmds/" + arg + ".c";
    if (file_size(arg) < 0)
    {
        return notify_fail("cmds 目录下没有找到这个档案 T_T\n");
    }
    else
    {
        write(read_file(arg));
    }

    return 1;
}
