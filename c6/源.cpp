#include<stdio.h>
//��һ��sizeo(������)����ʾ�������飬�����ܴ�С/bit
//������&����������ʾ�������飬ȡ�����������ַ
//�����������ʾ��Ԫ�صĵ�ַ
int main1() { 
	int arr[10] = { 0 };
	printf("%p ", arr);			//��Ԫ�صĵ�ַ
	printf("%p\n", arr+1);		//��Ԫ�صĵ�ַ+4
	printf("����������������������������������������\n");
	printf("%p ", &arr);		//�����ַ�ĵ�ַ
	printf("%p\n", &arr+1);		//�����ַ�ĵ�ַ+�����ַ�ĵ�ַ(+28)
	printf("����������������������������������������\n");
	printf("%p ", &arr[0]);		//��Ԫ�صĵ�ַ
	printf("%p\n", &arr[0] + 1);//��Ԫ�صĵ�ַ+4
	printf("������������������ά��int arrr[3][4]={ 0 };��������������������\n");
	int arrr[3][4]={ 0 };
	printf("�м���= %d  48/16=>3\n", sizeof(arrr)/sizeof(arrr[0]));//
	printf("�м���= %d  16/4 =>4\n", sizeof(arrr[0]) / sizeof(arrr[0][0]));//
return 0; }
// ����������������������������������������������������������������
int main2() {
	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 }; int i = 0;
	for ( i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			scanf("%d",&arr[i][j]);}}	
	for (i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			printf("&arr[%d][%d] = %p\n",i,j, &arr[i][j]);}}	
	return 0;} 	
��ά����=һά��������飨���ڴ���������ţ�

//����������������������������ð�����򡪡�������������������������
void bubble_sort(int arr[], int sz) 
{
	int i = 0;
	for ( i = 0; i < sz - 1; i++)
	{
		int flag = 1;//�����������ź�
		for (int j = 0; j < sz - 1 - i; j++)/*һ��*/
		{ 
			if (arr[j] > arr[j + 1]) /*����*/
			{	
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//����
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main3() {
	int arr[] = { 75,94,45,5,26,44,26,8,57,52,61,11,36,9,68,27,45,86,55,15 };
	/*����*/int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr,sz);
	for (size_t i = 0; i < sz; i++){
		printf("%d  ", arr[i]);
	}
	return 0;
}
