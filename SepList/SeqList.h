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

//初始化顺序表
void SLInit(SL* ps);

//打印顺序表
void SLPrint(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//头插
void SLPushFront(SL* ps, SLDataType x);

//尾删
void SLPopBack(SL* ps);

//头删
void SLPopFront(SL* ps);

//插入
void SLInsert(SL* ps, int pos, SLDataType x);

//删除
void SLErase(SL* ps, int pos);

//查找
int SLFind(SL* ps, SLDataType x);

//修改
void SLModify(SL* ps, int pos, SLDataType x);