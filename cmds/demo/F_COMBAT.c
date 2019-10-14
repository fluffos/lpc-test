// 战斗模块F_COMBAT
#define COMBAT_D __DIR__"COMBAT_D"

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
    me->move(VOID_OB);
    me->set("hp", 50);
}
