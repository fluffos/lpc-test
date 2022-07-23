// 示例：6.3.1

int main(object me, string arg)
{
    mapping x = ([
        "key1":(["test":"value1"])
    ]);
    mapping y = ([
        "key2":"value2"
    ]);

    x += y;
    printf("x = %O\n", x);
    cecho(x["test"]);
    cecho(x["key1"]["test"]);
    y *= (["value2":({1, 2, 3, 4, 5})]);
    printf("y = %O\n", y);

    return 1;
}
