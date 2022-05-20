#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLLDataType;

typedef struct SListNode
{
	SLLDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* phead);

//链表尾插
void SListPushBack(SListNode** phead, SLLDataType x);

//链表头插
void SListPushFront(SListNode** pphead, SLLDataType x);

//链表尾删
void SListPopBack(SListNode** pphead);

//链表头删
void SListPopFront(SListNode** pphead);

//查找元素
SListNode* SListFind(SListNode* phead, SLLDataType x);

//pos前插入元素
void SListInsert(SListNode** pphead, SListNode* pos, SLLDataType x);

//删除pos位置的值
void SListErase(SListNode** pphead, SListNode* pos);

//在pos后插入元素
void SListInsertAfter(SListNode** pphead, SListNode* pos, SLLDataType x);

//在pos后删除元素
void SListEraseAfter(SListNode* phead, SListNode* pos);
