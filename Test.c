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

//ȡջ��Ԫ��
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
	//�ȼ������
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
	//��ȻPop���ˣ�����ʵԽ����ʻ����ܹ����ʵ�Ԫ��
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
	//Ϊ�շ���true����Ϊ�շ���false
	return ps->top == 0;
}

int StackSize(ST* ps)
{
	assert(ps);
	//ֱ�ӷ���top�Ϳ����ˣ���Ϊtop�������±��1
	return ps->top;
}

//������ջʵ�ֶ��У�һ��pushջ��һ��popջ
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
		//���popջΪ�վͰ�pushջ������popջ
		//��������һ�κ����ݾ͵ߵ��ˣ�1��2��3��4�ͱ����4��3��2��1��1��ջ����ʵ���˶��еĲ���
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
		//���popջΪ�վͰ�pushջ������popջ
		//��������һ�κ����ݾ͵ߵ��ˣ�1��2��3��4�ͱ����4��3��2��1��1��ջ����ʵ���˶��еĲ���
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));
			StackPop(&obj->pushst);
		}
	}
	return StackTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	//������������ջ��ֻ������ջ��Ϊ�գ����в�Ϊ�գ�ֻҪ��һ��ջ��Ϊ�ն��оͲ�Ϊ��
	return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
}
void myQueueFree(MyQueue* obj) {
	//�ȰѶ����е�ջ�����ˣ��ٰ�obj��free���Ϳ�����
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