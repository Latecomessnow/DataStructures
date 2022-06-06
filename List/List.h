#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* prev;//前驱指针
	struct ListNode* next;//后继指针
	LTDataType data;
}LTNode;

LTNode* ListInit();

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDataType x);

void ListPushFront(LTNode* phead, LTDataType x);

void ListPopBack(LTNode* phead);

void ListPopFront(LTNode* phead);

//在pos位置前插入数据
void ListInsert(LTNode* pos, LTDataType x);

//删除pos位置的数据
void ListErase(LTNode* pos);

bool ListEmpty(LTNode* phead);
