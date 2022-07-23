int main(object me, string arg)
{
    function f;

    if (wizardp(me))
    {
        f = bind((: disable_wizard :), me);
        cecho("关闭wizard权限!");
    }
    else
    {
        f = bind((: enable_wizard :), me);
        cecho("开启wizard权限!");
    }
    evaluate(f);

    return 1;
}
