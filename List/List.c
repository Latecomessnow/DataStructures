#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//���ö���ָ�봴���ڱ�λ
//void ListInit(LTNode** pphead)
//{
//	assert(pphead);
//	*pphead = BuyListNode(-1);
//	(*pphead)->prev = *pphead;
//	(*pphead)->next = *pphead;
//}

//���÷���ֵ��ֻ��Ҫͨ��һ��ָ��Ϳ��Դ����ڱ�λ��
//��Ϊ��ߵĺ�������ʹ�õ�һ��ָ�룬��������ʹ�÷���ֵ�����ڱ�λ�ȽϺ���
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	//�ڱ�λ�ڵ�ǰ����̶�ָ���Լ�
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	//ע��curӦ��phead->next��ʼ����Ϊphead���ڱ�λ�����洢��Ч����
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");  
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;
	//ע���Ǵ�phead���൱��phead����һ�ڵ㼴β�ڵ����β��
	ListInsert(phead, x);
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
	//���ڱ�λ����һ�ڵ��ǰ��ͷ�壬posǰ
	ListInsert(phead->next, x);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	//��������Ƿ�Ϊ��
	//assert(phead->prev != phead);
	//LTNode* tail = phead->prev;
	//phead->prev = tail->prev;
	//tail->prev->next = phead;
	//free(tail);
	//βɾ�൱�ڴ��ڱ�λ����һ�ڵ㿪ʼ
	ListErase(phead->prev);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->prev != phead);
	//LTNode* next = phead->next;
	//phead->next = next->next;
	//next->next->prev = phead;
	//free(next);
	//ͷɾ�൱���ڱ�λ��һ�ڵ㿪ʼ
	ListErase(phead->next);
}

//�п�
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	//����Ϊ�շ���true����Ϊ�շ���false
	return phead->next == phead;
}

//��posλ��ǰ����
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}