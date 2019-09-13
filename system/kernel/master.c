string get_root_uid()
{
    // debug_message("get_root_uid : ROOT");
    return "ROOT";
}

string author_file(string str)
{
    // debug_message("author_file : " + str);
    return str;
}

string get_bb_uid()
{
    // debug_message("get_bb_uid : BACKBONE");
    return "BACKBONE";
}

string domain_file(string str)
{
    // debug_message("domain_file : " + str);
    return str;
}

object connect(int port)
{
    return new (LOGIN_OB);
}

string creator_file(string str)
{
    // debug_message("creator_file : " + str);
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
    str = save_variable(map);
    if (!flag && ob)
        tell_object(ob, str);
}

string *epilog(int load_empty)
{
    // debug_message("epilog : " + load_empty);
    return ({});
}

void preload(string filename)
{
    // debug_message("preload : " + filename);
}

void flag(string flag)
{
    // debug_message("flag : " + flag);
}

string *get_include_path(string file)
{
    // debug_message("get_include_path file : " + file);
    return ({ ":DEFAULT:" });
}

void crash(string crash_message, object command_giver, object current_object)
{
    debug_message("crash crash_message : " + crash_message);
    debug_message("crash command_giver : " + command_giver);
    debug_message("crash current_object : " + current_object);
}
/*
string object_name( object ob )
{
    return file_name(ob);
}
*/
// bind()
int valid_bind(object binder, object old_owner, object new_owner)
{
    debug_message("valid_bind binder : " + binder);
    debug_message("valid_bind old_owner : " + old_owner);
    debug_message("valid_bind new_owner : " + new_owner);
    return 1;
}

// database
mixed valid_database(object caller, string func, mixed *info)
{
    debug_message("valid_database caller : " + caller);
    debug_message("valid_database func : " + func);
    debug_message("valid_database info : " + save_variable(info));

    if (func == "connect")
        return DB_PASSWD; // mysql数据库密码
    else
        return 1;
}

// set_hide()
int valid_hide(object ob)
{
    debug_message("valid_hide ob : " + ob);
    return 1;
}

// link()
int valid_link(string from, string to)
{
    debug_message("valid_link from : " + from);
    debug_message("valid_link to : " + to);
    return 1;
}
/*
int valid_object( object obj )
{
    debug_message("valid_object obj : " + obj);
    return 1;
}
*/
int valid_override( string file, string efun_name , string main_file )
{
    debug_message("valid_override file : " + file);
    debug_message("valid_override efun_name : " + efun_name);
    debug_message("valid_override main_file : " + main_file);
    return 1;
}
/*
int valid_read(string file, mixed user, string func)
{
    debug_message("valid_read file : " + file);
    debug_message("valid_read user : " + user);
    debug_message("valid_read func : " + func);
    return 1;
}
*/
// seteuid()
int valid_seteuid(object obj, string euid)
{
    debug_message("valid_seteuid obj : " + obj);
    debug_message("valid_seteuid euid : " + euid);
    return 1;
}

// shadow()
int valid_shadow(object ob)
{
    debug_message("valid_shadow ob : " + ob);
    return 1;
}

// socket
int valid_socket(object caller, string func, mixed *info)
{
    debug_message("valid_socket caller : " + caller);
    debug_message("valid_socket func : " + func);
    debug_message("valid_socket info : " + save_variable(info));
    return 1;
}
/*
int valid_write(string file, mixed user, string func)
{
    debug_message("valid_write file : " + file);
    debug_message("valid_write user : " + user);
    debug_message("valid_write func : " + func);
    return 1;
}
*/
