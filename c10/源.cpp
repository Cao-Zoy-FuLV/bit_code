#include <stdio.h>
#include "malloc.h"
using namespace std;
enum Day {
	m = 1,
	t,
	w,
	f,

};
int main1(){

	const int a = 0;
	char* p = (char*)malloc(1);//void*
	enum Day today = t;
	printf("%d\n", today);
	return 0;
}
int main2() {
	int a = 0, b = 1;
	(a = b) = 100;//b->a.100->a
	printf("%d %d\n", a, b);//表达式，可以被赋值
	(a != b ? a : b) = 1000;
	printf("%d %d\n", a, b);//表达式，可以被赋值

	return 0;
}



#include <iostream>
//流输入cin   流输出cont
//cin==scanf
//cont==sprintf
//类对象相同功能的函数
int main3() {
	string n;
	cin >> n;//  >> :流输入运算符由语境决定 ( >>被重载)
	cout << "n=" << n   <<      endl;
	//		先	   然后       最后"end"l=回车
	cout << "最大输入字符 " << n.max_size() << endl;
	return 0;
}
int main4() {
	int a, b;
	cin >> a >> b;
	cout << a << " " << b << endl;
	return 0;
}
int main4_1() {
	// 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下3行代码
	// 可以提高C++IO效率
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}



#include <iomanip>
int main5() {
	int a = 123; float b = 1.14514;
	cout << "XXXXXX" << endl;
	cout << setiosflags(ios::left) << setw(6) << a << endl;
	//				→左				一共占6位
	cout << setprecision(5) << setiosflags(ios::fixed) << b << endl;
	//		设置有效位数5
	cout << "输出10进制 默认 " << dec << a ;
	cout << "输出16进制 "      << hex << a ;
	cout << "输出8进制  "      << oct << a << endl;//
	cout << setfill('M') << setw(10) << a << endl;
	//		填充
	int h = 0, m = 0, s = 0;//00:00:00
	cout << "时钟格式  " << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m << ":" << setfill('0') << setw(2) << s << endl;
	return 0;
} 



