#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void TestQueue1()
{
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	QueuePush(&Q, 5);
	while (!QueueEmpty(&Q))
	{
		printf("%d ", QueueFront(&Q));
		QueuePop(&Q);
	}
	putchar('\n');
	//QueuePop(&Q);
	//QueuePop(&Q); 
	//QueuePop(&Q);
	//QueuePop(&Q);
	//QueuePop(&Q);
	//QueuePop(&Q);
}

int main()
{
	TestQueue1();
	return 0;
}