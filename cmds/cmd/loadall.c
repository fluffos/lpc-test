#include <ansi.h>
inherit CLEAN_UP;

int loadall(string dir);

int main(object me, string dir)
{
    if (!dir)
        dir = "/";
    if (dir[ < 1] != '/')
        dir += "/";
    if (file_size(dir) != -2)
        return notify_fail(dir + "目录不存在···\n");

    write("check dir " + dir + "\n");
    if (loadall(dir))
        return 1;
}

int loadall(string dir)
{
    string file, err, *dirs;

    if (!arrayp(get_dir(dir)))
        return 1;

    dirs = get_dir(dir);
    if (dir == "/")
        dirs = dirs - ({".git", ".vscode", "data", "log", "tmp", "www"});
    if (dir == "/cmds/")
        dirs = dirs - ({"test", "demo"});

    foreach (file in dirs)
    {
        if (member_array(file, ({"simul_efun", "master"})) > -1)
            continue;

        reset_eval_cost();
        switch (file_size(dir + file))
        {
        case -1:
            //无法读取该目录，跳过
            break;
        case -2:
            if (file != "." && file != "..")
                call_out("loadall", 1, dir + file + "/");
            break;
        default:
            if ((dir + file)[ < 2.. < 1] == ".c")
            {
                if (err = catch (load_object(dir + file)))
                    cecho("loadall", "\n\tcheck : " + dir + file + "\n" + err);
            }
        }
    }
    write("check dir " + dir + " is ok.\n");
    return 1;
}
