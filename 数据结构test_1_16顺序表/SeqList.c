#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
////初始化
void SeqListInit(PSeqList ps)
{
	assert(ps);
	//申请动态内存的空间
	ps->_array = (DataType*)malloc(LISTMAX * sizeof(DataType));
	//判断内存空间是否申请成功
	if (ps->_array == NULL)
	{
		return;
	}
	ps->_capacity = LISTMAX;
	ps->_size = 0;
}
void SeqListDestroy(PSeqList ps)//销毁使用过的内存空间
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity  = 0;
	ps->_size = 0;
	
}
// 尾插 
//size为有效元素的个数
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	SeqListNEWCapacity(ps);
	ps->_array[ps->_size] = data;
	(ps->_size)++;
}
// 尾删 
void SeqListPopBack(PSeqList ps)
{
	assert(ps);
	(ps->_size)--;
}
//头插
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
//头删
void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	for (int i = 1; i < ps->_size; i++)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	(ps->_size)--;
}
//打印函数
void PrintSeqList(PSeqList ps)
{
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
//在任意位置插入
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
// 任意位置删除 
void SeqListErase(PSeqList ps, int pos)
{
	int i = pos + 1;
	for (i = pos + 1 ; i < ps->_size; i++)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	(ps->_size)--;
}
//顺序表增容
void SeqListNEWCapacity(PSeqList ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)//内存已满
	{
		DataType* str = (DataType*)malloc(LISTMAX * sizeof(DataType)* 2);
		if (str != NULL)
		{
			memcpy(str, ps->_array, LISTMAX * sizeof(DataType));
			free(ps->_array);
			ps->_array = str;
			str = NULL;
			ps->_capacity  *= 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
			return;
		}
	}

}
// 检测data释放在顺序表中 
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
// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps)
{
	return ps->_capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps)
{
	if (0 == ps->_size)
	{
		return NULL;
	}
	return;
}
// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps)
{
	return ps->_array[0];
}

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps)
{
	return ps->_array[ps->_size-1];
}
// 移除顺序表中第一个值为data的元素 
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
// 移除顺序表中所有值为data的元素 
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
// 获取顺序表有效元素个数 
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
