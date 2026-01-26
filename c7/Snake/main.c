//
// Created by Administrator on 2025/11/8.
//

#include "Snake.h"
//测试逻辑
void test()
{
    //环境测试
    // HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //
    // char* retp  = setlocale(LC_ALL, NULL);
    // printf("当前语言环境是：%s\n", retp);
    // char* retp2  = setlocale(LC_ALL,"");
    // wchar_t* wc1= L"当前语言环境是：";
    // wprintf(L"%ls",wc1);
    // printf("%s\n", retp2);
    //

    int ch =0;
    do
    {
        system("cls");
        //创建游戏
        Snake snake = {0};
        //初始化游戏

        GameStart(&snake);
        //运行游戏
        RunGame(&snake);
        // 退出游戏-善后工作
        GameEnd(&snake);
        Setpos(18, 16);
        wprintf(L"是否重新开始游戏？(y/n)： ");
        while (getchar() != '\n')
        ch = getchar();
       //清理回车
    }while (ch == 'y'|| ch == 'Y');

}

int main0()
{
    //设置本地化环境以支持中文显示
    setlocale(LC_ALL, "");
    srand((unsigned  int)time(NULL));
    test();

    getchar();
    return 0;
}
