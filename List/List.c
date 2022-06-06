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

//利用二级指针创建哨兵位
//void ListInit(LTNode** pphead)
//{
//	assert(pphead);
//	*pphead = BuyListNode(-1);
//	(*pphead)->prev = *pphead;
//	(*pphead)->next = *pphead;
//}

//利用返回值，只需要通过一级指针就可以创建哨兵位了
//因为后边的函数都是使用的一级指针，所以这里使用返回值创建哨兵位比较合适
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	//哨兵位节点前驱后继都指向自己
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	//注意cur应从phead->next开始，因为phead是哨兵位，不存储有效数据
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
	//注意是传phead，相当于phead的上一节点即尾节点进行尾插
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
	//在哨兵位的下一节点的前边头插，pos前
	ListInsert(phead->next, x);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	//检查链表是否为空
	//assert(phead->prev != phead);
	//LTNode* tail = phead->prev;
	//phead->prev = tail->prev;
	//tail->prev->next = phead;
	//free(tail);
	//尾删相当于从哨兵位的上一节点开始
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
	//头删相当于哨兵位下一节点开始
	ListErase(phead->next);
}

//判空
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	//链表为空返回true，不为空返回false
	return phead->next == phead;
}

//在pos位置前插入
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

//删除pos位置的节点
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}