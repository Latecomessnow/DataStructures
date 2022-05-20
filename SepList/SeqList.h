#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define INIT_CAPACITY 3

typedef int SLDataType;

typedef struct SepList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

//��ʼ��˳���
void SLInit(SL* ps);

//��ӡ˳���
void SLPrint(SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x);

//ͷ��
void SLPushFront(SL* ps, SLDataType x);

//βɾ
void SLPopBack(SL* ps);

//ͷɾ
void SLPopFront(SL* ps);

//����
void SLInsert(SL* ps, int pos, SLDataType x);

//ɾ��
void SLErase(SL* ps, int pos);

//����
int SLFind(SL* ps, SLDataType x);

//�޸�
void SLModify(SL* ps, int pos, SLDataType x);