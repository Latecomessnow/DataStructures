#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void TestSList1()
{
	SListNode* n1 = (SListNode*)malloc(sizeof(SListNode));
	assert(n1);
	SListNode* n2 = (SListNode*)malloc(sizeof(SListNode));
	assert(n2);
	SListNode* n3 = (SListNode*)malloc(sizeof(SListNode));
	assert(n3);
	SListNode* n4 = (SListNode*)malloc(sizeof(SListNode));
	assert(n4);
	SListNode* n5 = (SListNode*)malloc(sizeof(SListNode));
	assert(n5);
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	SListNode* plist = n1;
	SListPrint(plist);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPrint(plist);

}

void TestSList2()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPrint(plist);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
}

void TestSList3()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);

}

void TestSList4()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListFind(plist, 4);
}

void TestSList5()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListNode* ret = SListFind(plist, 4);
	if (ret != NULL)
	{
		ret->data = 28;
		printf("ур╣╫ак\n");
	}
	SListPrint(plist);
	SListNode* pos = SListFind(plist, 28);
	if (pos)
	{
		SListInsert(&plist, pos, 4);
	}
	SListPrint(plist);
	pos = SListFind(plist, 28);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);
	pos = SListFind(plist, 2);
	if (pos)
	{
		SListInsertAfter(&plist, pos, 4);
	}
	SListPrint(plist);
	pos = SListFind(plist, 1);
	if (pos)
	{
		SListEraseAfter(plist, pos);
	}
	SListPrint(plist);

}

int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
	//TestSList4();
	TestSList5();
	return 0;
}