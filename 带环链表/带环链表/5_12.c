#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * quick;
    int L1, L2;
    L1 = L2 = 0;
    slow = quick = head;
    while (quick && quick->next)
    {
        slow = slow->next;
        quick = quick->next->next;
        L1++;
        if (slow == quick)
        {
            L1++;
            struct ListNode* newhead = slow->next;
            slow = slow->next;
            quick->next = NULL;

            while (slow)
            {
                slow = slow->next;
                L2++;
            }
            int divalue = L1 > L2 ? L1 - L2 : L2 - L1;
            struct ListNode* shorts = head, * longs = newhead;
            if (L1 > L2)
            {
                shorts = newhead;
                longs = head;
            }
            while (divalue--)
                longs = longs->next;
            while (shorts && longs && shorts != longs)
            {
                shorts = shorts->next;
                longs = longs->next;
            }
            quick->next = newhead;
            return shorts;
        }
    }
    return NULL;
}
int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 1;
    n2->val = 2;
    n1->next = n2;
    n2->next = n1;
    detectCycle(n1);
	return 0;
}