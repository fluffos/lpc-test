/**
 * sockets 相关测试,这里是UDP模式服务端
 */

#define UDP 2
#define PORT 6000

nosave int S;
nosave string Addr;
nosave object R;

// udp模式使用
void read_callback(int fd, mixed message, string addr)
{
    S = fd;
    Addr = addr;
    R && tell_object(R, sprintf("【UDP服务端】read_callback: fd = %d, from = %s, message = %s\n", fd, addr, message));
    // 发送消息给客户端，需要udp客户端绑定端口
    if (message == "hi")
    {
        socket_write(fd, "你好，客户端！", addr);
    }
}

private void server_init()
{
    int s, err;

    // 创建一个 efun socket 连接
    s = socket_create(UDP, "read_callback");
    if (s < 0)
    {
        debug("【UDP服务端】socket_create error: " + socket_error(s));
    }
    else
    {
        debug("【UDP服务端】socket_create: fd = " + s);
        // 绑定端口到 socket 连接
        err = socket_bind(s, PORT);
        if (err < 0)
        {
            debug("【UDP服务端】socket_bind error: " + socket_error(err));
            socket_close(s);
        }
        else
        {
            debug("【UDP服务端】socket_bind SUCCESS!");
            debug("【UDP服务端】UDP Socket 服务已启动 : " + socket_address(s, 1));
        }
    }
}

void create()
{
    R = this_player();
    server_init();
}

int main(object me, string arg)
{
    R = me;
    if (arg)
    {
        int err;

        err = socket_write(S, arg, Addr);
        if (err < 0)
        {
            debug("【UDP服务端】socket_write error: " + socket_error(err));
        }
        else
        {
            debug("【UDP服务端】消息已发送：" + arg);
        }
    }

    return 1;
}
