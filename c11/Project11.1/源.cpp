#include<iostream>
using namespace std;

// ���������е�����Ԫ��
void swap(int(&a)[10], int left, int right) {
	int temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}

//�������������,�ݹ�ʵ��
int partitona(int(&a)[10], int start, int end) {
	//ѡȡ֧��
	int pivot = a[start];

	//ָ��ָ������ͷβԪ�صġ�ָ�롱
	int left = start, right = end;

	//�������ָ��û���������ͼ����ƶ�
	while(left < right){
		//��ָ�벻ͣ���ƣ�ֱ���ҵ�һ����֧����ֵ
		while (a[left] <= pivot && left < right)
			 ++left;
		//��ָ�벻ͣ���ƣ�ֱ���ҵ�һ��С��ֵ
		while (a[right] >= pivot && left < right) 
			--right;
	 //���һ���
		swap(a, left, right);
	}
	//��һָ������λ�õ�ֵ����֧��ֵ�Ĵ�С��ϵ
	if (a[left]<pivot)
	{
		//��֧��ֵС����ֱ�ӻ��������ͷλ��
		swap(a, start, left);
		return left;
	}
	if (a[left]>pivot)
	{
		//��֧��ֵ�󣬾ͽ�ǰһ��λ�õ�Ԫ��ֱ�ӻ��������ͷλ��
		swap(a, start, left-1);
		return left-1;
	}
}

//�������������,�ݹ�ʵ��
void quickSort(int(&a)[10], int start, int end) {
	//��׼���
	if (start >= end) return;

	int mid = partitona(a, start, end);

	//�ݹ���ã��ֱ�������ּ�������
	quickSort(a, start, mid - 1); 
	quickSort(a, mid + 1, end);
}

//��ӡ����
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