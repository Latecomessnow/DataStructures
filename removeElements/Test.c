#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;
    struct ListNode* tail = newhead;
    newhead->next = NULL;
    while (cur)
    {
        if (cur->val != val)
        {
            tail->next = cur;
            tail = cur;
        }
        cur = cur->next;
    }
    //×¢ÒâÎ²ÒªÖÃ¿Õ
    tail->next = NULL;
    struct ListNode* list = newhead->next;
    free(newhead);
    return list;
}