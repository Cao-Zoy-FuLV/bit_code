//
// Created by Administrator on 2026/4/3.
//

#ifndef C14_RBTREE_H
#define C14_RBTREE_H

#include <cassert>
#include <iostream>
using namespace std;

// 枚举值表示颜色
enum Colour
{
    RED,
    BLACK
};

// 这里我们默认按key/value结构实现
template<class T>
struct RBTreeNode
{
    T _data;
    RBTreeNode <T>* _left;
    RBTreeNode <T>* _right;
    RBTreeNode <T>* _parent;
    Colour _col;
    RBTreeNode( const T& data )
        : _data(data)
        , _left(nullptr)
        , _right(nullptr)
        , _parent(nullptr) {}
};

template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
    typedef RBTreeNode <T> Node;
    typedef RBTreeIterator <T, Ref, Ptr> Self;
    Node* _node;
    Node* _root;
    RBTreeIterator( Node* node, Node* root )
        : _node(node)
        , _root(root) {}

    ///关键代码1
    Self& operator++()
    {
        if ( _node->_right )
        {
            // 右不为空，右子树最左结点就是中序第一个
            Node* min = _node->_right;
            while ( min->_left )
            {
                min = min->_left;
            }
            _node = min;
        }
        else
        {
            // 孩子是父亲左的祖先
            Node* cur = _node;
            Node* parent = cur->_parent;
            while ( parent && cur == parent->_right )
            {
                cur = parent;
                parent = cur->_parent;
            }
            _node = parent;
        }
        return *this;
    }
    ///关键代码2
    Self& operator--()
    {
        if ( _node == nullptr ) // end()
        {
            // --end()，特殊处理，走到中序最后一个结点，整棵树的最右结点
            Node* rightMost = _root;
            while ( rightMost && rightMost->_right )
            {
                rightMost = rightMost->_right;
            }
            _node = rightMost;
        }
        else if ( _node->_left )
        {
            // 左子树不为空，中序左子树最后一个
            Node* rightMost = _node->_left;
            while ( rightMost->_right )
            {
                rightMost = rightMost->_right;
            }
            _node = rightMost;
        }
        else
        {
            // 孩子是父亲右的祖先
            Node* cur = _node;
            Node* parent = cur->_parent;
            while ( parent && cur == parent->_left )
            {
                cur = parent;
                parent = cur->_parent;
            }
            _node = parent;
        }
        return *this;
    }
    Ref operator*()
    {
        return _node->_data;
    }
    Ptr operator->()
    {
        return &_node->_data;
    }
    bool operator!=( const Self& s ) const
    {
        return _node != s._node;
    }
    bool operator==( const Self& s ) const
    {
        return _node == s._node;
    }
};

template<class K, class T, class KeyOft>
class RBTree
{
    typedef RBTreeNode <T> Node;

public:
    RBTree() = default;
    ~RBTree()
    {
        Destroy(_root);
        _root = nullptr;
    }
    typedef RBTreeIterator <T, T&, T*> Iterator;
    typedef RBTreeIterator <T, const T&, const T*> Const_Iterator;

    Iterator Begin()
    {
        Node* cur = _root;
        while ( cur && cur->_left )
        {
            cur = cur->_left;
        }
        return Iterator(cur, _root);
    }
    Iterator End()
    {
        return Iterator(nullptr, _root);
    }
    Const_Iterator Begin() const
    {
        Node* leftMost = _root;
        while ( leftMost && leftMost->_left )
        {
            leftMost = leftMost->_left;
        }
        return ConstIterator(leftMost, _root);
    }
    Const_Iterator End() const
    {
        return ConstIterator(nullptr, _root);
    }


    ////插入代码
    pair <Iterator, bool> Insert( const T& data )
    {
        if ( _root == nullptr )
        {
            _root = new Node(data);
            _root->_col = BLACK;
            // return pair <Iterator, bool>(Iterator(_root,_root), true);
            return { Iterator(_root, _root), true };
        }

        KeyOft kot;
        Node* parent = nullptr;
        Node* cur = _root;

        while ( cur )
        {
            if ( kot(cur->_data) < kot(data) )
            {
                parent = cur;
                cur = cur->_right;
            }
            else if ( kot(cur->_data) > kot(data) )
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return { Iterator(cur, _root), false };
            }
        }
        cur = new Node(data);
        Node* newcur = cur;
        cur->_col = RED;
        if ( kot(parent->_data) < kot(data) )
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        //连接父节点
        cur->_parent = parent;

