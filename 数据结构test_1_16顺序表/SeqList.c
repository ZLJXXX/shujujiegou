#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
////��ʼ��
void SeqListInit(PSeqList ps)
{
	assert(ps);
	//���붯̬�ڴ�Ŀռ�
	ps->_array = (DataType*)malloc(LISTMAX * sizeof(DataType));
	//�ж��ڴ�ռ��Ƿ�����ɹ�
	if (ps->_array == NULL)
	{
		return;
	}
	ps->_capacity = LISTMAX;
	ps->_size = 0;
}
void SeqListDestroy(PSeqList ps)//����ʹ�ù����ڴ�ռ�
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity  = 0;
	ps->_size = 0;
	
}
// β�� 
//sizeΪ��ЧԪ�صĸ���
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	SeqListNEWCapacity(ps);
	ps->_array[ps->_size] = data;
	(ps->_size)++;
}
// βɾ 
void SeqListPopBack(PSeqList ps)
{
	assert(ps);
	(ps->_size)--;
}
//ͷ��
void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	SeqListNEWCapacity(ps);
	int i = ps->_size ;
	for (i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	(ps->_size)++;
}
//ͷɾ
void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	for (int i = 1; i < ps->_size; i++)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	(ps->_size)--;
}
//��ӡ����
void PrintSeqList(PSeqList ps)
{
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
//������λ�ò���
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	assert(ps);
	int i = ps->_size;
	for (i = ps->_size; i >= pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	(ps->_size)++;
}
// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos)
{
	int i = pos + 1;
	for (i = pos + 1 ; i < ps->_size; i++)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	(ps->_size)--;
}
//˳�������
void SeqListNEWCapacity(PSeqList ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)//�ڴ�����
	{
		DataType* str = (DataType*)malloc(LISTMAX * sizeof(DataType)* 2);
		if (str != NULL)
		{
			memcpy(str, ps->_array, LISTMAX * sizeof(DataType));
			free(ps->_array);
			ps->_array = str;
			str = NULL;
			ps->_capacity  *= 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
			return;
		}
	}

}
// ���data�ͷ���˳����� 
int SeqListFind(PSeqList ps, DataType data)
{
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			return i;
		}
	}
}
// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps)
{
	return ps->_capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps)
{
	if (0 == ps->_size)
	{
		return NULL;
	}
	return;
}
// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps)
{
	return ps->_array[0];
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps)
{
	return ps->_array[ps->_size-1];
}
// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data)
{
	int i = 0;
	for (; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			for (int j = i + 1; j <= ps->_size; j++)
			{
				ps->_array[j - 1] = ps->_array[j];
			}
		}
	}
	(ps->_size)--;
}
// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data)
{

	int i = 0; int count = 0;
	for (; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			count++;
		}
		else
			ps->_array[i - count] = ps->_array[i];
	}
	ps->_size -= count;
}
// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps)
{
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_size; i++)
	{
		count++;
	}
	return count;
}
