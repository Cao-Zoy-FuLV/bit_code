#include <bits/stdc++.h>
using namespace std;

/*
*给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

返回复制链表的头节点。

用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。
 */
struct Node
{
    int val;
    struct Node* next;
    struct Node* random;
};

void ca(struct Node* head, struct Node* a)
{
    struct Node* h = head;
    while (h->next)
    {
        h = h->next;
    }
    h->next = a;
}

int bl(struct Node* head)
{
    struct Node* h = head;
    int a = 1;
    while (h->next)
    {
        std::cout << h->val << " ";
        std::cout << h->next << " ";
        std::cout << h->random << " /_  ";

        h = h->next;
        a++;
    }
    std::cout << h->val << " ";
    std::cout << h->next << " ";
    std::cout << h->random << " ///\n";
    return a;
}

struct Node* copyRandomList(struct Node* head)
{
    struct Node *h2 = head, *h = head;
    struct Node* z = (struct Node*)malloc(sizeof(struct Node));
    if (z != NULL)
    {
        z->val = 0;
        z->next = NULL;
        z->random = NULL;
    }
    int a = bl(head);
    // cout << "旧链表长度" << a << "\n";
    for (int i = 0; i < a; i++)
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        if (node != NULL)
        {
            node->val = h->val;
            node->next = h->next;
            node->random = NULL;
            h->next = node;
            h = node->next;
        }
    }
    int b = bl(head);
    //设置random指针
    h = head;
    while (h != NULL) {
        if (h->random != NULL) {
            h->next->random = h->random->next;
        }
        h = h->next->next;
    }

    h = head;
    struct Node* newHead = head->next;
    struct Node* newCurr = newHead;

    while (h != NULL && newCurr != NULL) {
        h->next = h->next->next;
        h = h->next;

        if (h != NULL) {
            newCurr->next = h->next;
            newCurr = newCurr->next;
        }
    }

    return newHead;
}

int main()
{
    struct Node* haed = (struct Node*)malloc(sizeof(struct Node));
    struct Node* haed1 = (struct Node*)malloc(sizeof(struct Node));
    if (haed1 != NULL)
    {
        haed1->val = 2;
        haed1->next = NULL;
        haed1->random = haed1;
    }
    if (haed != NULL)
    {
        haed->val = 1;
        haed->next = haed1;
        haed->random = haed1;
    }

    struct Node* z = copyRandomList(haed);
    bl(z);

    return 0;
}
