#include<stdio.h>
//（一）sizeo(数组名)，表示整个数组，计算总大小/bit
//（二）&数组名，表示整个数组，取出整个数组地址
//（三）其余表示首元素的地址
int main1() {
	int arr[10] = { 0 };
	printf("%p ", arr);			//首元素的地址
	printf("%p\n", arr + 1);		//首元素的地址+4
	printf("————————————————————\n");
	printf("%p ", &arr);		//数组地址的地址
	printf("%p\n", &arr + 1);		//数组地址的地址+数组地址的地址(+28)
	printf("————————————————————\n");
	printf("%p ", &arr[0]);		//首元素的地址
	printf("%p\n", &arr[0] + 1);//首元素的地址+4
	printf("————————二维—int arrr[3][4]={ 0 };——————————\n");
	int arrr[3][4] = { 0 };
	printf("有几行= %d  48/16=>3\n", sizeof(arrr) / sizeof(arrr[0]));//
	printf("有几列= %d  16/4 =>4\n", sizeof(arrr[0]) / sizeof(arrr[0][0]));//
	return 0;
}
// ————————————————————————————————
int main2() {
	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 }; int i = 0;
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
	return 0;
}
//二维数组=一维数组的数组（在内存中连续存放）

//——————————————冒泡排序——————————————
void bubble_sort(int arr[], int sz)
{
	int j = 0;
	for (size_t i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)/*一趟*/ {
			if (arr[j] > arr[j + 1])
			{   
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main3() {
	int arr[] = { 75,94,45,5,26,44,26,8,57,52,61,11,36,9,68,27,45,86,55,15 };
	/*趟数*/int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, sz);
	for (size_t i = 0; i < sz; i++) {
		printf("%d  ", arr[i]);
	}
	return 0;
}



// ————————————————————————————————————
//————指针变量用来存放地址的，地址是唯一标示一块内存空间的
//————指针的大小在32位平台是4个字节,在64位平台是8个字节
int main4() {
	char* pc = NULL;	printf("%zu	", sizeof pc);
	short* ps = NULL;	printf("%zu	", sizeof ps);
	int* pi = NULL;		printf("%zu	", sizeof pi);
	double* pd = NULL;	printf("%zu	", sizeof pd);
	//-sizeof返回类型为 unsigned int
	return 0;
}

//——>指针类型
int main4_2() {
	int a = 0x11223344;
	int* pa = &a;				*pa = 0;
	char* pc = (char*)&a;		*pc = 0;
	//————指针类型决定了指针在被解引用的时候访问几个字节
	//char* 的指针   解引用访问 1 个字节
  //double* 的指针 解引用访问 8 个字节
	//int* 的指针	 解引用访问 4 个字节
	//float* 的指针  解引用访问 4 个字节
	//int* 和float*  区别在：存储方式不一样
	return 0;
}
int main5() {
	int a = 0x11223344;
	//100 - 10进制
	//0x64 -16进制
	//144 - 8进制
	//110 0100 - 2进制	
	int* pa = &a;
	printf("pa=%p\n", pa);
	printf("pa+1=%p\n", pa + 1);//+4字节
	char* pc = (char*)&a;
	printf("pc=%p\n", pc);
	printf("pc+1=%p\n", pc + 1);//+1字节
	//————指针类型决定了指针+或-操作时跳过字节
	//————指针类型决定指针步长
	return 0;
}

//——>指针+-整数
int main6() {
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < sz; i++)
	//{//数组下标的写法	
	//	arr[i] = 1;
	//} 
	int* p = arr;
	//for (int i = 0; i < sz; i++)
	//{//指针写法1
	//	*p = 2; p++;	
	//}
	for (int i = 0; i < sz; i++)
	{//指针写法2
		*(p + i) = 3;

	}
	//—— > 数组：    一组同类型的元素集合
	//—— > 指针变量：存放地址的变量
	for (int i = 0; i < sz; i++)
		printf("%p———%p\n", &arr[i], p + i);
	return 0;				  //arr[i]==*(arr+i)
}

//——>指针-指针
int/*新MY_strlen方法*/MY_strlen(const char* str) {
	const	char* start = str;
	while (*str != '\0') str++;
	return (str - start);
}
int main7() {
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);
	//指针一指针得到的指针和指针之间元素的个数
	//指向同一个空间的指针才相减
	int len = MY_strlen("asd");
	printf("%d", len);
	return 0;
}

