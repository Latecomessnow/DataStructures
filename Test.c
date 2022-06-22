#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

//队列节点
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

//创建队列结构体
typedef struct Queue
{
	//队头队尾两个指针
	QNode* head;
	QNode* tail;
}Queue;

//队列初始化
void QueueInit(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);

//入队
void QueuePush(Queue* pq, QDataType x);

//出队
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);

//队列长度
int QueueSize(Queue* pq);


#define _CRT_SECURE_NO_WARNINGS 1


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		//保存下一节点
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//创建待插入队列节点
	//队尾入数据
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//队列为空
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		//更新尾指针
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	//判空
	assert(!QueueEmpty(pq));
	//一个节点
	//队首指针判断
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//取队头
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

//取队尾
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->tail == NULL;
}

//队列长度
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}


//队列实现栈
//此处用了匿名结构体的写法
typedef struct {
	//创建两个队列倒数据实现栈
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	//错误示范
	/*创建了一个栈的局部变量，但局部变量出了作用域就会被销毁，返回一个被销毁的变量的地址是一个野指针
	MyStack st;
	return &st;*/
	//我们需要malloc一块空间出来，即使指向这块空间的指针被销毁了，只要没有被free掉，这块空间依然存在
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	//再将栈里面的队列初始化一下,注意要取地址
	QueueInit(&obj->q1);
	QueueInit(&obj->q2);
	return obj;
}

void myStackPush(MyStack* obj, int x) {
	//插入的时候要往非空队列中插入
	//一开始并不知道哪个队列是空的或非空的，这时可以做个判断
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	//倒数据，假设一下空队列和非空队列
	Queue* EmptyQ = &obj->q1;
	Queue* nonEmptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		EmptyQ = &obj->q2;
		nonEmptyQ = &obj->q1;
	}
	//而取栈顶数据的时候非空队列要往空队列倒数据，倒到只剩一个数据后再取数据，最后Pop掉就可以了
	while (QueueSize(nonEmptyQ) > 1)
	{
		QueuePush(EmptyQ, QueueFront(nonEmptyQ));
		QueuePop(nonEmptyQ);
	}
	//此时还剩一个数据保存一下
	QDataType top = QueueFront(nonEmptyQ);
	//取了数据要pop掉，把它变为空队列，以便下一次倒数据
	QueuePop(nonEmptyQ);
	return top;
}

int myStackTop(MyStack* obj) {
	Queue* EmptyQ = &obj->q1;
	Queue* nonEmptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		EmptyQ = &obj->q2;
		nonEmptyQ = &obj->q1;
	}
	//直接利用取队尾数据
	QDataType top = QueueBack(nonEmptyQ);
	return top;
}

bool myStackEmpty(MyStack* obj) {
	//连个队列都为空栈才为空，只要有一个队列不为空栈就不为空
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	//先要把队列删除了，再free掉obj
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/