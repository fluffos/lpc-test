// 打印所有载入游戏的对象
int main(object me, string arg)
{
    if (arg == "-c")
        print_r(objects( (:clonep:) ));
    else if (arg == "-o")
        print_r(objects( (: !clonep($1) :) ));
    else
        print_r(objects());

    return 1;
}
