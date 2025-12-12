//
// Created by Administrator on 2025/12/10.
//

#ifndef SNAKE_STACK_H
#define SNAKE_STACK_H

#endif //SNAKE_STACK_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>



typedef int  STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;

}ST;


//建栈
void ST_init(ST* pst);
//销毁栈
void ST_destroy(ST* pst);
//入栈
void ST_push(ST* pst,STDataType x);
//出栈
void ST_pop(ST* pst);
STDataType ST_top(ST* pst);
//判空
bool ST_empty(ST* pst);
//获取数据个数
int ST_size(ST* pst);
