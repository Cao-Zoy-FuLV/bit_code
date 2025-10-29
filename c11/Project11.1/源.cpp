#include<iostream>
using namespace std;

// 交换数组中的两个元素
void swap(int(&a)[10], int left, int right) {
	int temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}

//定义快速排序函数,递归实现
int partitona(int(&a)[10], int start, int end) {
	//选取支点
	int pivot = a[start];

	//指定指向数组头尾元素的“指针”
	int left = start, right = end;

	//如果左右指针没有相遇，就继续移动
	while(left < right){
		//左指针不停右移，直到找到一个比支点大的值
		while (a[left] <= pivot && left < right)
			 ++left;
		//右指针不停左移，直到找到一个小的值
		while (a[right] >= pivot && left < right) 
			--right;
	 //左右互换
		swap(a, left, right);
	}
	//判一指针相遇位置的值，跟支点值的大小关系
	if (a[left]<pivot)
	{
		//比支点值小，就直接换到数组的头位置
		swap(a, start, left);
		return left;
	}
	if (a[left]>pivot)
	{
		//比支点值大，就将前一个位置的元素直接换到数组的头位置
		swap(a, start, left-1);
		return left-1;
	}
}

//定义快速排序函数,递归实现
void quickSort(int(&a)[10], int start, int end) {
	//基准情况
	if (start >= end) return;

	int mid = partitona(a, start, end);

	//递归调用，分别对两部分继续排序
	quickSort(a, start, mid - 1); 
	quickSort(a, mid + 1, end);
}

//打印数组
void printArrav(const int(&a)[10]) {
	for (int n :a) {
		cout << n << "\t";
	}
	cout << endl;
}

int main() {
	int arr[10] = { 23 ,45, 18 , 6 , 11 ,19 , 22 , 18 , 12 , 9 };
	printArrav(arr);
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, size - 1);
	printArrav(arr);

}