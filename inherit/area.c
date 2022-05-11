// 区域模式环境功能模块，在此模式下环境从“点”变成了“面”，玩家在同一环境中也有了距离的概念

inherit DBASE;

#include <ansi.h>

mixed *area;
// Location Of Loaded Objects
// 所有區域載入之对象的座標另成一個集合，以方便快速查找
string *LOLO = ({});
// 傳回有載入对象的座標集
string *query_LOLO() { return LOLO; }
// 加入一個座標元素在LOLO集中
void add_LOLO(string location)
{
    if (member_array(location, LOLO) == -1)
        LOLO += ({location});
}
// 刪除一個座標元素在LOLO集中
void del_LOLO(string location)
{
    if (member_array(location, LOLO) != -1)
        LOLO -= ({location});
}

// 游戏对象实时图标
nosave mapping icon = ([]);

mapping query_icon() { return icon; }

// 取得某对象權重
int get_icon_weight(object ob)
{
    if (wizardp(ob))
        return 1024;
    else if (userp(ob))
        return 512;
    else if (living(ob))
        return 64;
    else if (objectp(ob))
        return 1;
    else
        return 0;
}

// 設定某座標權重
int set_icon_weight(int x, int y, int value)
{
    string coord;

    if (!this_object())
        return 0;
    if (!this_object()->check_scope(x, y))
        return 0;

    coord = (string)x + "," + (string)y;

    icon[coord] += value;

    if (icon[coord] <= 0)
        map_delete(icon, coord);

    return 1;
}

int check_icon(int x, int y)
{
    if (undefinedp(icon[(string)x + "," + (string)y]))
        return 0;
    else
        return 1;
}

string get_icon(int x, int y)
{
    string coord;
    coord = (string)x + "," + (string)y;
    if (icon[coord] == 1024)
        return "😇";
    else if (icon[coord] == 512)
        return HIG "♀ " NOR;
    else if (icon[coord] == 64)
        return HIC "♀ " NOR;
    else if (icon[coord] >= 1)
        return "❔";
    else
        return "  ";
}

// 移除某座標圖樣
int remove_icon(int x, int y)
{
    if (!undefinedp(icon[(string)x + "," + (string)y]))
        return 1;
    else if (map_delete(icon, (string)x + "," + (string)y))
        return 1;
    return 0;
}

// 刪除所有圖示集
int delete_icon()
{
    icon = ([]);
    return 1;
}

// 區域檢查
int is_area() { return 1; }

// 使用__DIR__之相對路徑
string file_path(string dir)
{
    dir = replace_string(dir, "__DIR__", query("file_path"));
    return dir;
}

// 座標範圍檢查
int check_scope(int x, int y)
{
    if (y < 0 || x < 0 || y >= sizeof(area) || x >= sizeof(area[y]))
        return 0;
    return 1;
}

// 檢查某座標是否有障礙物，是否可穿透
int is_move(int x, int y)
{
    // 如果巫師設定為穿牆模式
    if (wizardp(this_player()))
        return 1;
    if (!check_scope(x, y))
        return 0;
    if (undefinedp(area[y][x]["block"]))
        return 1;
    if (!area[y][x]["block"])
        return 1;
    return 0;
}

// 查詢某座標的資訊
mapping *query_info(int x, int y)
{
    if (!check_scope(x, y))
        return 0;
    return area[y][x];
}

// 設定一般資料
int set_data(int x, int y, string type, mixed value)
{
    if (!check_scope(x, y))
        return 0;
    area[y][x][type] = value;
    return 1;
}
// 刪除一般資料
int delete_data(int x, int y, string type)
{
    if (!check_scope(x, y))
        return 0;
    if (undefinedp(area[y][x][type]))
        return 1;
    map_delete(area[y][x], type);
    return 1;
}
// 取得一般資料
mixed query_data(int x, int y, string type)
{
    if (!check_scope(x, y))
        return 0;
    if (undefinedp(area[y][x][type]))
        return 0;
    return area[y][x][type];
}

