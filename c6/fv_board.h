#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void meun();
#define ROW 3
#define COL 3
///初始化棋盘
void init_board(char board[ROW][COL], int row, int col);
//打印棋盘 
void dispaly_board(char board[ROW][COL], int row, int col);
//玩家下
void player_move(char board[ROW][COL], int row, int col);
//电脑下
void pc_move(char board[ROW][COL], int row, int col);
//判断输赢
char is_win(char board[ROW][COL], int row, int col);
