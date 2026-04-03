#include<iostream>

#include <sstream>
#include<vector>
#include<fstream>

#include "AVLTree.h"
#include  "vector.h"
#include "RBTree.h"
using namespace std;

int main0()
{
    ifstream input("a.txt");
    string line;
    while ( getline(input, line) )
    {
        cout << line << endl;
    }
    ofstream output("a.txt");
    while ( getline(input, line) ) //清空
    {
        output << line << endl;
    }


    return 0;
}

int vector_main()
{
    l::test();
    return 0;
}

void TestRBTree1()
{
    RBTree <int, int> t;
    // 常规的测试用例
    // int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
    // 特殊的带有双旋场景的测试用例
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    for ( auto e : a )
    {
        t.Insert({ e, e });
    }

    t.InOrder();
    cout << t.IsBalance() << endl;
}
void TestRBTree2()
{
    const int N = 1000000;
    vector <int> v;
    v.reserve(N);
    srand(time(0));
    for ( size_t i = 0; i < N; i++ )
    {
        v.push_back(rand() + i);
    }

    size_t begin2 = clock();
    RBTree <int, int> t;
    for ( auto e : v )
    {
        t.Insert(make_pair(e, e));
    }
    size_t end2 = clock();
    cout << "Insert:" << end2 - begin2 << endl;
    cout << t.IsBalance() << endl;
    cout << "Height:" << t.Height() << endl;
    cout << "Size:" << t.Size() << endl;
    size_t begin1 = clock();
    // 确定在的值
    for ( auto e : v )
    {
        t.Find(e);
    }
    // 随机值
    // for ( size_t i = 0; i < N; i++ )
    // {
    //     t.Find((rand() + i));
    // }
    size_t end1 = clock();
    cout << "Find:" << end1 - begin1 << endl;
}

void TestAVLTree1()
{
    AVLTree <int, int> t;
    // 常规的测试用例
    int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
    // 特殊的带有双旋场景的测试用例
    // int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };


    for ( auto e : a )
    {
        t.Insert({ e, e });
    }

    t.InOrder();
    cout << t.IsBalanceTree() << endl;
}
void TestAVLTree2()
{
    const int N = 1000000;
    vector <int> v;
    v.reserve(N);
    srand(time(0));
    for ( size_t i = 0; i < N; i++ )
    {
        v.push_back(rand() + i);
    }

    size_t begin2 = clock();
    AVLTree <int, int> t;
    for ( auto e : v )
    {
        t.Insert(make_pair(e, e));
    }
    size_t end2 = clock();
    cout << "Insert:" << end2 - begin2 << endl;
    cout << t.IsBalanceTree() << endl;
    cout << "Height:" << t.Height() << endl;
    cout << "Size:" << t.Size() << endl;
    size_t begin1 = clock();
    // 确定在的值
    for ( auto e : v )
    {
        t.Find(e);
    }
    // 随机值
    // for ( size_t i = 0; i < N; i++ )
    // {
    //     t.Find((rand() + i));
    // }
    size_t end1 = clock();
    cout << "Find:" << end1 - begin1 << endl;
}

// 插入一堆随机值，测试平衡，顺便测试一下高度和性能等
void TestTree()
{
    const int N = 10000000;
    vector <int> v;
    v.reserve(N);
    srand(time(0));
    for ( size_t i = 0; i < N; i++ )
    {
        v.push_back(rand() + i);
    }
    size_t begin2 = clock();
    AVLTree <int, int> t1;
    for ( auto e : v )
    {
        t1.Insert(make_pair(e, e));
    }
    size_t end2 = clock();

    size_t begin3 = clock();
    RBTree <int, int> t2;
    for ( auto e : v )
    {
        t2.Insert(make_pair(e, e));
    }
    size_t end3 = clock();
    cout << "RBTree Insert:" << end3 - begin3 << t2.IsBalance() << endl;
    cout << "AVL Insert:" << end2 - begin2 << t1.IsBalanceTree() << endl;
    cout << "RBTree Height:" << t2.Height() << endl;
    cout << "AVL Height:" << t1.Height() << endl;
    cout << "RBTree Size:" << t2.Size() << endl;
    cout << "AVL Size:" << t1.Size() << endl;
    size_t begin1 = clock();
    // 确定在的值
    // for ( auto e : v )
    // {
    //     t1.Find(e);
    // }
    // 随机值
    for ( size_t i = 0; i < N; i++ )
    {
        t1.Find((rand() + i));
    }
    size_t end1 = clock();

    size_t begin4 = clock();
    // 确定在的值
    // for ( auto e : v )
    // {
    //     t2.Find(e);
    // }
    // 随机值
    for ( size_t i = 0; i < N; i++ )
    {
        t2.Find((rand() + i));
    }
    size_t end5 = clock();

    cout << "RBTree Find:" << end5 - begin4 << endl;
    cout << "AVL Find:" << end1 - begin1 << endl;
}

int main( int argc, char* argv[] )
{
    TestTree();
}

