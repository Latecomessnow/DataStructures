#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

TestStack1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackTop(&st);
	StackTop(&st);
	StackTop(&st);
	StackTop(&st);
	StackTop(&st);
	StackTop(&st);
}

void TestStack2()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		//取完栈顶数据后pop掉
		StackPop(&st);
	}
	putchar('\n');
}

void TestStack3()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	printf("%d\n", StackSize(&st));
}
int main()
{
	//TestStack1();
	//TestStack2();
	TestStack3();
	return 0;
}