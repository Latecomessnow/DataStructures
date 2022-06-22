#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

//���нڵ�
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

//�������нṹ��
typedef struct Queue
{
	//��ͷ��β����ָ��
	QNode* head;
	QNode* tail;
}Queue;

//���г�ʼ��
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);

//���
void QueuePush(Queue* pq, QDataType x);

//����
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

//�п�
bool QueueEmpty(Queue* pq);

//���г���
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
		//������һ�ڵ�
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//������������нڵ�
	//��β������
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//����Ϊ��
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		//����βָ��
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	//�п�
	assert(!QueueEmpty(pq));
	//һ���ڵ�
	//����ָ���ж�
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

//ȡ��ͷ
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

//ȡ��β
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

//���г���
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


//����ʵ��ջ
//�˴����������ṹ���д��
typedef struct {
	//�����������е�����ʵ��ջ
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	//����ʾ��
	/*������һ��ջ�ľֲ����������ֲ���������������ͻᱻ���٣�����һ�������ٵı����ĵ�ַ��һ��Ұָ��
	MyStack st;
	return &st;*/
	//������Ҫmallocһ��ռ��������ʹָ�����ռ��ָ�뱻�����ˣ�ֻҪû�б�free�������ռ���Ȼ����
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	//�ٽ�ջ����Ķ��г�ʼ��һ��,ע��Ҫȡ��ַ
	QueueInit(&obj->q1);
	QueueInit(&obj->q2);
	return obj;
}

void myStackPush(MyStack* obj, int x) {
	//�����ʱ��Ҫ���ǿն����в���
	//һ��ʼ����֪���ĸ������ǿյĻ�ǿյģ���ʱ���������ж�
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
	//�����ݣ�����һ�¿ն��кͷǿն���
	Queue* EmptyQ = &obj->q1;
	Queue* nonEmptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		EmptyQ = &obj->q2;
		nonEmptyQ = &obj->q1;
	}
	//��ȡջ�����ݵ�ʱ��ǿն���Ҫ���ն��е����ݣ�����ֻʣһ�����ݺ���ȡ���ݣ����Pop���Ϳ�����
	while (QueueSize(nonEmptyQ) > 1)
	{
		QueuePush(EmptyQ, QueueFront(nonEmptyQ));
		QueuePop(nonEmptyQ);
	}
	//��ʱ��ʣһ�����ݱ���һ��
	QDataType top = QueueFront(nonEmptyQ);
	//ȡ������Ҫpop����������Ϊ�ն��У��Ա���һ�ε�����
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
	//ֱ������ȡ��β����
	QDataType top = QueueBack(nonEmptyQ);
	return top;
}

bool myStackEmpty(MyStack* obj) {
	//�������ж�Ϊ��ջ��Ϊ�գ�ֻҪ��һ�����в�Ϊ��ջ�Ͳ�Ϊ��
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	//��Ҫ�Ѷ���ɾ���ˣ���free��obj
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