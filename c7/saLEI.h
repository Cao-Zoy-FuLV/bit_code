#pragma once
#include<stdio.h>
#include <time.h>
#include<stdlib.h>
//���̲���
#define ROW 9
#define COL 9
#define ROWS  ROW+2
#define COLS  COL+2
//ǰͷ
void meun();
void SA_game();
//��ʼ������
void initial_board(char board[ROWS][COLS], int rows, int cols,char set);
//��ӡ����
void display_board(char board[ROWS][COLS], int row, int col);
//����
void set_mine(char board[ROWS][COLS], int row, int col);
///��������
#define FV_COUNT 5
////����
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);