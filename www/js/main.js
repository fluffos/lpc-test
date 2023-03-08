// 基于xterm.js的websocket通信

function isMobile() {
    const userAgent = navigator.userAgent || navigator.vendor || window.opera;
    const mobiles = ["windows phone", "android", "iPhone", "iPad", "iPod"];
    for (let i = 0; i < mobiles.length; i++) {
        if (new RegExp(mobiles[i], "i").test(userAgent)) {
            return true;
        }
    }
    return false;
}

const WebFontSize = 14;
const MobileFontSize = 9;
const term = new Terminal({
    convertEol: true,
    disableStdin: true,
    allowProposedApi: true,
    fontSize: isMobile() ? MobileFontSize : WebFontSize
});
const unicode14Addon = new Unicode14Addon(true);
const weblinksAddon = new WebLinksAddon.WebLinksAddon();
const fitAddon = new FitAddon.FitAddon();
term.loadAddon(unicode14Addon);
term.unicode.activeVersion = '14';
term.loadAddon(weblinksAddon);
term.loadAddon(fitAddon);

document.addEventListener("DOMContentLoaded", () => {
    // 玩家输入指令
    const cmd = document.getElementById("cmd");
    // 指令发送按钮
    const send = document.getElementById("send");
    // 按键事件
    cmd.addEventListener("keydown", (e) => {
        switch (e.key) {
            case "Enter":
                sendCmd();
                break;
            case "ArrowUp":
                getCmd1();
                break;
            case "ArrowDown":
                getCmd2();
                break;
        }
    });

    const container = document.getElementById('container')
    container.style.height = "90vh";
    // Open the terminal in terminal-container
    term.open(container);
    // Make the terminal's size and geometry fit the size of terminal-container
    fitAddon.fit();
});
window.addEventListener('resize', fitAddon.fit);

let ws = null
// 取得websocket地址
function getWsUrl(extra_url) {
    const protocol = window.location.protocol === 'https:' ? 'wss://' : 'ws://';
    const host = window.location.host;
    return `${protocol}${host}/${extra_url}`;
}
// 连接游戏
function mudConnect() {
    if ("WebSocket" in window) {
        let url = getWsUrl();
        // 打开一个 web socket
        ws = new WebSocket(url, "ascii");
        const attachAddon = new AttachAddon.AttachAddon(ws);
        term.loadAddon(attachAddon);
        ws.onopen = (_event) => {
            console.log("服务器连接成功！");
            cmd.focus();
        };
        ws.onclose = (_event) => {
            console.log("服务器连接断开！");
            term.write("\r\n<======== Connection Lost ========>\r\n");
            send.setAttribute("disabled", "disabled");
            cmd.setAttribute("disabled", "disabled");
        };
        ws.onerror = (_event) => {
            console.log("服务器连接失败！");
        };
    } else {
        // 浏览器不支持 WebSocket
        alert("您的浏览器不支持 WebSocket!");
    }
}

let history = [];
let history_index = -1;
let current_command = "";

// 发送指令
function sendCmd() {
    if (ws) {
        if (cmd.value) {
            history.push(cmd.value);
            if (history.length > 20) {
                history.shift();
            }
            history_index = -1;
        }
        ws.send(cmd.value + "\n");
        term.write(cmd.value + "\n\r");
        cmd.value = "";
    } else {
        console.log("服务器未连接！");
    }
}
// 历史输入
function getCmd1() {
    // If there is history, show last one
    if (history.length > 0) {
        // remember current command
        if (history_index === -1) {
            current_command = cmd.value;
        }
        if (history_index < history.length - 1) {
            history_index = history_index + 1;
            cmd.value = history[history.length - history_index - 1];
        }
    }
}
function getCmd2() {
    if (history_index > -1) {
        history_index = history_index - 1;
        if (history_index >= 0) {
            cmd.value = history[history.length - history_index - 1];
        } else {
            cmd.value = current_command;
        }
    }
}
