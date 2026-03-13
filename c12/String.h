#pragma once
#include <iostream>
using namespace std;

class String
{
public:
    String(const char* p = NULL); //默认参数只能在声明。
    //			拷贝构造器——用一个对象生成另外一个对象
    //  1.	由己存在的对象创建新对象。也就是新对象，不由构造器来构造，
    //而是由拷贝构造器来完成的，拷贝构造器的格式是固定的。
    //class 类名
    //{
    //		类名 (const 类名& another){拷贝构造器}
    // }
    //	2. 若不提供，系统会捏供默认（成功编译），一旦自定义，系统不再提供默认。
    //	3. 系统提供的默认，是一种等位拷贝。也就是江湖说的，浅浅的拷贝。
    //	4. 浅拷贝，会导致，内存重析构。 double free.
    //在有些情况下（含有堆空间的时候)，要自实现拷贝构造
    String(const String& another); //拷贝构造器
    /*
        * 如果返回对象是一个当前函数局部域的局部对象，函数结束就销毁了，那么使用
        引用返回是有问题的，这时的引用相当于一个野引用，类似一个野指针一样。传引用返回可以减少
        拷贝，但是一定要确保返回对象，在当前函数结束后还在，才能用引用返回
     */


    /*
    * 			赋值运算符重载 ‘=’
        1. 用一个己有的给另外一个己有对象赋值，两个对象均己创建结束后发生的赋值行为
    类名
    {
            类名& operator=(const 类名& 源对象）
                拷贝体
    }
        2. 译器提供默认〈编译成功的原因）,一旦自定义，系统不再提供默认。

        3. 默认赋值运算符重载,也是一种等位赋值,浅赋值
        4. 浅赋值,有可能导致:
            4.1 自身内存泄漏。
            4.2 内存发生重构。
            4.3 自赋值。
     5. 如果一个类显示实现了析构并释放资源，那么他就需要显示写赋值运算符重载，否则就不需要。
     */
    String& operator=(const String& another);
    String operator+(const String& another);
    bool operator>(const String& another);
    bool operator<(const String& another);
    bool operator==(const String& another);
    char& operator[](int idx);
    char at(int idx);


    char* char_s();
    ~String();

private:
    char* _str;
};
