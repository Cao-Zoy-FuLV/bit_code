#include <bits/stdc++.h>
using namespace std;

/*
* 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

数据范围：
0<n≤200
进阶： 空间复杂度 O(1) ，时间复杂度 O(n)
 */


class Solution
{
    class Sum
    {
    public:
        Sum()
        {
            _ret += _i;
            ++_i;
        }
        static int getRet()
        {
            return _ret;
        }

    private:
        static int _i;
        static int _ret;
    };

public:
    int Sum_Solution(int n)
    {
        Sum S[n];
        return Sum::getRet();
    }
};

int Solution::Sum::_i = 1;
int Solution::Sum::_ret = 0;

//单元测试代码
#include <cassert>

void test_Sum_Solution()
{
    /*// 测试用例 1: n = 1
    {
        Solution sol;
        int result = sol.Sum_Solution(1);
        assert(result == 1);
        cout << "Test 1 passed: n=1, result=" << result << endl;
    }*/

    /*
    // 测试用例 2: n = 3 (1+2+3 = 6)
    {
        Solution sol;
        int result = sol.Sum_Solution(3);
        assert(result == 6);
        cout << "Test 2 passed: n=3, result=" << result << endl;
    }*/

    /*// 测试用例 3: n = 5 (1+2+3+4+5 = 15)
    {
        Solution sol;
        int result = sol.Sum_Solution(5);
        assert(result == 15);
        cout << "Test 3 passed: n=5, result=" << result << endl;
    }*/

    /*// 测试用例 4: n = 10 (1+2+...+10 = 55)
    {
        Solution sol;
        int result = sol.Sum_Solution(10);
        assert(result == 55);
        cout << "Test 4 passed: n=10, result=" << result << endl;
    }*/

    // 测试用例 5: n = 100 (1+2+...+100 = 5050)
    {
        Solution sol;
        int result = sol.Sum_Solution(100);
        assert(result == 5050);
        cout << "Test 5 passed: n=100, result=" << result << endl;
    }
}

int main()
{
    test_Sum_Solution();
    return 0;
}
