#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SListPrint(SListNode* phead)
{
	assert(phead);
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//����һ���½ڵ�
SListNode* BuySListNode(SLLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//����β��
void SListPushBack(SListNode** pphead, SLLDataType x)
{
	//assert(*phead);//�������������Ϊ��ʱ��plist����ָ���ָ��
	SListNode* newnode = BuySListNode(x);
	//�������Ϊ�գ��Ͱ��½ڵ㸳��plist��Ϊͷ�ڵ�
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//���ҵ������β�ٽ���β��
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//����ͷ��
void SListPushFront(SListNode** pphead, SLLDataType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	//ͷ��ʱ�������ͷ��ı�
	*pphead = newnode;
}

//����βɾ
void SListPopBack(SListNode** pphead)
{
	//����Ϊ�����ܽ���ɾ��
	assert(*pphead);
	//һ���ڵ�
	//����ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

//����ͷɾ
void SListPopFront(SListNode** pphead)
{
	assert(*pphead != NULL);
	SListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//����Ԫ��
SListNode* SListFind(SListNode* phead, SLLDataType x)
{
	assert(phead != NULL);
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//posǰ����Ԫ��
void SListInsert(SListNode** pphead, SListNode* pos, SLLDataType x)
{
	assert(pos);
	assert(pphead);
	//ͷ��
	if (*pphead == NULL)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SListNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

//ɾ��posλ�õ�ֵ
void SListErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//ע��
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//��pos�����Ԫ��
void SListInsertAfter(SListNode** pphead, SListNode* pos, SLLDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//��pos��ɾ��Ԫ��
void SListEraseAfter(SListNode* phead, SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	SListNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}