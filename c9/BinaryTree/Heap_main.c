//
// Created by Administrator on 2026/1/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <minwindef.h>
#include <stdbool.h>

#include "Heap.c"
//    堆排序
void HeapSort(int a[], int n)
{
    //降序，建小堆
    //升序，建大堆

    //向下调整 O(n•logn)
    // for (int i = 0; i < n; ++i)
    // {
    //     Adjustup(a, i);
    // }

    //向上调整 O(n)
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        AdjustDwon(a, n, i);
    }

    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDwon(a, end, 0);
        --end;
    }
}

int main1()
{
    int a[] = {4, 2, 8, 1, 5, 6, 9, 7, 22, 333, 55555, 987, 44};
    /*
    HP ahp;
    HP_Init(&ahp);
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
    {
        HP_Push(&ahp, a[i]);
    }

    //找出最大/小的前k个
    int k;
    scanf("%d",&k);
    while (k--){printf("%d ",HP_Top(&ahp));HP_Pop(&ahp);}
    */

    HeapSort(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        printf("%d ", a[i]);
    }


    return 0;
}

//
void topK()
{
    int k;
    printf("请输入前k:");
    scanf("%d", &k);
    int* kminheap = (int*)malloc(k * sizeof(int));
    if (kminheap == NULL)
    {
        printf("malloc fail\n");
        return;
    }
    //打开文件
    FILE* fp = fopen("../data.txt", "r");
    if (fp == NULL)
    {
        printf("无法打开文件 ../data.txt\n");
        return;
    }
    for (int i = 0; i < k; ++i)
    {
        fscanf(fp, "%d", &kminheap[i]);
    }

    //创建k堆
    for (int i = (k - 2) / 2; i >= 0; i--)
    {
        AdjustDwon(kminheap, k, i);
    }
    //读取剩下的N-k个数
    int x = 0;
    while (fscanf(fp, "%d", &x) != EOF)
    {
        if (x > kminheap[0])
        {
            kminheap[0] = x;
            AdjustDwon(kminheap, k, 0);
        }
    }
    //输出"最大的前k个"
    printf("最大的前%d个:\n", k);
    for (int i = 0; i < k; ++i)
    {
        printf("%d ", kminheap[i]);
    }
}

int main2()
{
    topK();
    return 0;
}

typedef int BTDataType;

typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BTNode;

BTNode* BuyNode(int x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->data = x;
    node->left = node->right = NULL;
}

BTNode* BT_Create()
{
    BTNode* node1 = BuyNode(1);
    BTNode* node2 = BuyNode(2);
    BTNode* node3 = BuyNode(3);
    BTNode* node4 = BuyNode(4);
    BTNode* node5 = BuyNode(5);
    BTNode* node6 = BuyNode(6);
    BTNode* node7 = BuyNode(7);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;
    node5->left = node7;

    return node1;
}

/*      1
     2    4
   3    5   6
*/

void PrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

//求二叉树节点个数
int TreeSize(BTNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//求二叉树节点个数
int TreeLeafSize(BTNode* root)
{
    return root == NULL ? 0 : root->left == NULL && root->right == NULL ? 1 : TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//求二叉树高度
int TreeHeight(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = TreeHeight(root->left);
    int right = TreeHeight(root->right);
    return left > right ? left + 1 : right + 1;
}

//求第k层的节点个数
int TreeLevel(BTNode* root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }
    int left = TreeLevel(root->left, k - 1);
    int right = TreeLevel(root->right, k - 1);
    return left + right;
}

//单值二叉树
bool isUnivalTree(BTNode* root)
{
    if (root == NULL)
    {
        return true;
    }
    int left = isUnivalTree(root->left);
    int right = isUnivalTree(root->right);
    return left && right &&
        (root->left == NULL || root->left->data == root->data) &&
        (root->right == NULL || root->right->data == root->data);
}

BTNode* Find(BTNode* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        return root;
    }
    BTNode* left = Find(root->left, x);
    if (left)
    {
        return left;
    }
    BTNode* right = Find(root->right, x);
    if (right)
    {
        return right;
    }
    return NULL;
}

//层序遍历 BFS（广度优先搜索）
#include "Queue.c"

void LevelOrder(BTNode* root)
{
    Queue q;
    Queue_init(&q);
    if (root)
    {
        Queue_push(&q, root);
    }
    while (!Queue_empty(&q))
    {
        BTNode* node = Queue_front(&q);
        printf("%d ", node->data);
        Queue_pop(&q);
        if (node->left)
        {
            Queue_push(&q, node->left);
        }
        if (node->right)
        {
            Queue_push(&q, node->right);
        }
    }
    Queue_destroy(&q);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
    Queue q;
    Queue_init(&q);
    if (root)
    {
        Queue_push(&q, root);
    }
    while (!Queue_empty(&q))
    {
        BTNode* node = Queue_front(&q);
        Queue_pop(&q);
        if (node == NULL)
        {
           break;
        }
        Queue_push(&q, node->left);
        Queue_push(&q, node->right);
    }
    while (!Queue_empty(&q))
    {
        BTNode* node = Queue_front(&q);
        if (node)
        {
            printf("不是完全二叉树\n");
            return 0;
        }
        Queue_pop(&q);
    }
    Queue_destroy(&q);
    return true ;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
    if (*root == NULL)
    {
        return;
    }
    BinaryTreeDestory(&(*root)->left);
    BinaryTreeDestory(&(*root)->right);
    free(*root);
    *root = NULL;
}


int main0()
{
    BTNode* root = BT_Create();
    printf("前序遍历:");
    PrevOrder(root);
    printf("\n中序遍历:");
    InOrder(root);
    printf("\n层序遍历:");
    LevelOrder(root);
    printf("\n树节点个数: %d\n", TreeSize(root));
    printf("树叶子节点个数: %d\n", TreeLeafSize(root));
    printf("树高度: %d\n", TreeHeight(root));
    int k = 4;
    printf("第%d层: %d\n", k, TreeLevel(root, k));
    printf("单值二叉树: %d\n", isUnivalTree(root));
    printf("查找节点: %d\n", Find(root, 5)->data);
    printf("是否是完全二叉树: ");BinaryTreeComplete(root);
    return 0;
}
