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
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
struct TreeNode {
         int val;
         struct TreeNode *left;
        struct TreeNode *right;
    };

bool isSymmetric_core(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    if (left->val != right->val)
    {
        return false;
    }
    return isSymmetric_core(left->left, right->right)&&
            isSymmetric_core(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    return isSymmetric_core(root->left, root->right);
}


int main0() {

    return 0;
}