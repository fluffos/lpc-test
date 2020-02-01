/**
 * sockets MUD 模式客户端测试
 */
nosave int s;

void socket_init(int mode)
{
    int err;
    string addr = "127.0.0.1 5000";
    // 创建一个 efun socket 连接
    s = socket_create(mode, "read_callback", "close_callback");
    if (s < 0)
    {
        debug("【8.3.2】socket_create error : " + socket_error(s));
    }
    else
    {
        debug("【8.3.2】socket_create fd = " + s);
        if (mode != 2 && mode != 4)
        {
            // 启动一个 socket 连接
            err = socket_connect(s, addr, "read_callback", "write_callback");
            if (err < 0)
            {
                debug("【8.3.2】socket_connect error : " + socket_error(err));
                socket_close(s);
            }
            else
            {
                debug("【8.3.2】socket_connect SUCCESS!");
            }
        }
    }
}

void create()
{
    socket_init(0);
}

int main(object me, string arg)
{
    int err;
    if(arg == "release")
    {
        err = socket_release(s, load_object(__DIR__"8.3.5"), "release_callback");
        if (err < 0)
        {
            debug("【8.3.2】socket_release error : " + socket_error(err));
        }
        else
        {
            debug("【8.3.2】socket_release SUCCESS！");
        }
        return 1;
    }
    err = socket_write(s, arg);
    if (err < 0)
    {
        debug("【8.3.2】socket_write error : " + socket_error(err));
    }
    else
    {
        debug("【系统】消息已发送！");
    }
    return 1;
}

void write_callback(int fd)
{
    int err;
    debug("【8.3.2】write_callback fd : " + fd);
    err = socket_write(fd, "你好，这是来自客户端的问候^_^");
    if (err < 0)
    {
        debug("【8.3.2】socket_write error : " + socket_error(err));
    }
}

void read_callback(int fd, mixed message)
{
    debug("【8.3.2】read_callback fd : " + fd);
    shout("【8.3.2】read_callback : " + message + "\n");
}

void close_callback(int fd)
{
    debug("【8.3.2】close_callback fd : " + fd);
    socket_close(fd);
}
