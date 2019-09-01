// 示例：5.2.1

// 全局变量，可以在当前文件中使用，不会被存档
nosave string file = "/data/dbase";
// 全局变量，可以在当前文件中使用，会被存档
string data;

int sum(int m, int n);

int main(object me, string arg)
{
    // me、arg 是局部变量，可以在 main() 内部使用
    if (arg == "load")
    {
        if (file_size(file + __SAVE_EXTENSION__) > 0)
        {
            // 读取存档，file 是全局变量
            restore_object(file);
            printf("data = %s\n", data);
        }
        else
        {
            printf("目前没有存档！\n");
        }
    }
    else if (arg)
    {
        // data 是全局变量
        data = arg;
        // 数据存档，file 是全局变量
        if (!catch (save_object(file)))
        {
            printf("数据存档成功！\n");
        }
        else
        {
            printf("数据存档失败，请确认存档目录 data 存在！\n");
        }
    }
    else
    {
        // begin、end、result 是块级变量，只能在本代码块内使用
        int begin = 1, end = 1024;
        int result = sum(begin, end);
        printf("The sum from %d to %d is %d\n", begin, end, result);
    }

    return 1;
}

int sum(int m, int n)
{
    int sum = 0;
    //m、n、sum 都是局部变量，只能在 sum() 内部使用
    // i 是块级变量，只能在 for 循环内部使用
    for (int i = m; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
