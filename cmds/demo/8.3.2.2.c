/**
 * sockets DATAGRAM 模式客户端测试
 */
nosave int s;

void create()
{
    int mode = 2;
    // 创建一个 efun socket 连接
    s = socket_create(mode, "read_callback");
    // 如果不绑定端口，将使用随机端口连接服务器，但无法收到服务端返回的消息
    socket_bind(s, 6001);
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
    if (!arg)
    {
        debug("请输入要发送的内容~~~");
        return 1;
    }

    err = socket_write(s, arg, "127.0.0.1 6000");
    if (err < 0)
    {
        debug("【8.3.3】socket_write error : " + socket_error(err));
        socket_close(s);
    }
    else
    {
        debug("【系统】消息已发送！");
    }
    return 1;
}

void read_callback(int fd, mixed message, string addr)
{
    debug("【8.3.3】read_callback fd : " + fd);
    debug("【8.3.3】read_callback from : " + addr);
    shout("【8.3.3】read_callback : " + message + "\n");
}
