/**
 * sockets release 相关测试
 */

nosave int S;
nosave object R;

void create()
{
    R = this_player();
}

int main(object me, string arg)
{
    if (S && arg)
    {
        int err;
        err = socket_write(S, arg);
        if (err < 0)
        {
            debug("【Socket】socket_write error: " + socket_error(err));
        }
        else
        {
            debug("【Socket】消息已发送：" + arg);
        }
    }

    return 1;
}

void release_callback(int fd)
{
    S = fd;
    socket_acquire(fd, "read_callback", "write_callback", "close_callback");
}

void read_callback(int fd, mixed message)
{
    tell_object(R, sprintf("【Socket】read_callback: fd = %d, message = %s\n", fd, message));

    // 发送消息给客户端
    if (message == "hi")
    {
        socket_write(fd, "hello ^_^");
    }
}

void write_callback(int fd)
{
    tell_object(R, sprintf("【Socket】write_callback: fd = %d\n", fd));
}

void close_callback(int fd)
{
    tell_object(R, sprintf("【Socket】close_callback: fd = %d\n", fd));
    socket_close(fd);
}
