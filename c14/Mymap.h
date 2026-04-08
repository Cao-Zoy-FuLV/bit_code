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
        typedef typename RBTree <K, pair <const K, V>, mapKeyOfT>::Const_Iterator const_iterator;

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

        pair <iterator, bool> insert( const pair <K, V>& kv )
        {
            return _t.Insert(kv);
        }

        V& operator[]( const K& k )
        {
            // insert 实现具有插入和修改的功能
            pair <iterator, bool> ret = insert({ (k, V()) });
            return ret.first->second;
        }

    private:
        RBTree <K, pair <const K, V>, mapKeyOfT> _t;
    };
}
#endif //C14_MYMAP_H
