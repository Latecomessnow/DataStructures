#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);

void StackDestroy(ST* ps);

void StackPush(ST* ps, STDataType x);

void StackPop(ST* ps);

//取栈顶元素
STDataType StackTop(ST* ps);

int StackSize(ST* ps);

bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	//先检查容量
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->data, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("relloc fail\n");
			exit(-1);
		}
		ps->data = tmp;
		ps->capacity = newCapacity;
	}
	ps->data[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	//虽然Pop掉了，但其实越界访问还是能够访问到元素
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->data[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	//为空返回true，不为空返回false
	return ps->top == 0;
}

int StackSize(ST* ps)
{
	assert(ps);
	//直接返回top就可以了，因为top比最大的下标大1
	return ps->top;
}

//用两个栈实现队列，一个push栈，一个pop栈
typedef struct {
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&obj->pushst);
	StackInit(&obj->popst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popst))
	{
		//如果pop栈为空就把push栈拷贝到pop栈
		//这样拷贝一次后数据就颠倒了，1，2，3，4就变成了4，3，2，1，1是栈顶就实现了队列的操作
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	int top = StackTop(&obj->popst);
	StackPop(&obj->popst);
	return top;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popst))
	{
		//如果pop栈为空就把push栈拷贝到pop栈
		//这样拷贝一次后数据就颠倒了，1，2，3，4就变成了4，3，2，1，1是栈顶就实现了队列的操作
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	return StackTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	//队列中有两个栈，只有两个栈都为空，队列才为空，只要有一个栈不为空队列就不为空
	return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
}
void myQueueFree(MyQueue* obj) {
	//先把队列中的栈销毁了，再把obj给free掉就可以了
	StackDestroy(&obj->pushst);
	StackDestroy(&obj->popst);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/