#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* prev;//ǰ��ָ��
	struct ListNode* next;//���ָ��
	LTDataType data;
}LTNode;

LTNode* ListInit();

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDataType x);

void ListPushFront(LTNode* phead, LTDataType x);

void ListPopBack(LTNode* phead);

void ListPopFront(LTNode* phead);

//��posλ��ǰ��������
void ListInsert(LTNode* pos, LTDataType x);

//ɾ��posλ�õ�����
void ListErase(LTNode* pos);

bool ListEmpty(LTNode* phead);
