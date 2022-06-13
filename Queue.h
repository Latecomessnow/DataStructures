#pragma once

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