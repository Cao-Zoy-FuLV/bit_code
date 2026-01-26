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
/*
 * 编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
 * 例如如下的先序遍历字符串： ABC##DE#G##F###
 * 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
 */

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* CreateTree(char* pre, int* index)
{
    if (pre[*index] == '#') {
        *index += 1;
        return NULL;
    }
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data =pre[(*index)++];
    node->left = CreateTree(pre, index);
    node->right = CreateTree(pre, index);
    return node;

}
void InOrder(TreeNode* root)
{
    if (root == NULL) {
        return;
    }
    InOrder(root->left);
    putchar(root->data);
    putchar(' ');
    InOrder(root->right);
}
int main0() {
    char pre[10];
    scanf("%s", pre);
    int index = 0;
    TreeNode* root = CreateTree(pre, &index);
    InOrder(root);
    return 0;
}