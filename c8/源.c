#include <stdio.h>
int main1() {
	//ָ������
	int arr[4];
	char* ch[5];
	//����ָ��
	int arr2[5];
	int(*pa)[5] = &arr2;
	//pa����--��int(* )[] 
	char* arr3[6] = { 0 };
	char* (*p3)[6] = &arr3;
	//p3�Ǵ�������ָ�������
	return 0;
}

int test(const char* str)
{
	printf("test()\n");
	return 0;
}
int main2()
{
	//����ָ��-Ҳ��һ��ָ�룬��ָ������ָ��
	printf("%p\n", test);
	printf("%p\n", &test);
	//ͬΪ������ַ
	int (*pf)(const char*) = test;
	//pf����--��int (* )(const char*)
	(*pf)("avb"); test("abc"); pf("abc");//ͬ

	//	Ӳ��������׵�ַΪ 0 λ�õĺ�����
	//	( *(void (*)() )0 )();
	//	void ��* ��()-->����ָ������
	//	( )0-->ǿ������ת��==0��Ϊ������ַ
	//	(* )( )-->���ú�����void:�޲�����
	//	����:
	//	 �� 0 ǿ������ת��Ϊ���޲Σ����������� void �ĺ����ĵ�ַ
	//	 ���� 0 ��ַ�����������
	//
		//
		//void (* signal( int, void(*)(int) ) )(int);
		//signal �Ǻ�����  
		//int, void(*)(int) �ǲ���
		//����:
		//���� signal ����
		//��һ�������������� int 
		//�ڶ������������Ǻ���ָ�룬�ú���ָ��ָ��ĺ��������� int,
		// ���������� void
		//signal �����ķ�������Ҳ��һ������ָ�룬
		// �ú�ָ��ָ��ĺ��������� int ��
		// ��������Ҳ�� void
		// �򻯣�
		//typedef void(* pf_t)(int);  �� void(*)(int) ����������Ϊ pf_t
		//pf_t signal(int,pf_t);
	return 0;
}

//������������������������������(ת�Ʊ�)������������������������������������
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
	//����ָ������
	int (*pf_[5])(int, int) = { 0,Add,Sub,Mul,Div };
	//ָ�򡼺���ָ�����顽��ָ��
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
			printf("������2��������:>");
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


//�������������������������������ص���������������������������������������������
//�ص�����    ͨ������ָ����õĺ���
//����Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ������, 
// �����ָ�뱻������������ָ��ĺ���ʱ�����ǻص�������
//�ص����������ɸú���, ��ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ�
// ���ڶԸ��¼�������������Ӧ
//

#include <string.h>
#include <stdlib.h>

//qsort ����  -���������������͵�����
//void qsort (void* base, //��Ҫ�������ݵ���ʼλ��
//			size_t num, //�����������Ԫ�صĸ���
//			size_t width, //�����������Ԫ�صĴ�С(��λ���ֽ�)
//			int(* cmp)(const void* el,const void* e2));//����ָ��-�ȽϺ��� e1 �� e2 ���Ƚϵ�2��

// void* ���޾������͵�ָ�룬���Խ����������͵ĵ�ַ
//	���Բ��ܽ����ò�����Ҳ����+-����

//������������
int cmp_int(const void* e1, const void* e2)
{
	// �Ƚ� 2 ������Ԫ�� 
	// e1ָ��һ������  e2 ָ����һ������
	return (*(int*)e1 - *(int*)e2);//����
	//return (*(int*)e2 - *(int*)e1);//����
}
//����ʹ�� qsort ��������������
void test1()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,9,10,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	//qsort ���ڲ�����������cmp__int
	for (size_t i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}
//����ʹ�� qsort ������ṹ����

struct Stu
{
	char name[20];
	int age;
};
//�Ƚ�����
int cmp_stu_by_name(const void* e1, const void* e2)
{	//strcmp  ����>0, ==0, <0 
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
//�Ƚ�����
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//ʹ�� qsort ������ṹ����
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

//��������>>>>>>>ð������

//����
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
		int flag = 1;//�����������ź�
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)/*һ��*/
		{
			//cmp e1 �� e2 ���Ƚϵ�2����ַ
			if (cmp((char*)bass + j * width, (char*)bass + (j + 1) * width) > 0)
			{   //����ַ*���ݵĿ��=�����Ƚ���
				Swap((char*)bass + j * width, (char*)bass + (j + 1) * width, width);
				flag = 0;//����
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

//��������ϣ�������㷨
//����1 ����һ���������� delta1,delta2...deltak, ���� delta =n/2, �����ÿ�� delta ��ǰһ���� 1/2 deltak=l 
//����2 ���ݲ������С����� k ������
//����3 �Ե� i �����򣬸��ݶ�Ӧ�Ĳ��� delta ,���Ȳ���λ��Ԫ�ط��飬��ͬһ����Ԫ����ԭλ���Ͻ���ֱ�Ӳ�������
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