int main(object me, string arg)
{
#ifdef __PACKAGE_DB__
    mixed db, rows, *res;

    db = db_connect("127.0.0.1", "mud.ren", "root");
    if (stringp(db)) /* error */
        debug("数据库连接失败：" + db);
    else
    {
        db_exec(db, "set names utf8"); // 防止乱码
        if (arg)
        {
            // db_exec(db, "delete from password_resets where email=\"test@test.cn\"");
            // db_exec(db, "insert into password_resets values (\"test@test.cn\", \"abcdefg1234567890\", \"2020-10-15 12:34:00\")");
            // db_exec(db, "update password_resets set token=\"" + arg + "\" where email=\"test@test.cn\"");
        }
        rows = db_exec(db, "SELECT * FROM password_resets limit 30");
        if (!rows)
            debug("查询结果为空");
        else if (stringp(rows))
            debug(rows); /* error */
        else
        {
            debug(rows);
            for (int i = 0; i <= rows; i++)
            {
                res = db_fetch(db, i);
                // printf("%O\n", res);
                debug(i + " " + res[0] + " " + res[1] + " " + res[2]);
            }
        }

        db_close(db);
    }
#else
    debug("当前驱动不支持数据库。");
#endif
    return 1;
}
