#include<stdio.h>
//———————————————比较2数，打印MAX———————————————————
int _max(int x, int y) {
	return (x > y ? x : y);
}
int main1() {
	int a = 0; int b = 0;
	scanf("%d%d", &a, &b);
	printf("MAX= %d", _max(a, b);//传值调用)	
return 0;}
//———————————————交换2数———————————————————
void Swap(int* px, int* py) {
	//*px *py储存的是 a b的地址
	int z = *px;  *px = *py; *py = z;
}
//实参传递形参，形参是实参的零食拷贝
//形参的修改不会影响实参
int main2() {
	int a = 0;
	int b = 0;	
	scanf("%d%d",&a,&b);
	printf("交换之前：a=%d  b=%d", a, b);
	Swap(&a, &b);//传址调用/*传递地址参数*/
	printf("交换结果：a=%d  b=%d", a, b);
return 0;}
//—————= 需要改变实参时用指针变量 =—————————————————



//————————————— 100~200地质数———————————————
#include <math.h>
//sqrt(a)<——开a的平方
//非质数/非素数：一个数的两个公因数一定有一个小于或等于这个数平方根，整除这个数
//m=a*b			  例：16=2*8/4*4  (2和4 <= 4 )				
// a||b<=sqrt(m)
int is_prime(int a) {
	int flag = 1; int i = 0;
	for (i = 2; i <=sqrt(a); i++)
	{if ( a % i == 0 )return 0;}
	return 1;}
//bool ——》返回真（true）假（false）	
//	   ——》1byte
int main3() {
	int i = 0;int count = 0;
	for (i = 101; i <=200; i+=2)
	{if (is_prime(i)) { printf("%d  ", i); count++; }}
	printf("\ncount=%d", count);
return 0;}
// 
// 
// ————————————判断闰年——————————————————
//闰年：被4整除并且不能被100整除或被400整除
int IS_leap_year(int y){
	return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));}
int main4() {
	int year1 = 0; int year2 = 0;
	scanf("判断闰年：%d", &year2);
	if (IS_leap_year(year2))printf("yes  yes  yes\n");
	else printf("NO  NO  NO\n");
	printf("1000~3000年全部闰年\n");
	for(year1=1000;year1<=3000;year1++)
	{if (IS_leap_year(year1))printf("%d  ", year1);}
	return 0;}


