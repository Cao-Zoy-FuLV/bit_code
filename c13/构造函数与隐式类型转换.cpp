//
// Created by Administrator on 2026/3/9.
//
#include <cstring>
#include<iostream>
using namespace std;

class Data
{
public:
    Data(int a, int b=1)//构造函数d=1的缺省值是在对象初始化传参调用和声明无关
    //初始化列表：（初始值或者表达式）每个初始化只能初始一次
    //内置类型：编译器自动初始化     自定义类型：调用默认构造
        : _a(a), _b(b)//定义的不必须全部
        , _c(a)//初始化列表成员只跟声明顺序有关，建议和声明保持一致
        ,_ptr1((int*)malloc(12))
    {
        if (_ptr1== nullptr)
            perror("malloc error");
        else
            memset(_ptr1, 0, 12);
    }
    //只能在初始化列表=》必须在定义的时候初始化
    //不能初始化const声明
    //如：
    //private:
    //      const int a1
    //引用不能初始化
    //如：
    //private:
    //      int& a1
    void Print()
    {
        cout << _a << " "<<_定义 << _b << endl;
    }
private:
    //声明，缺省值-》初始化列表用
    int _定义=0;//这没开空间属于声明，0属于缺省值
    int _a;
    int _b;
    int _c;
    int* _ptr1;
    //和_ptr1一样,不初始列表也会走初始列表，写了就用缺省值初始，
    int * _ptr2=(int*)malloc(12);
};


int main(int argc, char* argv[])
{
    //对象声明
    Data d1=Data(1,2);
    d1.Print();
    return 0;
}



class A
{
public:
    // 构造函数explicit就不再支持隐式类型转换
    // explicit A(int a1)
    A(int a1=0)
    :_a1(a1)
    {}
    A(const A& aa)
    {
        _a1=aa._a1;
    }
    A(int a1, int a2)
    :_a1(a1)
    , _a2(a2)
    {}
    void Print()
    {
        cout << _a1 << " " << _a2 << endl;
    }
    int Get() const
    {
        return _a1 + _a2;
    }
private:
    int _a1 = 1;
    int _a2 = 2;

};

class Stack
{
public:
    void push(const A& arr){}
private:
    A _arr[10];
    int _top;

};
int main1(int argc, char* argv[])
{
    A aa1(1);
    aa1.Print();

    // 隐式类型转换
    //先用2构造函数构造临时对象，然后在用临时对象拷贝构造aa2
    //编译器遇到连续构造+拷贝构造一〉优化为直接构造
    A aa2 = 2;//"xxx"不支持
    aa2.Print();

    A& raa1=aa1;
    // A& raa2 =2;错误因为中间变量为常量
    const A& raa2 =2;

    Stack st;
    A aa3(3);
    //下2效果一样
    st.push(aa3);
    st.push(3);//(单参数特供)

    A aa5 ={1,1};
   const A& raa6={2,2};
    st.push(aa5);
    st.push({1,1});

    return 0;
}

