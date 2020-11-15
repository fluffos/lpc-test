// 示例：2.1.8
class example {
    string name;
    int age;
    string *lover;
}

class example test(string name, int age, string *lover)
{
    class example test = new (class example);
    // 赋值
    test->name = name;
    test->age = age;
    test->lover = lover;
    return test;
}

int main(object me, string arg)
{
    // 变量
    class example instance;

    instance = test("mudren", 24, ({"a", "b", "c", "d", "e"}));
    // 取值
    printf("name : %s，age : %d, lover : %@-7s\n", instance->name, instance->age, instance->lover);
    return 1;
}
