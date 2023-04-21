#include <windows.h>

LPCSTR classname = " "; //设置你的窗口类名
LPCSTR caption = " "; //设置你的窗口标题
int x = 0,y = 0; //设置你的窗口位置
int width = 640, height = 480; //设置你的窗口宽高

//回调函数
long long WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch(msg)
    {
        case WM_CLOSE:case WM_DESTROY:case WM_QUIT:  //窗口关闭的消息
         exit(0);
        break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);  //定义回调函数的返回值
}

int WINAPI WinMain(HINSTANCE hInst,  //实例句柄
            HINSTANCE hPrev, 
            LPSTR lpCmdLine, 
            int nCmdShow)
{
    WNDCLASSA wc; //窗口结构体
    memset(&wc, 0, sizeof(wc));
    wc.lpszClassName = classname;
    wc.hInstance = hInst; //实例句柄
    wc.lpfnWndProc = WndProc;
    RegisterClassA(&wc); //注册
    HWND hwnd = CreateWindowA(classname, caption, WS_VISIBLE|WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, NULL, hInst, NULL);  //创建窗口
    if(hwnd == NULL) return -1;  
    MSG msg;  //消息类
    while(true) if(GetMessage(&msg, NULL, 0, 0))  //消息循环  获得消息
    {
        TranslateMessage(&msg); //处理消息
        DispatchMessageA(&msg); //分发消息
    }
}
