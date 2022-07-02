#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);

void HeapDestroy(HP* php);

void HeapPrint(HP* php);

void HeapPush(HP* php, HPDataType x);

void HeapPop(HP* php);

int HeapSize(HP* php);

bool HeapEmpty(HP* php);

HPDataType HeapTop(HP* php);