//—— > 指针的关键运算
#define N_VALUES 5
//将数组（N_VALUES【5】）初始化
int main8() {
	float values[N_VALUES];
	float* vp;
	for (vp = &values[0]; vp < &values[N_VALUES];)
		*vp++ = 1;//正着赋值
	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
		*vp = 2;//倒着赋值
	return 0;
}
//—— > 倒着赋值
//实际在绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免这样写
//因为标准并不保证它可行。
//—— > 标准规定:
//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针交
//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。

//——>二级指针
int main9() {
	int a = 1;
	int* pa = &a;//pa=>一级指针变量
	int** ppa = &pa;//ppa=>二级指针变量
	//——>指针数组
	int arr[10] = { 0 };
	int b = 1; int* pb = &b;
	int e = 2; int* pe = &e;
	int c = 3; int* pc = &c;
	int* parr[10] = { &e, &b, &c };//parr=>指针数组
	for (int i = 0; i < 3; i++)
		printf("%d\n", *(parr[i]));
	//——>指针	二维数组	
	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 2,3,4,5 };
	int arr3[4] = { 3,4,5,6 };
	int* parr1[3] = { arr1,arr2,arr3 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			printf("%d ", parr1[i][j]);
		printf("\n");
	}
	return 0;
}



//————————————————————————————————————————
struct r {//——>结构体
	char name[20];
	char te1e[12];
	char sex[5];
	int high;
};
struct rs {//——>结构体嵌套
	struct r r;
	int n;
	float f;
};
void print1(struct r* r1) {
	printf("%s %s %s %d	", r1->name, r1->te1e, r1->sex, r1->high);
}//结构体变量->成员变量
void print2(struct r r1) {
	printf("%s %s %s %d\n", r1.name, r1.te1e, r1.sex, r1.high);
}//结构体变量.成员变量
int main10() {
	struct r r1 = { "sa","15688889999","lan",180 };//结构体变量创建
	struct rs s1 = { {"bi","13388889999","jiao",160 },100,1.01 };
	printf("%s %s %s %d\n", r1.name, r1.te1e, r1.sex, r1.high);
	printf("%s %s %s %d %d %f\n", s1.r.name, s1.r.te1e, s1.r.sex, s1.r.high, s1.n, s1.f);
	print1(&r1); print2(r1);
	return 0;
}
//———————————1!+2!+3!....n!—————————————————————————————

////n!
int main11() {
	int n = 0;
	scanf("%d", &n);
	int ret = 1;
	for (int i = 1; i <= n; i++)
		ret *= i;
	printf("%d\n", ret);

	return 0;
}

int main12() {
	int n = 0; int sum = 0;
	scanf("%d", &n);
	int ret = 1;
	for (int j = 1; j <= n; j++)
	{
		ret = 1;
		for (int i = 1; i <= j; i++)
			ret *= i;
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}

//————————————————————————————————————————
// 1		局部数据存在栈区，
// 2		先使用高地址的空间，在使用低地址的空间
//	 数组随着下标增涨地址由低到高
// 3		如果 i 和 arr 之间由适当的空间，利用数组的越界操作僦可能会覆盖到 i 
//	 就可能出现死循环  
int main13() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (size_t i = 0; i <= 16; i++)
	{//
		arr[i] = 0; printf("Saniao\n");
	}
	return 0;
}

