//
// Created by Administrator on 2025/12/1.
//
#pragma execution_character_set("utf-8")

#include <stdio.h>
#include <windows.h>
void rotate(int* nums, int numsSize, int k)
{
    if (numsSize <= 1) return;

    // 处理k大于数组长度的情况
    k = k % numsSize;
    if (k == 0) return;

    // 反转整个数组
    for (int i = 0; i < numsSize / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = temp;
    }

    // 反转前k个元素
    for (int i = 0; i < k / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[k - 1 - i];
        nums[k - 1 - i] = temp;
    }

    // 反转剩余元素
    for (int i = 0; i < (numsSize - k) / 2; i++) {
        int temp = nums[k + i];
        nums[k + i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = temp;
    }
}


int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, 7, k);
     for (int i = 0; i < 7; i++)
     {
         printf("%d 你好", nums[i]);

     }
    fflush(stdout);
    Sleep(30000);
    return 0;
}

