//
// Created by Administrator on 2026/1/14.
//

#include "Heap.h"


void HP_Init(HP* php)
{
    assert(php);
    php->a = NULL;
    php->size = php->capacity = 0;
}

void Swap(HPDataType* a, HPDataType* b)
{
    HPDataType temp = *a;
    *a = *b;
    *b = temp;
}

void HP_Destroy(HP* php)
{
    assert(php);
    free(php->a);
    php->a = NULL;
    php->capacity = php->size = 0;
}

/*
 *1先将新的元素放在数组的末尾
 *2对比当前元素和父节点大小，继续向上调整
 */
void Adjustup(HPDataType* a, int child)
{
    int parent = (child - 1) / 2;
    // while (child > 0 && a[child] < a[parent])   //小堆
    while (child > 0 && a[child] > a[parent])   //大堆
    {
        Swap(&a[child], &a[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

void HP_Push(HP* php, HPDataType x)
{
    assert(php);
    if (php->size == php->capacity)
    {
        int new = php->capacity == 0 ? 4 : php->capacity * 2;
        HPDataType* tmp = (HPDataType*)realloc(php->a, new * sizeof(HPDataType));
        if (tmp == NULL)
        {
            perror("realloc Fail");
            return;
        }
        php->a = tmp;
        php->capacity = new;
    }
    php->a[php->size++] = x;
    Adjustup(php->a, php->size - 1);
}

/*
 *1先将顶节点和数组末尾的元素交换位置
 *2删除掉末尾的元素
 *3对比当前元素和父节点大小，继续向上调整
 */
void AdjustDown(HPDataType* a, int n, int parent)
{
    //设左孩子中较小
    int child = parent * 2 + 1;
    while (child < n)
    {
        //找出较小的孩子
        // if (a[child + 1] < a[child] && child + 1 < n) //小堆
        if (a[child + 1] > a[child] && child + 1 < n)    //大堆

        {
            ++child;
        }
        // if (a[child] < a[parent])    //小堆
        if (a[child] > a[parent])    //大堆
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

//删除堆顶元素
//时间复杂度O(logn)最优O(1)
void HP_Pop(HP* php)
{
    assert(php);
    assert(php->size > 0);
    Swap(&php->a[0], &php->a[php->size - 1]);
    php->size--;

    AdjustDown(php->a, php->size, 0);
}

HPDataType HP_Top(HP* php)
{
    assert(php);
    assert(php->size > 0);
    return php->a[0];
}

bool HP_Empty(HP* php)
{
    assert(php);
    return php->size == 0;
}
