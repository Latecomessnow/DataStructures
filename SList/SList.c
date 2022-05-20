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

//创建一个新节点
SListNode* BuySListNode(SLLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//链表尾插
void SListPushBack(SListNode** pphead, SLLDataType x)
{
	//assert(*phead);//错误操作，链表为空时，plist就是指向空指针
	SListNode* newnode = BuySListNode(x);
	//如果链表为空，就把新节点赋给plist作为头节点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//先找到链表的尾再进行尾插
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//链表头插
void SListPushFront(SListNode** pphead, SLLDataType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	//头插时，链表的头会改变
	*pphead = newnode;
}

//链表尾删
void SListPopBack(SListNode** pphead)
{
	//链表为空则不能进行删除
	assert(*pphead);
	//一个节点
	//多个节点
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

//链表头删
void SListPopFront(SListNode** pphead)
{
	assert(*pphead != NULL);
	SListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//查找元素
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

//pos前插入元素
void SListInsert(SListNode** pphead, SListNode* pos, SLLDataType x)
{
	assert(pos);
	assert(pphead);
	//头插
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

//删除pos位置的值
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
		//注意
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//在pos后插入元素
void SListInsertAfter(SListNode** pphead, SListNode* pos, SLLDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//在pos后删除元素
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