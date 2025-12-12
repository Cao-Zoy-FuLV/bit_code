//
// Created by Administrator on 2025/12/11.
//
#include  "Queue.c"
int main(int argc, char* argv[])
{
    Queue q;
    Queue_init(&q);
    Queue_push(&q,1);
    Queue_push(&q,2);
    Queue_push(&q,3);
    Queue_push(&q,4);
    Queue_push(&q,5);
    while (!Queue_empty(&q))
    {
        printf("%d ",Queue_front(&q));
        Queue_pop(&q);
    }
    Queue_destroy(&q);
    return 0;
}
