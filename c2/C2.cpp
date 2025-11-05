#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
//———————判断ji———————————————————
//int main() {
//	int a = 0;
//	int b = 0;
//	scanf_s("%d", &a);
//	if (a % 2)
//		printf("ji");
//	else
//	{
//		printf("NOji");
//	}
//	
//	return  0;
//}
//————————0~100的NOji————————————————————————// 
//int main() {
//	int a = 0;
//	while (a <= 100)
//	{	
//		if (a % 2){
//			printf("%d  ",a);
//		}
//		a++;
//	}
//return  0;}
//——————————————test————————————————————//
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3; printf("%d  ", b); printf("%d\n", a);
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	int c = 1 % 3;
//	printf("%d\n", c);
//	return 0;
//}
//—————————————test—————————————————————// 
//int  main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%.2f\n", sum);
//	return 0;
//}
//——————————————————猜数字————————————————
// void menu()
// {
//     printf("********************************\n");
//     printf("*******     1. play      *******\n");
//     printf("*******     0. exit      *******\n");
//     printf("********************************\n");
// }
//
//
// void game()
// {
//     //RAND_MAX-32767
//     //1.生成随机数
//     //讲解rand函数
//     int ret = rand() % 100 + 1;
//     int num = 0;
//     //2.猜数字
//     while (1)
//     {
//         printf("请猜数字:>");
//         scanf("%d", &num);
//         if (num == ret)
//         {
//             printf("恭喜你，猜对了\n");
//             break;
//         }
//         else if (num > ret)
//         {
//             printf("猜大了\n");
//         }
//         else
//         {
//             printf("猜小了\n");
//         }
//     }
// }


//int main()
//{
//	int input = 0;
//	//讲解srand函数
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//—————————————99乘法表——————————————————————//
//int main()
//{
//	int i = 0;
//	//控制行数
//	for (i = 1; i <= 9; i++)
//	{
//		//打印每一行内容，每行有i个表达式
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
// }
//———————————test————————————————————————
// int s(int a)
// {
//     int c = 0;
//     static int b = 3;
//     c += 1;
//     b += 2;
//     return (a + b + c);
// }

//int main()
//{
//	int i;
//	int a = 2;
//	for ( i = 0; i <5; i++){printf("%d\t", s(a));}
//	//2 5 1		8
//	//2 7 1		10
//	//2 9 1		12
//	//2 11 1	14
//	//2 14 1	16
//	return 0;
//}
//———————1！+2！——+n！——————————————————————————
//int main()
//{
//	int a = 10; int i = 1; int b = 1; int c = 0;
//	scanf("%d", &a);
//	for (i = 1; i <= a; i++)
//	{
//		b = b * i; c += b; printf("%d\n", c);
//	}
//	return 0;
//}
//————————(有序)2分法——————
//int main()
//{
//	int k=0; scanf("%d", &k);
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//总数/每个大小=个数
//	int l = 0; int r = sz - 1;
//	while (l<=r)//必加=
//	{	int mid = l + ( r - l ) / 2;//mid=短加长的一半
//		if (arr[mid] < k)l = mid + 1;
//		else if (arr[mid] > k)r = mid - 1;
//		else {printf("=%d", mid);break;	}
//		if(l>r)printf("sb");
//	}
//	return 0;
//}

//——————————————————————————————————————————————力扣27.移除元素
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。
// 然后返回 nums 中与 val 不同的元素的数量。
// 假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
// 更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。返回 k。
#include <iostream>
using namespace std;
// int removeElement(vector<int>& nums, int val)
// {
//     int a = 0;
//     int sz = nums.size();
//     for (int i = 0; i < sz; i++)
//     {
//         if (nums[i] != val)
//         {
//             nums[a] = nums[i];
//             a++;
//         }
//         cout << nums[i] << " ";
//     }
//     printf("\n");
//     return a;
// };
//
// int main()
// {
//     vector<int> nums = {3, 2, 2, 3};
//     int val = 3;
//     int k = removeElement(nums, val);
// }

//———————————————————————力扣88.合并两个有序数组
// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    //从前往后遍历
    /*int con1 = 0;
    if (m == 0)
    {
        copy(nums2.begin(), nums2.end(), nums1.begin());
        return;
    }
    for (int i = 0; i < m + n; i++)
    {
        if (i < n)
        {
            for (int k = 0; k <= m+con1; k++)
            {
                if (nums2[i] <= nums1[k])
                {
                    for (int j = 0; j < m-k+con1; j++)
                    {
                        if (m - 1 + con1 - j >=  0)
                        {
                            nums1[m + con1 - j] = nums1[m - 1 + con1 - j];
                        }
                    }
                    nums1[k] = nums2[i];
                    con1++;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < n - con1; i++)
            {
                nums1[m + con1 + i] = nums2[con1 + i];
            }
        }
    }*/
    int l1 =m - 1;
    int l2 = n - 1;
    int l3 = m + n - 1;
    while (l1 >= 0 && l2 >= 0)
    {
        if (nums1[l1] < nums2[l2])
        {
            nums1[l3--] = nums2[l2--];
        }
        else
        {
            nums1[l3--] = nums1[l1--];

        }
    }
    //除了循环有两种情况： l1 >= 0 或者 l2 >= 0
    //只需处理 l2 < 0 的情况 (l2还没完全放入 nums1 )
    while (l2 >= 0)
    {
        nums1[l3--]=nums2[l2--];
    }
    //此时nums1包含了nums2中的数据

}

int main()
{
    int m = 3;
    int n = 3;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
# if 1
    cout << "实例1 ";
    merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    vector<int> nums3 = {1};
    vector<int> nums4 = {};
    vector<int> nums5 = {0};
    cout << "\n";

    cout << "实例2 ";
    merge(nums3, 1, nums4, 0);
    for (int i = 0; i < nums3.size(); i++)
    {
        cout << nums3[i] << "";
    }
    cout << "\n";

    cout << "实例3 ";
    merge(nums5, 0, nums3, 1);
    for (int i = 0; i < nums5.size(); i++)
    {
        cout << nums5[i] << " ";
    }
    cout << "\n";

    cout << "实例6 ";
    vector<int> nums8 = {2, 0};
    vector<int> nums9 = {1};
    merge(nums8, 1, nums9, 1);
    for (int i = 0; i < nums8.size(); i++)
    {
        cout << nums8[i] << " ";
    }
    cout << "\n";

    cout << "实例5 ";
    vector<int> nums6 = {4, 5, 6, 0, 0, 0};
    vector<int> nums7 = {1, 2, 3};
    merge(nums6, m, nums7, n);
    for (int i = 0; i < nums6.size(); i++)
    {
        cout << nums6[i] << " ";
    }
    cout << "\n";

    cout << "实例7 ";
    vector<int> nums10 = {4, 0, 0, 0, 0, 0};
    vector<int> nums11 = {1, 2, 3, 5, 6};
    merge(nums10, 1, nums11, 5);
    for (int i = 0; i < nums10.size(); i++)
    {
        cout << nums10[i] << " ";
    }
    cout << "\n";
 #endif
    cout << "实例8 ";
    vector<int> nums12 = {1,2,4,5,6,0};
    vector<int> nums13= {3};
    merge(nums12, 5, nums13, 1);
    for (int i = 0; i < nums12.size(); i++)
    {
        cout << nums12[i] << " ";
    }
    cout << "\n";


    return 0;
}
