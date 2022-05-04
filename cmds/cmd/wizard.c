int main(object me, string arg)
{
    function f;

    if (wizardp(me))
    {
        f = bind((: disable_wizard :), me);
        debug("关闭wizard权限!");
    }
    else
    {
        f = bind((: enable_wizard :), me);
        debug("开启wizard权限!");
    }
    evaluate(f);

    return 1;
}
