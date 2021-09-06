// 关闭服务器
int main(object me, string arg)
{
    if (query_ip_number(me) != "127.0.0.1")
    {
        return 0;
    }

    shutdown(0);

    return 1;
}