// 設定區域細節描述
int set_area_detail(int x, int y, string title, string detail)
{
    if (!check_scope(x, y))
        return 0;
    if (undefinedp(area[y][x]["detail"]))
        area[y][x]["detail"] = ([]);
    area[y][x]["detail"][title] = detail;
    return 1;
}

// 刪除區域細節描述
int del_area_detail(int x, int y, string title)
{
    if (!check_scope(x, y))
        return 0;
    if (undefinedp(area[y][x]["detail"]))
        return 1;

    map_delete(area[y][x]["detail"], title);

    if (sizeof(area[y][x]["detail"]) < 1)
        map_delete(area[y][x], "detail");
    return 1;
}

// 取得區域細節資料
mapping query_area_detail(int x, int y)
{
    if (!check_scope(x, y))
        return 0;
    if (undefinedp(area[y][x]["detail"]))
        return ([]);
    return area[y][x]["detail"];
}

// 設定區域型出口
int set_area_exit(int x, int y, string filename, int exit_x, int exit_y)
{
    if (!check_scope(x, y))
        return 0;
    area[y][x]["area_exit"] = ([]);
    area[y][x]["area_exit"]["filename"] = filename;
    area[y][x]["area_exit"]["x_axis"] = exit_x;
    area[y][x]["area_exit"]["y_axis"] = exit_y;
    return 1;
}

// 設定某座標要載入的对象檔
int set_loads(int x, int y, string filename, int amount)
{
    if (!check_scope(x, y))
        return 0;
    if (amount <= 0)
        return 0;
    if (undefinedp(area[y][x]["loads"]))
        area[y][x]["loads"] = ([]);
    area[y][x]["loads"][filename] = amount;

    // 加入快速搜尋集
    add_LOLO((string)y + "," + (string)x);
    return 1;
}
// 將某座標要載入的对象檔移除
int del_loads(int x, int y)
{
    if (!check_scope(x, y))
        return 0;
    if (undefinedp(area[y][x]["loads"]))
        return 1;
    map_delete(area[y][x], "loads");

    // 移除快速搜尋集
    del_LOLO((string)y + "," + (string)x);
    return 1;
}

// 查詢某坐標的出口
string *query_exits(int x, int y, int option)
{
    string *exits = ({});

    if (!option)
    {
        // 往北可能有路
        if (y - 1 >= 0)
        {
            if (x - 1 >= 0 && is_move(x - 1, y - 1))
                exits += ({"northwest"});
            if (x >= 0 && is_move(x, y - 1))
                exits += ({"north"});
            if (x + 1 < sizeof(area[0]) && is_move(x + 1, y - 1))
                exits += ({"northeast"});
        }

        // 往南可能有路
        if (y + 1 < sizeof(area))
        {
            if (x - 1 >= 0 && is_move(x - 1, y + 1))
                exits += ({"southwest"});
            if (x >= 0 && is_move(x, y + 1))
                exits += ({"south"});
            if (x + 1 < sizeof(area[0]) && is_move(x + 1, y + 1))
                exits += ({"southeast"});
        }

        // 往東可能有路
        if (x + 1 < sizeof(area[0]) && is_move(x + 1, y))
            exits += ({"east"});

        // 往西可能有路
        if (x - 1 >= 0 && is_move(x - 1, y))
            exits += ({"west"});
    }
    else
    {
        // 往北可能有路
        if (y - 1 >= 0)
        {
            if (x - 1 >= 0 && is_move(x - 1, y - 1))
                exits += ({"西北(" HIK "nw" NOR ")"});
            if (x >= 0 && is_move(x, y - 1))
                exits += ({"北(" HIK "n" NOR ")"});
            if (x + 1 < sizeof(area[0]) && is_move(x + 1, y - 1))
                exits += ({"東北(" HIK "ne" NOR ")"});
        }

        // 往南可能有路
        if (y + 1 < sizeof(area))
        {
            if (x - 1 >= 0 && is_move(x - 1, y + 1))
                exits += ({"西南(" HIK "sw" NOR ")"});
            if (x >= 0 && is_move(x, y + 1))
                exits += ({"南(" HIK "s" NOR ")"});
            if (x + 1 < sizeof(area[0]) && is_move(x + 1, y + 1))
                exits += ({"東南(" HIK "se" NOR ")"});
        }

        // 往東可能有路
        if (x + 1 < sizeof(area[0]) && is_move(x + 1, y))
            exits += ({"東(" HIK "e" NOR ")"});

        // 往西可能有路
        if (x - 1 >= 0 && is_move(x - 1, y))
            exits += ({"西(" HIK "w" NOR ")"});
    }
    return exits;
}

