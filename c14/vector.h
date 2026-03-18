//
// Created by Administrator on 2026/3/17.
//

#ifndef C14_VECTOR_H
#define C14_VECTOR_H
#include <algorithm>
#include <cassert>
#include <iostream>
#include <bits/forward_list.h>

#include "../c12/String.h"

namespace l
{
    template <class T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        //强制生成默认构造
        vector() = default;

        vector(const vector<T>& v)
        {
            reserve(v.size());
            for (auto& e : v)
            {
                push_back(e);
            }
        }

        //类模板的成员函数，还可以继续是函数模板
        template <class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        vector(size_t n, const T& val = T())
        {
            reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                push_back(val);
            }
        }

        vector(int n, const T& val = T())
        {
            reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                push_back(val);
            }
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t old_size = size();
                T* tmp = new T[n];

                for (size_t i = 0; i < old_size; i++)
                {
                    tmp[i] = _start[i];
                }

                delete[] _start;
                _start = tmp;
                _finish = old_size + tmp;
                _end_of_storage = tmp + n;
            }
        }

        void resize(size_t n, const T& val = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                reserve(n);
                while (_finish < _start + n)
                {
                    *(_finish) = val;
                    ++_finish;
                }
            }
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        void push_back(const T& x)
        {
            //扩容
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = x;
            ++_finish;
        }

        bool empty()
        {
            return _start == _finish;
        }

        void pop_back()
        {
            assert(!empty());
            --_finish;
        }

        iterator insert(iterator pos, const T& x)
        {
            assert(pos >= _start && pos <= _finish);
            //扩容
            if (_finish == _end_of_storage)
            {
                size_t old_pos = pos - _start;
                reserve(capacity() == 0 ? 4 : capacity() * 2);
                pos = _start + old_pos;
            }

            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }
            *pos = x;
            ++_finish;
            return pos;
        }

        //erase后迭代器失效 必须返回新的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos >= _start && pos < _finish);

            iterator it = pos + 1;
            while (it != _finish)
            {
                *(it - 1) = *it;
                ++it;
            }
            --_finish;
            return pos;
        }

        void clear()
        {
            _start = _finish;
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        vector<T>& operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }

    private:
        iterator _start = nullptr;
        iterator _finish = nullptr;
        iterator _end_of_storage = nullptr;
    };

    template <class T>
    void print_vector(const vector<T>& v)
    {
        //没有实例化的类模板编译器不能识别是 类型 还是 静态成员变量，
        //必须添加 typename 换成auto方便
        // typename vector<T>::const_iterator cit = v.begin();
        auto cit = v.begin();
        while (cit != v.end())
        {
            std::cout << *cit << " ";
            ++cit;
        }
        std::cout << std::endl;
    }

    void test()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(4);
        v.push_back(4);
        v.push_back(5);
        print_vector(v);

        vector<double> vb;
        vb.push_back(1.1);
        vb.push_back(2.2);
        vb.push_back(3.3);
        // print_vector(vb);

        // v.insert(v.begin(), 0);
        // v.insert(v.begin() + 4, 4);
        // print_vector(v);
        //
        // int x;
        // std::cin >> x;
        // auto pos = std::find(v.begin(), v.end(), x);
        // if (pos!=v.end())
        // {
        //     //insert后pos就失效了
        //     pos = v.insert(pos,10);
        //     // (* pos) *= 2;
        //     v.insert(pos+2, 100);

        // //删除所有偶数
        // auto it = v.begin();
        // while (it != v.end())
        // {
        //     if (*it % 2 == 0)
        //     {
        //         //迭代器失效 必须更新
        //         it = v.erase(it);
        //     }
        //     else
        //         ++it;
        // }
        vector<int> v1 = v;
        // v1.resize(5, 1);
        // print_vector(v1);
        // v1.resize(10, 2);
        // print_vector(v1);
        // v1.resize(5, 3);
        vector<int> v3;
        v3.push_back(10);
        v3.push_back(20);
        v3.push_back(30);
        // v1 = v3;
        // print_vector(v1);
        vector<int> v4(v1.begin(), v1.begin() + 3);
        print_vector(v4);
        vector<std::string> v5(4, "ppp");
        print_vector(v5);
        v5.push_back("xxx");
        v5.push_back("xxx");
        v5.push_back("xxx");
        print_vector(v5);
        vector<int> v6(10, 1);
        print_vector(v6);
    }
}
#endif //C14_VECTOR_H
