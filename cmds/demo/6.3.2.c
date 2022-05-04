int main(object me, string arg)
{
    // 声明映射变量
    mapping m1, m2, m3, m;
    string *keys = ({"a", "b", "c"});
    // 初始化
    m = (["name":"mudren", "age":18, "gender":"男性"]);
    printf("m = %O\n", m);
    // 写
    m["name"] = "雪风";
    // 增
    m["title"] = "MUD游戏菜鸟";
    // m += (["title":"MUD游戏老鸟"]);
    m += (["data":([
                "hp":100,
                "mp":50,
                "str":50,
                "def":30,
                "dex":20])]);
    m += (["ob": me]);
    printf("m = %O\n", m);
    // 删
    map_delete(m, "gender");
    map_delete(m["data"], "mp");
    // 读
    printf("m = %O\n", m);
    printf("name = %O\n", m["name"]);
    printf("hp = %O\n", m["data"]["hp"]);

    // 取所有键值
    printf("keys = %O\n", keys(m));
    printf("values = %O\n", values(m));

    // 判断 undefinedp()
    printf("%d\n", undefinedp(m["age"]));
    printf("%d\n", nullp(m["gender"]));
    printf("%O\n", m["gender"]);

    // 映射与json转换（sefun）
    printf("%s\n", json_encode(m));

    // 初始化空映射
    m = allocate_mapping(100);
    printf("m = %O\n", m);
    m = ([]);
    printf("m = %O\n", m);

    m1 = allocate_mapping(keys, ({"一", "二", "三"}));
    m2 = allocate_mapping(keys, "mud");
    m3 = allocate_mapping(keys, (: repeat_string($1, 5) :));
    printf("m1 = %O\n", m1);
    printf("m2 = %O\n", m2);
    printf("m3 = %O\n", m3);

    // 运算
    m1 = ([]);
    m2 = ([]);
    m1["driver"] = "mudos";
    m2["mudos"] = "fluffos";
    m3 = m1 + m2;
    printf("m3 = %O\n", m3);
    m3 = m1 * m2;
    printf("m3 = %O\n", m3);

    // copy
    m2 = m1;
    m3 = copy(m1);
    printf("m1 = %O\n", m1);
    m2["mudos"] = "fluffos";
    printf("m1 = %O\n", m1);
    printf("m3 = %O\n", m3);

    // 关于映射中的键
    m[0] = "test";
    m[me] = "test";
    m[keys] = "test";
    printf("m = %O\n", m);

    return 1;
}
