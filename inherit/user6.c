inherit __DIR__ "user5";

// 客户端窗口大小
void window_size(int width, int height)
{
    string msg = sprintf("TELNET NAWS: %dx%d\n", width, height);
    receive(msg);
}

// receive_environ
void receive_environ(string var, string value)
{
    string msg = sprintf("TELNET ENV received: %s=%s\n", var, value);
    receive(msg);
}

void mxp_enable()
{
    receive("<MXP negotiation: enabled.>\n");
}

void gmcp_enable()
{
    receive("<GMCP negotiation: enabled.>\n");
}

void gmcp(string req)
{
    receive("<GMCP request received.>\n");
    receive(req);
    receive("\n<GMCP request end.>\n");
}

void mxp_tag(string command)
{
    receive("<MXP TAG: " + command + ".>\n");
}

void act_mxp()
{
    efun::act_mxp();
}

// 发送gmcp数据到客户端
void send_gmcp(string req)
{
    efun::send_gmcp(req);
}

void msp_enable()
{
    receive("<MSP negotiation: enabled.>\n");
}

// 发送msp数据到客户端
void msp_oob(string req)
{
    efun::telnet_msp_oob(req);
}
