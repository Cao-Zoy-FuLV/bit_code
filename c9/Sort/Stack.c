//
// Created by Administrator on 2025/12/10.
//
#include"Stack.h"

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
