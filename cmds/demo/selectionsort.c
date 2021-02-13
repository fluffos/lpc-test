inherit __DIR__ "arraysort";

int main(object me, string arg)
{
    int t, *arr = array(atoi(arg));
    printf("待排序数据：%O", arr);
    // printf("已排序数据：%O", sort_array(arr, 1));
    t = time_expression(selectionSort(arr));
    printf("排序结果：%O，排序用时：%d\n", arr, t);

    return 1;
}
