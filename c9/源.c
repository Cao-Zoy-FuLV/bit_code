#include<stdio.h>
//��һ��sizeo(������)����ʾ�������飬�����ܴ�С/bit
//������&����������ʾ�������飬ȡ�����������ַ
//�����������ʾ��Ԫ�صĵ�ַ
int main1() {
	int arr[10] = { 0 };
	printf("%p ", arr);			//��Ԫ�صĵ�ַ
	printf("%p\n", arr + 1);		//��Ԫ�صĵ�ַ+4
	printf("����������������������������������������\n");
	printf("%p ", &arr);		//�����ַ�ĵ�ַ
	printf("%p\n", &arr + 1);		//�����ַ�ĵ�ַ+�����ַ�ĵ�ַ(+28)
	printf("����������������������������������������\n");
	printf("%p ", &arr[0]);		//��Ԫ�صĵ�ַ
	printf("%p\n", &arr[0] + 1);//��Ԫ�صĵ�ַ+4
	printf("������������������ά��int arrr[3][4]={ 0 };��������������������\n");
	int arrr[3][4] = { 0 };
	printf("�м���= %d  48/16=>3\n", sizeof(arrr) / sizeof(arrr[0]));//
	printf("�м���= %d  16/4 =>4\n", sizeof(arrr[0]) / sizeof(arrr[0][0]));//
	return 0;
}
// ����������������������������������������������������������������
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
//��ά����=һά��������飨���ڴ���������ţ�

//����������������������������ð�����򡪡�������������������������
void bubble_sort(int arr[], int sz)
{
	int j = 0;
	for (size_t i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)/*һ��*/ {
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
	/*����*/int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr, sz);
	for (size_t i = 0; i < sz; i++) {
		printf("%d  ", arr[i]);
	}
	return 0;
}



// ������������������������������������������������������������������������
//��������ָ�����������ŵ�ַ�ģ���ַ��Ψһ��ʾһ���ڴ�ռ��
//��������ָ��Ĵ�С��32λƽ̨��4���ֽ�,��64λƽ̨��8���ֽ�
int main4() {
	char* pc = NULL;	printf("%zu	", sizeof pc);
	short* ps = NULL;	printf("%zu	", sizeof ps);
	int* pi = NULL;		printf("%zu	", sizeof pi);
	double* pd = NULL;	printf("%zu	", sizeof pd);
	//-sizeof��������Ϊ unsigned int
	return 0;
}

//����>ָ������
int main4_2() {
	int a = 0x11223344;
	int* pa = &a;				*pa = 0;
	char* pc = (char*)&a;		*pc = 0;
	//��������ָ�����;�����ָ���ڱ������õ�ʱ����ʼ����ֽ�
	//char* ��ָ��   �����÷��� 1 ���ֽ�
  //double* ��ָ�� �����÷��� 8 ���ֽ�
	//int* ��ָ��	 �����÷��� 4 ���ֽ�
	//float* ��ָ��  �����÷��� 4 ���ֽ�
	//int* ��float*  �����ڣ��洢��ʽ��һ��
	return 0;
}
int main5() {
	int a = 0x11223344;
	//100 - 10����
	//0x64 -16����
	//144 - 8����
	//110 0100 - 2����	
	int* pa = &a;
	printf("pa=%p\n", pa);
	printf("pa+1=%p\n", pa + 1);//+4�ֽ�
	char* pc = (char*)&a;
	printf("pc=%p\n", pc);
	printf("pc+1=%p\n", pc + 1);//+1�ֽ�
	//��������ָ�����;�����ָ��+��-����ʱ�����ֽ�
	//��������ָ�����;���ָ�벽��
	return 0;
}

//����>ָ��+-����
int main6() {
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < sz; i++)
	//{//�����±��д��	
	//	arr[i] = 1;
	//} 
	int* p = arr;
	//for (int i = 0; i < sz; i++)
	//{//ָ��д��1
	//	*p = 2; p++;	
	//}
	for (int i = 0; i < sz; i++)
	{//ָ��д��2
		*(p + i) = 3;

	}
	//���� > ���飺    һ��ͬ���͵�Ԫ�ؼ���
	//���� > ָ���������ŵ�ַ�ı���
	for (int i = 0; i < sz; i++)
		printf("%p������%p\n", &arr[i], p + i);
	return 0;				  //arr[i]==*(arr+i)
}

