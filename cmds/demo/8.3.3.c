// 显示 socket_status
int main(object me, string arg)
{
    if (arg)
    {
        print_r(socket_status(atoi(arg)));
    }
    else
    {
        print_r(socket_status());
    }

    return 1;
}
