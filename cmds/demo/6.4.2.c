// 示例：6.4.2
int main(object me, string arg)
{
    string *arr = ({"master", "apply", "efun", "mud", "fluffos", "test"});
    printf("原始数组 = %O\n", arr);
    printf("排序后数组 = %O\n", sort_array(arr, (: strcmp :)));
    return 1;
}
