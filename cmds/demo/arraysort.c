// 生成乱序数组
int *array(int n)
{
    if (n > 15000)
    {
        n = 15000;
    }

    // return shuffle(allocate(n, (: $1 * secure_random($(n)) :)));
    return shuffle(allocate(n, (: $1 + 1 :)));
}

// 交换数组元素
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
 * 冒泡排序
 */
void bubbleSort(int *arr)
{
    int len = sizeof(arr);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

/*
 * 快速排序
 */
int partition(int *arr, int left, int right)
{
    int pivot = left, index = pivot + 1;
    for (int i = index; i <= right; i++)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr, i, index);
            index++;
        }
    }
    swap(arr, pivot, index - 1);
    return index - 1;
}

varargs void quickSort(int *arr, int left, int right)
{
    int len = sizeof(arr), index;

    if (nullp(right))
    {
        right = len - 1;
    }

    if (left < right)
    {
        index = partition(arr, left, right);
        quickSort(arr, left, index - 1);
        quickSort(arr, index + 1, right);
    }
}

/*
 * 插入排序
 */
void insertionSort(int *arr)
{
    int len = sizeof(arr), index, current;

    for (int i = 1; i < len; i++)
    {
        index = i - 1;
        current = arr[i];
        while (index >= 0 && arr[index] > current)
        {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = current;
    }
}

/*
 * 选择排序
 */
void selectionSort(int *arr)
{
    int len = sizeof(arr), index;

    for (int i = 0; i < len - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        swap(arr, i, index);
    }
}

/*
 * 归并排序
 */
int *merge(int *left, int *right)
{
    int *result = ({});

    while (sizeof(left) && sizeof(right))
    {
        if (left[0]<=right[0])
        {
            result += ({left[0]});
            left -= ({left[0]});
        }
        else
        {
            result += ({right[0]});
            right -= ({right[0]});
        }
    }
    while (sizeof(left))
    {
        result += ({left[0]});
        left -= ({left[0]});
    }
    while (sizeof(right))
    {
        result += ({right[0]});
        right -= ({right[0]});
    }

    return result;
}

int *mergeSort(int *arr)
{
    int len = sizeof(arr);
    int middle, *left, *right;

    if (len < 2)
    {
        return arr;
    }

    middle = floor(len / 2);
    left = arr[0..middle-1];
    right = arr[middle..];

    return merge(mergeSort(left), mergeSort(right));
}

// 排序测试
int main(object me, string arg)
{
    int n = atoi(arg);
    int *arr = array(n);
    int *arr1 = copy(arr), *arr2 = copy(arr), *arr3 = copy(arr), *arr4 = copy(arr), *arr5 = copy(arr);
    int t, t1, t2, t3, t4, t5;

    if (!n)
    {
        debug("请输入 `arraysort n` 生成数据并测试，n 为待排序数据个数。");
        return 1;
    }
    // 待排序数据
    printf("arr：%@ d\n", arr);
    t = time_expression(arr = sort_array(arr, 1));
    t1 = time_expression(bubbleSort(arr1));
    t2 = time_expression(quickSort(arr2));
    t3 = time_expression(insertionSort(arr3));
    t4 = time_expression(selectionSort(arr4));
    t5 = time_expression(arr5 = mergeSort(arr5));
    // 排序结果
    printf("arr0：%@ d\n", arr);
    printf("arr1：%@ d\n", arr1);
    printf("arr2：%@ d\n", arr2);
    printf("arr3：%@ d\n", arr3);
    printf("arr4：%@ d\n", arr4);
    printf("arr5：%@ d\n", arr5);
    printf("sort_array用时：%d，冒泡排序用时：%d，快速排序用时：%d，插入排序用时：%d，选择排序用时：%d，归并排序用时：%d\n", t, t1, t2, t3, t4, t5);
    return 1;
}
