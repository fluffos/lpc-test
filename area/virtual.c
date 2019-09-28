// 虚拟环境服务
mixed compile_area(string file)
{
    string *path, virtual;
    object ob;
    int x, y, z, elements, n;

    path = explode(file, "/");
    n = sizeof(path) - 1;
    virtual = replace_string(file, "/" + path[n], "");

    if (file_size(virtual + ".c") < 1)
    {
        return 0;
    }

    if ((elements = sscanf(path[n], "%d,%d,%d", x, y, z)) != 3)
    {
        if ((elements = sscanf(path[n], "%d,%d", x, y)) != 2)
        {
            return 0;
        }
    }

    if (elements == 2 && !(ob = new (virtual, x, y)))
    {
        return 0;
    }
    else if (elements == 3 && !(ob = new (virtual, x, y, z)))
    {
        return 0;
    }

    return ob;
}
