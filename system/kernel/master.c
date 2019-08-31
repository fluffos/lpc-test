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

int valid_bind(object binder, object old_owner, object new_owner)
{
    debug_message("binder : " + binder);
    debug_message("old_owner : " + old_owner);
    debug_message("new_owner : " + new_owner);
    return 1;
}

int valid_shadow(object ob)
{
    debug_message("valid_shadow : " + ob);
    return 1;
}
