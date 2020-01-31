int main(object me, string arg)
{
#ifdef __PACKAGE_DB__
    mixed db, rows, *res;

    db = db_connect("127.0.0.1", "demo", "root");
    if (stringp(db)) /* error */
        debug("数据库连接失败：" + db);
    else
    {
        db_exec(db, "set names utf8"); // 防止乱码
        rows = db_exec(db, "SELECT id,title FROM threads limit 30");
        if (!rows)
            debug("查询结果为空");
        else if (stringp(rows))
            debug(rows); /* error */
        else
            for (int i = 1; i < rows; i++)
            {
                res = db_fetch(db, i);
                // printf("%O\n", res);
                debug(res[0] + " " + res[1]);
            }

        db_close(db);
    }
#else
    debug("当前驱动不支持数据库。");
#endif
    return 1;
}
