//
// Created by Administrator on 2026/4/6.
//

#ifndef C14_HASHTABLE_H
#define C14_HASHTABLE_H
#include <iostream>
#include <list>

namespace l
{
    namespace open_address
    {
        enum State
        {
            EXIST,
            EMPTY,
            DELETE
        };

        template<class K, class V>
        struct HashData
        {
            pair <K, V> _kv;
            State _state = EMPTY;
        };

        template<class K>
        struct HashFunc
        {
            unsigned long operator()( const K& key )
            {
                return key;
            }
        };

        // BKDTR_Hash 哈希函数
        template<>
        struct HashFunc <string>
        {
            size_t operator()( const string& s )
            {
                size_t hash = 0;
                for ( auto& e : s )
                {
                    hash *= 131;
                    hash += e;
                }
                return hash;
            }
        };

        template<class K, class V, class Hash=HashFunc <K>>
        class HashTable
        {
        public:
            HashTable()
                : _tables(__stl_next_prime(0))
              , _n(0) {}

            inline unsigned long __stl_next_prime( unsigned long n )
            {
                // Note: assumes long is at least 32 bits.
                static const int __stl_num_primes = 28;
                static const unsigned long __stl_prime_list[__stl_num_primes] = {
                53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157,
                98317, 196613, 393241, 786433, 1572869, 3145739, 6291469,
                12582917, 25165843, 50331653, 100663319, 201326611,
                402653189, 805306457, 1610612741, 3221225473, 4294967291
                };
                const unsigned long* first = __stl_prime_list;
                const unsigned long* last = __stl_prime_list + __stl_num_primes;
                const unsigned long* pos = lower_bound(first, last, n);
                return pos == last ? *(last - 1) : *pos;
            }

            bool Insert( const pair <K, V>& kv )
            {
                if ( Find(kv.first) )
                    return false;

                //负载因子>=0.7就扩容
                if ( _n * 10 / _tables.size() >= 7 )
                {
                    // 扩容逻辑：通常扩容为原来的2倍或寻找下一个质数
                    HashTable <K, V, Hash> newHt;
                    newHt._tables.resize(__stl_next_prime(_tables.size() + 1));
                    // 将旧数据重新哈希插入到新表中
                    for ( auto& data : _tables )
                    {
                        if ( data._state == EXIST )
                        {
                            newHt.Insert(data._kv);
                        }
                    }
                    // 交换新旧表
                    _tables.swap(newHt._tables);
                    _n = newHt._n; // 更新元素个数，虽然Insert中已经增加，但这里为了保持新表状态一致，直接赋值新表的n（注意：newHt._n在Insert过程中已经累加）
                    // 注意：上面的swap后，_tables变成了新的，_n应该等于新表中实际存在的元素个数。
                    // 由于我们是遍历旧表Insert到新表，newHt._n就是旧表中EXIST的数量，也就是当前的_n。
                    // 所以 _n 保持不变即可，或者显式赋值 _n = newHt._n;
                }

                Hash hash;
                size_t hash0 = hash(kv.first) % _tables.size();
                size_t hashi = hash0;
                size_t i = 1;
                int flag = 1;
                while ( _tables[hashi]._state == EXIST )
                {
                    //线性探测
                    hashi = (hash0 + i) % _tables.size();
                    ++i;

                    //二次探测
                    /*
                    hashi = (hash0 + flag(i * i)) % _tables.size();
                    if ( hashi < _tables.size() ) hashi += _tables.size();
                    if ( flag == 1 ) flag = -1;
                    else{++i;flag = 1;
                    }*/
                }
                _tables[hashi]._kv = kv;
                _tables[hashi]._state = EXIST;
                ++_n;

                return true;
            }
            HashData <K, V>* Find( const K& key )
            {
                Hash hash;
                size_t hash0 = hash(key) % _tables.size();
                size_t hashi = hash0;
                size_t i = 1;
                while ( _tables[hashi]._state != EMPTY )
                {
                    if ( _tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key )
                    {
                        return &_tables[hashi];
                    }
                    // 线性探测
                    hashi = (hash0 + i) % _tables.size();

                    ++i;
                }
                return nullptr;
            }
            bool Erase( const K& key )
            {
                HashData <K, V>* ret = Find(key);
                if ( ret == nullptr )
                {
                    return false;
                }
                else
                {
                    ret->_state = DELETE;
                    --_n;
                    return true;
                }
            }

        private :
            vector <HashData <K, V>> _tables{};
            size_t _n = 0; // 表中存储数据个数
        };
    }

    namespace hash_bucket
    {
        template<class K, class V>
        struct HashNode
        {
            pair <K, V> _kv;
            HashNode <K, V>* _next;
            HashNode( const pair <K, V>& kv )
                : _kv(kv)
              , _next(nullptr) {}
        };

        template<class K>
        struct HashFunc
        {
            unsigned long operator()( const K& key )
            {
                return key;
            }
        };

        template<>
        struct HashFunc <string>
        {
            unsigned long operator()( const string& key )
            {
                unsigned long hash = 0;
                for ( auto& c : key )
                {
                    hash = hash * 131 + c;
                }
                return hash;
            }
        };

