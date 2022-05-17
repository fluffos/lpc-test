/**
 * sockets DATAGRAM 模式客户端测试
 */

#define UDP 2
#define ADDR "127.0.0.1 6000"

nosave int S;
nosave object R;

void read_callback(int fd, mixed message, string addr)
{
    R && tell_object(R, sprintf("【UDP客户端】read_callback: fd = %d, from = %s, message = %s\n", fd, addr, message));
}

private void client_init()
{
    // 创建一个 efun socket 连接
    S = socket_create(UDP, "read_callback");
    // 如果不绑定端口，将使用随机端口连接服务器，但无法收到服务端返回的消息
    socket_bind(S, 52099);
    if (S < 0)
    {
        debug("【UDP客户端】socket_create error: " + socket_error(S));
    }
    else
    {
        debug("【UDP客户端】socket_create: fd = " + S);
    }
}

void create()
{
    R = this_player();
    client_init();
}

int main(object me, string arg)
{
    R = me;
    if (arg)
    {
        int err;
        // UDP 发送消息到服务器
        err = socket_write(S, arg, ADDR);
        if (err < 0)
        {
            debug("【UDP客户端】socket_write error: " + socket_error(err));
            // socket_close(S);
        }
        else
        {
            debug("【UDP客户端】消息已发送：" + arg);
        }
    }

    return 1;
}
