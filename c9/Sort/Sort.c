//
// Created by Administrator on 2026/1/20.
//

#include "Sort.h"

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void InsertSort(int* a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        //[0,end]有序 end+1位置的值插入[0,end],保持有序
        int end = i;
        int temp = a[end + 1];
        while (end >= 0)
        {
            if (a[end] > temp)
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
            a[end + 1] = temp;
        }
    }
}

void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        //+1 使得最后一次gap为 1
        gap /= 3 + 1;
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (a[end] > tmp)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
                a[end + gap] = tmp;
            }
        }
    }
}

void SelectSort(int* a, int n)
{
    int begin = 0;
    int end = n - 1;

    while (begin < end)
    {
        int mini = begin;
        int maxi = begin;
        for (int i = begin + 1; i <= end; ++i)
        {
            if (a[i] < a[mini])
                mini = i;
            if (a[i] > a[maxi])
                maxi = i;
        }
        Swap(&a[begin], &a[mini]);
        // 特殊情况：如果最大值原来在begin位置，由于上面的交换，
        // maxi现在应该指向mini的位置
        if (maxi == begin)
        {
            maxi = mini;
        }
        Swap(&a[end], &a[maxi]);
        begin++;
        end--;
    }
}

void AdjustDwon(int* a, int n, int root)
{
    //设左孩子中较小
    int child = root * 2 + 1;
    while (child < n)
    {
        //找出较小的孩子
        // if (a[child + 1] < a[child] && child + 1 < n) //小堆
        if (a[child + 1] > a[child] && child + 1 < n) //大堆
        {
            ++child;
        }
        // if (a[child] < a[root])    //小堆
        if (a[child] > a[root]) //大堆
        {
            Swap(&a[child], &a[root]);
            root = child;
            child = root * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int* a, int n)
{
    //降序，建小堆
    //升序，建大堆

    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        AdjustDwon(a, n, i);
    }

    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDwon(a, end, 0);
        --end;
    }
}

void BubbleSort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0; // 标记是否发生交换
        for (int j = 0; j < n - 1 - i; j++) /*一趟*/
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = 1; // 发生交换，标记为1
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}