//———————————————— consy  assert ———————————————————————
#include <assert.h>
char* my_strcpy(char* dest, const char* src)
//char*-->实现链式访问
//strcpy函数返回的是目标空间的起始地址
{
	char* ret = dest;
	//断言
	assert(src != NULL); assert(dest != NULL);
	while (*dest++ = *src++);
	return ret;
}
int main14() {
	char arr1[20] = "xxxxxxxxxxxxxxxxx";
	char arr2[] = "Saniao";
	//char* p = NULL;//strcpy在拷贝字符串，会把源字符串的\0拷贝
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}
int main15() {
	//const 修饰指针变量
	const int n1 = 10;
	//const int* p = &n1; 
	//int n2 = 1; 
	//p = &n2;
	// 1 ． const 放在*的左边
	//意思是： p 指向的对象不能通过 p 来改变了，但是 p 变量本身的值是可以改变的
	int* const p = &n1;
	*p = 2;
	// 2 、 const 放在*的右边
	//意思是： p 指向的对象是可以通过 p 来改变的，但是不能修改 p 变量本身的值
	printf("%d", n1);
	return 0;
}
//————————————————————判断三角形————————————————————
//
int main16() {
	int a = 0; int b = 0; int c = 0;
	while (scanf("%d %d %d", &a, &b, &c) == 3)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))//判断
		{
			if (a == b && b == c) {
				printf("1");//等边三角彳亍
			}
			else if ((a == b && b != c) || (a == c && c != b) || (b == c && b != c)) {
				printf("2");//等腰三角形
			}
			else {//普通三角形
				printf("3");
			}
		}
		else printf("0");//不是三角形
	}
	return 0;
}
#include	<stdio.h>
#include	<assert.h>

//——————求字符串长度——————————————————————————————
int my_strlen(const char* str) {
	int count = 0;
	assert(str);
	while (*str != '\0')
	{
		count++; str++;
	}
	return count;
}
int main17() {
	char arr[] = "Sanina";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
//————————————————————————————————————

//————————————————————————————————————————
#include <math.h>//水仙花
//求出 0 ～ 99999 之间的所有“水仙花数”并输出。
//“水仙花数”是指一个 n 位数，其各位数字的 n 次方之和确好等于该数本身
// 如： 153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3 ，则 153 是一个“水仙花数”。
int Narcissistic_number(int i) {
	//1 .  计算i是几位数
	int n = 1;//至少是1位
	int sum = 0;
	int tmp = i;
	while (tmp / 10)
	{
		n++;
		tmp /= 10;
	}
	//2 .  得到 i 每一位，计算他的 n 次方之和
	tmp = i;
	while (tmp)
	{
		sum += pow(tmp % 10, n);
		tmp /= 10;
	}
	return sum == i;

}
int main18() {
	int i = 0;
	for (i = 0; i <= 99999; i++)
	{
		if (Narcissistic_number(i))
			printf("%d\n", i);
	}
	return 0;
}
int main19() {
	int money = 0;
	scanf("%d", &money);
	if (money > 0)
		printf("%d\n", 2 * money - 1);
	else
		printf("%d\n", 0);
	return 0;
}
//————————————————————————————————————
//倒置字符串
void reverse(char* left, char* right) {
	assert(left); assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++; right--;
	}
}
int main20() {
	char arr[10000] = { 0 };
	//输入
	gets(arr);
	//倒置
	int len = my_strlen(arr);
	//总逆序
	reverse(arr, arr + len - 1);
	//逆序个个单词
	char* start = arr;
	while (*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0')
			end++;
		reverse(start, end - 1);
		if (*end != '\0')
			end++;
		start = end;
	}
	//输出
	printf("%s", arr);
	return 0;
}
#include <Windows.h>
//————————————————————————————————————
int main21() {
	unsigned int i;
	for (i = 3; i >= 0; i--)
		//-1 -> unsignde int i ->0xffffffff
		//-2 ->................->0xffffffff-1
	{
		printf("%u \n", i);
		Sleep(500);//休眠5000ms
	}
	return 0;
}

int main22() {
	char a = 127;
	a++;
	printf("%d\n", a);
	char b = a - 128;
	printf("%d\n", b);
	char c = a + 128;
	printf("%d\n", c);
	return 0;
}

