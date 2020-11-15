/**
 * sockets release 相关测试
 */

nosave int S;

int main(object me, string arg)
{
    int err;
    err = socket_write(S, arg);
    if (err < 0)
    {
        debug("【8.3.5】socket_write error : " + socket_error(err));
    }
    else
    {
        debug("【系统】消息已发送！");
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
    debug("【8.3.5】read_callback fd : " + fd);
    shout("【8.3.5】read_callback : " + message + "\n");
    // 发送消息给客户端
    if (message == "hi")
    {
        socket_write(fd, "hello ^_^");
    }
}

void write_callback(int fd)
{
    debug("【8.3.5】write_callback fd : " + fd);
}

void close_callback(int fd)
{
    debug("【8.3.5】close_callback fd: " + fd);
    socket_close(fd);
}
