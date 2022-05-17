// 显示 socket_status
int main(object me, string arg)
{
#ifdef FLUFFOS
    if (arg)
    {
        print_r(socket_status(atoi(arg)));
    }
    else
    {
        print_r(socket_status());
    }
#endif
    return 1;
}
