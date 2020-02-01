/**
 * sockets DATAGRAM 模式客户端测试
 */
nosave int s;

void create()
{
    int mode = 2;
    // 创建一个 efun socket 连接
    s = socket_create(mode, "read_callback", "close_callback");
    if (s < 0)
    {
        debug("【8.3.3】socket_create error : " + socket_error(s));
    }
    else
    {
        debug("【8.3.3】socket_create fd = " + s);
    }
}

int main(object me, string arg)
{
    int err;
    // UDP 发送消息到服务器
    err = socket_write(s, arg, "127.0.0.1 5000");
    if (err < 0)
    {
        debug("【8.3.3】socket_write error : " + socket_error(err));
        // socket_close(s);
    }
    else
    {
        debug("【系统】消息已发送！");
    }
    return 1;
}

void read_callback(int fd, mixed message)
{
    debug("【8.3.3】read_callback fd : " + fd);
    shout("【8.3.3】read_callback : " + message);
}

void close_callback(int fd)
{
    debug("【8.3.3】close_callback fd : " + fd);
    socket_close(fd);
}
