/**
 * sockets TCP模式客户端测试
 */

#define TCP 1
#define ADDR "127.0.0.1 6000"

nosave int S;
nosave object R;

void close_callback(int fd)
{
    R && tell_object(R, sprintf("【TCP客户端】close_callback: fd = %d\n", fd));
    socket_close(fd);
}

void write_callback(int fd)
{
    R && tell_object(R, sprintf("【TCP客户端】write_callback: fd = %d\n", fd));
}

void read_callback(int fd, mixed message)
{
    R && tell_object(R, sprintf("【TCP客户端】read_callback: fd = %d, message = %s\n", fd, message));
}

private void client_init()
{
    int err;
    // 创建一个 efun socket 连接
    S = socket_create(TCP, "read_callback", "close_callback");
    if (S < 0)
    {
        cecho("【TCP客户端】socket_create error : " + socket_error(S));
    }
    else
    {
        cecho("【TCP客户端】socket_create fd = " + S);
        // 启动一个 socket 连接
        err = socket_connect(S, ADDR, "read_callback", "write_callback");
        if (err < 0)
        {
            cecho("【TCP客户端】socket_connect error : " + socket_error(err));
            socket_close(S);
        }
        else
        {
            cecho("【TCP客户端】socket_connect SUCCESS!");
        }
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
        err = socket_write(S, arg);
        if (err < 0)
        {
            cecho("【TCP客户端】socket_write error : " + socket_error(err));
        }
        else
        {
            cecho("【TCP客户端】消息已发送：" + arg);
        }
    }

    return 1;
}
