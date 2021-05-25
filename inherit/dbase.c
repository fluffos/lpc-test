/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: dbase.c
Description: 数据存取接口
Author: xuefeng
Version: v1.0
Date: 2019-09-15
*****************************************************************************/
mapping dbase;
nosave mapping tmp_dbase;

// void create(){}

mixed _set(mapping map, string *parts, mixed value)
{
    if (sizeof(parts) == 1)
        return map[parts[0]] = value;

    if (!map[parts[0]] || !mapp(map[parts[0]]))
        map[parts[0]] = ([parts[1]:0]);

    return _set(map[parts[0]], parts[1..sizeof(parts)-1], value);
}

mixed _query(mapping map, string *parts)
{
    mixed value;
    int i, s;

    value = map;
    s = sizeof(parts);
    for (i = 0; i < s; i++)
    {
        if (undefinedp(value = value[parts[i]]))
            break;
        if (!mapp(value))
            break;
    }
    return value;
}

int _delete(mapping map, string *parts)
{
    if (sizeof(parts) == 1)
    {
        map_delete(map, parts[0]);
        return 1;
    }
    if (!map[parts[0]] || !mapp(map[parts[0]]))
        return 0;
    return _delete(map[parts[0]], parts[1..sizeof(parts)-1]);
}

mixed set(string prop, mixed data)
{
    if (!mapp(dbase))
        dbase = ([]);

    if (strsrch(prop, '/') != -1)
        return _set(dbase, explode(prop, "/"), data);

    return dbase[prop] = data;
}

varargs mixed query(string prop, int raw)
{
    mixed data;

    if (!mapp(dbase))
        return 0;

    if (undefinedp(dbase[prop]) && (strsrch(prop, '/') != -1))
        data = _query(dbase, explode(prop, "/"));
    else
        data = dbase[prop];

    if (raw)
        return data;

    return evaluate(data, this_object());
}

int delete(string prop)
{
    if (!mapp(dbase))
        return 0;

    if (strsrch(prop, '/') != -1)
        return _delete(dbase, explode(prop, "/"));
    else
    {
        map_delete(dbase, prop);
        return 1;
    }
}

mixed add(string prop, mixed data)
{
    mixed old;

    if (!mapp(dbase) || !(old = query(prop, 1)))
        return set(prop, data);

    if (functionp(old))
        error("dbase: add() - called on a function type property.\n");

    return set(prop, old + data);
}

mapping query_entire_dbase()
{
    return dbase;
}

void set_dbase(mapping data)
{
    if (!mapp(data))
        return;

    dbase = data;
}

mixed set_temp(string prop, mixed data)
{
    if (!mapp(tmp_dbase))
        tmp_dbase = ([]);

    if (strsrch(prop, '/') != -1)
        return _set(tmp_dbase, explode(prop, "/"), data);

    return tmp_dbase[prop] = data;
}

varargs mixed query_temp(string prop, int raw)
{
    mixed data;

    if (!mapp(tmp_dbase))
        return 0;

    if (strsrch(prop, '/') != -1)
        data = _query(tmp_dbase, explode(prop, "/"));
    else
        data = tmp_dbase[prop];

    if (functionp(data) && !raw)
        return (*data)(this_object());
    else
        return data;
}

int delete_temp(string prop)
{
    if (!mapp(tmp_dbase))
        return 0;

    if (strsrch(prop, '/') != -1)
        return _delete(tmp_dbase, explode(prop, "/"));
    else
    {
        map_delete(tmp_dbase, prop);
        return 1;
    }
}

mixed add_temp(string prop, mixed data)
{
    mixed old;

    if (!mapp(tmp_dbase) || !(old = query_temp(prop, 1)))
        return set_temp(prop, data);

    if (functionp(old))
        error("dbase: add_temp() - called on a function type property.\n");

    return set_temp(prop, old + data);
}

mapping query_entire_temp_dbase()
{
    return tmp_dbase;
}

void set_temp_dbase(mapping data)
{
    if (!mapp(data))
        return;

    tmp_dbase = data;
}