// ————————————2分查找——————————————————
int binary_search(int arr[]/*创建的是指针变量*/, int k, int sz) {
	int l = 0; int r = sz-1; int mid = l = (l - r) / 2;
	while (l<=r)
	{	if (arr[mid] < k)l = mid + 1;
		else	if (arr[mid] > k)r = mid - 1;
		else return mid;//找到，返回下标
	}	return -1;      //找不到，返回-1 	
}
int main5() {
	int arr[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
//			   	    0 1 2 3 4 5 6 7 8 9 10
	int k = 0; scanf("：%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr/*数组传参是传首位地址*/, k, sz);
	if (ret == -1)printf("sb");
	else printf("下标=%d", ret);
return 0;}
 //———————— 调用函数，显示次数 —————————————————
void sb(int*p){(*p)++;}
//传第地址，在原参数增加
int main6() {int a = 0;
	 sb(&a); printf("%d\n", a); sb(&a); printf("%d\n", a); 
return 0;}


//————===递归函数：少量的程序执行多数计算————————————————
//——————接受一个无符号整型，顺序打印每一位————————————————
void print(unsigned int a){		 //(1)123     (1)12		
	if (a > 9) {							
		print(a / 10);			 //(1)12	  (1)1 	
	}	printf("%d ", a % 10);}  //(3)3		  (2)2	    (1)1
int main7() {
	unsigned int a = 0; scanf("%u", &a);//%d(带符号的整型)%u（无符号）
	print(a);
return 0;}

//————————————模拟strlen——————————————————————
int my_strlen1(char*str/*char str[]*/) {
	int count = 0;
	while (*str != '\0') {
		count++;
		str++;//找下一个字符
	}return count;}
//—————————模拟strlen(无临时变量||count）)
//———————— ===递归函数：少量的程序执行多数计算
int my_strlen2(char str[]){//将abc\0->1+b+c+\0->1+1+c+\0->1+1+1+0
	if (*str != '\0')//非\0就进入递归每次返回加1
		return 1+my_strlen2(str+1);
//					     （++str)会改变传入值本身，而（str+1）只会改变函数识别到的地址	
	else return 0;/*遇到\0返沪0*/}
int main8() {
	char arr[9999]; scanf("%s",arr);
	int len = my_strlen1(arr);
	printf("%d", len);
return 0;}

//———————————————————————————————————— 
//———————————  sizeof，strlen 区别———————————————
//sizeof
// =>是一个一个一个操作符
//	 用来计算变量（类型）所占内存空间大小，不关注内存存放的具体数据
//	 单位是字节
//strlen
// =>是一个一个一个库函数
//	 是专门求字符串长度，只能针对字符串
//	 从参数给定的地址向后找'\0',统计之前出现的字符的个数
//———————————————————————————————————— 

//————————————计算n！===递归函数：少量的程序执行多数计算———————
int fac(int n) {
	if (n <= 1)return 1;
	else return n * fac(n - 1);}

int main9() {
	int n = 0; scanf("%d", &n); printf("%d!=%d",n,fac(n));
return 0;}

//————————————求第n个斐波那契数————————————————
//斐波那契数列又称黄金分割数列，这个数列从第3项开始，每一项都等于前两项之和
//如1、1、2、3、5、8、13、21、34， F(n) = F(n - 1) + F(n - 2)（n ≥ 2，n ∈ N * ）
//————————————线性递推数列
int Fid1(int n) {	
	if (n <= 2)return 1;
	else return Fid1(n - 1) + Fid1(n - 2);}//运算量大，浪费资源
int Fid2(int n) {
	int a = 1; int b = 1; int c = 0;
	while (n >= 3) {c = a + b; a = b; b = c; n--;}
	return c;}			//循环优化”线性“递推数列
int main11() {						
	int n = 0; scanf("%d", &n); printf("当47时栈溢出\n%d", Fid2(n));
	return 0;}
////————————————辗转相除法求公因数——————————————
////核心原理：两个数的最大公约数等于其中较小的数字和二者之间余数的最大公约数
int main12() {
	int a = 1; int b = 1; int c = 1; scanf("%d %d", &a, &b);
	while (c = a % b) { a = b; b = c; }printf("%d", b);
return 0;}//———————公倍数=a*b/最大公约数
 
#include <string.h>
//————————————逆序字符串（递归版）——————————）
void reverse1(char* str) {//单参数版
	char tmp = *str;//1.取第一个
	int len = my_strlen2(str);//总字符串长度
	*str = *(str + len - 1);//2.最后一个的字符赋值给第一个
	*(str + len - 1) = '\0';//3.最后一个变成\0
	if(my_strlen2(str+1) >= 2)//加入（除中间剩下1个时不进入函数）限制条件
		reverse1(str+1);//4.中间的重复调用函数
	*(str + len - 1) = tmp;//5.将第一个的字符赋值给最后一个
}
void reverse2(char arr[], int l, int r) {//多参数版	
	if( l < r  )
	{	char tmp = arr[l];
		arr[l] = arr[r];
		arr[r] = tmp;
		reverse2(arr, l + 1, r - 1);
	}
		
}
int main13() {
	char arr[300] = "asdf"; //scanf("%s", &arr);
	//reverse1(arr); printf("%s", arr);
	int l = 0; int r = strlen(arr) - 1;
	reverse2(arr, l, r); printf("%s", arr);
	return 0;
}
// ———————————— n的k次方（递归版）  ————————————
double Pow(int n, int k) {
	if (k > 0)return  n * Pow(n, k - 1);
	else if (k == 0)return 1;
	else return 1.0/Pow(n, -k);
}
int main14() {
	int n = 0; int k = 0; scanf("%d %d", &n, &k);
	printf("%f", Pow(n, k));
	
return 0;}

//—————————————1步1||2脚上10阶台阶————————————
int fun1(int n) {
	if (n <= 2)return n;
	else return fun1(n - 1) + fun1(n - 2);
}
int main15() {
	int a1 = fun1(10); printf("%d", a1);
return 0;}

//————————————数据中删指定数———————————————
int main16() {
	int arr[9] = { 0 };
	printf("输入6个数字(最后一为为要删数)\n");
	for (int i = 0; i < 5; i++) {//接受数据		
		scanf("%d  ", &arr[i]);			
	}	
	int del = 0;scanf("%d", &del);
	int j = 0;//作为下标锁定的位置是用来存放不删除的数据
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] != del) {
			arr[j++] = arr[i];
		  //arr[j] = arr[i];j++;	
		}
	}
	for (int i = 0; i < j; i++) {
		printf("%d  ", arr[i]);
	}
	return 0;
}

