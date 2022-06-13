#pragma once

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