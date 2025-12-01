//
// Created by Administrator on 2025/11/8.
//

#ifndef BIT_CODE_SNAKE_H
#define BIT_CODE_SNAKE_H
#endif //BIT_CODE_SNAKE_H
#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>


#define POS_X 24
#define POS_Y 5
//类型声明
#define  wall L'墙'
#define  food L'洞'
#define  body L'蛇'

//蛇的方向
enum Direction
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
};

//蛇的状态
enum GAME_STSTE
{
    OK, //正常
    KILL_BY_WALL, //撞墙
    KILL_BY_SELF, //撞自己
    END, //正常退出
};

//蛇身节点结构体
typedef struct SnakeNode
{
    //坐标
    int x;
    int y;
    //下一个节点
    struct SnakeNode* next;
} SnakeNode, *pSnakeNode;

//贪吃蛇
typedef struct Snake
{
    pSnakeNode _pSnake; //蛇头指针
    pSnakeNode _pfood; //食物指针
    enum Direction _dir; //蛇的方向
    enum GAME_STSTE _state; //蛇的状态
    int _food_weight; //单食物分数
    int _score; //总分数
    int _sleep_time; //速度
} Snake, *pSnake;

//函数声明

//设置光标位置
void Setpos(short x, short y);

//游戏初始化
void GameStart(pSnake ps);

//  欢迎界面
void WelcomeToGame();

//  创建地图
void CreateMap();

//  初始化蛇
void InitSnake(pSnake ps);

//  初始化食物
void CreateFood(pSnake ps);

//运行游戏
void RunGame(pSnake ps);

//  蛇的移动-走一步
void SnkeMove(pSnake ps);

//  下一个坐标是否是食物
int NextIsFood(pSnakeNode next,pSnake ps);

//  下一个坐标是是食物 吃了
void EatFood(pSnakeNode next,pSnake ps);

//  下一个坐标不是食物
void NOFood(pSnakeNode next,pSnake ps);

//游戏善后
void GameEnd(pSnake ps);