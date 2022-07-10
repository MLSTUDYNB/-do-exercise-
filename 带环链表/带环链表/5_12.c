#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow, * quick;
//    int L1, L2;
//    L1 = L2 = 0;
//    slow = quick = head;
//    while (quick && quick->next)
//    {
//        slow = slow->next;
//        quick = quick->next->next;
//        L1++;
//        if (slow == quick)
//        {
//            L1++;
//            struct ListNode* newhead = slow->next;
//            slow = slow->next;
//            quick->next = NULL;
//
//            while (slow)
//            {
//                slow = slow->next;
//                L2++;
//            }
//            int divalue = L1 > L2 ? L1 - L2 : L2 - L1;
//            struct ListNode* shorts = head, * longs = newhead;
//            if (L1 > L2)
//            {
//                shorts = newhead;
//                longs = head;
//            }
//            while (divalue--)
//                longs = longs->next;
//            while (shorts && longs && shorts != longs)
//            {
//                shorts = shorts->next;
//                longs = longs->next;
//            }
//            quick->next = newhead;
//            return shorts;
//        }
//    }
//    return NULL;
//}
struct ListNode* BuyNodeList(int x)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}


void ListpushBack(struct ListNode** phead,int x)
{
    struct ListNode* newnode = BuyNodeList(x);
    struct ListNode* cur = *phead;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = newnode;
}
void f(struct ListNode* head, int n, int k)
{
    struct ListNode* newnode = BuyNodeList(k);
    while (--n)
    {
        head = head->next;
    }
    struct ListNode* cur = head->next;
    head->next = newnode;
    newnode->next = cur;

}
void print(struct ListNode* head)
{
    struct ListNode* cur = head;
    while (cur)
    {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}
int main()
{

    struct ListNode* head= BuyNodeList(1);

    ListpushBack(&head, 2);
    ListpushBack(&head, 3);
    ListpushBack(&head, 4);
    ListpushBack(&head, 5);
    print(head);
    f(head, 3, 0);
    print(head);
	return 0;
}