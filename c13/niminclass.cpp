#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A(int a = 0)
    :_a(a)
    {
        cout << "A(int a)" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    int _a;
};
class Solution {
public:
    int Sum_Solution(int n) {
        //...
        return n;
    }
};
bool f(int i, int j){return i>j;}

int main()
{
    A aa1;
    // 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
    //A aa1();
    // 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
    // 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
    A();
    A(1);
    A aa2(2);
    // 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
    Solution().Sum_Solution(10);


    int a[]={486,95,34,75,345,};
    //<升序
    sort(a,a+5);
    //>降序
    // sort(a,a+5, f);
    sort(a,a+5, greater< int>());
    return 0;
}