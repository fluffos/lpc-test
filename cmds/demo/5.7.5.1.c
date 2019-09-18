// 示例：5.7.5.1

int main(object me, string arg)
{
    object ob = load_object("/cmds/demo/5.7.5");

    ob->test1(); // 无效
    ob->test2(); // 无效
    ob->test3();
    ob->test();
    // 使用封装的方法修改值
    ob->set_s1("5.7.5.1 重新设置 private 变量的值");
    // 通地封装的方法获取值
    debug(ob->get_s1());
    return ob->main();
}
