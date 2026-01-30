//
// Created by Administrator on 2026/1/30.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void LomutoQuickSort(int* a, int left, int right)
{
    if (left >= right) return;
    int begin = left, end = right;
    int randi = (rand() % (right - left + 1)) + left;
    Swap(&a[randi], &a[left]);
    int kye = a[left];
    int cut = left + 1;
    while (cut <= right)
    {
        if (a[cut] < kye)
        {
            Swap(&a[cut], &a[left]);
            ++left;
            ++cut;
        }
        else if (a[cut] > kye)
        {
            Swap(&a[cut], &a[right]);
            --right;
        }
        else { ++cut; }
    }
    // 修正：左子区间应到 left - 1
    LomutoQuickSort(a, begin, left - 1);
    LomutoQuickSort(a, right + 1, end);
}

//给你一个整数数组 nums，请你将该数组升序排列。
//你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，
//并且空间复杂度尽可能小。

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    srand(time(0));
    LomutoQuickSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}

int main()
{
    int a[10] = {5, 2, 3, 1, 4, 4, 4, 4, 6, 7,};
    int size = sizeof(a) / sizeof(a[0]);
    int returnSize = 0;
    printf("排序前  ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    sortArray(a, size, &returnSize);
    printf("排序后  ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
