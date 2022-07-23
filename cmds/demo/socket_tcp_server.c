/**
 * sockets 相关测试,这里是TCP模式服务端
 */

#define TCP 1
#define PORT 6000

nosave int S;
nosave object R;

void close_callback(int fd)
{
    R && tell_object(R, sprintf("【TCP服务端】close_callback: fd = %d\n", fd));
    socket_close(fd);
}

void write_callback(int fd)
{
    R && tell_object(R, sprintf("【TCP服务端】write_callback: fd = %d\n", fd));
}

void read_callback(int fd, mixed message)
{
    R && tell_object(R, sprintf("【TCP服务端】read_callback: fd = %d, message = %s\n", fd, message));
    // 发送消息给客户端
    if (message == "hi")
    {
        socket_write(fd, "你好呀。");
    }
}

void listen_callback(int fd)
{
    int err;
    R && tell_object(R, sprintf("【TCP服务端】listen_callback: fd = %d\n", fd));
    // 在一个 socket 上接受连接
    S = socket_accept(fd, "read_callback", "write_callback");
    if (S < 0)
    {
        R && tell_object(R, sprintf("【TCP服务端】socket_accept error: %s\n", socket_error(S)));
    }
    else
    {
        R && tell_object(R, sprintf("【TCP服务端】socket_accept: fd = %d\n", S));
        err = socket_write(S, "欢迎连接到服务器 mud.ren ^_^");
        if (err < 0)
        {
            R && tell_object(R, sprintf("【TCP服务端】socket_write error: %s\n", socket_error(err)));
        }
    }
}

private void server_init()
{
    int s, err;

    // 创建一个 efun socket 连接
    s = socket_create(TCP, "read_callback", "close_callback");
    if (s < 0)
    {
        cecho("【TCP服务端】socket_create error: " + socket_error(s));
    }
    else
    {
        cecho("【TCP服务端】socket_create: fd = " + s);
        // 绑定端口到 socket 连接
        err = socket_bind(s, PORT);
        if (err < 0)
        {
            cecho("【TCP服务端】socket_bind error: " + socket_error(err));
            socket_close(s);
        }
        else
        {
            cecho("【TCP服务端】socket_bind SUCCESS!");

            // 监听一个 socket 连接
            err = socket_listen(s, "listen_callback");
            if (err < 0)
            {
                cecho("【TCP服务端】socket_listen error: " + socket_error(err));
                socket_close(s);
            }
            else
            {
                cecho("【TCP服务端】socket_listen ON " + socket_address(s, 1));
            }
        }
    }
}

void create()
{
    R = this_player();
    server_init();
}

int release()
{
    if(S)
    {
        int err;
        err = socket_release(S, load_object(__DIR__"socket_server"), "release_callback");
        if (err < 0)
        {
            cecho("【TCP服务端】socket_release error: " + socket_error(err));
        }
        else
        {
            cecho("【TCP服务端】socket_release SUCCESS！");
        }
    }

    return 1;
}

int main(object me, string arg)
{
    R = me;
    if (arg == "release")
    {
        release();
    }
    else if (arg)
    {
        int err;

        err = socket_write(S, arg);
        if (err < 0)
        {
            cecho("【TCP服务端】socket_write error: " + socket_error(err));
        }
        else
        {
            cecho("【TCP服务端】消息已发送：" + arg);
        }
    }

    return 1;
}
