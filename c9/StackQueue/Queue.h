//
// Created by Administrator on 2025/12/11.
//

#ifndef SNAKE_QUEUE_H
#define SNAKE_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#endif //SNAKE_QUEUE_H

typedef int QDataType;

// 链式结构：表示队列
typedef struct QListNode
{
    struct QListNode* Next;
    QDataType val;
} QNode;

// 队列的结构
typedef struct Queue
{
    QNode* phead;
    QNode* ptaill;
    int size;
} Queue;

// 初始化队列
void Queue_init(Queue* pq);
// 队尾入队列
void Queue_push(Queue* pq, QDataType x);
// 队头出队列
void Queue_pop(Queue* pq);
// 获取队列头部元素
QDataType Queue_front(Queue* pq);
// 获取队列队尾元素
QDataType Queue_back(Queue* pq);
// 获取队列中有效元素个数
int Queue_size(Queue* pq);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int Queue_empty(Queue* pq);
// 销毁队列
void Queue_destroy(Queue* pq);
