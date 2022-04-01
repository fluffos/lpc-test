/*
 * @Author: 雪风@mud.ren
 * @Date: 2021-09-05 12:15:32
 * @LastEditTime: 2022-03-31 14:23:41
 * @LastEditors: 雪风
 * @Description: 玩家存档与读档接口
 *  https://bbs.mud.ren
 */
inherit __DIR__ "user4";

// void create(){}

// 指定存档位置
varargs string query_save_file(string data)
{
    return "/data/" + (data || geteuid(this_object()));
}

varargs int save(string data)
{
    string file;

    if (stringp(file = this_object()->query_save_file(data)))
        return save_object(file);

    return 0;
}

varargs int load(string data)
{
    string file;

    if (stringp(file = this_object()->query_save_file(data)))
        return restore_object(file);

    return 0;
}
