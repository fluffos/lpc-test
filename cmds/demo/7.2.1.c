// 示例：7.2.1
int main(object me, string arg)
{
    cecho("文件目录：" + __DIR__);
    cecho("文件名：" + __FILE__);
#ifdef FLUFFOS
    cecho("当行前：" + __LINE__);
#endif
    cecho("文件名：" + file_name());

    return 1;
}
