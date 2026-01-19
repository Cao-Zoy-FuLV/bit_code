//
// Created by Administrator on 2025/12/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>


typedef char  STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;

}ST;

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



bool isValid(char* s)
{
    ST St;
    ST_init(&St);
    while (*s)
    {
        if (*s=='('
            ||*s=='['
            ||*s=='{')
        {
            ST_push(&St,*s);
        }
        else
        {
            if (ST_empty(&St))
            {
                return 0;
            }
            char top=ST_top(&St);
            ST_pop(&St);
            //不匹配
            if (top=='('&&*s!=')'
                ||top=='['&&*s!=']'
                ||top=='{'&&*s!='}')
            {
                ST_destroy(&St);
                return 0;
            }
        }
        ++s;
    }
    //数量匹配
    bool r=ST_empty(&St);

    ST_destroy(&St);
    return r;
}

int main() {

    printf("%s\n",isValid("()")?"true":"False");
    printf("%s\n",isValid("()[]{}")?"true":"False");
    printf("%s\n",isValid("(]")?"true":"False");
    return 0;
}
