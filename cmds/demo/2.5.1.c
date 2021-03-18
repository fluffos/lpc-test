// 转义字符输出
int main()
{
    // 字符串
    write("\61\11\62\11\63\12");
    write("\141\x9\142\x9\143\xa");
    write("\61\62\63\t\x61\x62\x63\n");
    write("\123");
    write("\n");
    // 字符
    write('\123');
    write("\n");
    return 1;
}
