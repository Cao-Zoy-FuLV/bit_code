//
// Created by Administrator on 2026/1/20.
//

#ifndef SNAKE_SORT_H
#define SNAKE_SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#endif //SNAKE_SORT_H

// 打印
void PrintArray(int* a, int n);

// 排序实现的接口

// 插入排序 时间复杂度O(n^2)
void InsertSort(int* a, int n);
// 希尔排序 时间复杂度O(n^1.3)
void ShellSort(int* a, int n);
// 选择排序 时间复杂度O(n^2)
void SelectSort(int* a, int n);

// 堆排序
// 时间复杂度O(nlogn)
// 大堆升序 小堆降序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// 冒泡排序 时间复杂度O(n^2)
void BubbleSort(int* a, int n);

// 快速排序 递归实现 时间复杂度O(nlogn)
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
// 快速排序挖坑法
void QuickSortPit(int* a, int left, int right);
// 快速排序前后指针法
int QuickSortFroBackPointSingle(int* a, int left, int right);
void QuickSortFroBackPoint(int* a, int left, int right);

// 归并排序递归实现 时间复杂度O(nlogn)
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序 时间复杂度O(n)
//  只适合整数数据 数据范围不大
void CountSort(int* a, int n);
