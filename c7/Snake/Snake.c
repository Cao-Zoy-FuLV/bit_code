//
// Created by Administrator on 2025/11/8.
//

#include "Snake.h"

void Setpos(short x, short y)
{
    //获得标准输出设备的句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ///设置光标位置
    COORD pos = {x, y};
    SetConsoleCursorPosition(hOut, pos);
}

void WelcomeToGame()
{
    Setpos(40, 13);
    wprintf(L"欢迎来到贪吃蛇游戏\n");
    Setpos(50, 16);
    system("pause");
    system("cls");
    Setpos(24, 13);
    wprintf(L"用 上、下、左、右键控制蛇移动 按f3加速 f4减速 \n");
    Setpos(24, 14);
    wprintf(L"加速能获得更高的分数\n");
    Setpos(50, 16);
    system("pause");
    system("cls");
}

void CreateMap()
{
    //上
    for (int i = 0; i < 29; i++)
    {
        wprintf(L"%lc", wall);
    }
    //下
    Setpos(0, 26);
    for (int i = 0; i < 29; i++)
    {
        wprintf(L"%lc", wall);
    }
    //左
    for (int i = 0; i <= 25; i++)
    {
        Setpos(0, i);
        wprintf(L"%lc", wall);
    };

    //右
    for (int i = 0; i <= 25; i++)
    {
        Setpos(56, i);
        wprintf(L"%lc", wall);
    };
}

void InitSnake(pSnake ps)
{
    pSnakeNode cur = NULL;
    for (int i = 0; i < 5; i++)
    {
        cur = (pSnakeNode)malloc(sizeof(SnakeNode));
        if (cur == NULL)
        {
            perror("内存分配失败");
            exit(-1);
        }
        cur->next = NULL;
        cur->x = POS_X + 2 * i;
        cur->y = POS_Y;

        //头插
        if (ps->_pSnake == NULL)
        {
            ps->_pSnake = cur;
        }
        else
        {
            cur->next = ps->_pSnake;
            ps->_pSnake = cur;
        }
    }
    cur = ps->_pSnake;
    while (cur != NULL)
    {
        Setpos(cur->x, cur->y);
        wprintf(L"%lc", body);
        cur = cur->next;
    }
    //设置蛇的属性

    ps->_dir = RIGHT; //默认向右移动
    ps->_food_weight = 10; //单食物分数
    ps->_score = 0; //总分
    ps->_sleep_time = 150; //单位  ms
    ps->_state = OK; //正常
}

void CreateFood(pSnake ps)
{
    int x = 0;
    int y = 0;
again:
    do
    {
        x = rand() % 53 + 2;
        y = rand() % 25 + 1;
    }
    while (x % 2 != 0);
    pSnakeNode cur = ps->_pSnake;
    while (cur != NULL)
    {
        if (cur->x == x && cur->y == y)
        {
            goto again;
        }
        cur = cur->next;
    }

    //创建食物
    pSnakeNode pfood = (pSnakeNode)malloc(sizeof(SnakeNode));
    if (pfood == NULL)
    {
        perror("内存分配失败");
        exit(-1);
    }
    pfood->x = x;
    pfood->y = y;
    pfood->next = NULL;
    Setpos(x, y);
    wprintf(L"%lc", food);
    ps->_pfood = pfood;
}

void GameStart(pSnake ps)
{
    //0.设置窗口大小，光标隐藏
    //设置控制台的大小
    system("title snake-game");
    system("mode con cols=100 lines=30");
    //设置光标
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci); //获取控制台光标信息
    cci.bVisible = FALSE; //隐藏控制台光标
    SetConsoleCursorInfo(hOut, &cci); //设置控制台光标信息
    //1.打印初始界面-功能介绍
    WelcomeToGame();
    //2 绘制地图
    CreateMap();
    //3.创建蛇
    InitSnake(ps);
    //4.创建食物
    CreateFood(ps);
}

void PrintHelp()
{
    Setpos(64, 12);
    wprintf(L"不能传墙，不能咬到自己\n");
    Setpos(64, 13);
    wprintf(L"用上、下、左、右键控制蛇移动\n");
    Setpos(64, 14);
    wprintf(L"按f3加速 f4减速\n");
    Setpos(64, 15);
    wprintf(L"加速能获得更高的分数\n");
    Setpos(64, 17);
    wprintf(L"按ESC键退出游戏 空格键暂停游戏\n");
}

#define KEY_press(vk) ((GetAsyncKeyState(vk)&1)?1:0)

void Pause()
{
    while (1)
    {
        Sleep(100);
        if (KEY_press(VK_ESCAPE))
        {
            break;
        }
    };
}

int NextIsFood(pSnakeNode next, pSnake ps)
{
    return next->x == ps->_pfood->x && next->y == ps->_pfood->y;
}

