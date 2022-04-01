#include <ansi.h>
int main(object me, string arg)
{
    string help = @HELP $CYN$
        _        _______  _______   _________ _______  _______ _________
       ( \      (  ____ )(  ____ \  \__   __/(  ____ \(  ____ \\__   __/
       | (      | (    )|| (    \/     ) (   | (    \/| (    \/   ) (
       | |      | (____)|| |           | |   | (__    | (_____    | |
       | |      |  _____)| |           | |   |  __)   (_____  )   | |
       | |      | (      | |           | |   | (            ) |   | |
       | (____/\| )      | (____/\     | |   | (____/\/\____) |   | |
       (_______/|/       (_______/     )_(   (_______/\_______)   )_($NOR$
    $YEL$--------------------------------------------------------------------$NOR$
    ＬＰＣ－ＴＥＳＴ使用指南，请输入 $HIY$tutorial$NOR$ 根据提示操作。
    当你输入$HIY$tutorial user$NOR$后，解锁更多功能，最主要的是可以直接使用 efun
目录下的指令，也可以直接运行 demo 目录下的示例。具体有哪些指令和示例可
以输入以下指令查看：
    get_dir cmds/efun 和 get_dir cmds/demo

HELP;
    string file;

    if (!arg)
    {
        write(ansi(help));
    }
    else if (file_size(file = "/cmds/" + arg + ".c") > 0 || file_size(file = "/cmds/test/" + arg + ".c") > 0 || file_size(file = "/cmds/efun/" + arg + ".c") > 0 || file_size(file = "/verbs/" + arg + ".c") > 0)
    {
        notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
        return file->help();
    }
    else
    {
        return notify_fail("没有这个指令。\n");
    }

    return 1;
}
