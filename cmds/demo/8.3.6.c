#include <ansi.h>

#define STREAM 1
#define EESUCCESS 1

nosave mapping status = ([]);
nosave object receiver;

void write_data(int fd)
{
    socket_write(fd, "GET " + status[fd]["path"] + " HTTP/1.0\nHost: " + status[fd]["host"] + "\n\r\n\r");
}

void receive_data(int fd, mixed result)
{
    string idiom;
    result = result[strsrch(result, "{")..];
    // debug_message(sprintf("%d || %O", strlen(result), result));
    if (strsrch(result, "total") > -1)
    {
        int total;
        result = json_decode(result);
        total = result["total"];
        idiom = HIY "和 " + status[fd]["keyword"] + " 相关的成语共有 " + total + " 条，索引如下：" NOR + "\n";
        result = result["result"];
        idiom += "----------------------------------------\n";
        foreach (mapping list in result)
        {
            idiom += HIC "成语：" + list["name"] + "\n索引：" + list["id"] + NOR + "\n";
        }
        idiom += "----------------------------------------\n";

        if (total > 20)
        {
            idiom += HIR "相关成语超过二十条，推荐使用更精确的关键词查询。" NOR "\n";
        }

        idiom += HIG "可以使用 `8.3.6 索引` 阅读指定成语。" NOR "\n";

        tell_object(receiver, idiom);
    }
    else
    {
        result = json_decode(result);
        if (result["error_code"])
        {
            tell_object(receiver, "没有找到相关索引成语。\n");
        }
        else
        {
            result = result["result"];
            idiom = "----------------------------------------\n";
            idiom += HIY "成语：" + result["name"] + NOR "\n";
            idiom += HIW "读音：" + result["spell"] + NOR + "\n";
            idiom += "----------------------------------------\n";
            idiom += HIC "解释：" + result["content"] + NOR + "\n";
            if (result["derivation"])
            {
                idiom += HIW "出处：" + result["derivation"] + NOR + "\n";
            }
            if (result["samples"])
            {
                idiom += HIW "示例：" + result["samples"] + NOR + "\n";
            }
            idiom += "----------------------------------------\n";
            tell_object(receiver, idiom);
        }
    }
}

void receive_callback(int fd, mixed result, string addr)
{
    // 此方法无效
}

void socket_shutdown(int fd)
{
    socket_close(fd);
}

int main(object me, string arg)
{
    int fd;
    int ret;
    string host = "api.avatardata.cn";
    string addr = "121.42.196.237 80";
    string key = "f47de96f0bd04223817aca17ca150f0e";
    string path;

    receiver = me;
    if (is_chinese(arg))
    {
        path = "/ChengYu/Search?key=" + key + "&keyWord=" + arg;
        msg("info", "$ME开始查找和 " + arg + " 相关的成语。", receiver);
    }
    else if (strlen(arg) == 36)
    {
        path = "/ChengYu/LookUp?key=" + key + "&id=" + arg;
        msg("info", "$ME开始查阅成语的详细解释。", receiver);
    }
    else
    {
        path = "/ChengYu/Random?key=" + key;
        msg("info", "$ME开始学习成语。", receiver);
    }

    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["host"] = host;
    status[fd]["path"] = path;
    status[fd]["keyword"] = arg;

    ret = socket_connect(fd, addr, "receive_data", "write_data");
    if (ret != EESUCCESS)
    {
        tell_object(receiver, "服务器连接失败。\n");
        socket_close(fd);
    }

    return 1;
}
