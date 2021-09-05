/*
 * @Author: 雪风@mud.ren
 * @Date: 2021-09-05 12:15:32
 * @LastEditTime: 2021-09-05 13:39:47
 * @LastEditors: 雪风
 * @Description: 玩家存档与读档接口
 *  https://bbs.mud.ren
 */
inherit __DIR__ "user4";

// void create(){}

// 指定存档位置
string query_save_file()
{
    return "/data/" + geteuid(this_object());
}

int save()
{
    string file;

    if (stringp(file = this_object()->query_save_file()))
        return save_object(file);

    return 0;
}

int load()
{
    string file;

    if (stringp(file = this_object()->query_save_file()))
        return restore_object(file);

    return 0;
}
