#include<iostream>

#include <sstream>
#include<vector>
#include<fstream>
#include <set>
#include  "vector.h"

/*
#include "AVLTree.h"
#include "HashTable.h"
#include "RBTree.h"
#include  "Mymap.h"
#include "Mysat.h"
*/


/*
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

 */
/*
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



int l_sat_map( int argc, char* argv[] )
{
    l::sat <int> s;
    l::map <int, int> m;
    s.insert(1);
    m.insert({ 1, 1 });
    s.insert(2);
    m.insert({ 2, 2 });
    s.insert(3);
    m.insert({ 3, 3 });
    s.insert(4);
    m.insert({ 4, 4 });
    s.insert(5);
    m.insert({ 5, 5 });

    l::sat <int>::iterator sit = s.begin();
    for ( auto& e : s )
    {
        cout << e << " ";
    }
    cout << endl;;
    l::map <int, int>::iterator mit = m.begin();
    while ( mit != m.end() )
    {
        mit->second++;
        // mit->first++;firstg 为const改不了
        cout << mit->first << " ：" << mit->second << endl;
        ++mit;
    }
    cout << endl;;

    // system("pause");
    return 0;
}
*/
/*
int main()
{
    int a[] = { 19, 30, 5, 36, 13, 20, 21, 12 };
    l::open_address::HashTable <int, int> ht1;
    for ( auto e : a )
    {
        ht1.Insert({ e, e });
    }
    ht1.Insert({ 14, 14 });
    if ( ht1.Find(30) )
    {
        cout << "找到30" << endl;
    }
    const char* c[] = { "aa", "bb", "cc", "dd" };
    l::open_address::HashTable <string, string> ht2;
    for ( auto e : c )
    {
        ht2.Insert({ e, e });
    }
    int a2[] = { 19, 30, 5, 36, 13, 20, 21, 12, 24, 96 };
    l::hash_bucket::HashTable <int, int> hb1;
    for ( auto e : a2 )
    {
        hb1.Insert({ e, e });
    }
    hb1.Erase(96);
    if ( hb1.Find(96) )
    {
        cout << "找到96" << endl;
    }

    system("pause");
    return 0;
}
*/


#include "shared_ptr.h"
#include "../c12/Date.h"
int main( int argc, char* argv[] )
{
    l::shared_ptr <Date> sp1(new Date);
    // 支持拷贝
    l::shared_ptr <Date> sp2(sp1);
    l::shared_ptr <Date> sp3 = sp2;
    //支持定制删除器
    l::shared_ptr <Date> sp4(new Date, [] ( Date* p ) { delete p; });
    system("pause");
}

