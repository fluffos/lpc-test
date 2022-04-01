/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-04-01 10:51:31
 * @LastEditTime: 2022-04-01 11:24:30
 * @LastEditors: 雪风
 * @Description: 游戏实体对象（不包括环境）公共方法
 *  https://bbs.mud.ren
 */

inherit DBASE;

// present() 调用 - 通过 id 查找对象
int id(string id)
{
    return (geteuid() == id) || (geteuid()[0..0] == id);
}

// parser 调用，根据字符串查询对象
string *parse_command_id_list()
{
    return ({geteuid(), geteuid()[0..0]});
}

// 方便移动对象到指定环境
int move(mixed dest)
{
    move_object(dest);

    if (interactive(this_object()))
    {
        command("look");
    }

    return 1;
}

// 对象简称
string short()
{
    return sprintf("%s(%s)", query("name")||"???", geteuid());
}

// 对象描述
string long()
{
    return query("long") || short();
}
