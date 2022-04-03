// 迷宫
#include <ansi.h>
inherit MAZE;

void create()
{
    //迷宫房间所继承的物件的档案名称
    set_inherit_room( ROOM );

    //迷宫房间里的怪物
    set_maze_npcs(({__DIR__ "world/npc/mob"}));

    //迷宫的单边长
    set_maze_long(10);

    //入口方向(出口在对面)
    set_entry_dir("south");

    //入口与区域的连接方向
    set_link_entry_dir("south");

    //入口与区域的连接档案名
    set_link_entry_room(__DIR__"world/5,2,0");

    //出口与区域的连接方向
    set_link_exit_dir("enter");

    //出口与区域的连接档案名
    set_link_exit_room(__DIR__"tower");

    //入口房间短描述
    set_entry_short(HIY "巨人王庭入口" NOR);

    //入口房间描述
    set_entry_desc(YEL @LONG
    这里是巨人王庭宫殿遗迹的入口，这里永远处于黄昏状态，那黄昏的光芒宛若实质，覆盖在宫殿表面，带来了强烈的衰败感。
LONG NOR);

    //出口房间短描述
    set_exit_short(HIY "巨人王庭出口" NOR);

    //出口房间描述
    set_exit_desc(HIW @LONG
    你眼前一亮，深深的吸了口气，心想总算是出来了。不过景色忽的一变，眼前出现一座高耸入云的魔法塔。
LONG NOR);

    //迷宫房间的短描述
    set_maze_room_short(HIB "巨人王庭" NOR);

    //迷宫房间的描述，如果有多条描述，制造每个房间的时候会从中随机选择一个。
    set_maze_room_desc(HIB @LONG
    这里是巨人王庭内部，因为真神的影响，绝大部分力量都明显衰退了，只有被神国承认的守卫，才能发挥相对正常的水准。
LONG NOR);

    // 迷宫房间是否为户外房间？
    // set_outdoors(1);

    // 是否绘制迷宫地图?
    set_maze_map(1);

    // 迷宫的额外参数
    set_extra_info(([
    ]));
}
