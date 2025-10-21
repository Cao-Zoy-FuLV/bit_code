#include <stdio.h>
//——————————printf（printf）:打印打印里字符个数—————————
//int main() {
//	printf("%d", printf("%d", printf("%d",43)));
//return 0;}
//——————————————————————————————————————
int _jia(int a ,int b)
{ 
	return a + b;
	//没有return着返回最后一行的指令执行结果
 }
#define sd(a,b)a+b
//int main() {
//	//exter  调用外部函数
//	extern int add(int a, int b);
//	int a = 10;
//	int b = 20;
//	int z = /*_jia*//*add*//*sd*/(a, b);
//	printf("%d",z);
//	return 0;
//}
//——————————————————————————————————————
//int main()
//{	
//
//		int a = 0;
//		while (a<200000)
//		{
//			printf("laji:%d\n",a);
//			a++;
//		}
//		if (a>=2000)
//		{
			//printf("6\n");
//		}
//		else{
//			printf("la");
//		}
//	return 0;
//}
//——————————————————————————————————————// 
//int main()
//{
//
//	int a[10] = { 1,2,3,4,5,6,7,4,8,9.10 };
//	int i = 0;
//		while (i<10)
//		{
//			printf("%d  ", a[i] );
//			i++;
//		}
//		return 0;
//}
//——————————————————————————————————————// 
//int main() {
//	int x = 0;
//	int y = 0;
//	scanf("%d", &x);
//	if (x < 0)
//		y = -1;
//	else if (x == 0)
//		y = 0;
//	else
//		y = 1;
//	printf("%d\n", y);
//	return 0;
//——————————————————————————————————————//}
//int main() {
//	int a = 1;
//	int b = 2;
//	printf("%d",a>b?a:b);
//	return 0;
//}
struct ss
{
	 char a[2];
	 int b;
	 float c;
	 char d[5];
};
void pr(struct ss* b) {
	printf("%s %d %.2f %s\n",b->a, b->b, b->c, b->d);
	printf("%s %d %.2f %s\n", (*b).a,(*b).b,(*b).c,(*b).d);

}
//int main() {
//	struct ss p = { "1",2,3.149,"4" };
//	pr(&p);
//	printf("%s %d %.2f %s\n", p.a, p.b, p.c, p.d);
//	
//return 0;}


//————————————3次登录密码———————————————————
//比较2字符串不能用==用  #include <string.h> 中 strcmp
#include <string.h>
//int main() {
//	int i;
//	char mm[20] = { 0 };
//	for ( i= 0;i <3;i++)
//	{
//		printf("="); scanf("%s", mm);
//		if (strcmp(mm,".")==0) 
//		{
//			printf("Y");
//			break;
//		}
//		else
//		{
//			printf("sb\n");
//		}}
//		if(i==3)
//		{
//			printf("大sb");
//		}
//return 0; }
//————————计算1/1 - 1/2+1/3 - 1/4+1/5.....+1/99-1/100————————
//int main() {
//	double a = 0; int flag = 1;
//	for (int i = 1; i <=100; i++)
//	{
//		a = a + flag * (1.0/*浮点数除法*/ / i);
//		flag = -flag;
//	}	printf("%1f", a); 
//return 0;}

//————————————找出10个数中最带的————————————
//int main() {
//	int arr[10] = { 0 };
//		//如果没指定元素个数，就会根据初始化推算元素个数
//		//int arr[]={0}==int arr[1]={0}
//		//输入时则栈被破坏
//	for (int i = 0; i < 10; i++)
//	{//循环输入10个数保存在arr中
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	//将第一个元素赋值给max
//	for (int i = 1; i < 10; i++) {
//		if (arr[i > max]) 
//		{//arr中每个大于max元素赋值给ta
//			max = arr[i]; 
//		} 
//	}
//	return 0;
//}

//——————————————————————————————————————//}
//判断计算机存储方法
	//int main() {
	//	int a = 1;
	//	if (*(char*)&a != 0)		
	//		printf("小端\n");
	//	else printf("大端");
	//	return 0;
	//}

int main1() {
	unsigned char a =-1;
	//11111111 11111111 11111111 11111111
	//截断 -> 11111111 - a
	printf("%d\n", a);
	char b = 512;
	//000000000 0000000 00000001 00000000
	//截断 -> 00000000 - b
	printf("%d\n", b);
	char c = -128;
	// 11111111 11111111 11111111 10000000 
	// 截断 -> 10000000 - c	
	printf("%u\n", c);
	char c1 =  128; 
	// 00000000 00000000 00000000 10000000 
	// 截断 -> 10000000 - c1
	printf("%u\n", c1);

	int i = -20;
	//11111111 11111111 11111111 11101100
	unsigned int j = 10;
	//00000000 00000000 00000000 00001010 
	printf("%d\n", i + j);

	return 0;
}
//————————————————堆排序————————————————————

//n ：待排序的数组长度
//R[]：待排序序数组， n个数放在 R[1], R[2],…… ，R[n]中
//v ：节点编号，以 v 为根的二又树， R[v]>=2R[2v], R[v]>=2R[2v+1], 
//	    且其左子树和右子树都是大顶堆：

