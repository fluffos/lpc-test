int main(object me, string arg)
{
#ifdef __PACKAGE_DB__
#ifndef __USE_SQLITE3__
    debug("当前驱动不支持SQLITE3数据库。");
#else
    mixed db, rows, *res;

    db = db_connect("", "/tmp/sqlite.db", "", __USE_SQLITE3__);
    if (stringp(db)) /* error */
        debug("数据库连接失败：" + db);
    else
    {
        rows = db_exec(db, "DROP TABLE IF EXISTS demo");
        rows = db_exec(db, "create table IF NOT EXISTS demo(name varchar(10), value bigint);");
        rows = db_exec(db,  "insert into demo values('hello!',10);");
        rows = db_exec(db,  "insert into demo values('goodbye', 20);");
        rows = db_exec(db,  "insert into demo values('largeint', 9223372036854775807);");
        rows = db_exec(db,  "select * from demo;");

        for (int i = 0; i <= rows; i++)
        {
            res = db_fetch(db, i);
            // printf("%O\n", res);
            debug(res[0] + " " + res[1]);
        }

        db_close(db);
    }
#endif
#else
    debug("当前驱动不支持数据库。");
#endif
    return 1;
}
