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
    ＬＰＣ－ＴＥＳＴ使用指南，刚登录游戏的玩家请输入 $HIY$tutorial$NOR$ 根据提示操作。
    当你进入游戏后，会发现自己除了可以使用以下指令外，什么也做不了（不能动、不能看、不能说）：
        $CYN$bit_test$NOR$    位运算测试指令，如：bit_test 2 1
        $CYN$cat$NOR$         教程示例代码查看指令，如：cat 2.1.1
        $CYN$color$NOR$       颜色测试指令，显示你的客户端支持的颜色
        $CYN$data$NOR$        存档数据查看指令，查看对象的可存档数据
        $CYN$emoji$NOR$       emoji字符列表，显示常用的emoji表情
        $CYN$eval$NOR$        强大而简单的游戏测试指令，需wizard权限
        $CYN$help$NOR$        显示帮助文件，也可以输入 help [cmd] 查看指令使用说明，如：help fight
        $CYN$hi$NOR$          智能消息测试指令，可以和其他玩家打招呼
        $CYN$loadall$NOR$     游戏代码调试用，加载所有文件到内存，看看是否有错
        $CYN$mudinfo$NOR$     显示游戏信息，使用 mudinfo -v 可显示更多内容
        $CYN$quit$NOR$        退出游戏
        $CYN$tutorial$NOR$    游戏向导，可以逐步解锁更多能力，也可根据相关代码学习具体实现
        $CYN$update$NOR$      代码更新指令，修改代码后使用此指令更新生效
        $CYN$variables$NOR$   对象全局变量查看指令，能比 data 指令查看更多的内容
        $CYN$wizard$NOR$      开启wizard权限，允许使用eval指令

    当你输入$HIY$tutorial user$NOR$后，会解锁更多功能，你慢慢变的能看、能动、能说、能战斗。

    另外还可以可以直接使用 efun 目录下的指令。具体有哪些指令和示例可以输入以下指令查看：
        $CYN$get_dir cmds/efun$NOR$

    提示：如有疑问，可以在输入$HIY$tutorial user3$NOR$后，在线$HIC$chat 问题内容$NOR$寻求QQ群中网友的帮助。
HELP;
    string file;

    if (!arg)
    {
        write(ansi(help));
    }
    else if (file_size(file = "/cmds/cmd/" + arg + ".c") > 0 || file_size(file = "/cmds/test/" + arg + ".c") > 0 || file_size(file = "/cmds/efun/" + arg + ".c") > 0 || file_size(file = "/verbs/" + arg + ".c") > 0)
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
