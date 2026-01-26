//
// Created by Administrator on 2026/1/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>


typedef char STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
} ST;

void ST_init(ST* pst)
{
    assert(pst);
    pst->a = NULL;
    pst->capacity = 0;
    //栈顶指向下一个位置
    pst->top = 0;
    //栈顶指向栈顶位置
    // pst->top = -1;
}

void ST_destroy(ST* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->capacity = pst->top = 0;
}

void ST_push(ST* pst, STDataType x)
{
    assert(pst);

    if (pst->top == pst->capacity)
    {
        int new = pst->capacity == 0 ? 4 : pst->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(pst->a, new * sizeof(STDataType));
        if (tmp == NULL)
        {
            perror("realloc Fail");
            return;
        }
        pst->a = tmp;
        pst->capacity = new;
    }
    pst->a[pst->top++] = x;
}

void ST_pop(ST* pst)
{
    assert(pst);
    assert(pst->top > 0);
    pst->top--;
}

STDataType ST_top(ST* pst)
{
    assert(pst);
    assert(pst->top > 0);
    return pst->a[pst->top - 1];
}

bool ST_empty(ST* pst)
{
    assert(pst);
    return pst->top == 0;
}

int ST_size(ST* pst)
{
    assert(pst);
    return pst->top;
}


//以上复制 stack 的

/*
 *
*请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：

你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

 */


typedef struct
{
    ST pushStack;
    ST popStack;
} MyQueue;

MyQueue* myQueueCreate()
{
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    ST_init(&obj->pushStack);
    ST_init(&obj->popStack);
    return obj;
}

void myQueuePush(MyQueue* obj, int x)
{
    ST_push(&obj->pushStack, x);
}

int myQueuePeek(MyQueue* obj); //前置声明
int myQueuePop(MyQueue* obj)
{
    int ret = myQueuePeek(obj);
    ST_pop(&obj->popStack);
    return ret;
}

int myQueuePeek(MyQueue* obj)
{
    if (ST_empty(&obj->popStack))
    {
        /// 倒数据  将pushStack中的元素全部弹出，并压入popStack中
        while (!ST_empty(&obj->pushStack))
        {
            ST_push(&obj->popStack, ST_top(&obj->pushStack));
            ST_pop(&obj->pushStack);
        }
    }
    return ST_top(&obj->popStack);
}

bool myQueueEmpty(MyQueue* obj)
{
    return ST_empty(&obj->pushStack) && ST_empty(&obj->popStack);
}

void myQueueFree(MyQueue* obj)
{
    ST_destroy(&obj->pushStack);
    ST_destroy(&obj->popStack);
    free(obj);
}

int main0()
{
    MyQueue* obj = myQueueCreate();
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePush(obj, 3);

    printf("%d\n", myQueuePeek(obj));
    printf("%d\n", myQueuePop(obj));
    printf("%d\n", myQueuePop(obj));
    printf("%d\n", myQueuePop(obj));
    printf("%d\n", myQueueEmpty(obj));
    return 0;
}
