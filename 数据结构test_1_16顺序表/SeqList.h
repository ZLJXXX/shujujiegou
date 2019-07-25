#define _CRT_SECURE_NO_WARNINGS
#define LISTMAX 3 
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
/* 静态顺序表
struct SeqList
{
	DataType array[MAXSIZE]; // 保存顺序表中有序元素 
	int size; // 顺序表中有效元素的个数 
};
*/
typedef int DataType;

typedef struct SeqList
{
	DataType* _array; // 保存顺序表中有效元素个数 
	int _capacity; // 空间总大小 
	int _size; // 有效元素个数 
}SeqList, *PSeqList;

//typedef struct SeqList SeqList; 
//PSeqList 结构体指针ps
//DataType data 加入元素的数据类型
void SeqListInit(PSeqList ps);
void SeqListDestroy(PSeqList ps);

// 尾插 
void SeqListPushBack(PSeqList ps, DataType data);
// 尾删 
void SeqListPopBack(PSeqList ps);

// 头插 
void SeqListPushFront(PSeqList ps, DataType data);
// 头删 
void SeqListPopFront(PSeqList ps);
// 任意位置插入 
void SeqListInsert(PSeqList ps, int pos, DataType data);

// 任意位置删除 
void SeqListErase(PSeqList ps, int pos);

// 检测data释放在顺序表中 
int SeqListFind(PSeqList ps, DataType data);

// 移除顺序表中第一个值为data的元素 
void SeqListRemove(PSeqList ps, DataType data);

// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll(PSeqList ps, DataType data);

// 获取顺序表有效元素个数 
int SeqListSize(PSeqList ps);
//顺序表增容
void SeqListNEWCapacity(PSeqList ps);

// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps);

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps);

// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps);

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps);
// 
void PrintSeqList(PSeqList ps);