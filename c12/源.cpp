
#include "String.h"
#include "this_zz.h"
int main1()
{
	String s1;
	String s2("我阐述你的梦");
	cout << s1.char_s();
	cout << s2.char_s() << endl;

	//拷贝构造器——用一个对象生成另外一个对象
	String s3(s2);
	cout << s3.char_s() << endl;
	String s4 = s3;//本质：拷贝构造器——用己有一个对象，完成一个对象从无到有的创建过程
	cout << s4.char_s() << endl;

	this_zz _this(20, "我阐述你的", "梦");
	_this.display();
	_this.grow_up().grow_up().grow_up().display();//链式表达

	//赋值运算符重载 ‘=’
	String s5;
	//s5 = s4;//==>s5.operator = (s4);
	s5 = s4 = s3 = s2 = s1;//==>s5.operator =(s4.operator=(s3.operator=(s2.operator=(s1))));
	//(s5 = s4)=s3//s3=>(main空间的栈上的临时空间) s4=>s5 (临时空间)=>s5
	cout << s5.char_s() << endl;
	cout << s3.char_s() << endl;
	
	String x = "我阐述你的 ", y = "梦";
	String z = x + y;
	cout << z.char_s() << endl;
	if (x == y)
		cout << " x = y " << endl;
	if (x > y)
		cout << " x > y " << endl;
	if (x < y)
		cout << " x < y " << endl;
	x[8] = 'S';
	cout << x[8] << endl;
	return 0;
}

//拷贝构造器发生的时机
//  1。 构造新对象  This This_a； This This_b = This_a;
//  2。 传参或返回对界
//对于普通变量来说，传引用效果不明显。
//对于类对象而言，传对象效率很高。
//传引用等价于，扩大了原对象的作用域。
void fun1(This& This_1) {}//传引用(&This_1)效率高
//传参
int main2()
{
	This This_a;
	This This_b = This_a;
	fun1(This_a);
	return 0;
}
//栈上的对象是可以返回的，但不能回栈上的引用〈除非返回对象本身）
This fun2(This& This_1) { return This_1; }
int main3()
{
	This This_a;
	//调用返回时,又开辟空间在main函数栈上
	This This_b;
	This_b = fun2(This_a);
	return 0;
}
//返回2
This fun3() { This This_1; return This_1; }
int main4()
{
	This This_a;
	This_a = fun3();
	cout << "This_a 的地址" << &This_a << endl;
	return 0;
}