//三数找中
int GetMid(int* a, int left, int right)
{
    int mid = (left + right) / 2;
    if (a[left] < a[mid])
    {
        if (a[left] < a[mid])
        {
            return mid;
        }
        else if (a[left] < a[right])
        {
            return right;
        }
        else
        {
            return left;
        }
    }
    else // a[left] > a[mid]
    {
        if (a[mid] > a[right])
        {
            return mid;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

void QuickSort(int* a, int left, int right)
{
    if (left >= right)
        return;

    //小区间优化，不再递归分割排序，减少递归次数
    if (right - left + 1 < 10)
    {
        InsertSort(a + left, right - left + 1);
    }
    else
    {
        // 三数找中 优化已经有序的数
        int mid = GetMid(a, left, right);
        Swap(&a[left], &a[mid]);

        int keyi = left;
        int begin = left, end = right;
        while (begin < end)
        {
            //右边找小（先走）
            while (begin < end && a[end] >= a[keyi])
            {
                --end;
            }
            //左边找大
            while (begin < end && a[begin] <= a[keyi])
            {
                ++begin;
            }
            Swap(&a[begin], &a[end]);
        }
        Swap(&a[keyi], &a[begin]);
        keyi = begin;
        if (keyi > left)
        {
            QuickSort(a, left, keyi - 1);
        }
        if (keyi < right)
        {
            QuickSort(a, keyi + 1, right);
        }
    }
}

#include "Stack.c"//栈 深度优先

void QuickSortNonR(int* a, int left, int right)
{
    ST st;
    ST_init(&st);
    ST_push(&st, right);
    ST_push(&st, left);


    while (!ST_empty(&st))
    {
        int begin = ST_top(&st);
        ST_pop(&st);
        int end = ST_top(&st);
        ST_pop(&st);

        int keyi = QuickSortFroBackPointSingle(a, begin, end);

        if (keyi + 1 < end)
        {
            ST_push(&st, end);
            ST_push(&st, keyi + 1);
        }
        if (begin < keyi - 1)
        {
            ST_push(&st, keyi - 1);
            ST_push(&st, begin);
        }
    }
    ST_destroy(&st);
}

void QuickSortPit(int* a, int left, int right)
{
    if (left >= right)
        return;
    int tmp = a[left];
    int keyi = left;
    int begin = left, end = right;
    while (begin < end)
    {
        while (begin < end && a[end] >= tmp)
        {
            --end;
        }
        a[begin] = a[end];

        while (begin < end && a[begin] <= tmp)
        {
            ++begin;
        }
        a[end] = a[begin];
    }
    a[begin] = tmp;
    keyi = begin;

    if (keyi > left)
    {
        QuickSortPit(a, left, keyi - 1);
    }
    if (keyi < right)
    {
        QuickSortPit(a, keyi + 1, right);
    }
}

int QuickSortFroBackPointSingle(int* a, int left, int right)
{
    if (left >= right)
        return left;
    int tmp = a[left];

    int keyi = GetMid(a, left, right);

    int prev = left; //前指针
    int cur = prev + 1; //后指针
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && prev++ != cur) //prev != cur是为了避免无用的原地交换
        {
            Swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    Swap(&a[keyi], &a[prev]);
    keyi = prev;
    return keyi;
}

void QuickSortFroBackPoint(int* a, int left, int right)
{
    if (left >= right)
        return;
    //小区间优化，不再递归分割排序，减少递归次数
    if (right - left + 1 < 10)
    {
        InsertSort(a + left, right - left + 1);
    }
    else
    {
        int keyi = QuickSortFroBackPointSingle(a, left, right);

        // if（）提前避免一些无效的递归调用
        if (keyi > left)
            QuickSortFroBackPoint(a, left, keyi - 1);
        if (keyi < right)
            QuickSortFroBackPoint(a, keyi + 1, right);
    }
}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    //  [begin,min-1] [mid,end]有序即可
    _MergeSort(a, tmp, begin, mid);
    _MergeSort(a, tmp, mid + 1, end);
    //归并
    int begin1 = begin;
    int end1 = mid;
    int begin2 = mid + 1;
    int end2 = end;
    int i = begin;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
        {
            tmp[i++] = a[begin1++];
        }
        else
        {
            tmp[i++] = a[begin2++];
        }
    }
    while (begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
    }
    while (begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }
    memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail");
        return;
    }
    _MergeSort(a, tmp, 0, n - 1);
    free(tmp);
    tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail");
        return;
    }
    //每组归并的数据个数
    int gap = 1;
    while (gap < n)
    {
        for (int i = 0; i < n; i += gap * 2)
        {
            int begin1 = i;
            int end1 = i + gap - 1;
            int begin2 = i + gap;
            int end2 = i + gap * 2 - 1;
            if (begin2 >= n)
            {
                break;
            }
            if (end2 >= n)
            {
                end2 = n - 1;
            }
            int j = i;
            while (begin1 <= end1 && begin2 <= end2)
            {
                if (a[begin1] < a[begin2])
                {
                    tmp[j++] = a[begin1++];
                }
                else
                {
                    tmp[j++] = a[begin2++];
                }
            }
            while (begin1 <= end1)
            {
                tmp[j++] = a[begin1++];
            }
            while (begin2 <= end2)
            {
                tmp[j++] = a[begin2++];
            }
            memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
        }
        gap *= 2;
    }

    free(tmp);
    tmp = NULL;
}

void CountSort(int* a, int n)
{
    int min = a[0];
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int range = max - min + 1;
    int* countArr = (int*)calloc(range, sizeof(int));
    if (countArr == NULL)
    {
        perror("malloc fail");
        return;
    }
    //统计个数
    for (int i = 0; i < n; i++)
    {
        countArr[a[i] - min]++;
    }
    //排序
    int j=0;
    for (int i = 0, j = 0; i < range; i++)
    {
        while (countArr[i]--)
        {
            a[j++] = i + min;;
        }
    }
    free(countArr);
}