        //如果父节点是红色，则需要处理
        while ( parent && parent->_col == RED )
        {
            Node* grandfather = parent->_parent;
            if ( parent == grandfather->_left )
            {
                //如果父节点是左节点
                //      g
                //  p       u
                Node* uncle = grandfather->_right;
                //并且叔节点是红色、就把父节点和叔节点变黑，祖父节点变红
                if ( uncle && uncle->_col == RED )
                {
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;

                    // 继续向上处理
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else
                {
                    // u存在且为黑或不存在 ->旋转+变色
                    if ( cur == parent->_left )
                    {
                        //          g
                        //      p       u
                        //  c
                        //右单旋
                        RotateR(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else
                    {
                        //          g
                        //      p       u
                        //         c
                        //左右双旋
                        RotateL(parent);
                        RotateR(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;
                }
            }
            else
            {
                //如果父节点是右节点
                //      g
                //  u       p
                Node* uncle = grandfather->_left;
                // 叔叔存在且为红变色即可
                if ( uncle && uncle->_col == RED )
                {
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;

                    // 继续往上处理
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else // 叔叔不存在，或者存在且为黑
                {
                    // 情况二：叔叔不存在或者存在且为黑
                    // 旋转+变色
                    // g
                    // u p
                    // c
                    if ( cur == parent->_right )
                    {
                        RotateL(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else
                    {
                        //       g
                        //  u        p
                        //      c
                        RotateR(parent);
                        RotateL(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;
                }
            }
        }

        _root->_col = BLACK;//暴力处理
        return { Iterator(newcur, _root), true };
    }

    // 右单旋
    void RotateR( Node* parent )
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        parent->_left = subLR;//核心步骤1
        if ( subLR )
        {
            subLR->_parent = parent;
        }


        // parent有可能是整棵树的根，也可能是局部的子树
        // 如果是整棵树的根，要修改_root
        // 如果是局部的指针要跟上一层链接
        Node* pParent = parent->_parent;
        subL->_right = parent;//核心步骤2
        parent->_parent = subL;

        if ( pParent == nullptr )
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else
        {
            if ( pParent->_left == parent )
            {
                pParent->_left = subL;
            }
            else
            {
                pParent->_right = subL;
            }
            subL->_parent = pParent;
        }
    }
    // 左单旋
    void RotateL( Node* parent )
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        parent->_right = subRL;
        if ( subRL )
        {
            subRL->_parent = parent;
        }

        Node* pParent = parent->_parent;
        subR->_left = parent;
        parent->_parent = subR;

        if ( pParent == nullptr )
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else
        {
            if ( pParent->_left == parent )
            {
                pParent->_left = subR;
            }
            else
            {
                pParent->_right = subR;
            }
            subR->_parent = pParent;
        }
    }

    int Height()
    {
        return Height_imp(_root);
    }
    int Size()
    {
        return Size_imp(_root);
    }
    Node* Find( const K& key )
    {
        Node* cur = _root;
        while ( cur )
        {
            if ( cur->_kv.first < key )
            {
                cur = cur->_right;
            }
            else if ( cur->_kv.first > key )
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }

    /*
     bool IsBalance()
    {
        if ( _root == nullptr ) return true;
        if ( _root->_col == RED ) return false;
        // 参考值
        int refNum = 0;
        Node* cur = _root;
        while ( cur )
        {
            if ( cur->_col == BLACK )
            {
                ++refNum;
            }
            cur = cur->_left;
        }
        return Check(_root, 0, refNum);
    }
    void InOrder()
    {
        InOrder(_root);
        std::cout << endl;;
    }
*/

private:
    /*
     void InOrder( Node* root )
    {
        if ( root )
        {
            InOrder(root->_left);
            cout << root->_kv.first << " ：" << root->_kv.second << "   col->" << (root->_col == 1 ? "RED" : "BLACK") << endl;
            InOrder(root->_right);
        }
    }
    */
    int Size_imp( Node* root )
    {
        if ( root == nullptr ) return 0;
        return Size_imp(root->_left) + Size_imp(root->_right) + 1;
    }
    //树高度
    int Height_imp( Node* root )
    {
        if ( root == nullptr ) return 0;
        int leftHeight = Height_imp(root->_left);
        int rightHeight = Height_imp(root->_right);
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
    /*
    // 红黑树的验证
    bool Check( Node* root, int blackNum, const int refNum )
    {
        if ( root == nullptr )
        {
            // 前序遍历走到空时，意味着一条路径走完了
            //cout << blackNum << endl;
            if ( refNum != blackNum )
            {
                cout << "存在黑色结点的数量不相等的路径" << endl;
                return false;
            }
            return true;
        }
        // 检查孩子不太方便，因为孩子有两个，且不一定存在，反过来检查父亲就方便多了
        if ( root->_col == RED && root->_parent->_col == RED )
        {
            cout << root->_kv.first << "存在连续的红色结点" << endl;
            return false;
        }
        if ( root->_col == BLACK )
        {
            blackNum++;
        }
        return Check(root->_left, blackNum, refNum) && Check(root->_right, blackNum, refNum);
    }
    */
    void Destroy( Node* root )
    {
        if ( root == nullptr ) return;
        Destroy(root->_left);
        Destroy(root->_right);
        delete root;
    }

private:
    Node* _root = nullptr;
};

#endif //C14_RBTREE_H
