string get_root_uid()
{
    return "ROOT";
}

string author_file(string str)
{
    return str;
}

string get_bb_uid()
{
    return "BACKBONE";
}

string domain_file(string str)
{
    return str;
}

object connect(int port)
{
    return new (LOGIN_OB);
}

string creator_file(string str)
{
    return str;
}

void log_error(string file, string message)
{
    write_file(LOG_DIR + "log_error", message);
}

void error_handler(mapping map, int flag)
{
    object ob;
    string str;

    ob = this_interactive() || this_player();

    if (flag)
        str = "*Error caught\n";
    else
        str = "";

    str += sprintf("\nError: %s\nProgram: %s\nObject: %O\nFile: %s - Line: %d\n[%s]\n",
                map["error"], (map["program"] || "No program"),
                (map["object"] || "No object"),
                map["file"],
                map["line"],
                implode(map_array(map["trace"],
                    (: sprintf("\n\tProgram: %s\n\tObject: %O \n\tFile: %s\n\tFunction : %s\n\tLine: %d\n", $1["program"], $1["object"], $1["file"], $1["function"], $1["line"]) :)), "\n"));
    write_file(LOG_DIR + "error_handler", str);

    if (!flag && ob)
        tell_object(ob, str);
}

// bind()
int valid_bind(object binder, object old_owner, object new_owner)
{
    debug_message("binder : " + binder);
    debug_message("old_owner : " + old_owner);
    debug_message("new_owner : " + new_owner);
    return 1;
}

mixed valid_database(object caller, string func, mixed *info)
{

    debug_message("caller : " + caller);
    debug_message("func : " + func);
    debug_message("info : " + save_variable(info));

    if (func == "connect")
        return DB_PASSWD; // mysql数据库密码
    else
        return 1;
}

// set_hide()
int valid_hide(object ob)
{
    debug_message("valid_hide : " + ob);
    return 1;
}

// link()
int valid_link(string from, string to)
{
    debug_message("from : " + from);
    debug_message("to : " + to);
    return 1;
}
/*
int valid_read(string file, mixed user, string func)
{
    debug_message("file : " + file);
    debug_message("user : " + user);
    debug_message("func : " + func);
    return 1;
}
 */
// seteuid()
int valid_seteuid(object obj, string euid)
{
    debug_message("obj : " + obj);
    debug_message("euid : " + euid);
    return 1;
}

// shadow()
int valid_shadow(object ob)
{
    debug_message("valid_shadow : " + ob);
    return 1;
}

// socket
int valid_socket(object caller, string func, mixed *info)
{
    debug_message("caller : " + caller);
    debug_message("func : " + func);
    debug_message("info : " + save_variable(info));
    return 1;
}
/*
int valid_write(string file, mixed user, string func)
{
    debug_message("file : " + file);
    debug_message("user : " + user);
    debug_message("func : " + func);
    return 1;
}
 */
