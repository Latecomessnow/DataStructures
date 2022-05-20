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

//����β��
void SListPushBack(SListNode** phead, SLLDataType x);

//����ͷ��
void SListPushFront(SListNode** pphead, SLLDataType x);

//����βɾ
void SListPopBack(SListNode** pphead);

//����ͷɾ
void SListPopFront(SListNode** pphead);

//����Ԫ��
SListNode* SListFind(SListNode* phead, SLLDataType x);

//posǰ����Ԫ��
void SListInsert(SListNode** pphead, SListNode* pos, SLLDataType x);

//ɾ��posλ�õ�ֵ
void SListErase(SListNode** pphead, SListNode* pos);

//��pos�����Ԫ��
void SListInsertAfter(SListNode** pphead, SListNode* pos, SLLDataType x);

//��pos��ɾ��Ԫ��
void SListEraseAfter(SListNode* phead, SListNode* pos);
