/**
 * sockets 相关测试,这里是服务端
 */
void close_callback(int fd);
void write_callback(int fd);
void listen_callback(int fd);

nosave int S;

void socket_init(int mode)
{
    int s, err, port = 5000;

    // 创建一个 efun socket 连接
    s = socket_create(mode, "read_callback", "close_callback");
    if (s < 0)
    {
        debug("【8.3.1】socket_create error : " + socket_error(s));
    }
    else
    {
        debug("【8.3.1】socket_create fd = " + s);
        // 绑定端口到 socket 连接
        err = socket_bind(s, port);
        if (err < 0)
        {
            debug("【8.3.1】socket_bind error : " + socket_error(err));
            socket_close(s);
        }
        else
        {
            debug("【8.3.1】socket_bind SUCCESS!");
            if (mode != 2 && mode != 4)
            {
                // 监听一个 socket 连接
                err = socket_listen(s, "listen_callback");
                if (err < 0)
                {
                    debug("【8.3.1】socket_listen error : " + socket_error(err));
                    socket_close(s);
                }
                else
                {
                    debug("【8.3.1】socket_listen ON " + socket_address(s, 1));
                }
            }
            else
            {
                debug("【系统提示】UDP Socket 服务已启动 : " + socket_address(s, 1));
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
    if (arg == "udp")
    {
        socket_init(2);
    }
    else if(arg == "release")
    {
        err = socket_release(S, load_object(__DIR__"8.3.5"), "release_callback");
        if (err < 0)
        {
            debug("【服务端】socket_release error : " + socket_error(err));
        }
        else
        {
            debug("【系统提示】socket_release SUCCESS！");
        }
    }
    else
    {

        err = socket_write(S, arg);
        if (err < 0)
        {
            debug("【服务端】socket_write error : " + socket_error(err));
        }
        else
        {
            debug("【系统提示】消息已发送！");
        }
    }
    return 1;
}

void listen_callback(int fd)
{
    int err;
    debug("【8.3.1】listen_callback fd : " + fd);
    // 在一个 socket 上接受连接
    S = socket_accept(fd, "read_callback2", "write_callback");
    if (S < 0)
    {
        debug("【8.3.1】socket_accept error : " + socket_error(S));
    }
    else
    {
        debug("【8.3.1】socket_accept fd = " + S);
        err = socket_write(S, "欢迎连接到服务器 mud.ren ^_^");
        if (err < 0)
        {
            debug("【客户端】socket_write error : " + socket_error(err));
        }
        else
        {
            debug("【系统提示】消息已发送！");
        }
    }
}

void read_callback(int fd, mixed message)
{
    debug("【8.3.1】read_callback fd : " + fd);
    shout("【8.3.1】read_callback : " + message + "\n");
}

varargs void read_callback2(int fd, mixed message)
{
    debug("【8.3.1】read_callback2 fd : " + fd);
    shout("【8.3.1】read_callback2 : " + message + "\n");
    // 发送消息给客户端
    if (message == "hi")
    {
        socket_write(fd, "你好呀。");
    }
}

void write_callback(int fd)
{
    debug("【8.3.1】write_callback fd : " + fd);
}

void close_callback(int fd)
{
    debug("【8.3.1】close_callback fd: " + fd);
    socket_close(fd);
}
