#include <iostream>
using namespace std;

//		const 
// 1. 修饰数据成员 
//初始化位置只能在参数列表里面,修饰的数据成员，不能被修改
// 2. 修饰成员函数,位置函数声明之后，实现体之前,求在声明和定义处都要有 const 修饰 
//	 const 函数承诺 
//不会修改数据成员能访问 const 和非 const 数据成员,
//但不能修改,非 const 数据成员,只能访问 const 成员函数。
//   构成重载
// const 对象只能调用 const 成员函数。
// 非 const 对象优先调用非 const 成员函数，若无则调用 const 成员函数
// 4. 修饰类对象
// const 修饰函数，是从函数的层面，不修改数据。
// const 修饰对象，是从对象的层面，不修改数据,只能调用 const 成员函数。
// 
class _const
{
public:
	_const(int val)
		:val(val) {}//const只能在参数列表里面;
	void print1()
	{
		cout << val << endl;

	}
	void print2() const
	{
		cout << "const" << endl;
		//a=0  不会修改数据成员
		int a = 0; //可以修改局部变量
		//print1();只能访问 const 成员函数。
	}
	void print2()
	{
		cout << "not const" << endl;
	}
private:
	const int val;//修饰数据成员
	int a = 0;
};
int main1()
{
	_const a(1);
	//a.print1();
	a.print2();
	const _const b(1);
	b.print2();
	return 0;
}



class _static;//前向性声明
//class的友元
class dis2//前向性声明
{
public:
	void dis(_static& t);
};
//		static
//全局变量 外延性 static 作用域,仅限于文件
//局部变量 auto 生命周期=main  
//存储位置：DATA 段（全局初始化区）——存放初始化的全局变量和静态变量 
//			或 BSS 段（全局未初始化区）存放未初始化的全局变量和静态变量。程序运行结束时自动释放
//			的 RW 段
//
// 1. static 在类内部的表現，用来实现族类对象间的数据共享
//生成对象的时候，static成员在类声明的时候，就己经开辟了空间（data rw）。而普通数据员才有空间。
// static 数据成员，既属于类，也属于对象，但终归于类
// 2. 初始化
//类内定义，类外初始化。 type 类名::变量名=值
// 3. 修饰成员函数，他的作用只有一个，用于管理 static 成员。
// static 修饰的成员函数，既属类也属于对象，但终归于类。
//因为他属于类，所以没有 this 指针,不能访问非 static 数据成员及其成员函数
class _static
{
public:
	_static() {};

	void print()
	{
		cout << as << endl;
	}
	int& gat_x()
	{
		return x;
	}
	static int& gat_as()
	{
		//x=0;没有this指针
		return as;
	}
	friend void dis1(_static& t); //函数〈全局，也可类的成员函数）可以作友元，称为友元函数。
	friend void dis2::dis(_static& t);//声明友元函数
	friend class dis3;//把B声明A的友元，就可以涌过A的变量访间A的private:数据成员。

private:
	int x;
	int y;
	int z;
	static int as;

};
//全局的友元
void dis1(_static& t)
{
	cout << t.x << t.y << t.z << endl;
}
//类的成员函数
void dis2::dis(_static& t)
{
	cout << t.x << t.y << t.z << endl;
}
//友元类--成员函数全为友元函数
class dis3
{
public:
	void dis(_static& t)
	{
		cout << t.x << t.y << t.z << endl;
	}
};


int _static::as = 0;//只能在类外初始化
int main()
{
	_static a, b, c;
	cout << "sizeof(_static) " << sizeof(_static) << endl;
	cout << "sizeof(a) " << sizeof(a) << endl;

	_static::gat_as() = 97;
	a.gat_x() = 1;
	b.gat_x() = 2;
	c.gat_x() = 3;
	a.gat_as()++;
	b.gat_as()++;
	c.gat_as()++;
	cout << a.gat_as() << endl;
	cout << _static::gat_as() << endl;

	//友元
	dis1(a);
	dis2 v; v.dis(a);
	dis3 n; n.dis(a);

	return 0;
}





class CCSprite
{
public:
	CCSprite(int d)
	{
		data = d;
		if (head == NULL)
		{
			this->next = NULL;
			head = this;
		}
		else
		{
			this->next = head->next;
			head = this;
		}
	}
	static void traverseCCSprit()
	{
		CCSprite* ph = head;
		while (ph != NULL)
		{
			cout << ph->data << endl;
			ph = ph->next;
		}
	}
	~CCSprite() {};
private:
	int data;
	CCSprite* next;
	static CCSprite* head;
	static const int a = 0; //被static const修饰只能就地初始化
};
CCSprite* CCSprite::head = NULL;
int main3()
{
	CCSprite a(1), b(2), c(3);
	CCSprite::traverseCCSprit();
	cout << endl;
	for (size_t i = 0; i <= 9; i++)
	{
		new CCSprite(i);
		CCSprite::traverseCCSprit();
	}
	cout << endl;
	CCSprite::traverseCCSprit();


	return 0;
}

