/*****************************************************************************
Copyright: 2021, Mud.Ren
File name: monster_d.c
Description: 游戏怪物守护进程
Author: xuefeng@mud.ren
Version: v1.0
*****************************************************************************/
/*
 * ID, Name, HP, 攻, 防, 速, EXP, Gold
 */
nosave mixed mob_info = ({
    ({"mob", "小恶魔", 7, 6, 5, 4, 2, 1}),
    ({"mob1", "迷雾树人", 14, 12, 10, 8, 4, 2}),
    ({"mob2", "人脸玫瑰", 21, 18, 15, 12, 6, 3}),
    ({"mob3", "千面狩猎者", 28, 24, 20, 16, 8, 4}),
    ({"mob4", "六翼石像鬼", 35, 30, 25, 20, 10, 5}),
    ({"mob5", "诡术邪怪", 42, 36, 30, 24, 12, 6}),
    ({"mob6", "灵界掠夺者", 49, 42, 35, 28, 14, 7}),
    ({"mob7", "梦境捕手", 70, 60, 50, 40, 20, 10}),
    ({"mob8", "心灵巨龙", 100, 90, 70, 50, 30, 15}),
    ({"mob9", "暗天使恶灵", 150, 130, 120, 100, 50, 20}),
});

// 超出范围则随机返回
int limit(int index)
{
    if (index < 1 || index >= sizeof(mob_info))
        index = 1 + random(sizeof(mob_info) - 1);
    return index;
}

mixed info(int index)
{
    index = limit(index);
    return mob_info[index];
}
