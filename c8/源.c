#include <stdio.h>
int main1() {
	//指针数组
	int arr[4];
	char* ch[5];
	//数组指针
	int arr2[5];
	int(*pa)[5] = &arr2;
	//pa类型--》int(* )[] 
	char* arr3[6] = { 0 };
	char* (*p3)[6] = &arr3;
	//p3是储存数组指针的数组
	return 0;
}

int test(const char* str)
{
	printf("test()\n");
	return 0;
}
int main2()
{
	//函数指针-也是一种指针，是指向函数的指针
	printf("%p\n", test);
	printf("%p\n", &test);
	//同为函数地址
	int (*pf)(const char*) = test;
	//pf类型--》int (* )(const char*)
	(*pf)("avb"); test("abc"); pf("abc");//同

	//	硬件需调用首地址为 0 位置的函数。
	//	( *(void (*)() )0 )();
	//	void （* ）()-->函数指针类型
	//	( )0-->强制类型转换==0改为函数地址
	//	(* )( )-->调用函数（void:无参数）
	//	阐述:
	//	 把 0 强制类型转换为：无参，返回类型是 void 的函数的地址
	//	 调用 0 地址处的这个函数
	//
		//
		//void (* signal( int, void(*)(int) ) )(int);
		//signal 是函数名  
		//int, void(*)(int) 是参数
		//阐述:
		//声明 signal 函数
		//第一个参数的类型是 int 
		//第二参数的类型是函数指针，该函数指针指向的函数參数是 int,
		// 返回类型是 void
		//signal 函数的返回类型也是一个函数指针，
		// 该函指针指向的函数参数是 int ，
		// 返回类型也是 void
		// 简化：
		//typedef void(* pf_t)(int);  把 void(*)(int) 类型重命名为 pf_t
		//pf_t signal(int,pf_t);
	return 0;
}

//————————————计算器(转移表)——————————————————
int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }
int Mul(int x, int y) { return x * y; }
int Div(int x, int y) { return x / y; }
void menu()
{
	printf("*******************\n");
	printf("***** 1.Add  ******\n");
	printf("***** 2.Sub  ******\n");
	printf("***** 3.Mul  ******\n");
	printf("***** 4.Div  ******\n");
	printf("***** 0.Exit ******\n");
	printf("*******************\n");
}
int main3() {
	int input = 0; int x = 0; int y = 0; int ret = 0;
	//函数指针数组
	int (*pf_[5])(int, int) = { 0,Add,Sub,Mul,Div };
	//指向〖函数指针数组〗的指针
	//int (*(*pf_)[5])(int, int) = &pf_;
	do
	{
		menu();
		printf(":>");
		scanf("%d", &input);
		if (input == 0)
		{
			printf("Exit\n");
		}
		else if (input >= 1 && input <= 4)
		{
			printf("请输入2个操作数:>");
			scanf("%d %d", &x, &y);
			ret = pf_[input](x, y);
			printf("%d\n", ret);
		}
		else
		{
			printf("Saniao\n");
		}
	} while (input);
	return 0;
}


//———————————————回调函数————————————————————
//回调函数    通过函数指针调用的函数
//如果把函数的指针（地址）作为参数传递给另一个函数, 
// 当这个指针被用来调用其所指向的函数时，就是回调函数。
//回调函数不是由该函数, 的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，
// 用于对该事件或条件进行响应
//

#include <string.h>
#include <stdlib.h>

//qsort 函数  -可以排序任意类型的数据
//void qsort (void* base, //将要排序数据的起始位置
//			size_t num, //待排序的数据元素的个数
//			size_t width, //待排序的数据元素的大小(单位是字节)
//			int(* cmp)(const void* el,const void* e2));//函数指针-比较函数 e1 和 e2 待比较的2数

// void* 是无具体类型的指针，可以接受任意类型的地址
//	所以不能解引用操作，也不能+-整数

//排序整型数据
int cmp_int(const void* e1, const void* e2)
{
	// 比较 2 个整型元素 
	// e1指向一个整数  e2 指向另一个整数
	return (*(int*)e1 - *(int*)e2);//升序
	//return (*(int*)e2 - *(int*)e1);//降序
}
//测试使用 qsort 来排序整型数据
void test1()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,9,10,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	//qsort 在内部函数调用了cmp__int
	for (size_t i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}
//测试使用 qsort 来排序结构数据

struct Stu
{
	char name[20];
	int age;
};
//比较名字
int cmp_stu_by_name(const void* e1, const void* e2)
{	//strcmp  返回>0, ==0, <0 
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
//比较年零
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//使用 qsort 来排序结构数据
void test2()
{
	struct Stu s[] =
	{
		{"zhangsan",15},
		{"lisi",30},
		{"wangwu",25}
	};
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
int main4() {
	test1();
	test2();
	return 0;
}

//————>>>>>>>冒泡排序

//交换
void Swap(char* buf1, char* buf2, int width)
{
	for (size_t i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++; buf2++;
	}
}
void bubble_sort(void* bass, int sz, int width, int(*cmp)(const void* el, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设数组是排好
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)/*一趟*/
		{
			//cmp e1 和 e2 待比较的2数地址
			if (cmp((char*)bass + j * width, (char*)bass + (j + 1) * width) > 0)
			{   //传地址*数据的宽度=任意宽度交换
				Swap((char*)bass + j * width, (char*)bass + (j + 1) * width, width);
				flag = 0;//计入
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main5() {
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (size_t i = 0; i < sz; i++)
		printf("%d ", arr[i]);

	return 0;
}

void f(int r, int* s)
{
	int c = 2 * r + 1;
	*s = c * r;
	r = *s - c;
}
int main6() {
	int x = 3;
	int a = 3 * x - 1;
	f(x, &a);
	printf("%d", a + x);
	return 0;
}

//————希尔排序算法
//步骤1 构造一个步长序列 delta1,delta2...deltak, 其中 delta =n/2, 后面的每个 delta 是前一个的 1/2 deltak=l 
//步骤2 根据步长序列、进行 k 趟排序
//步骤3 对第 i 趟排序，根据对应的步长 delta ,将等步长位置元素分组，对同一组内元素在原位置上进行直接插入排序。
void shellsort(int data[], int n)
{
	int* delta, k, i, t, dk, j;
	k = n;
	delta = (int*)malloc(sizeof(int) * (n / 2));
	i = 0;
	do
	{
		k = k / 2;
		delta[i++] = k;
	} while (k > 1);
	i = 0;
	while (dk = delta[i] > 0)
	{
		for (k = delta[i]; k < n; ++k)
		{
			if (data[k] < data[k - dk])
			{
				t = data[k];
				for (j = k - dk; j >= 0 && t < data[j]; j -= dk)
				{
					data[j + dk] = data[j];
				}
			}
			data[j + dk] = t;
		}
		i++;
	}
}
void shell_sort(int arr[], int len) {
	int gap, i, j;
	int temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}
int main7() {
	int arr1[12] = {222,111,99,88,77,66,55,44,33,22,111,0};
	shellsort(arr1, 12);
	for (size_t i = 0; i < 12; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	int arr2[12] = { 222,111,99,88,77,66,55,44,333,22,11,0 };
	shell_sort(arr2, 12);
	for (size_t i = 0; i < 12; i++)
	{
		printf("%d ", arr2[i]);
	}

	return 0;
}