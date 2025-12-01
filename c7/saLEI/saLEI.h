#pragma once
#include<stdio.h>
#include <time.h>
#include<stdlib.h>
//棋盘参数
#define ROW 9
#define COL 9
#define ROWS  ROW+2
#define COLS  COL+2
//前头
void meun();
void SA_game();
//初始化棋盘
void initial_board(char board[ROWS][COLS], int rows, int cols,char set);
//打印棋盘
void display_board(char board[ROWS][COLS], int row, int col);
//雷普
void set_mine(char board[ROWS][COLS], int row, int col);
///几个雷普
#define FV_COUNT 5
////撅雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);