//————————————数据最大与最小差——————————————
int main17() {
	int arr[9] = { 0 }; printf("输入5个数字\n");
	for (int i = 0; i < 5; i++) {//接受数据		
		scanf("%d", &arr[i]);			
	}	
	int max = 0; int min = 100;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	printf("%d",max-min);
	return 0;
}

//———————————水仙花数 Lily_Number——————————————
//变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字
//1461拆分成（1和461）, （14和61）, （146和1), 
//如果所有拆分后的乘积之和等于自身，则是一个Lily Number
#include<math.h>//pow(x,x)x^x
int main() { 
	for (int i = 10; i < 99999999; i++)
	{
		int j = 0; int sum = 0;
		for ( j = 1; j <=4 ; j++)
		{
			int k = (int)pow(10, j);
			sum += (i % k) * (i / k);
		}
		if (sum == i)
			printf("%d  ", i);
	}
	return 0;
}
//———————返回参数二进制中1的个数——————————————
int count_num_of_1_v1(unsigned int n){
	int count = 0;
	while (n) {
		if ((n % 2) == 1)count++;
		n /= 2;
	}
	return count;}
int count_num_of_1_v2(int n) {
	int i = 0; int count = 0;
	for ( i = 0; i < 32; i++)
		if (((n >> i) & 1) == 1)count++;
	return count;}
int count_num_of_1_v3(int n) {//经典版
	int count = 0;
	while (n) {
		n &= (n--); count++;
	}//判断是否为2的n次方
	 //if (n &= (n--))== 0)
 	return count;}
int main18() {
	int n = 0; scanf("%d", &n);
	int n1 = count_num_of_1_v1(n); printf("%d\n", n1);
	int n2 = count_num_of_1_v1(n); printf("%d\n", n2);
	int n3 = count_num_of_1_v1(n); printf("%d\n", n3);
	return 0;
}

//———————两个int(32位)整数m和n的二进制表达中,有多少个位(bit)不同？
int count_diff_bit1(int n, int m) {
	int i = 0; int count = 0;
	for (i = 0; i < 32; i++)
		if (((n >> i) & 1) != ((m >> i) & 1))count++;
	return count;
}
int count_diff_bit2(int n, int m) {//经典版
	int count = 0;
	int ret = n ^ m;
	while (ret)
	{
		ret &= (ret--); count++;
	}
	return count;
}
int main19() {
	int m = 0; int n = 0; scanf("%d %d", &n,&m);
	int n1 = count_diff_bit1(n, m); printf("%d\n", n1);
	int n2 = count_diff_bit1(n, m); printf("%d\n", n2);
	return 0;
}
//————获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
int main20() {
	int n = 0; scanf("%d", &n);
	//获取鸡数位
	for (int i = 30; i >= 0; i -= 2)
		printf("%d\n", (n >> i) & 1);
	//获取非鸡数位
	for (int i = 31; i >= 1; i -= 2)
		printf("%d\n", (n >> i) & 1);

return 0;}
//————————————打印X——————————
int main21(){
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int i = 0; int j = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j)printf("* ");
				else if (i + j == n - 1)printf("* ");
				else printf(" ");
			}
			printf("\n");}
	}
	return 0;
}
int main22() {
	int y = 0; int m = 0; int d = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30.31 };
	//           月分   1, 2, 3. 4, 5, 6, 7, 8, 9,10,11,12  
	while (scanf("%d%d", &y, &m) == 2) {
		int d = days[m];
		if ((IS_leap_year(y) == 1) && (m == 2))d++;
		printf("%d\n", d);
	}
	return 0;
}