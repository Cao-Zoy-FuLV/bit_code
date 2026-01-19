//
// Created by Administrator on 2026/1/14.
//

#ifndef SNAKE_HEAP_H
#define SNAKE_HEAP_H

#endif //SNAKE_HEAP_H
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
    HPDataType* a;
    int size;
    int capacity;
}HP;

void HP_Init(HP* php);
void HP_Destroy(HP* php);
void HP_Push(HP* php, HPDataType x);
void HP_Pop(HP* php);
HPDataType HP_Top(HP* php);
bool HP_Empty(HP* php);
