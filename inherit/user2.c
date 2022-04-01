inherit __DIR__ "user";

// apply函数：如果用户对象中有process_input()，驱动会将玩家所有输入传入这里
// 如果 process_input() 方法返回字符串，此字符串会取代玩家的输入；如果返回 0 则保持玩家输入的内容不变；如果返回 1 则完全过滤掉此输入内容，不再做任何处理。
mixed process_input(string verb)
{
    string *word = explode(verb, " ");
    mapping alias = ([
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
       "ls":"get_dir",
    ]);

    // verb = lower_case(verb);

    switch (verb[0])
    {
    case '.':
        return "say " + verb[1..];
    }

    if (sizeof(word) && !undefinedp(alias[word[0]]))
    {
        word[0] = alias[word[0]];
        return implode(word, " ");
    }

    return verb;
}