// 地圖顯示
string show_area(int x, int y)
{
    int i, j, x_start, y_start, x_size, y_size;
    string msg;

    // 決定顯示地圖的Y軸起點, X軸起點
    y_size = sizeof(area);
    x_size = sizeof(area[0]);

    if (y <= 5 || y_size <= 11)
        y_start = 0;            // 上
    else if (y >= y_size - 6)
        y_start = y_size - 11;  // 中
    else
        y_start = y - 5;        // 下

    if (x <= 10 || x_size <= 21)
        x_start = 0;            // 左
    else if (x >= x_size - 10)
        x_start = x_size - 21;  // 中
    else
        x_start = x - 10;       // 右

    // 建立即時地圖
    msg = sprintf(BBLU "╲" U " %-25s %s (%3d,%3d) " NOR + BBLU "╱\n" NOR,
                  query("name") + (area[y][x]["short"] ? " - " + area[y][x]["short"] : ""),
                  (area[y][x]["no_fight"] ? "安全区" : "战斗区"), x, y, );

    for (i = y_start; i < y_size && i < y_start + 11; i++)
    {
        msg += BBLU " |" NOR;
        for (j = x_start; j < x_size && j < x_start + 21; j++)
        {
            if (y == i && x == j)
                msg += "😃";
            else if (undefinedp(area[i][j]["icon"]) && (!undefinedp(area[i][j]["room_exit"]) || !undefinedp(area[i][j]["area_exit"])))
                msg += "🌀";
            else if (check_icon(j, i))
            {
                msg += get_icon(j, i);
            }
            else
            {
                msg += area[i][j]["icon"] ? area[i][j]["icon"] : "  ";
            }
        }
        msg += BBLU "| " NOR;
        msg += "\n";
    }
    msg += BBLU "╱" + repeat_string("￣", 22) + "╲" NOR;

    return SAVEC + CUP(1,1) + msg + RESTC;
}

varargs string show_objects(int x, int y)
{
    string str = "";
    object ob;

    if (undefinedp(area[y][x]["objects"]))
        return "";

    if (sizeof(area[y][x]["objects"]) >= 30)
        return "这里的東西太多，一時看不清楚...\n";
    // todo 增加排序
    foreach (ob in area[y][x]["objects"])
    {
        if (ob == this_player())
            continue;
        if (!objectp(ob) || environment(ob) != this_object() ||
            ob->query("area_info/y_axis") != y || ob->query("area_info/x_axis") != x)
        {
            area[y][x]["objects"] -= ({ob});
            continue;
        }
        str += sprintf("  %s\n", ob->short());
    }

    return str;
}

