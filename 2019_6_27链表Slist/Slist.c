#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"
void SListInit(SList* plt){
	assert(plt);
	plt->_head = NULL;
}
void SListPushBack(SList* plt, SLTDataType x)//尾插
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//先申请一个新的节点
	newnode->_data = x;
	newnode->_next = NULL;
	//判断链表是否为空
	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void SListPushfront(SList* plt, SLTDataType x)//头插
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//先申请一个新的节点
	newnode->_data = x;
	newnode->_next = NULL;
	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else
	{
		newnode->_next = plt->_head;
		plt->_head = newnode;
	}
}
void SListPopBack(SList* plt)//尾删
{
	assert(plt);
	SListNode* cur = plt->_head;
	if (plt->_head == NULL)//当为空链表时
	{
		return;
	}
	else if (cur->_next == NULL)//有一个节点
	{
		free(cur);
		cur = NULL;
	}
	else//有多个节点
	{
		SListNode* cur = plt->_head;
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}
void SListPopfront(SList* plt)//头删
{
	assert(plt);
	SListNode* cur = plt->_head;
	plt->_head = cur->_next;
	free(cur);
	cur = NULL;
}
SListNode* SListfind(SList* plt, SLTDataType x)//通过值来查找
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
//void SListDestory(SList* plt);
void Slistprint(SList* plt)
{
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;	
	};
	printf("NULL\n");
}
void SListInsertAfter(SListNode* pos, SLTDataType x)//任意位置后面插
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//先申请一个新的节点
	newnode->_data = x;
	newnode->_next = NULL;//申请节点并初始化

	newnode->_next = pos->_next;
	pos->_next = newnode;
}
void SListEraseAfter(SList* plt,SListNode* pos)//任意位置后面删
{
	assert(plt);
	SListNode* cur = plt->_head;
	SListNode* prev = NULL;
	while (prev!= pos)
	{
		prev = cur;
		cur = cur->_next;
	}
	prev->_next = cur->_next;
	free(cur);
	cur = NULL;
}
void SListDestory(SList* plt)
{
	assert(plt);
	SListNode* cur = plt->_head;
	SListNode* prev = NULL ;
	while (cur != NULL)
	{
		prev = cur;
		free(prev);
		prev = prev->_next;
	}
	plt->_head = NULL;
}
void TestSList1()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushfront(&s, 11);
	SListPushfront(&s, 12);
	SListPushfront(&s, 13);
	SListPushfront(&s, 14);
	//SListPopBack(&s);
	//SListPopBack(&s);
	//SListPopfront(&s);
	//SListPopfront(&s);
	SListNode* pos = SListfind(&s, 4);
	SListInsertAfter(pos,2);
	SListEraseAfter(&s,pos);//任意位置后面删
	Slistprint(&s);
	//SListDestory(&s);
}