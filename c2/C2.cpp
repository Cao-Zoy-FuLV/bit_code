#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void menu()
{
	printf("********************************\n");
	printf("*******     1. play      *******\n");
	printf("*******     0. exit      *******\n");
	printf("********************************\n");
}


void game()
{
	//RAND_MAX-32767
	//1.生成随机数
	//讲解rand函数
	int ret = rand() % 100 + 1;
	int num = 0;
	//2.猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		else if (num > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
		}
	}
}


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
}
//———————————test————————————————————————
int s(int a) {
	int c = 0;
	static int b = 3;
	c += 1; b += 2;
	return (a + b + c);
}
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