void EatFood(pSnakeNode next, pSnake ps)
{
    //头插
    ps->_pfood->next = ps->_pSnake;
    ps->_pSnake = ps->_pfood;

    //释放下一个位置的节点
    free(next);
    next = NULL;
    pSnakeNode cur = ps->_pSnake;
    //打印蛇
    while (cur != NULL)
    {
        Setpos(cur->x, cur->y);
        wprintf(L"%lc", body);
        cur = cur->next;
    }
    ps->_score += ps->_food_weight;
    //重新生成食物
    CreateFood(ps);
}

void NOFood(pSnakeNode next, pSnake ps)
{
    //头插
    next->next = ps->_pSnake;
    ps->_pSnake = next;
    pSnakeNode cur = ps->_pSnake;
    while (cur->next->next != NULL)
    {
        Setpos(cur->x, cur->y);
        wprintf(L"%lc", body);
        cur = cur->next;
    }
    //把最后的一个节点打印成空
    Setpos(cur->next->x, cur->next->y);
    printf("  ");
    //释放掉最后一个节点
    free(cur->next);
    //把倒数第2个节点的下一个地址置为NULL
    cur->next = NULL;
}

void SnkeMove(pSnake ps)
{
    //创建下一步的节点
    pSnakeNode newHead = (pSnakeNode)malloc(sizeof(SnakeNode));
    if (newHead == NULL)
    {
        perror("内存分配失败");
        exit(-1);
    }
    switch (ps->_dir)
    {
    case UP:
        newHead->x = ps->_pSnake->x;
        newHead->y = ps->_pSnake->y - 1;
        break;
    case DOWN:
        newHead->x = ps->_pSnake->x;
        newHead->y = ps->_pSnake->y + 1;
        break;
    case LEFT:
        newHead->x = ps->_pSnake->x - 2;
        newHead->y = ps->_pSnake->y;
        break;
    case RIGHT:
        newHead->x = ps->_pSnake->x + 2;
        newHead->y = ps->_pSnake->y;
    }
    //下一个坐标是否是食物
    if (NextIsFood(newHead, ps))
    {
        EatFood(newHead, ps);
    }
    else
    {
        NOFood(newHead, ps);
    }
    //检测是否撞到墙
    if (ps->_pSnake->x < 2 || ps->_pSnake->x > 56 || ps->_pSnake->y < 1 || ps->_pSnake->y > 26)
    {
        ps->_state = KILL_BY_WALL;
    }
    //检测是否撞到自己
    pSnakeNode cur = ps->_pSnake->next;
    while (cur != NULL)
    {
        if (ps->_pSnake->x == cur->x && ps->_pSnake->y == cur->y)
        {
            ps->_state = KILL_BY_SELF;
            break;
        }
        cur = cur->next;
    }
}

void RunGame(pSnake ps)
{
    //打印帮助信息
    PrintHelp();
    do
    {
        //打印总分，和食物分数
        Setpos(64, 10);
        wprintf(L"总分：%d ", ps->_score);
        Setpos(64, 11);
        wprintf(L"食物分数：%2d\n", ps->_food_weight);
        Setpos(64, 12);
        wprintf(L"速度：%d ms\n", ps->_sleep_time);

        if (KEY_press(VK_UP) && ps->_dir != DOWN)
        {
            ps->_dir = UP;
        }
        else if (KEY_press(VK_DOWN) && ps->_dir != UP)
        {
            ps->_dir = DOWN;
        }
        else if (KEY_press(VK_LEFT) && ps->_dir != RIGHT)
        {
            ps->_dir = LEFT;
        }
        else if (KEY_press(VK_RIGHT) && ps->_dir != LEFT)
        {
            ps->_dir = RIGHT;
        }
        else if (KEY_press(VK_SPACE))
        {
            //暂停
            Pause();
        }
        else if (KEY_press(VK_F3))
        {
            //加速
            if (ps->_sleep_time > 50)
            {
                ps->_sleep_time -= 50;
                ps->_food_weight += 2;
            }
        }
        else if (KEY_press(VK_F4))
        {
            //减速
            if (ps->_food_weight > 2)
            {
                ps->_sleep_time += 30;
                ps->_food_weight -= 2;
            }
        }
        else if (KEY_press(VK_ESCAPE))
        {
            //退出
            ps->_state = END;
        }
        SnkeMove(ps); //蛇走一步的过程
        Sleep(ps->_sleep_time);
    }
    while (ps->_state == OK);
}

void GameEnd(pSnake ps)
{
    Setpos(64, 6);
    switch (ps->_state)
    {
    case KILL_BY_WALL:
        wprintf(L"游戏结束，你撞墙了\n");
        break;
    case KILL_BY_SELF:
        wprintf(L"游戏结束，你撞自己了\n");
        break;
    case END:
        wprintf(L"游戏结束，你退出了\n");
        break;
    }
    Setpos(0, 29);
    //释放链表
    pSnakeNode cur = ps->_pSnake;
    while (cur != NULL)
    {
        pSnakeNode del = cur;
        cur = cur->next;
        free(del);
    }
}
