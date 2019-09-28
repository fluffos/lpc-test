// clean_up.c
#define NEVER_AGAIN 0
#define AGAIN 1

int clean_up(int inherited)
{
    object *inv;

    // 在线游戏玩家不清除
    if (interactive(this_object()))
        return AGAIN;
    // 在环境中的对象不主动清除（通过清除环境来清理）
    if (environment())
        return AGAIN;
    // 如果环境中有玩家则不清除环境
    inv = all_inventory();
    for (int i = sizeof(inv) - 1; i >= 0; i--)
        if (interactive(inv[i]))
            return AGAIN;

    destruct(this_object());
    return NEVER_AGAIN;
}
