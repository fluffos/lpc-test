/**
 * sockets 相关测试
 */
void close_callback(int fd);

int main(object me, string arg)
{
    int s, err, mode = atoi(arg);

    // 创建一个 efun socket 连接
    s = socket_create(mode, "read_callback", "close_callback");
    debug("【客户端】socket_create : " + s);
    if (s < 0)
    {
        debug("【客户端】socket_create error : " + socket_error(s));
        close_callback(s);
    }
    else
    {
        if (mode != 2 && mode != 4)
        {
            // 启动一个 socket 连接
            err = socket_connect(s, "127.0.0.1 5000", "read_callback", "write_callback");
            debug("【客户端】socket_connect : " + err);
            if (err < 0)
            {
                debug("【客户端】socket_connect error : " + socket_error(err));
                close_callback(s);
            }
            else
            {
                // TCP 发送消息到服务器
                err = socket_write(s, "socket_TCP...\n");
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
    debug("【客户端】write_callback : " + fd);
    err = socket_write(fd, "你好，这是来自客户端的问候^_^\n");
    if (err < 0)
    {
        debug("【客户端】socket_write error : " + socket_error(err));
    }
}

void read_callback(int fd, mixed message)
{
    debug("【客户端】read_callback : " + fd);
    shout("【客户端】" + message);
}

void close_callback(int fd)
{
    debug("【客户端】close_callback : " + fd);
    debug("【客户端】socket_close : " + socket_close(fd));
}
