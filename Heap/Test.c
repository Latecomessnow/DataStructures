#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void TestHeap1()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);
	//HeapPush(&hp, 1);
	//HeapPrint(&hp);
	//printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));
}

void TestHeap2()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	//HeapPrint(&hp);
	HeapPop(&hp);

}

int main()
{
	//TestHeap1();
	TestHeap2();
	return 0;
}