//����>ָ��-ָ��
int/*��MY_strlen����*/MY_strlen(const char* str) {
	const	char* start = str;
	while (*str != '\0') str++;
	return (str - start);
}
int main7() {
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);
	//ָ��һָ��õ���ָ���ָ��֮��Ԫ�صĸ���
	//ָ��ͬһ���ռ��ָ������
	int len = MY_strlen("asd");
	printf("%d", len);
	return 0;
}

//���� > ָ��Ĺؼ�����
#define N_VALUES 5
//�����飨N_VALUES��5������ʼ��
int main8() {
	float values[N_VALUES];
	float* vp;
	for (vp = &values[0]; vp < &values[N_VALUES];)
		*vp++ = 1;//���Ÿ�ֵ
	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
		*vp = 2;//���Ÿ�ֵ
	return 0;
}
//���� > ���Ÿ�ֵ
//ʵ���ھ��󲿷ֵı��������ǿ���˳���������ģ�Ȼ�����ǻ���Ӧ�ñ�������д
//��Ϊ��׼������֤�����С�
//���� > ��׼�涨:
//����ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ�뽻
//���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽϡ�

//����>����ָ��
int main9() {
	int a = 1;
	int* pa = &a;//pa=>һ��ָ�����
	int** ppa = &pa;//ppa=>����ָ�����
	//����>ָ������
	int arr[10] = { 0 };
	int b = 1; int* pb = &b;
	int e = 2; int* pe = &e;
	int c = 3; int* pc = &c;
	int* parr[10] = { &e, &b, &c };//parr=>ָ������
	for (int i = 0; i < 3; i++)
		printf("%d\n", *(parr[i]));
	//����>ָ��	��ά����	
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



//��������������������������������������������������������������������������������
struct r {//����>�ṹ��
	char name[20];
	char te1e[12];
	char sex[5];
	int high;
};
struct rs {//����>�ṹ��Ƕ��
	struct r r;
	int n;
	float f;
};
void print1(struct r* r1) {
	printf("%s %s %s %d	", r1->name, r1->te1e, r1->sex, r1->high);
}//�ṹ�����->��Ա����
void print2(struct r r1) {
	printf("%s %s %s %d\n", r1.name, r1.te1e, r1.sex, r1.high);
}//�ṹ�����.��Ա����
int main10() {
	struct r r1 = { "sa","15688889999","lan",180 };//�ṹ���������
	struct rs s1 = { {"bi","13388889999","jiao",160 },100,1.01 };
	printf("%s %s %s %d\n", r1.name, r1.te1e, r1.sex, r1.high);
	printf("%s %s %s %d %d %f\n", s1.r.name, s1.r.te1e, s1.r.sex, s1.r.high, s1.n, s1.f);
	print1(&r1); print2(r1);
	return 0;
}
//����������������������1!+2!+3!....n!����������������������������������������������������������

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

//��������������������������������������������������������������������������������
// 1		�ֲ����ݴ���ջ����
// 2		��ʹ�øߵ�ַ�Ŀռ䣬��ʹ�õ͵�ַ�Ŀռ�
//	 ���������±����ǵ�ַ�ɵ͵���
// 3		��� i �� arr ֮�����ʵ��Ŀռ䣬���������Խ������ֿ��ܻḲ�ǵ� i 
//	 �Ϳ��ܳ�����ѭ��  
int main13() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (size_t i = 0; i <= 16; i++)
	{//
		arr[i] = 0; printf("Saniao\n");
	}
	return 0;
}

//�������������������������������� consy  assert ����������������������������������������������
#include <assert.h>
char* my_strcpy(char* dest, const char* src)
//char*-->ʵ����ʽ����
//strcpy�������ص���Ŀ��ռ����ʼ��ַ
{
	char* ret = dest;
	//����
	assert(src != NULL); assert(dest != NULL);
	while (*dest++ = *src++);
	return ret;
}
int main14() {
	char arr1[20] = "xxxxxxxxxxxxxxxxx";
	char arr2[] = "Saniao";
	//char* p = NULL;//strcpy�ڿ����ַ��������Դ�ַ�����\0����
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}
int main15() {
	//const ����ָ�����
	const int n1 = 10;
	//const int* p = &n1; 
	//int n2 = 1; 
	//p = &n2;
	// 1 �� const ����*�����
	//��˼�ǣ� p ָ��Ķ�����ͨ�� p ���ı��ˣ����� p ���������ֵ�ǿ��Ըı��
	int* const p = &n1;
	*p = 2;
	// 2 �� const ����*���ұ�
	//��˼�ǣ� p ָ��Ķ����ǿ���ͨ�� p ���ı�ģ����ǲ����޸� p ���������ֵ
	printf("%d", n1);
	return 0;
}
//�����������������������������������������ж������Ρ���������������������������������������
//
int main16() {
	int a = 0; int b = 0; int c = 0;
	while (scanf("%d %d %d", &a, &b, &c) == 3)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))//�ж�
		{
			if (a == b && b == c) {
				printf("1");//�ȱ�������ء
			}
			else if ((a == b && b != c) || (a == c && c != b) || (b == c && b != c)) {
				printf("2");//����������
			}
			else {//��ͨ������
				printf("3");
			}
		}
		else printf("0");//����������
	}
	return 0;
}
#include	<stdio.h>
#include	<assert.h>

