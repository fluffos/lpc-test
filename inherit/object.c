/*
 * @Author: 雪风@mud.ren
 * @Date: 2022-04-01 10:51:31
 * @LastEditTime: 2022-04-03 19:16:02
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
    object me = this_object();
    object env = environment(me);

    // 如果由area移出, 在這做move_out動作
    if (env && env->is_area())
    {
        mapping info;
        info = me->query("area_info");
        env->move_out(info["x_axis_old"], info["y_axis_old"], me);
    }

    move_object(dest);

    // 如果移入的不是區域或虚空，則刪除area_info
    if (me->query("area_info") && !dest->is_area() && !dest->query("void"))
    {
        me->delete("area_info");
    }
    // 对没有用area_move到area的移动到随机坐标
    if (dest->is_area() && !me->query("area_info"))
    {
        // debug_message(sprintf("[!]%O -> %O", me, dest));
        me->set("area_info/x_axis", random(dest->query("x_axis_size")));
        me->set("area_info/y_axis", random(dest->query("y_axis_size")));
    }

    if (interactive(me))
    {
        command("look");
    }

    return 1;
}

void move_or_destruct(object dest)
{
    if (dest)
    {
        move(dest);
    }
    else
    {
        cecho("突然一阵时空扭曲，你被传送到虚空。");
        move(VOID_OB);
    }
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
