#include <windows.h>
#pragma comment( lib, "user32.lib" )
//windres ico.rc -o ico.o    .rc为创建的配置资源文件用 windres 编译为.o连接文件
//gcc 锁屏.cpp ico.o -o 锁屏.exe  链接到主程序
int main() {
    // Sleep(3000);
    PostMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,2);
    system("rundll32.exe user32.dll,LockWorkStation");

    return 0;
}