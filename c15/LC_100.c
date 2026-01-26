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

/*给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。*/


bool isSameTree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    if (root == NULL || subRoot == NULL)
    {
        return false;
    }
    if (root->val != subRoot->val)
    {
        return false;
    }
    return isSameTree(root->left, subRoot->left) &&
            isSameTree(root->right, subRoot->right);
}

int main0()
{
    return 0;
}