        template<class K, class V, class Hash = HashFunc <K>>
        class HashTable
        {
            typedef HashNode <K, V> Node;
            inline unsigned long __stl_next_prime( unsigned long n )
            {
                static const int __stl_num_primes = 28;
                static const unsigned long __stl_prime_list[__stl_num_primes] =
                {
                53, 97, 193, 389, 769,
                1543, 3079, 6151, 12289, 24593,
                49157, 98317, 196613, 393241, 786433,
                1572869, 3145739, 6291469, 12582917, 25165843,
                50331653, 100663319, 201326611, 402653189, 805306457,
                1610612741, 3221225473, 4294967291
                };

                const unsigned long* first = __stl_prime_list;
                const unsigned long* last = __stl_prime_list +
                                            __stl_num_primes;
                const unsigned long* pos = lower_bound(first, last, n);
                return pos == last ? *(last - 1) : *pos;
            }

        public:
            HashTable()
                : _tables(__stl_next_prime(0), nullptr)
              , _n(0) {}
            // 拷贝构造和赋值拷贝需要实现深拷贝
            HashTable( const HashTable& ht )
                : _tables(ht._tables.size(), nullptr)
              , _n(0)
            {
                // 遍历源表的每个桶，深拷贝节点
                for ( size_t i = 0; i < ht._tables.size(); i++ )
                {
                    Node* cur = ht._tables[i];
                    while ( cur )
                    {
                        // 创建新节点并插入到当前表
                        Insert(cur->_kv);
                        cur = cur->_next;
                    }
                }
            }
            //赋值拷贝
            HashTable& operator=( const HashTable& ht )
            {
                if ( this != &ht )
                {
                    // 先释放原有资源
                    this->~HashTable();

                    // 重新初始化
                    _tables.resize(ht._tables.size(), nullptr);
                    _n = 0;

                    // 深拷贝所有节点
                    for ( size_t i = 0; i < ht._tables.size(); i++ )
                    {
                        Node* cur = ht._tables[i];
                        while ( cur )
                        {
                            Insert(cur->_kv);
                            cur = cur->_next;
                        }
                    }
                }
                return *this;
            }
            ~HashTable()
            {
                // 依次把每个桶释放
                for ( size_t i = 0; i < _tables.size(); i++ )
                {
                    Node* cur = _tables[i];
                    while ( cur )
                    {
                        Node* next = cur->_next;
                        delete cur;
                        cur = next;
                    }
                    _tables[i] = nullptr;
                }
            }
            bool Insert( const pair <K, V>& kv )
            {
                Hash hs;
                size_t hashi = hs(kv.first) % _tables.size();
                // 负载因子==1扩容
                if ( _n == _tables.size() )
                {
                    /*HashTable<K, V> newHT;
                    newHT._tables.resize(__stl_next_prime(_tables.size()+1);
                    for (size_t i = 0; i < _tables.size(); i++)
                    {
                    Node* cur = _tables[i];
                    while(cur)
                    {
                    
                    newHT.Insert(cur->_kv);
                    cur = cur->_next;
                    }
                    }
                    _tables.swap(newHT._tables);
                    */
                    // 这里如果使用上面的方法，扩容时创建新的结点，后面还要使用就结点，浪费了

                    // 下面的方法，直接移动旧表的结点到新表，效率更好
                    vector <Node*>
                            newtables(__stl_next_prime(_tables.size() + 1), nullptr);
                    for ( size_t i = 0; i < _tables.size(); i++ )
                    {
                        Node* cur = _tables[i];
                        while ( cur )
                        {
                            Node* next = cur->_next;
                            // 旧表中节点，挪动新表重新映射的位置
                            size_t hashi = hs(cur->_kv.first) %
                                           newtables.size();
                            // 头插到新表
                            cur->_next = newtables[hashi];
                            newtables[hashi] = cur;
                            cur = next;
                        }
                        _tables[i] = nullptr;
                    }
                    _tables.swap(newtables);
                }
                // 头插
                Node* newnode = new Node(kv);
                newnode->_next = _tables[hashi];
                _tables[hashi] = newnode;
                ++_n;
                return true;
            }
            Node* Find( const K& key )
            {
                Hash hs;
                size_t hashi = hs(key) % _tables.size();

                Node* cur = _tables[hashi];
                while ( cur )
                {
                    if ( cur->_kv.first == key )
                    {
                        return cur;
                    }
                    cur = cur->_next;
                }
                return nullptr;
            }
            bool Erase( const K& key )
            {
                Hash hs;
                size_t hashi = hs(key) % _tables.size();
                Node* prev = nullptr;
                Node* cur = _tables[hashi];
                while ( cur )
                {
                    if ( cur->_kv.first == key )
                    {
                        if ( prev == nullptr )
                        {
                            _tables[hashi] = cur->_next;
                        }
                        else
                        {
                            prev->_next = cur->_next;
                        }
                        delete cur;
                        --_n;
                        return true;
                    }
                    prev = cur;
                    cur = cur->_next;
                }
                return false;
            }

        private:
            vector <Node*> _tables; // 指针数组
            size_t _n = 0; // 表中存储数据个数
        };
    }
}
#endif //C14_HASHTABLE_H