varargs int do_look(object me, string arg)
{
    int i = 0;
    string str = "", long, *exits;
    mapping info;

    if (!userp(me))
        return 0;

    info = me->query("area_info");

    if (!info)
        return 0;

    if (!check_scope(info["x_axis"], info["y_axis"]))
        return 0;

    if (arg)
    {
        return notify_fail("你要看什麼？\n");
    }

    // 长描述
    long = query_data(info["x_axis"], info["y_axis"], "long");
    if (long)
    {
        message("long", ansi(long), me);
    }

    // 出口提示
    exits = query_exits(info["x_axis"], info["y_axis"], 1);
    if ((i = sizeof(exits)))
    {
        str += "这里的出口有 " NOR;
        while (i--)
            str += exits[i] + (i ? "、" : "。\n");
    }
    else
        str += "这里沒有任何出口。\n";

    // 顯示对象
    str += show_objects(info["x_axis"], info["y_axis"]);

    message("vision", str, me);
    // 顯示地圖
    message("MAP", show_area(info["x_axis"], info["y_axis"]), me);

    return 1;
}

// 对象移入某座標處理
int move_in(int x, int y, object ob)
{
    // 超出區域大小範圍
    if (!check_scope(x, y))
        return 0;

    // 該座標沒有对象集(objects)，則將对象集設為空
    if (undefinedp(area[y][x]["objects"]))
        area[y][x]["objects"] = ({});

    // 对象已經存在对象集(objects)中，就不需要再加入对象集
    if (member_array(ob, area[y][x]["objects"]) != -1)
        return 1;

    // 对象加入对象集中
    area[y][x]["objects"] += ({ob});

    // 改變即時的圖示
    set_icon_weight(x, y, get_icon_weight(ob));

    return 1;
}

// 对象移出某座標處理
int move_out(int x, int y, object ob)
{
    // 超出區域大小範圍
    if (!check_scope(x, y))
        return 0;

    // 該座標沒有对象集(objects)
    if (undefinedp(area[y][x]["objects"]))
        return 1;

    // 改變即時的圖示
    set_icon_weight(x, y, -get_icon_weight(ob));

    // 对象不存在於对象集(objects)中，就不需要再移出对象集
    if (member_array(ob, area[y][x]["objects"]) == -1)
        return 1;

    // 对象移出对象集
    area[y][x]["objects"] -= ({ob});

    // 座標完全沒对象時，刪除对象集
    if (sizeof(area[y][x]["objects"]) < 1)
    {
        map_delete(area[y][x], "objects");
    }

    return 1;
}

object make_inventory(string file, int x, int y)
{
    object ob;

    file = file_path(file);
    ob = new (file);

    if (!ob)
        return 0;

    ob->set("area_info/x_axis", x);
    ob->set("area_info/y_axis", y);
    ob->set("area_info/x_axis_old", x);
    ob->set("area_info/y_axis_old", y);

    if (move_in(x, y, ob))
    {
        ob->move(this_object());
    }
    else
        destruct(ob);

    return ob;
}

varargs void reset(int temp)
{
    int i, j, x, y, amount, t = 0;
    mapping ob;
    string file;

    if (!sizeof(LOLO) || temp >= sizeof(LOLO))
        return;

    for (i = temp; i < sizeof(LOLO); i++)
    {
        if (sscanf(LOLO[i], "%d,%d", y, x) != 2)
            continue;
        if (!check_scope(x, y))
            continue;
        if (undefinedp(area[y][x]["loads"]))
            continue;
        if (!mapp(ob = area[y][x]["loaded"]))
            ob = ([]);
        foreach (file, amount in area[y][x]["loads"])
        {
            for (j = amount; j > 0; j--)
            {
                if (objectp(ob[file + " " + j]))
                    continue;
                ob[file + " " + j] = make_inventory(file, x, y);
            }
            area[y][x]["loaded"] = ob;
        }
        t++;
        if (t >= 3)
        {
            call_out("reset", 1, i + 1);
            return;
        }
    }
    return;
}


