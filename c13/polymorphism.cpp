//
// Created by Administrator on 2026/3/28.
//
#include  <iostream>
using namespace std;
/*
多态
    完成某个行为(函数)，可以传不同的对象就会完成不同的行为
    实现多态还有两个必须重要条件：
        必须是基类的指针或者引用调用虚函数
        被调用的函数必须是虚函数，并且完成了虚函数重写/覆盖。
    虚函数（virtual）的覆盖/重写
        派生类的虚函数和基类虚函数 1.名相同 2.返回值类型相同 3.参数列表相同
 */
class Person
{
public:
    virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person
{
public:
    virtual void BuyTicket() { cout << "买票-打折" << endl; } //派生类可以去掉virtual （但不规范）
};

class T
{
public:
    void BuyTicket() { cout << "买票-全价" << endl; }
};

void Func(Person* ptr)
//ptr 必须是一个基类指针或者引用 才构成多态
{
    // 虽然都是Person指针Ptr在调用BuyTicket ，但是由ptr指向的对象决定的。
    // 运行时到指向的对象的虚函数中寻找对应的虚函数的地址，进行调用
    ptr->BuyTicket();
}

int main1()
{
    Person ps;
    Student st;
    T t;
    Func(&ps);
    Func(&st);

    //虚函数会保存在虚函数表（函数指针数组）中
    cout << sizeof(st) << endl;
    cout << sizeof(t) << endl;
    return 0;
}

//以下程序输出什么？ 
class A
{
public:
    virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
    virtual void test() { func(); }
};

class B : public A
{
public:
    void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};

/*
    p->test()
                ↓ ——p是B的对象 test() 传 A* thsi
    thsi->func()
                ↓——构成多态 调用 B::func()
    输出： B->1
    重写的本质 是实现虚函数 派生类不重新定义基类的缺省参数值

    p->func()
                ↓——普通调用 B::func()
    输出： B->0
 */
int main2()
{
    B* p = new B;
    p->test(); //B->1
    p->func(); //B->0

    return 0;
}

/*
 纯虚函数和抽象类
    在虚函数的后面写上 = 0，纯虚函数在派生类重写，基类只要声明即可。
    包含纯虚函数的类叫做抽象类，抽象类不能实例化出对象，
    派生类继承后不重写纯虚函数，那么派生类也是抽象类。
    纯虚函数某种程度上强制了派生类重写虚函数，因为不重写实例化不出对象。
 */
class x
{
public:
    //纯虚函数
    virtual void func() =0;
    //final 禁止派生类重写
    virtual void d() final {}
};

class y : public x
{
public:
    //override 强制检查派生类是否重写
    void func() override
    {
        cout << "y 实现的 x 的纯虚函数" << endl;
    }
};

int main3()
{
    //x 抽象类 不能实例化出对象
    // x x1;
    y y1;
    if (1)
    {
        y1.func();
    }
    return 0;
}

int main(int argc, char* argv[])
{
    main1();
    cout << "y 实现的 x 的纯虚函数" << endl;
}
