//
// Created by Administrator on 2025/12/11.
//

#include "Queue.h"

void Queue_init(Queue* pq)
{
    assert(pq);
    pq->phead = NULL;
    pq->ptaill = NULL;
    pq->size = 0;
}

void Queue_push(Queue* pq, QDataType x)
{
    assert(pq);
    QNode* new = (QNode*)malloc(sizeof(QNode));
    if (new == NULL)
    {
        perror("malloc fail");
        return;
    }
    new->val = x;
    new->Next = NULL;
    if (pq->ptaill == NULL)
    {
        pq->phead = pq->ptaill = new;
    }
    else
    {
        pq->ptaill->Next = new;
        pq->ptaill = new;
    }
    pq->size++;
}
void Queue_pop(Queue* pq)
{
    assert(pq);
    assert(pq->size!=0);
    if (pq->phead->Next == NULL)//最后一个节点
    {
        free(pq->phead);
        pq->phead = pq->ptaill = NULL;
    }
    else//多个节点
    {
        QNode* tmp = pq->phead;
        pq->phead = pq->phead->Next;
        free(tmp);
    }
    pq->size--;
}
QDataType Queue_front(Queue* pq)
{
    assert(pq);
    assert(pq->phead);
    return pq->phead->val;
}
QDataType Queue_back(Queue* pq)
{
    assert(pq);
    assert(pq->ptaill);
    return pq->ptaill->val;
}

int Queue_size(Queue* pq)
{
    assert(pq);
    return pq->size;
}

int Queue_empty(Queue* pq)
{
    assert(pq);
    return pq->size == 0;
}
void Queue_destroy(Queue* pq)
{
    assert(pq);
    while (pq->phead)
    {
        QNode* tmp = pq->phead;
        pq->phead = pq->phead->Next;
        free(tmp);
    }
    pq->ptaill = NULL;
    pq->size = 0;
}
