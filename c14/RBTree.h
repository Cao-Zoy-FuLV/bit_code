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
template <class K, class V> struct RBTreeNode
{
    // 这里更新控制平衡也要加入parent指针
    pair <K, V> _kv;
    RBTreeNode <K, V>* _left;
    RBTreeNode <K, V>* _right;
    RBTreeNode <K, V>* _parent;
    Colour _col;
    RBTreeNode( const pair <K, V>& kv )
        : _kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr) {}
};

template <class K, class V> class RBTree
{
    typedef RBTreeNode <K, V> Node;

public:
    bool Insert( const pair <K, V>& kv )
    {
        if ( _root == nullptr )
        {
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }

        Node* parent = nullptr;
        Node* cur = _root;

        while ( cur )
        {
            if ( cur->_kv.first < kv.first )
            {
                parent = cur;
                cur = cur->_right;
            }
            else if ( cur->_kv.first > kv.first )
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }
        cur = new Node(kv);
        cur->_col = RED;
        if ( parent->_kv.first < kv.first )
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
        return true;
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
    // 和AVLR树一样
    void InOrder()
    {
        InOrder(_root);
        std::cout << endl;;
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
     
private:
    void InOrder( Node* root )
    {
        if ( root )
        {
            InOrder(root->_left);
            cout << root->_kv.first << " ：" << root->_kv.second << "   col->" << (root->_col == 1 ? "RED" : "BLACK") << endl;
            InOrder(root->_right);
        }
    }
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

private:
    Node* _root = nullptr;
};

#endif //C14_RBTREE_H