//任意二个二进制浮点数 V 可以表示成下面的形式：
//V=(-1)^S * M * 2^E
//(-1)^S表示符号位
//M表示有效数字
//2^E表示位数
//V = 5.0f ;--二进制-->101.2--科学计数->1.10*2^2
//  =(-1)^0 * 1.01 * 2^2
//	  S=0	  M=1.01 E=2
//V = 9.5f;
//  =1001.1
//  =(-1)^0 * 1.0011 * 2^3
//	  S=0	 M=1.0011  E=3
//V = 9.6f
//  = 1001.100..1000010011010101010101010101010(无法精确)
//V = 5.5f
//  S = 0
//  M = 0x40 b0 00 00
//  E = 2+127/1023
//对于 32 位的浮点数，
//最高的 1 位是符号位 S(1bit)
//接着的 8 位是指数 E(8/11bit)
//剩下的 23 位为有效数字 M(23/52bit)
//取出时
//	E 不全为 0 或不全为 1
//指数 E 的计算值减去 127 （或 1023 ），得到真实值，
//再将有效数字 M 前加上第一位的 1 
// E 全为 0
//这时，浮点数的指数 E 等于 1-127 （或者1-1023）即为真实值，
//有效数字 M 不再加上第一位的 1 ，而是还原为 0.XXXXXXXXXXXXX 的小数。
//这样做是为了表示± 0 ，以及接近于0 的很小的数字。	
// E 全为 1
//有效数字 M 全为 0 ，表示±无穷大（正负取决于符号位 s ）；
int main23() {
	int n = 9;
	float* pfloat = (float*)&n;
	printf("n2:%d\n", n);
	//00000000 00000000 00000000 00001001
	printf("*pflota :%f\n", *pfloat);
	//pfloat	0x0000009c17f3fc04 {1.261e-44#DEN}--->0	
	*pfloat = 9.0;
	//S=0 E=3 M=1.001
	//0x00 00 10 41
	printf("n1:%d\n", n);
	//00 00 10 41
	printf("*pflota:%f\n", *pfloat);
	return 0;
}

//————————————————有序的序列合并————————————————————

int main24() {
	int arr1[5]; int arr2[6]; int arr3[5 + 6];
	int i = 0;
	//输入arr1值
	for (i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);
	//输入arr2值
	for (i = 0; i < 6; i++)
		scanf("%d", &arr2[i]);
	//合并
	int j = 0; int k = 0; int r = 0;
	while (j < 5 && k < 6)
	{
		if (arr1[j] < arr2[k])
		{
			arr3[r++] = arr1[j]; j++;
		}
		else
		{
			arr3[r++] = arr2[k]; k++;
		}
	}
	if (j < 5)
	{
		for (; j < 5; j++)
		{
			arr3[r++] = arr1[j]; j++;
		}
	}
	else
	{
		for (; k < 6; k++)
		{
			arr3[r++] = arr2[k]; k++;
		}
	}
	for (i = 0; i < 5 + 6; i++)
	{
		printf("%d ", arr3[i]);
	}
	return 0;
}

void heapify(int R[10], int v, int n)
{
	int i = v, j = 2 * i;
	R[0] = R[i];
	while (j <= n)
	{
		if (j < n && R[j] < R[j + 1])
		{
			j++;
		}
		if (R[i] < R[j])
		{
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else
		{
			j = n + 1;
		}
	}
	R[i] = R[0];
}
void heapSort(int R[10], int n)
{
	int i = 0;
	for (i = n / 2; i >= 1; i--)
	{
		heapify(R, i, n);
	}
	for (i = n; i > 1; i--)
	{
		R[0] = R[i];
		R[i] = R[1];
		R[1] = R[0];
		heapify(R, 1, i - 1);
	}
}
int main() {
	int R[] = { 1,10,13,15,4,20,19,8 };
	int n = 8;
	heapSort(R, n);
	return 0;
}