struct MyStruct
{
	float x;
	float y;
};
//c艹   一般操作符都是函数，函数是可以重载的
//operator 重载(静多态)
//函数名相同，参数列表不同〈类型，个数，顺序）
//返值类型不能作为重载的标志
//严格匹配隐式转化 double int float		int long double ambiguous
//  extern "C"==>防止倾轧
MyStruct operator+ (MyStruct a, MyStruct b)
{
	MyStruct c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
int main6() {
	int a = 0, b = 0;
	int c = a + b;
	MyStruct aa = { 1,2 }, bb = { 2,3 };
	MyStruct cc = aa + bb;
	cout << " cc= " << "< " << cc.x << "," << cc.y << " >" << endl;
	return 0;
}



void tian_qi_yu_bao(string w = "晴天")//默认为“晴天”
{	//求取时间
	time_t t = time(0);///1970，0，0，0至今 (单位s)
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d	 %x		%A  ", localtime(&t));
	//年 月 日  时/分/秒	周	
	cout << tmp << " 天气为" << w << endl;
}
int main7() {
	tian_qi_yu_bao();
	return 0;
}



int volume(int l = 2, int w = 2, int h = 2) { return l * w * h; }
//				从右往左默认，中间不能跳跃
//			实参的个数 + 默认参数的个数 >= 形参的个数
// 1 个参数或是 2 个参数的形式，重载，默认参数都是可以实现的。
// 但不可同时存在。
int main8() {

	cout << volume() << endl;
	cout << volume(1,2) << endl;
	cout << volume(3,3,3) << endl;
	return 0;
}


//c艹  引用
// 1. 引用是一种声明关系，类型与原类型保持一致
// 2. 引用且不分配内存,与被引用的变量有相同的地址
// 3. 声明的时候必须要初始化,已经声明的不可变更,可以多次引用
// 4. &符号前有数据型时是引用,其它皆为取地址 (重载)
int main9() {
	int a = 0;
	//*(int*) 0x11223344 = 500;
	//变量名实质 一段内存空间的别名
	int& ra = a;// ra 是 a 的引用
	int& rra = ra;// rra 是 ra 的再引用
	cout << "a=" << a << "  ra=" << ra << "  rra" << rra << endl;
	rra = 1;
	cout << "a=" << a << "  ra=" << ra << "  rra" << rra << endl;
	return 0;
}
// 5. 引用的本质，是对指针的再次包装。
// 5.1  可以定义指针的引用，但不能定义引用的引用
// 5.2  可以定义指针的指针（二级指针），但不能定义引用的指针。
// 5.3  可定义数组引用,但不能定义引用数组
int main10() {
    int* p;
    int*& rp = p;
	//指针的引用

	int a;
	int& ra = a;
	//int&& rra = ra;引用的引用
	
    int& pR = *p;
    //指针☞引用(引用可以取地址)

	int** pp = &p;
	//指针的指针（二级指针）
	//int& *ra = &ar;不能定义引用的指针

	int x = 0, y = 0, z = 0;
	int (arr1)[] = { x,y,z };
	int(&rarr)[3] = arr1;
	//数组引用
	int* (arr2)[] = { &x,&y,&z };
	//指针数组
	//int& rarr[] = {x,y,z}; 引用数组
	return 0;
}


#include <stdlib.h>//malloc 申请 free释放  C语言的.h
//new new[]  delete delete[]  关键字 可以被 operator
//1. new == malloc
int main11() {
    int* p = (int*)malloc(sizeof(int));//C
    //申请单变量空间
    int* pp = new int(0);
    //        申请int空间初始化为0
    cout << *pp << endl;
    //申请数组空间
    string* ps = new string("Saniao");
    cout << *ps << endl;
    //申请结构体空间
    struct Stu
    {
        int age;
        string name;
    };
    Stu* pStu = new Stu{ 12, "Saniao" };
    cout << pStu->age << "	" << pStu->name << endl;
    //申请指针数组空间
    char** ppc = new char* [5] {NULL};
    ppc[0] = new char[20];
    strcpy(ppc[0], "china1");
    ppc[1] = new char[20];
    strcpy(ppc[1], "china2");
    ppc[2] = new char[20];
    strcpy(ppc[2], "china3");
    while (*ppc)
    {
        cout << *ppc++ << endl;
    }
    //申请二维数组空间
    int(*pa)[4] = new int[3][4]{ {1} };
    for (int i = 0; i < sizeof(int[3][4]) / sizeof(int[4]); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << pa[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//2. delete == free
int main12() {
	int *p= new int[2];
	delete []p;//全
	delete p;//只有一个

//	int *pi = new(std::nothrow)int[123];
//		if (pi == NULL)return 1;
	return 0;
}

//	宏函数	时间换空间
//优点：代码内嵌，避免了函数的调用
//缺点：易产生歧义，使 text 段休积增大,不会进行类型检查。
#define SQR(i) ((i)*(i))
//	函数	空间换时间
//优点：一段高度抽象的逻辑，不易产生歧义，使 text 段休积变小
//缺点：函数调用的压栈与出栈的开销。
int sqr1(int i) { return i * i; }
//内朕函数 (inline)	  空间换时间
//优点：一段高度抽象的逻辑，不易产生歧义，会进行类型检查,还代码内嵌,避免函数调用的压栈与出栈的开销
//缺点：只有当函数只有 10 行甚至更少时才会将其定为内联函数（inline function) 咕噜咕噜/10 华为/5
inline int sqr2(int i) { return i * i; }
int main13() {
	int i = 0;
	while (i < 5) { cout << SQR(i++) << endl; }
	while (i < 5) { cout << sqr1(i) << endl; }
	while (i < 5) { cout << sqr2(i) << endl; }
	return 0;
}


//const 一定不可以改
//const-cast 只能应用于指针引用

void func1(int& v) {
	cout << v << endl;
}
//const - cast< 目标类型>（标识符）目标类类型只能是指针或引用
int main14() {
	const int a = 1;
	func1(const_cast<int&>(a));
	//引用
	int& ra = const_cast<int&>(a);
	ra = 2;
	cout << " a=" << a << "  ra=" << ra << endl;
	cout << " &a=" << &a << "  &ra=" << &ra << endl;
	//指针
	int* p = const_cast<int*>(&a);
	cout << " a=" << a << "  *p=" << *p << endl;
	cout << " &a=" << &a << "  &p=" << p << endl;
	//#define a 2 宏，在预处理的发生了替换
	//const int a = 2 ；在编译阶段发生了替换
	struct A
	{
		int a;
	};
	const A ad = { 10 };
	A* pA = const_cast<A*>(&ad);
	pA->a = 2;
	cout << pA->a << endl;
	return 0;
}



//协作开发
//  ::作用域运算符    前面要命名空间
//全局 无名 命名空间
//局部因为无法函数内定义函数所以 无命名空间
//namespace 是对全局命名空间的再次划分
//命名空间的关键字     namespace 后面+ 空间名 
namespace Space1 {
	int x = 0; //全局变量
	void func()//函数
	{
		cout << x << endl;
	}
	struct A//数据类型
	{
		int a;
	};
	namespace Space2	//其它命各空间 
	{
		int x = 0; //其它命各空间的全局变量
	}
}
//标准库命名空间
using namespace std;
int main15() {
	Space1::x = 1;
	cout << Space1::x << endl;
	Space1::Space2::x = 2;
	cout << Space1::Space2::x << endl;
	using Space1::x;//解包x
	using namespace Space1;//全解包Space1
	using namespace Space1::Space2;//只全解包Space2
	cout << x << endl;

	//string 不是关键字，而是一个类 char*
	string	Saniao("  Saniao ");
	cout << Saniao << endl;
	Saniao = " U  Saniao ";
	cout << Saniao << endl;
	string USaniao(Saniao);//初始化
	cout << Saniao << endl;
	cout << sizeof(Saniao) << "  " << sizeof(string) << endl; //封装一个一个一个 char*

	char buf[99];
	strcpy(buf, Saniao.c_str());//返回 c 串
	cout << buf << endl;

	int n = Saniao.find('i', 0);//查找
	cout << "n=" << n << endl;

	int n2 = Saniao.find_first_not_of(' ');
	Saniao.erase(0, Saniao.find_first_not_of(' '));//删除空
	cout << n2 << endl;
	cout << Saniao << endl;

	int n1 = Saniao.find_last_of('S');
	Saniao.erase(0, Saniao.find_last_of('S'));//删除S前面
	cout << n1 << endl;
	cout << Saniao << endl;

	//string 类型数组
	string sArr[4] = {
		"",
		"  1",
		" 222",
		"33333"
	};
	for (int i = 0; i < 4; i++)
	{
		cout << sArr[i] << endl;
	}

	return 0;
}

//打开文件，输出在控制台
int main16()//C语言版
{
    FILE* fp = fopen("test1.txt", "r+");
    if (fp == NULL)return -1;
    int lineCount = 0;
    char arr[999];
    while (fgets(arr, 999, fp) != NULL)
        lineCount++;
    rewind(fp);
    char** p = (char**)malloc((lineCount + 1) * sizeof(char*));
    char** pt = p;
    while (fgets(arr, 999, fp) != NULL)
    {
        int len = strlen(arr);
        *pt =(char*)malloc(len + 1);
        strcpy(*pt, arr);
        pt++;
    }
    *pt = NULL;
    while (*p)printf("%s", *p++);
    fclose(fp);
	return 0;
}

//C艹版
#include<vector>
int main17()
{
    FILE* fp = fopen("test1.txt", "r+");
    if (fp == NULL)return -1;

    vector<string> vs;
    //vector 就是个数组里面为 string 生成对象叫vs
    char arr[999];
    while (fgets(arr, 999, fp) != NULL)
    //fgets 从输入流 fp 即输入缓冲区中读取999个字符( /0 算1字符)到字符数组arr中
        vs.push_back(arr);
          // push_back追加在后面
    for (size_t i = 0; i < vs.size(); i++)
        cout << vs[i];
    fclose(fp);
    return 0;
}
#if 0
1 、 在C++中几乎不需要用宏，用 const 或 enum 定义显式的常量,
用 inline 避免函数调用的额外开销, 用模板去刻画一族函数或类型
用 namespace 去避免命名冲突
2 、 不要在你需要变量之前去声明，以保证你能立即对它进行初始化.
3 、 要用 malloc 用 new 运算会做的更好
4 、 避免使用 void 、指针算术、联合、强制，大多数情况下，强制都是设计错误的指示
5 、 尽量少用数组和 C 风格的字符串，标准库中的 string 和 vector 可以简化程序
6 、 更加重要的是，试着将程序考虑为一组由 类和对象 表示的相互作用的既念
而不是一堆数据结构和一些可以拨弄的二进制
#endif
