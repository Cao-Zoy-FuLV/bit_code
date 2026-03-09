
#include <iostream>
using namespace std;
class MyClass
{
public:
	MyClass() {
		pa[0] = &MyClass::f;
		pa[1] = &MyClass::ff;
		pa[2] = &MyClass::fff;
		pa[3] = &MyClass::ffff;
		pa[4] = &MyClass::fffff;
	}
	void select(int idx)
	{
		(this->*pa[idx])();
	}

private:
	void f() { cout << "void f()" << endl; }
	void ff() { cout << "void ff()" << endl; }
	void fff() { cout << "void fff()" << endl; }
	void ffff() { cout << "void ffff()" << endl; }
	void fffff() { cout << "void fffff()" << endl; }
	enum { cut = 5 };
	void(MyClass::* pa[cut])() = 
	{ 
		&MyClass::f,
		&MyClass::ff,
		&MyClass::fff,
		&MyClass::ffff,
		&MyClass::fffff
	};
};
int mainf()
{
	MyClass M;
	M.select(0);
	M.select(1);
	M.select(2);
	M.select(3);
	M.select(4);
	return 0;
}

class A {
public:
	void f() { cout << "A::f()" << endl; }
};

typedef  void(A::*PF)();

int main(int argc, char* argv[])
{
	// void (A::*pf)() = nullptr
	PF pf =nullptr;

	//C++规定成员函数必须加&才能取到函数指针
	pf=&A::f;

	A aa;
	(aa.*pf)();
	//   [ .* ] 运算符在函数回调中使用 ，实际少用
}
