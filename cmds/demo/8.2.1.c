int main(object me, string arg)
{
#ifdef __PACKAGE_DB__
#ifndef __USE_SQLITE3__
    debug("当前驱动不支持SQLITE3数据库。");
#else
    mixed db, err;

    if (!arg)
        return notify_fail(db_status());

    if (arg == "db_connect")
    {
        db = db_connect("", "/tmp/sqlite.db", "", __USE_SQLITE3__);
        if (stringp(db)) /* error */
            debug("数据库连接失败：" + db);
        else
            debug("数据库连接成功：" + db);
    }
    else
    {
        err = catch(db = db_close(atoi(arg)));
        if (stringp(err)) /* error */
            debug("数据库关闭出错：" + err);
        else if (db)
            debug("数据库关闭成功!");
        else
            debug("数据库关闭失败!");
    }
#endif
#else
    debug("当前驱动不支持数据库。");
#endif
    return 1;
}
