//
// Created by Administrator on 2025/12/5.
//

#include <cstddef>
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        //相遇
        if (slow == fast)
        {
            struct ListNode* meet = slow;
            while (meet != fast)
            {
                meet = meet->next;
                head = head->next;
            }
            return meet;
        }
    }
    return NULL;
}

/*
 *  head 到环入口 距离设 L
 *  相遇点（meet）到环 距离设 N
 *  环的周长设C
 *  相遇时
 *  slow 路程 ：L + N
 *  fast 路程 ：L + x*C + N (x至少为1)
 *
 *  fast走的路程为slow的2倍
 *  2*（L+N）= L + x*C + N
 *  L = (x-1)*C + C - N
 */
