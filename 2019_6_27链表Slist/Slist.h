#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include<stdlib.h>

// 单向 不带头 不循环
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType	_data;
	struct SListNode* _next;
}SListNode;

typedef struct SList  //头指针
{
	SListNode* _head;
}SList;

void SListInit(SList* plt);
void SListPushBack(SList* plt, SLTDataType x);//尾插
void SListPushfront(SList* plt, SLTDataType x);//头插
void SListPopBack(SList* plt);//尾删
void SListPopfront(SList* plt);//头删
void SListDestory(SList* plt);
SListNode* SListfind(SList* plt, SLTDataType x);//通过值来查找
void SListInsertAfter(SListNode* pos, SLTDataType x);//任意位置后面插
void SListEraseAfter(SList* plt,SListNode* pos);//任意位置后面删

void TestSList1();