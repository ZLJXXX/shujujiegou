
#pragma once
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include<Windows.h>
typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* front;
	QueueNode* tail;
}Queue;


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->front = NULL;
	pq->tail = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->tail == NULL)
	{
		pq->front = pq->tail = newnode;
	}
	else
	{
		pq->tail->_next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq && pq->front != NULL);
	QueueNode* next = pq->front->_next;
	free(pq->front);
	pq->front = next;
	if (pq->front == NULL)
	{
		pq->tail == NULL;
	}
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->front!=NULL);
	return pq->front->_data;
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq&&pq->tail!=NULL);
	return pq->tail->_data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->front == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->front;
	size_t count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
void TestQueue()

{
	Queue s;
	QueueInit(&s);
	QueuePush(&s, 1);
	QueuePush(&s, 2);
	QueuePush(&s, 3);
	QueuePush(&s, 4);
	while (!QueueEmpty(&s))
	{
		printf("%d ", QueueFront(&s));
		QueuePop(&s);
	}
	printf("\n");
	QueueDestory(&s);
}