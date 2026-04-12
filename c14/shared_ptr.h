//
// Created by Administrator on 2026/4/11.
//

#ifndef C14_SHARED_PTR_H
#define C14_SHARED_PTR_H
#include "functional"

namespace l
{
    template<class T>
    class shared_ptr
    {
    public:
        explicit shared_ptr( T* ptr = nullptr )
            : _ptr(ptr)
          , _pcount(new int(1)) {}

        //定制删除器版本
        template<class D>
        shared_ptr( T* ptr, D del )
            : _ptr(ptr)
          , _pcount(new int(1))
          , _del(del) {}

        shared_ptr( const shared_ptr <T>& sp )
            : _ptr(sp._ptr)
          , _pcount(sp._pcount)
          , _del(sp._del)
        {
            ++(*_pcount);
        }

        void release()
        {
            if ( --(*_pcount) == 0 )
            {
                // 最后一个管理的对象，释放资源
                _del(_ptr);
                delete _pcount;
                _ptr = nullptr;
                _pcount = nullptr;
            }
        }

        shared_ptr <T>& operator=( const shared_ptr <T>& sp )
        {
            if ( _ptr != sp._ptr )
            {
                release();
                _ptr = sp._ptr;
                _pcount = sp._pcount;
                ++(*_pcount);
                _del = sp._del;
            }
            return *this;
        }
        ~shared_ptr()
        {
            release();
        }
        T* get() const

        {
            return _ptr;
        }
        int use_count() const
        {
            return *_pcount;
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }

    private:
        T* _ptr;
        // int* _pcount;
        //保证_pcount线程安全 atomic原子的
        //但指向的资源不是线程安全，需要加锁
        std::atomic <int>* _pcount;
        //包装器 定制删除器
        std::function <void( T* )> _del = [] ( T* ptr ) { delete ptr; };
    };
}
#endif //C14_SHARED_PTR_H
