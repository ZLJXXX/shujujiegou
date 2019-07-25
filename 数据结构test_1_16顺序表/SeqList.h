#define _CRT_SECURE_NO_WARNINGS
#define LISTMAX 3 
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
/* ��̬˳���
struct SeqList
{
	DataType array[MAXSIZE]; // ����˳���������Ԫ�� 
	int size; // ˳�������ЧԪ�صĸ��� 
};
*/
typedef int DataType;

typedef struct SeqList
{
	DataType* _array; // ����˳�������ЧԪ�ظ��� 
	int _capacity; // �ռ��ܴ�С 
	int _size; // ��ЧԪ�ظ��� 
}SeqList, *PSeqList;

//typedef struct SeqList SeqList; 
//PSeqList �ṹ��ָ��ps
//DataType data ����Ԫ�ص���������
void SeqListInit(PSeqList ps);
void SeqListDestroy(PSeqList ps);

// β�� 
void SeqListPushBack(PSeqList ps, DataType data);
// βɾ 
void SeqListPopBack(PSeqList ps);

// ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data);
// ͷɾ 
void SeqListPopFront(PSeqList ps);
// ����λ�ò��� 
void SeqListInsert(PSeqList ps, int pos, DataType data);

// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos);

// ���data�ͷ���˳����� 
int SeqListFind(PSeqList ps, DataType data);

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data);

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data);

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps);
//˳�������
void SeqListNEWCapacity(PSeqList ps);

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps);

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps);

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps);

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps);
// 
void PrintSeqList(PSeqList ps);