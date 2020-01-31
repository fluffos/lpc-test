/**
 * sockets 相关测试
 */
void close_callback(int fd);

int main(object me, string arg)
{
    int s, err, mode = atoi(arg);

    // 创建一个 efun socket 连接
    s = socket_create(mode, "read_callback", "close_callback");
    if (s < 0)
    {
        debug("【客户端】socket_create error : " + socket_error(s));
    }
    else
    {
        debug("【客户端】socket_create fd = " + s);
        if (mode != 2 && mode != 4)
        {
            // 启动一个 socket 连接
            err = socket_connect(s, "127.0.0.1 5000", "read_callback", "write_callback");
            if (err < 0)
            {
                debug("【客户端】socket_connect error : " + socket_error(err));
                close_callback(s);
            }
            else
            {
                debug("【客户端】socket_connect SUCCESS!");
            }
        }
        else
        {
            // UDP 发送消息到服务器
            err = socket_write(s, "socket_UDP...\n", "127.0.0.1 5000");
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
    return 1;
}

void write_callback(int fd)
{
    int err;
    debug("【客户端】write_callback fd : " + fd);
    err = socket_write(fd, "你好，这是来自客户端的问候^_^\n");
    if (err < 0)
    {
        debug("【客户端】socket_write error : " + socket_error(err));
    }
}

void read_callback(int fd, mixed message)
{
    debug("【客户端】read_callback fd : " + fd);
    shout("【客户端】" + message);
    // socket_write(fd, "客户端收到信息是：" + message);
}

void close_callback(int fd)
{
    debug("【客户端】close_callback fd : " + fd);
    debug("【客户端】socket_close : " + socket_close(fd));
}