int save()
{
    int i, j, x_size, y_size;
    mapping LOADED_BAK, OBJECTS_BAK;
    mixed *AREA_BAK;

    // 存檔前將不需要儲取的變數清空，以免往後發生無法預期的錯誤
    AREA_BAK = area;

    LOADED_BAK = ([]);
    OBJECTS_BAK = ([]);

    x_size = this_object()->query("x_axis_size");
    y_size = this_object()->query("y_axis_size");

    // 每格座標中的暫時變數也要清空, 並暫存起來
    for (i = 0; i < y_size; i++)
    {
        if (undefinedp(LOADED_BAK[i]))
            LOADED_BAK[i] = ([]);
        if (undefinedp(OBJECTS_BAK[i]))
            OBJECTS_BAK[i] = ([]);
        for (j = 0; j < x_size; j++)
        {
            LOADED_BAK[i][j] = area[i][j]["loaded"];
            OBJECTS_BAK[i][j] = area[i][j]["objects"];
            map_delete(area[i][j], "loaded");  // loaded -> mapping
            map_delete(area[i][j], "objects"); // objects -> array
        }
    }

    if (save_object(file_name()))
    {
        // 儲存完便還原
        area = AREA_BAK;

        for (i = 0; i < y_size; i++)
        {
            for (j = 0; j < x_size; j++)
            {
                area[i][j]["loaded"] = LOADED_BAK[i][j];
                area[i][j]["objects"] = OBJECTS_BAK[i][j];
            }
        }
        return 1;
    }

    return 0;
}

void setup()
{
    int i;
    string file;

    seteuid(getuid());

    if (!restore_object(file_name()))
    {
        int j, y_size, x_size;

        y_size = query("y_axis_size");
        x_size = query("x_axis_size");

        area = allocate(y_size);
        for (i = 0; i < y_size; i++)
        {
            area[i] = allocate(x_size);
            for (j = 0; j < x_size; j++)
                area[i][j] = ([]);
        }

        // 儲存
        save();
    }

    // update 相對路徑
    file = base_name();
    i = strlen(file);
    while (i--)
        if (file[i..i] == "/")
            break;
    set("file_path", file[0..i]);

    reset();
}

int map_ansi_save()
{
    int i, j, x, y;
    string file, msg = "", msg2 = "";

    y = sizeof(area);
    x = sizeof(area[0]);

    file = base_name();

    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            if (j <= 49)
            {
                if (undefinedp(area[i][j]["icon"]))
                    msg += "  ";
                else
                    msg += area[i][j]["icon"];
            }
            else
            {
                if (undefinedp(area[i][j]["icon"]))
                    msg2 += "  ";
                else
                    msg2 += area[i][j]["icon"];
            }
        }
        msg += "\n";
        if (x > 49)
            msg2 += "\n";
    }

    if (x <= 49)
    {
        if (!write_file(file + ".ansi", msg, 1))
            write("儲存ANSI檔失敗。\n");
        else
            write("儲存ANSI檔成功(" + file + ".ansi)。\n");
    }
    else
    {
        write("因為此area寬度超過五十個字大小，故分成左右二個圖檔儲存。\n");
        if (!write_file(file + "_left.ansi", msg, 1))
            write("儲存左半邊ANSI檔失敗。\n");
        else
            write("儲存左半邊ANSI檔成功(" + file + "_left.ansi)。\n");
        if (!write_file(file + "_right.ansi", msg2, 1))
            write("儲存右半邊ANSI檔失敗。\n");
        else
            write("儲存右半邊ANSI檔成功(" + file + "_right.ansi)。\n");
    }

    return 1;
}

