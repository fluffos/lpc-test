/**
 * sockets 相关测试,这里是TCP模式服务端
 */

#define STREAM 1

void close_callback(int fd);
void write_callback(int fd);
void listen_callback(int fd);

nosave int S;

void listen_callback(int fd)
{
    int err;
    debug_message("【TCP服务端】listen_callback fd : " + fd);
    // 在一个 socket 上接受连接
    S = socket_accept(fd, "read_callback", "write_callback");
    if (S < 0)
    {
        debug_message("【TCP服务端】socket_accept error : " + socket_error(S));
    }
    else
    {
        debug_message("【TCP服务端】socket_accept fd = " + S);
        err = socket_write(S, "欢迎连接到服务器 mud.ren ^_^");
        if (err < 0)
        {
            debug_message("【TCP服务端】socket_write error : " + socket_error(err));
        }
    }
}

// tcp模式使用
void read_callback(int fd, mixed message)
{
    debug_message("【TCP服务端】read_callback fd : " + fd);
    debug_message("【TCP服务端】read_callback : " + message + "\n");
    // 发送消息给客户端
    if (message == "hi")
    {
        socket_write(fd, "你好呀。");
    }
}

void write_callback(int fd)
{
    debug_message("【TCP服务端】write_callback fd : " + fd);
}

void close_callback(int fd)
{
    debug_message("【TCP服务端】close_callback fd: " + fd);
    socket_close(fd);
}

private void server_init()
{
    int s, err, port = 6000;

    // 创建一个 efun socket 连接
    s = socket_create(STREAM, "read_callback", "close_callback");
    if (s < 0)
    {
        debug("【TCP服务端】socket_create error : " + socket_error(s));
    }
    else
    {
        debug("【TCP服务端】socket_create fd = " + s);
        // 绑定端口到 socket 连接
        err = socket_bind(s, port);
        if (err < 0)
        {
            debug("【TCP服务端】socket_bind error : " + socket_error(err));
            socket_close(s);
        }
        else
        {
            debug("【TCP服务端】socket_bind SUCCESS!");

            // 监听一个 socket 连接
            err = socket_listen(s, "listen_callback");
            if (err < 0)
            {
                debug("【TCP服务端】socket_listen error : " + socket_error(err));
                socket_close(s);
            }
            else
            {
                debug("【TCP服务端】socket_listen ON " + socket_address(s, 1));
            }
        }
    }
}

void create()
{
    server_init();
}

int main(object me, string arg)
{
    if (arg)
    {
        int err;
        err = socket_write(S, arg);
        if (err < 0)
        {
            debug("【TCP服务端】socket_write error : " + socket_error(err));
        }
        else
        {
            debug("【TCP服务端】消息已发送：" + arg);
        }
    }

    return 1;
}
