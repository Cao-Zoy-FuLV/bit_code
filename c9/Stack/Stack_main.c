//
// Created by Administrator on 2025/12/10.
//



#include "Stack.c"
int main0() {

    ST s;
    ST_init(&s);
    ST_push(&s,1);
    ST_push(&s,2);
    ST_push(&s,3);
    ST_push(&s,4);
    while (!ST_empty(&s))
    {
        printf("%d\n",ST_top(&s));
        ST_pop(&s);
    }

    ST_destroy(&s);
    return 0;
}