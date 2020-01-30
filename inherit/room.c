/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: room.c
Description: 通用游戏环境设置接口，通过reset()自动加载物品对象到房间
Author: xuefeng
Version: v1.0
*****************************************************************************/
inherit CLEAN_UP;
inherit DBASE;

// void create(){}

object make_inventory(string file)
{
    object ob;

    ob = new(file);
    ob->move(this_object());
    return ob;
}

// driver自动定期呼叫此apply
void reset()
{
    /**
     * ob_list:需要加载的对象map列表
     * ob:加载后的对象map列表
     * list:需要加载的对象的array列表
     */
    mapping ob_list, ob;
    string *list;
    int i, j;

    ob_list = query("objects");
    if (!mapp(ob_list))
        return;

    if (!mapp(ob = query_temp("objects")))
        ob = ([]);

    list = keys(ob_list);
    for (i = 0; i < sizeof(list); i++)
    {
        if (intp(ob_list[list[i]]) && ob_list[list[i]] > 1)
            ob[list[i]] = allocate(ob_list[list[i]]);

        switch (ob_list[list[i]])
        {
        case 1:
            // 如果对象不存在，生成一个
            if (!objectp(ob[list[i]]))
                ob[list[i]] = make_inventory(list[i]);
            break;
        default:
            for (j = 0; j < ob_list[list[i]]; j++)
            {
                // 如果对象不存在，生成一个
                if (!objectp(ob[list[i]][j]))
                {
                    ob[list[i]][j] = make_inventory(list[i]);
                    continue;
                }
            }
        }
    }
    // 缓存对象列表
    set_temp("objects", ob);
}

void setup()
{
    reset();
}
