#define _CRT_SECURE_NO_WARNINGS 1

*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 


struct ListNode* reverseList(struct ListNode* head) {
    //ͷ�巨
     struct ListNode* cur = head;
     struct ListNode* newhead = NULL;
     while (cur)
     {
         //ע��Ҫ����ԭ��cur->next��λ��
         struct ListNode* next = cur->next;
         cur->next = newhead;
         newhead = cur;
         cur = next;
     }
     return newhead;

    //��ָ��
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
}