// 主控对象，游戏核对文件之一
#define PASSWD ""
// 调试模式开关
nosave int debug = 0;

string get_root_uid()
{

    debug_message(ctime(time()) + " : get_root_uid()!");
    return "ROOT";
}

string author_file(string str)
{
    if (debug)
    {
        debug_message("author_file : " + str);
    }

    return str;
}

string get_bb_uid()
{
    debug_message(ctime(time()) + " : get_bb_uid()!");
    return "BACKBONE";
}

string domain_file(string str)
{
    if (debug)
    {
        debug_message("domain_file : " + str);
    }

    return str;
}

object connect(int port)
{
    return new (LOGIN_OB);
}

string creator_file(string str)
{
    if (debug)
    {
        debug_message("creator_file : " + str);
    }

    return str;
}

void log_error(string file, string message)
{
    write_file(LOG_DIR + "log_error", message);
}

void error_handler(mapping map, int caught)
{
    string str = "[" + ctime(time()) + "]";

    str += sprintf("\n%O\n\n", map);

    if (caught)
        printf("%s", map["error"]);
    else
        debug("出错啦！详情记录在 error_handler 日志。");

    write_file(LOG_DIR + "error_handler", str);
}

string *epilog(int load_empty)
{
    string *items = ({});
#ifdef PRELOAD
    items = update_file(PRELOAD);
#endif
    // debug_message("epilog : " + load_empty);
    return items;
}

void preload(string filename)
{
    // debug_message("preload : " + filename);
    if (stringp(filename))
    {
        load_object(filename);
    }
}

void flag(string flag)
{
    if (flag == "debug")
    {
        debug = 1;
    }
}

string *get_include_path(string file)
{
    if (debug)
    {
        debug_message("get_include_path file : " + file);
    }

    return ({ ":DEFAULT:" });
}

void crash(string crash_message, object command_giver, object current_object)
{
    if (debug)
    {
        debug_message("crash crash_message : " + crash_message);
        debug_message("crash command_giver : " + file_name(command_giver));
        debug_message("crash current_object : " + file_name(current_object));
    }
}

string object_name( object ob )
{
    return geteuid(ob);
}

mixed compile_object(string str)
{
    if (debug)
    {
        debug_message("compile_object : " + str);
    }

    if (sscanf(str, "/area/%*s", str))
    {
        return call_other(VIRTUAL_D, "compile_area", str);
    }
    else
    {
        return 0;
    }
}

// bind()
int valid_bind(object binder, object old_owner, object new_owner)
{
    if (debug)
    {
        debug_message("valid_bind binder : " + file_name(binder));
        debug_message("valid_bind old_owner : " + file_name(old_owner));
        debug_message("valid_bind new_owner : " + file_name(new_owner));
    }

    return 1;
}

// database
mixed valid_database(object caller, string func, mixed *info)
{
    if (debug)
    {
        debug_message("valid_database caller : " + file_name(caller));
        debug_message("valid_database func : " + func);
        debug_message("valid_database info : " + save_variable(info));
    }

    if (func == "connect")
        return PASSWD; // mysql数据库密码
    else
        return 1;
}

// set_hide()
int valid_hide(object ob)
{
    if (debug)
    {
        debug_message("valid_hide ob : " + file_name(ob));
    }

    return 1;
}

// link()
int valid_link(string from, string to)
{
    if (debug)
    {
        debug_message("valid_link from : " + from);
        debug_message("valid_link to : " + to);
    }

    return 1;
}

int valid_object( object obj )
{
    if (debug)
    {
        debug_message("valid_object obj : " + file_name(obj));
    }

    return 1;
}

int valid_override( string file, string efun_name , string main_file )
{
    if (debug)
    {
        debug_message("valid_override file : " + file);
        debug_message("valid_override efun_name : " + efun_name);
        debug_message("valid_override main_file : " + main_file);
    }

    return 1;
}

int valid_read(string file, mixed user, string func)
{
    if (debug)
    {
        debug_message("valid_read file : " + file);
        debug_message("valid_read user : " + user);
        debug_message("valid_read func : " + func);
    }

    return 1;
}

// seteuid()
int valid_seteuid(object obj, string euid)
{
    if (debug)
    {
        debug_message("valid_seteuid obj : " + file_name(obj));
        debug_message("valid_seteuid euid : " + euid);
    }

    return 1;
}

// shadow()
int valid_shadow(object ob)
{
    if (debug)
    {
        debug_message("valid_shadow ob : " + file_name(ob));
    }

    return 1;
}

// socket
int valid_socket(object caller, string func, mixed *info)
{
    if (debug)
    {
        debug_message("valid_socket caller : " + file_name(caller));
        debug_message("valid_socket func : " + func);
        debug_message("valid_socket info : " + save_variable(info));
    }

    return 1;
}

int valid_write(string file, mixed user, string func)
{
    if (debug)
    {
        debug_message("valid_write file : " + file);
        debug_message("valid_write user : " + user);
        debug_message("valid_write func : " + func);
    }

    return 1;
}
