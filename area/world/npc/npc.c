inherit DBASE;

// 方便移动对象到指定环境
int move(mixed dest)
{
    move_object(dest);

    return 1;
}

void create()
{
    set("name", "白银城冒险者");
    set("unit", "位");
}
