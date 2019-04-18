int main(object me, string arg)
{
    if (wizardp(me))
    {
        shutdown(0);
        return 1;
    }
    else
    {
        return 0;
    }
}