// 移动控制
int area_move(object who, int x, int y)
{
    mapping info;
    int env_area = 0;

    if (!objectp(who))
        return 0;

    if (environment(who) && environment(who)->is_area())
    {
        info = who->query("area_info");
        env_area = 1;
    }

    // 已經在同一個位置了
    if (this_object() == environment(who) &&
        x == who->query("area_info/x_axis") &&
        y == who->query("area_info/y_axis"))
        return 1;

    // 如果who move_in到新的area中失敗
    if (!move_in(x, y, who))
        return 0;

    who->set("area_info/x_axis", x);
    who->set("area_info/y_axis", y);
    // 成功移入area, move() 會從area裡移出
    if (who->move(this_object()))
    {
        who->set("area_info/x_axis_old", x);
        who->set("area_info/y_axis_old", y);
        return 1;
    }
    // 移入area失敗，如果原本是在area環境中，必須再移入一次
    else
    {
        // 將先前移到新的area再做移出
        move_out(x, y, who);
        if (env_area)
        {
            // 設回先前的 x, y
            who->set("area_info/x_axis", info["x_axis_old"]);
            who->set("area_info/y_axis", info["y_axis_old"]);
            if (!environment(who)->move_in(info["x_axis_old"], info["y_axis_old"]))
            {
                tell_object(who, "因為某種原因，你的角色在區域移動時產生了錯誤...\n");
                destruct(who);
                return 0;
            }
        }
    }
    return 0;
}

// 在区域中向指定方向移动
int area_go(object ob, string dir)
{
    int x, y, x_past, y_past;
    x_past = ob->query("area_info/x_axis");
    y_past = ob->query("area_info/y_axis");

    // 座标转换
    switch (dir)
    {
    case "north":
        y = y_past - 1;
        x = x_past;
        break;
    case "east":
        y = y_past;
        x = x_past + 1;
        break;
    case "south":
        y = y_past + 1;
        x = x_past;
        break;
    case "west":
        y = y_past;
        x = x_past - 1;
        break;
    case "northeast":
        y = y_past - 1;
        x = x_past + 1;
        break;
    case "southeast":
        y = y_past + 1;
        x = x_past + 1;
        break;
    case "southwest":
        y = y_past + 1;
        x = x_past - 1;
        break;
    case "northwest":
        y = y_past - 1;
        x = x_past - 1;
        break;
    default:
        return 0;
        break;
    }

    // 判断是否可移动
    if (!check_scope(x, y) || !is_move(x, y))
    {
        write("这个方向沒有出路");
        return 0;
    }


    // 移动到普通房间环境
    if (!undefinedp(area[y][x]["room_exit"]))
    {
        object room;
        if (!objectp(room = load_object(file_path(area[y][x]["room_exit"]))))
        {
            write("这个方向的出口有问题，请通知管理员处理。\n");
            return 0;
        }
        if (room->is_area())
        {
            write("这个方向的出口有问题，请通知管理员处理。\n");
            return 0;
        }
        else
        {
            return ob->move(room);
        }

        return 0;
    }

    // 移往別的區域
    if (!undefinedp(area[y][x]["area_exit"]))
    {
        object room;
        if (!objectp(room = load_object(file_path(area[y][x]["area_exit"]["filename"]))))
        {
            write("這個方向的出口有問題，請通知管理者來處理。\n");
            return 0;
        }
        if (!room->is_area())
        {
            write("這個方向的出口有問題，請通知管理者來處理。\n");
            return 0;
        }

        if (!room->area_move(ob, area[y][x]["area_exit"]["x_axis"], area[y][x]["area_exit"]["y_axis"]))
        {
            write("這個方向的出口有問題，請通知管理者來處理。\n");
            return 0;
        }
        return 1;
    }

    // 对象移出舊座標
    if (move_out(x_past, y_past, ob))
    {
        // 对象移入新座標
        if (move_in(x, y, ob))
        {
            ob->set("area_info/x_axis", x);
            ob->set("area_info/y_axis", y);
            ob->set("area_info/x_axis_old", x);
            ob->set("area_info/y_axis_old", y);
        }
        else
        {
            // 对象移入失敗，退回原座標
            move_in(x_past, y_past, ob);
            return 0;
        }
        if (userp(ob))
            do_look(ob);
    }
    else
        return 0;

    return 1;
}
