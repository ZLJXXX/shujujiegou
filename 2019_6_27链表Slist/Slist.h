#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include<stdlib.h>

// ���� ����ͷ ��ѭ��
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType	_data;
	struct SListNode* _next;
}SListNode;

typedef struct SList  //ͷָ��
{
	SListNode* _head;
}SList;

void SListInit(SList* plt);
void SListPushBack(SList* plt, SLTDataType x);//β��
void SListPushfront(SList* plt, SLTDataType x);//ͷ��
void SListPopBack(SList* plt);//βɾ
void SListPopfront(SList* plt);//ͷɾ
void SListDestory(SList* plt);
SListNode* SListfind(SList* plt, SLTDataType x);//ͨ��ֵ������
void SListInsertAfter(SListNode* pos, SLTDataType x);//����λ�ú����
void SListEraseAfter(SList* plt,SListNode* pos);//����λ�ú���ɾ

void TestSList1();