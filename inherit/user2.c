inherit __DIR__ "user";

nosave mapping alias = ([
        "s":"go south",
        "n":"go north",
        "w":"go west",
        "e":"go east",
       "sd":"go southdown",
       "nd":"go northdown",
       "wd":"go westdown",
       "ed":"go eastdown",
       "su":"go southup",
       "nu":"go northup",
       "wu":"go westup",
       "eu":"go eastup",
       "sw":"go southwest",
       "se":"go southeast",
       "nw":"go northwest",
       "ne":"go northeast",
        "d":"go down",
     "down":"go down",
        "u":"go up",
       "up":"go up",
      "out":"go out",
    "enter":"go enter",
     "chat":"shout",
      "who":"users",
        "i":"all_inventory",
        "l":"look",
       "ls":"get_dir",
]);

// apply函数：如果用户对象中有process_input()，驱动会将玩家所有输入传入这里
// 如果 process_input() 方法返回字符串，此字符串会取代玩家的输入；如果返回 0 则保持玩家输入的内容不变；如果返回 1 则完全过滤掉此输入内容，不再做任何处理。
mixed process_input(string arg)
{
    arg = lower_case(arg);

    if (sscanf(arg, "l %s", arg))
    {
        arg = "look " + arg;
    }
    else if (sscanf(arg, "ls %s", arg))
    {
        arg = "get_dir " + arg;
    }
    else if (sscanf(arg, "chat %s", arg))
    {
        arg = "shout " + arg;
    }
    else if (!undefinedp(alias[arg]))
    {
        arg = alias[arg];
    }

    return arg;
}
