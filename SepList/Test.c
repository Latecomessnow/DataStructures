#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void TestPushBack()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPrint(&s1);
	SLPushBack(&s1, 5);
	SLPrint(&s1);
	SLPushBack(&s1, 9);
	SLPrint(&s1);

}

void TestPushFront()
{
	SL s1;
	SLInit(&s1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLPushFront(&s1, 5);
	SLPrint(&s1);
	SLPushBack(&s1, 5);
	SLPushBack(&s1, 5);
	SLPrint(&s1);
}

void TestPopBack()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPrint(&s1);
	SLPopBack(&s1);
	SLPrint(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPrint(&s1);

}

void TestSLPopFront()
{
	SL s1;
	SLInit(&s1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLPushFront(&s1, 5);
	SLPrint(&s1);
	SLPopFront(&s1);
	SLPrint(&s1);

}

void TestInsert()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPrint(&s1);
	SLInsert(&s1, 0, 0);
	SLPrint(&s1);
	SLInsert(&s1, 2, 10);
	SLPrint(&s1);

}

void TestErase()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPrint(&s1);
	SLInsert(&s1, 0, 0);
	SLPrint(&s1);
	SLInsert(&s1, 6, 1);
	SLPrint(&s1);
	SLErase(&s1, 2);
	SLPrint(&s1);
}

void TestFind()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	int pos = SLFind(&s1, 1);
	if (pos != -1)
	{
		printf("找到了,下标为:%d\n", pos);
	}
	else
	{
		printf("找不到\n");
	}
}

void TestModify()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPrint(&s1);
	printf("请输入修改的值的下标:>");
	int pos = 0;
	scanf("%d", &pos);
	printf("请输入要修改后的值:>");
	int ret = 0;
	scanf("%d", &ret);
	SLModify(&s1, pos, ret);
	SLPrint(&s1);
}


void Test()
{
	SL s1;
	SLInit(&s1);
	SLInsert(&s1, 0, 0);
	SLInsert(&s1, 1, 1);
	SLInsert(&s1, 2, 2);
	SLPrint(&s1);
	SLInsert(&s1, 3, 3);
	SLInsert(&s1, 4, 4);
	SLPrint(&s1);
}
int main()
{
	//TestPushBack();
	//TestPushFront();
	//TestPopBack();
	//TestSLPopFront();
	//TestInsert();
	//TestErase();
	//TestFind();
	//TestModify();
	Test();
}