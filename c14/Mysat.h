//
// Created by Administrator on 2026/4/4.
//

#ifndef C14_MYSAT_H
#define C14_MYSAT_H
#include "RBTree.h"

namespace l
{
    template<class K>
    class sat
    {
        struct satKeyOfT
        {
            K operator()( const K& k ) const
            {
                return k;
            }
        };

    public:
        //                                               const K 保证kye不能被修改
        typedef typename RBTree <K, const K, satKeyOfT>::Iterator iterator;
        typedef typename RBTree <K, const K, satKeyOfT>::ConstIterator const_iterator;

        iterator begin()
        {
            return _t.Begin();
        }
        iterator end()
        {
            return _t.End();
        }
        const_iterator begin() const
        {
            return _t.Begin();
        }
        const_iterator end() const
        {
            return _t.End();
        }

        bool insert( const K& k )
        {
            return _t.Insert(k);
        }

    private:
        RBTree <K, const K, satKeyOfT> _t;
    };
}
#endif //C14_MYSAT_H
