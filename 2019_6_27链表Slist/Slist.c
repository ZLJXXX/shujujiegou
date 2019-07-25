#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"
void SListInit(SList* plt){
	assert(plt);
	plt->_head = NULL;
}
void SListPushBack(SList* plt, SLTDataType x)//β��
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//������һ���µĽڵ�
	newnode->_data = x;
	newnode->_next = NULL;
	//�ж������Ƿ�Ϊ��
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
void SListPushfront(SList* plt, SLTDataType x)//ͷ��
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//������һ���µĽڵ�
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
void SListPopBack(SList* plt)//βɾ
{
	assert(plt);
	SListNode* cur = plt->_head;
	if (plt->_head == NULL)//��Ϊ������ʱ
	{
		return;
	}
	else if (cur->_next == NULL)//��һ���ڵ�
	{
		free(cur);
		cur = NULL;
	}
	else//�ж���ڵ�
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
void SListPopfront(SList* plt)//ͷɾ
{
	assert(plt);
	SListNode* cur = plt->_head;
	plt->_head = cur->_next;
	free(cur);
	cur = NULL;
}
SListNode* SListfind(SList* plt, SLTDataType x)//ͨ��ֵ������
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
void SListInsertAfter(SListNode* pos, SLTDataType x)//����λ�ú����
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));//������һ���µĽڵ�
	newnode->_data = x;
	newnode->_next = NULL;//����ڵ㲢��ʼ��

	newnode->_next = pos->_next;
	pos->_next = newnode;
}
void SListEraseAfter(SList* plt,SListNode* pos)//����λ�ú���ɾ
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
	SListEraseAfter(&s,pos);//����λ�ú���ɾ
	Slistprint(&s);
	//SListDestory(&s);
}