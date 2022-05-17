/**
 * sockets MUD 模式客户端测试
 */

#define STREAM 1

nosave int S;

void write_callback(int fd)
{
    debug_message("【TCP客户端】write_callback fd : " + fd);
}

void read_callback(int fd, mixed message)
{
    debug_message("【TCP客户端】read_callback fd : " + fd);
    shout("【TCP客户端】read_callback : " + message + "\n");
}

void read_callback2(int fd, mixed message)
{
    debug_message("【TCP客户端】read_callback2 fd : " + fd);
    shout("【TCP客户端】read_callback2 : " + message + "\n");
}

void close_callback(int fd)
{
    debug_message("【TCP客户端】close_callback fd : " + fd);
    socket_close(fd);
}

private void client_init()
{
    int err;
    string addr = "127.0.0.1 6000";
    // 创建一个 efun socket 连接
    S = socket_create(STREAM, "read_callback", "close_callback");
    if (S < 0)
    {
        debug("【TCP客户端】socket_create error : " + socket_error(S));
    }
    else
    {
        debug("【TCP客户端】socket_create fd = " + S);
        // 启动一个 socket 连接
        err = socket_connect(S, addr, "read_callback2", "write_callback");
        if (err < 0)
        {
            debug("【TCP客户端】socket_connect error : " + socket_error(err));
            socket_close(S);
        }
        else
        {
            debug("【TCP客户端】socket_connect SUCCESS!");
        }
    }
}

void create()
{
    client_init();
}

int main(object me, string arg)
{
    int err;
    err = socket_write(S, arg);
    if (err < 0)
    {
        debug("【TCP客户端】socket_write error : " + socket_error(err));
    }
    else
    {
        debug("【TCP客户端】消息已发送：" + arg);
    }
    return 1;
}
