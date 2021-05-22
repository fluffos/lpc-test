// 战斗模块F_COMBAT
#define COMBAT_D "/system/daemons/combat_d"

int can_fight() { return 1; }

// 敌人列表
nosave object *enemies = ({});
// 获取敌人列表
object *query_enemy() { return enemies; }

// 判断是否在战斗中或在和指定对象战斗
varargs int is_fighting(object ob)
{
    if (!ob)
        return sizeof(enemies) > 0;

    return member_array(ob, enemies) != -1;
}

// 和指定对象开始战斗
void fight(object ob)
{
    if (member_array(ob, enemies) == -1)
    {
        enemies += ({ob});
    }
}

// 清理无效敌人
void clean_up_enemy()
{
    int i;
    if (i = sizeof(enemies))
    {
        while (i--)
        {
            if (!objectp(enemies[i]) || environment(enemies[i]) != environment())
            {
                enemies[i] = 0;
            }
        }
        enemies -= ({0});
    }
}

// 移除指定敌人
int remove_enemy(object ob)
{
    enemies -= ({ob});
    return 1;
}

// 清除所有敌人
void remove_all_enemy()
{
    enemies = ({});
}

// 开始攻击随机敌人
void attack()
{
    object me = this_object(), opponent;

    clean_up_enemy();
    if (sizeof(enemies) && objectp(opponent = element_of(enemies)))
    {
        COMBAT_D->fight(me, opponent);
    }
}

// 死亡处理
void die()
{
    object me = this_object();
    remove_all_enemy();
    msg("danger", "$ME死亡了。", me);
    me->move(START_ROOM);
    me->set("hp", me->query("max_hp"));
}

void heart_beat()
{
    // 死亡相关控制
    if (this_object()->query("hp") < 0)
    {
        die();
    }
    // 行动相关控制
    if (is_fighting())
    {
        // 战斗吧，皮卡丘
        attack();
    }
}
