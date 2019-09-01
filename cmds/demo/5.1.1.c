// 示例：5.1.1
// apply 方法，对象加载时自动执行
void create()
{
    // 发送信息给当前玩家
    write("create 5.1.1!\n");
}

// apply 方法，设置心跳后自动执行
void heart_beat()
{
    // 记录日志，请在driver界面或 debug.log 文件中查看
    debug_message(file_name(this_object()) + ": " + time());
}

int main(object me, string arg)
{
    if (query_heart_beat())
    {
        write("停止心跳！\n");
        set_heart_beat(0);
    }
    else
    {
        write("开始心跳！\n");
        set_heart_beat(1);
    }

    return 1;
}
