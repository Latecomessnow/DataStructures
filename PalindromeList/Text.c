#define _CRT_SECURE_NO_WARNINGS 1

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        if (A == NULL)
            return false;
        struct ListNode* fast, * slow;
        fast = slow = A;
        //快慢指针找到中间节点
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //找到中间节点slow后把中间节点后的链表进行逆置
        //逆置有两种方法，倒指向、头插
        //倒指向
        struct ListNode* n1, * n2, * n3;
        n1 = NULL;
        n2 = slow;
        n3 = n2->next;
        while (n2)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            //注意n3为空时就不需要动了，当n3为空时再执行n3 = n3->next，否则会造成空指针异常
            if (n3)
                n3 = n3->next;
        }
        //头插
//         struct ListNode* newHead = NULL;
//         while (slow)
//         {
//             struct ListNode* next = slow->next;
//             slow->next = newHead;
//             newHead = slow;
//             slow = next;
//         }
        struct ListNode* cur = A;
        //注意此n2已经指向空，n1才是指向头节点
        while (n1)
        {
            if (n1->val == cur->val)
            {
                n1 = n1->next;
                cur = cur->next;
            }
            else
                return false;
        }
        return true;
    }
};