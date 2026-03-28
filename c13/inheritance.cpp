//
// Created by Administrator on 2026/3/25.
//
#include  <iostream>
using namespace std;

class Person
{
public:
    Person(const char* name)
        : _name(name)
    {
        // std::cout << "Person()" << endl;
    }

    Person(const Person& p)
        : _name(p._name)
    {
        std::cout << "Person(const Person&)" << endl;
    }

    Person& operator=(const Person& p)
    {
        cout << "Person operator=(const Person& p)" << endl;
        if (this != &p)
            _name = p._name;
        return *this;
    }

    ///析构函数会变特殊处理成destructor()加virtual构成多态
    /// 基类中析构函数建议设计成虚函数
    virtual ~Person()
    {
        cout << "~Person()" << endl;
    }

protected :
    string _name; // 姓名
};

class Student : public Person
{
public :
    /*
        默认生成构造函数
        1、内置类型->不确定
        2、自定义类型->调用默认构造
        3、继承父类的成员变量->调用父类的默认构造

     */
    Student(const char* name, int no, const string& addrss)
        : Person(name), _No(no), _addrss(addrss) {}

    //默认生成拷贝构造函数就够用了，如果用深拷贝的资源才需要自己实现
    Student(const Student& s)
        : _No(s._No), _addrss(s._addrss), Person(s/* 赋值兼容规制 子->父 */)
    {
        //深拷贝
    }

    // 默认生成operator=数就够了，如果用深拷贝的资源才需要自己实现
    Student& operator=(const Student& s)
    {
        if (this != &s)
        {
            //父类和子类的operator=构成隐藏关系
            Person::operator=(s);
            _No = s._No;
            _addrss = s._addrss;
        }
        return *this;
    }

    //默认生成析构函数就够了，如果需要释放的资源才需要自己实现
    //子类和父类析构函数构成隐藏关系

    ///规定：析构不需要显示调用父类的析构函数
    ///子类的析构函数调用完会用父类的析构函数 保证先子后父
    ///加virtual构成多态 基类加virtual就彳亍 基类不加则派生类调不到析构函数
    virtual ~Student()
    {
        // Person::~Person();
        std::cout << "~Student()" << endl;
        //释放资源
    }

protected:
    int _No; // 学号
    string _addrss = "北京";
};

int main()
{
    // Student s1("张三", 1, "北京");
    // Student s2(s1);
    // Student s3("李四", 2, "上海");
    // s3 = s1;

    Person* p = new Person("析构测试");
    Student* s = new Student("张三", 1, "北京");

    //实际上就是p->dstructor() 结合 operator delete
    delete p;
    delete s;
    return 0;
}

// int main()
// {
//     Student sobj;
//     // 1.派生类对象可以赋值给基类的指针/引用
//     Person* pp = &sobj;
//     Person& rp = sobj;
//     // 生类对象可以赋值给基类的对象是通过调用后面会讲解的基类的拷贝构造完成的
//     Person pobj = sobj;
//     //2.基类对象不能赋值给派生类对象，这里会编译报错
//    // sobj = pobj;
//     return 0;
// }

/*
    A中的fun和B中的fun函数名相同，所以B中的fun()会隐藏掉A中的fun()
    A和B在不同作用域构不成函数重载
 */
class A
{
public:
    void fun()
    {
        cout << "func()" << endl;
    }
};

//注意在实际中在继承体系里面最好不要定义同名的成员。
class B : public A
{
public:
    void fun(int i)
    {
        cout << "func(int i)" << i << endl;
    }
};

int maim1()
{
    B b;
    b.fun(10);
    //（在派生类成员函数中，可以使用 基类::基类成员 显示访问）b.fun()编不过
    b.A::fun();
    return 0;
};
