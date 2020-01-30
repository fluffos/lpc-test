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
     */
    mapping ob_list, ob;
    string file;
    int amount;

    if (!mapp(ob_list = query("objects")))
        return;

    if (!mapp(ob = query_temp("objects")))
        ob = ([]);

    foreach(file, amount in ob_list)
    {
        if (amount == 1)
        {
            if(!objectp(ob[file]))
                ob[file] = make_inventory(file);
        }
        else
        {
            ob[file] = allocate(amount);
            for(int i = 0; i < amount; i++)
            {
                if(!objectp(ob[file][i]))
                    ob[file][i] = make_inventory(file);
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
