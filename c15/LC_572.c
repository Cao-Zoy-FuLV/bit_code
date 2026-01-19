//
// Created by Administrator on 2026/1/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>


/*给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。*/
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (!root && !subRoot)
    {
        return true;
    }
    if (!root || !subRoot)
    {
        return false;
    }
    return root->val == subRoot->val
        && isSameTree(root->left, subRoot->left)
        && isSameTree(root->right, subRoot->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (!root)
    {
        return false;
    }
    if (root->val == subRoot->val && isSameTree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}

int main()
{
    return 0;
}
