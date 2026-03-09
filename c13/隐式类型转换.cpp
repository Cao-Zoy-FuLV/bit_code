//
// Created by Administrator on 2026/3/9.
//
#include<iostream>
using namespace std;
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
    //explicit A(int a1, int a2)
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
int main(int argc, char* argv[])
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