//���������������ַ������ȡ�����������������������������������������������������������
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
//������������������������������������������������������������������������

//��������������������������������������������������������������������������������
#include <math.h>//ˮ�ɻ�
//��� 0 �� 99999 ֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ�� n λ�������λ���ֵ� n �η�֮��ȷ�õ��ڸ�������
// �磺 153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3 ���� 153 ��һ����ˮ�ɻ�������
int Narcissistic_number(int i) {
	//1 .  ����i�Ǽ�λ��
	int n = 1;//������1λ
	int sum = 0;
	int tmp = i;
	while (tmp / 10)
	{
		n++;
		tmp /= 10;
	}
	//2 .  �õ� i ÿһλ���������� n �η�֮��
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
//������������������������������������������������������������������������
//�����ַ���
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
	//����
	gets(arr);
	//����
	int len = my_strlen(arr);
	//������
	reverse(arr, arr + len - 1);
	//�����������
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
	//���
	printf("%s", arr);
	return 0;
}
#include <Windows.h>
//������������������������������������������������������������������������
int main21() {
	unsigned int i;
	for (i = 3; i >= 0; i--)
		//-1 -> unsignde int i ->0xffffffff
		//-2 ->................->0xffffffff-1
	{
		printf("%u \n", i);
		Sleep(500);//����5000ms
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

//������������Ƹ����� V ���Ա�ʾ���������ʽ��
//V=(-1)^S * M * 2^E
//(-1)^S��ʾ����λ
//M��ʾ��Ч����
//2^E��ʾλ��
//V = 5.0f ;--������-->101.2--��ѧ����->1.10*2^2
//  =(-1)^0 * 1.01 * 2^2
//	  S=0	  M=1.01 E=2
//V = 9.5f;
//  =1001.1
//  =(-1)^0 * 1.0011 * 2^3
//	  S=0	 M=1.0011  E=3
//V = 9.6f
//  = 1001.100..1000010011010101010101010101010(�޷���ȷ)
//V = 5.5f
//  S = 0
//  M = 0x40 b0 00 00
//  E = 2+127/1023
//���� 32 λ�ĸ�������
//��ߵ� 1 λ�Ƿ���λ S(1bit)
//���ŵ� 8 λ��ָ�� E(8/11bit)
//ʣ�µ� 23 λΪ��Ч���� M(23/52bit)
//ȡ��ʱ
//	E ��ȫΪ 0 ��ȫΪ 1
//ָ�� E �ļ���ֵ��ȥ 127 ���� 1023 �����õ���ʵֵ��
//�ٽ���Ч���� M ǰ���ϵ�һλ�� 1 
// E ȫΪ 0
//��ʱ����������ָ�� E ���� 1-127 ������1-1023����Ϊ��ʵֵ��
//��Ч���� M ���ټ��ϵ�һλ�� 1 �����ǻ�ԭΪ 0.XXXXXXXXXXXXX ��С����
//��������Ϊ�˱�ʾ�� 0 ���Լ��ӽ���0 �ĺ�С�����֡�	
// E ȫΪ 1
//��Ч���� M ȫΪ 0 ����ʾ�����������ȡ���ڷ���λ s ����
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

//����������������������������������������кϲ�����������������������������������������

int main24() {
	int arr1[5]; int arr2[6]; int arr3[5 + 6];
	int i = 0;
	//����arr1ֵ
	for (i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);
	//����arr2ֵ
	for (i = 0; i < 6; i++)
		scanf("%d", &arr2[i]);
	//�ϲ�
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
