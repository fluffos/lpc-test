/**
 * sockets 相关测试
 */
int main(object me, string arg)
{
    return 1;
}

void release_callback(int fd)
{
    socket_acquire(fd, "read_callback", "write_callback", "close_callback");
}

void read_callback(int fd, mixed message)
{
}

void write_callback(int fd)
{
}

void close_callback(int fd)
{
}
