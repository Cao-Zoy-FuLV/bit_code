//
// Created by Administrator on 2026/4/4.
//

#ifndef C14_MYMAP_H
#define C14_MYMAP_H

#include "RBTree.h"

namespace l
{
    template<class K, class V>
    class map
    {
        struct mapKeyOfT
        {
            const K& operator()( const pair <K, V>& kv ) const
            {
                return kv.first;
            }
        };

    public:
        typedef typename RBTree <K, pair <const K, V>, mapKeyOfT>::Iterator iterator;
        typedef typename RBTree <K, pair <const K, V>, mapKeyOfT>::ConstIterator const_iterator;

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

        bool insert( const pair <K, V>& kv )
        {
            return _t.Insert(kv);
        }

    private:
        RBTree <K, pair <const K, V>, mapKeyOfT> _t;
    };
}
#endif //C14_MYMAP_H
