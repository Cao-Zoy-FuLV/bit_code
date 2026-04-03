//
// Created by Administrator on 2026/3/31.
//
#ifndef C14_AVLTREE_H
#define C14_AVLTREE_H
#include <cassert>
#include <iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
    // 需要parent指针，后续更新平衡因子可以看到
    pair <K, V> _kv;
    AVLTreeNode <K, V>* _left;
    AVLTreeNode <K, V>* _right;
    AVLTreeNode <K, V>* _parent;
    int _bf; // balance factor（平衡因子）
    AVLTreeNode( const pair <K, V>& kv )
        : _kv(kv)
        , _left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
        , _bf(0) {}
};

template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode <K, V> Node;

public:
    /*
    更新原则
        1、平衡因子=右子树高度-左子树高度
        2、只有子树高度变化才会影响当前结点平衡因子
        3、增右子树，parent的平衡因子++ 增左子树，parent的平衡因子--
        4、parent所在子树的高度是否变化决定了是否会继续往上更新
    停止条件
        1、更新后parent的平衡因子等于 0 ，更新中parent的平衡因子变化为-1->0 或者 1->0 更新结束
        2、更新后parent的平衡因子等于 1 或 -1，更新前更新中parent的平衡因子变化为0->1 或者 0->-1，parent向上更新
        3、更新后parent的平衡因子等于 2 或 -2，更新前更新中parent的平衡因子变化为1->2 或者 -1->-2，旋转
     */
    bool Insert( const pair <K, V>& kv )
    {
        if ( _root == nullptr )
        {
            _root = new Node(kv);
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
        // 更新平衡因子
        while ( parent )
        {
            if ( cur == parent->_left )
                // + 左 --
                --parent->_bf;
            else
                //+ 右 ++
                ++parent->_bf;

            if ( parent->_bf == 0 )
            {
                // 更新结束
                break;
            }
            else if ( parent->_bf == 1 || parent->_bf == -1 )
            {
                // 继续往上更新
                cur = parent;
                parent = parent->_parent;
            }
            else if ( parent->_bf == 2 || parent->_bf == -2 )
            {
                // 不平衡了，旋转处理
                if ( parent->_bf == -2 && cur->_bf == -1 )
                {
                    RotateR(parent);
                }
                else if ( parent->_bf == 2 && cur->_bf == 1 )
                {
                    RotateL(parent);
                }
                else if ( parent->_bf == -2 && cur->_bf == 1 )
                {
                    RotateLR(parent);
                }
                else if ( parent->_bf == 2 && cur->_bf == -1 )
                {
                    RotateRL(parent);
                }
                else
                    assert(false);
                break;
            }
            else
                assert(false);
        }
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
        parent->_bf = subL->_bf = 0;
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
        parent->_bf = subR->_bf = 0;
    }
    // 左右双旋
    void RotateLR( Node* parent )
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        RotateL(subL);
        RotateR(parent);

        if ( bf == -1 )
        {
            parent->_bf = 1;
            subLR->_bf = 0;
            subL->_bf = 0;
        }
        else if ( bf == 1 )
        {
            parent->_bf = 0;
            subLR->_bf = 0;
            subL->_bf = -1;
        }
        else if ( bf == 0 )
        {
            parent->_bf = 0;
            subLR->_bf = 0;
            subL->_bf = 0;
        }
        else
        {
            assert(false);
        }
    }
    // 右左双旋
    void RotateRL( Node* parent )
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        RotateR(subR);
        RotateL(parent);

        if ( bf == -1 )
        {
            subR->_bf = 1;
            subRL->_bf = 0;
            parent->_bf = 0;
        }
        else if ( bf == 1 )
        {
            subR->_bf = 0;
            subRL->_bf = 0;
            parent->_bf = -1;
        }
        else if ( bf == 0 )
        {
            subRL->_bf = 0;
            subR->_bf = 0;
            parent->_bf = 0;
        }
        else
        {
            assert(false);
        }
    }

    // 和红黑树一样
    void InOrder()
    {
        InOrder(_root);
        std::cout << endl;;
    }

    bool IsBalanceTree()
    {
        return IsBalanceTree_imp(_root);
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

private:
    void InOrder( Node* root )
    {
        if ( root )
        {
            InOrder(root->_left);
            cout << root->_kv.first << " :" << root->_kv.second << "平衡因子" << root->_bf << endl;
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
    //平衡判断
    bool IsBalanceTree_imp( Node* root )
    {
        // 空树也是AVL树
        if ( nullptr == root ) return true;
        // 计算pRoot结点的平衡因子：即pRoot左右子树的高度差
        int leftHeight = Height_imp(root->_left);
        int rightHeight = Height_imp(root->_right);
        int diff = rightHeight - leftHeight;
        // 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
        // pRoot平衡因子的绝对值超过1，则一定不是AVL树
        if ( abs(diff) >= 2 )
        {
            // cout << root->_kv.first << "高度差异常" << endl;
            return false;
        }
        if ( root->_bf != diff )
        {
            cout << root->_kv.first << "平衡因子异常" << endl;
            return false;
        }
        // pRoot的左和右如果都是AVL树，则该树一定是AVL树
        return IsBalanceTree_imp(root->_left) && IsBalanceTree_imp(root->_right);
    }

private:
    Node* _root = nullptr;
};
#endif //C14_AVLTREE_H
