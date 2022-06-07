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
        //����ָ���ҵ��м�ڵ�
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //�ҵ��м�ڵ�slow����м�ڵ��������������
        //���������ַ�������ָ��ͷ��
        //��ָ��
        struct ListNode* n1, * n2, * n3;
        n1 = NULL;
        n2 = slow;
        n3 = n2->next;
        while (n2)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            //ע��n3Ϊ��ʱ�Ͳ���Ҫ���ˣ���n3Ϊ��ʱ��ִ��n3 = n3->next���������ɿ�ָ���쳣
            if (n3)
                n3 = n3->next;
        }
        //ͷ��
//         struct ListNode* newHead = NULL;
//         while (slow)
//         {
//             struct ListNode* next = slow->next;
//             slow->next = newHead;
//             newHead = slow;
//             slow = next;
//         }
        struct ListNode* cur = A;
        //ע���n2�Ѿ�ָ��գ�n1����ָ��ͷ�ڵ�
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