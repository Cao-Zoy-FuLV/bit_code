//
// Created by Administrator on 2026/1/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

#include "Sort.c"

// ≤‚ ‘≈≈–Úµƒ–‘ƒ‹∂‘±»
void TestOP()
{
    srand(time(0));
    const int N = 10000000;
    int* a1 = (int*)malloc(sizeof(int) * N);
    int* a2 = (int*)malloc(sizeof(int) * N);
    int* a3 = (int*)malloc(sizeof(int) * N);
    int* a4 = (int*)malloc(sizeof(int) * N);
    int* a5 = (int*)malloc(sizeof(int) * N);
    int* a6 = (int*)malloc(sizeof(int) * N);
    int* a7 = (int*)malloc(sizeof(int) * N);
    int* a8 = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i)
    {
        a1[i] = rand() + rand() + i;
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
        a7[i] = a1[i];
        a8[i] = a1[i];
    }

    clock_t begin1 = clock();
    // InsertSort(a1, N);
    clock_t end1 = clock();

    clock_t begin7 = clock();
    // BubbleSort(a7, N);
    clock_t end7 = clock();

    clock_t begin2 = clock();
    ShellSort(a2, N);
    clock_t end2 = clock();

    clock_t begin3 = clock();
    // SelectSort(a3, N);
    clock_t end3 = clock();

    clock_t begin4 = clock();
    HeapSort(a4, N);
    clock_t end4 = clock();

    clock_t begin5 = clock();
    QuickSortNonR(a5, 0, N - 1);
    clock_t end5 = clock();

    clock_t begin6 = clock();
    MergeSort(a6, N);
    clock_t end6 = clock();

    clock_t begin8 = clock();
    CountSort(a8, N);
    clock_t end8 = clock();

    printf("√∞≈›≈≈–Ú BubbleSort:   %.4f\n", (double)(end7 - begin7) / 1000);
    printf("≤Â»Î≈≈–Ú InsertSort:     %.4f\n", (double)(end1 - begin1) / 1000);
    printf("œ£∂˚≈≈–Ú ShellSort:      %.4f\n", (double)(end2 - begin2) / 1000);
    printf("—°‘Ò≈≈–Ú SelectSort:    %.4f\n", (double)(end3 - begin3) / 1000);
    printf("∂—≈≈–Ú     HeapSort£∫  %.4f\n", (double)(end4 - begin4) / 1000);
    printf("øÏÀŸ≈≈–Ú QuickSort:    %.4f\n", (double)(end5 - begin5) / 1000);
    printf("πÈ≤¢≈≈–Ú MergeSort:   %.4f\n", (double)(end6 - begin6) / 1000);
    printf("º∆ ˝≈≈–Ú CountSort:    %.4f\n", (double)(end8 - begin8) / 1000);
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
    free(a7);
    free(a8);
}

void main0()
{
    // srand(time(0));
    // const int N = 8000;
    // int* a1 = (int*)malloc(sizeof(int) * N);
    // for (int i = 0; i < N; ++i)
    // {
    //     a1[i] = rand()+rand();
    // }
    // PrintArray(a1, N);
    // clock_t begin1 = clock();
    //
    //
    // QuickSortNonR(a1, 0, sizeof(a1) / sizeof(int) - 1);
    //
    // clock_t end1 = clock();
    // PrintArray(a1, N);
    // printf("%.4f\n", (double)(end1 - begin1) / 1000);


    int a1[] = {5, 2, 3, 6, 1, 4};
    PrintArray(a1, sizeof(a1) / sizeof(int));
    CountSort(a1, sizeof(a1) / sizeof(int));
    PrintArray(a1, sizeof(a1) / sizeof(int));
 }

int main()
{
    // main0();
    TestOP();
    return 0;
}
