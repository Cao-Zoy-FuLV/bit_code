#include<stdio.h>
//（一）sizeo(数组名)，表示整个数组，计算总大小/bit
//（二）&数组名，表示整个数组，取出整个数组地址
//（三）其余表示首元素的地址
int main1() { 
	int arr[10] = { 0 };
	printf("%p ", arr);			//首元素的地址
	printf("%p\n", arr+1);		//首元素的地址+4
	printf("————————————————————\n");
	printf("%p ", &arr);		//数组地址的地址
	printf("%p\n", &arr+1);		//数组地址的地址+数组地址的地址(+28)
	printf("————————————————————\n");
	printf("%p ", &arr[0]);		//首元素的地址
	printf("%p\n", &arr[0] + 1);//首元素的地址+4
	printf("————————二维—int arrr[3][4]={ 0 };——————————\n");
	int arrr[3][4]={ 0 };
	printf("有几行= %d  48/16=>3\n", sizeof(arrr)/sizeof(arrr[0]));//
	printf("有几列= %d  16/4 =>4\n", sizeof(arrr[0]) / sizeof(arrr[0][0]));//
return 0; }
// ————————————————————————————————二维数组=一维数组的数组（在内存中连续存放）

int main2() {
	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 }; int i = 0;
	for ( i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			scanf("%d",&arr[i][j]);}}	
	for (i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			printf("&arr[%d][%d] = %p\n",i,j, &arr[i][j]);}}	
	return 0;} 	

//——————————————冒泡排序——————————————
void bubble_sort(int arr[], int sz) 
{
	int i = 0;
	for ( i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设数组是排好
		for (int j = 0; j < sz - 1 - i; j++)/*一趟*/
		{ 
			if (arr[j] > arr[j + 1]) /*交换*/
			{	
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//计入
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
	/*趟数*/int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_sort(arr,sz);
	for (size_t i = 0; i < sz; i++){
		printf("%d  ", arr[i]);
	}
	return 0;
}

