#include <windows.h>
#pragma comment( lib, "user32.lib" )
int main() {
    PostMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,2);
    system("rundll32.exe user32.dll,LockWorkStation");

    return 0;
}