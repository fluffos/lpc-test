// 关闭服务器
int main(object me, string arg)
{
    if (!wizardp(me))
    {
        return 0;
    }

    shutdown(0);

    return 1;
}
