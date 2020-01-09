// 虚拟环境服务
mixed compile_area(string file)
{
    string virtual;
    object ob;
    int x, y, z, m, n;

    n = strsrch(file, "/", -1);
    if (n < 1)
    {
        return 0;
    }

    virtual = file[0..n - 1];

    if (file_size(virtual + ".c") < 1)
    {
        return 0;
    }

    if ((m = sscanf(file[n + 1..], "%d,%d,%d", x, y, z)) != 3)
    {
        if ((m = sscanf(file[n + 1..], "%d,%d", x, y)) != 2)
        {
            return 0;
        }
    }

    if (m == 2 && !(ob = new (virtual, x, y)))
    {
        return 0;
    }
    else if (m == 3 && !(ob = new (virtual, x, y, z)))
    {
        return 0;
    }

    return ob;
}
