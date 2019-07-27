
#include"Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_array, a, sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	//构建成堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_array, hp->_size, i);
	}
}
//堆分为大堆和小堆 ，现在使用大堆
void Swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//向下调整
void AdjustDown(HPDataType* _array, size_t n, size_t parent)
{
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		//选出较大的孩子
		if (child + 1 < n && _array[child] < _array[child + 1])
		{
			child++;
		}
		//较大孩子大于双亲，交换
		if (_array[child]>_array[parent])
		{
			Swap(&(_array[child]), &(_array[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//向上调整
void Adjustup(HPDataType* _array, size_t child)
{
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (_array[parent] < _array[child])
		{
			Swap(&(_array[parent]), &(_array[child]));
			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			break;
		}
	}
}
void HeapDestory(Heap* hp)
{
	if (hp->_array != NULL)
	{
		
		free(hp->_array);
		hp->_array = NULL;
		hp->_capacity = 0;
		hp->_size = 0;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	//先进行增容
	HPDataType newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
	if (hp->_capacity == hp->_size)
	{
		hp->_array = (HPDataType*)realloc(hp->_array, sizeof(HPDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	for (int i = hp->_size - 1; i >= 0; --i)
	{
		Adjustup(hp->_array, i);
	}
}
void HeapPop(Heap* hp)
{
	Swap(&(hp->_array[hp->_size - 1]), &(hp->_array[0]));
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	return hp->_array[0];
}
HPDataType HeapSize(Heap* hp)
{
	return hp->_size - 1;
}
bool HeapEmpty(Heap* hp)
{
	return hp->_array == NULL;
}
void printheap(Heap* hp)
{
	for (int i =0 ; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}
void heapsort(Heap* hp,HPDataType* a, int n)
{
	//堆排序
	//从小到大排序 用大堆
	//构建成堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_array, hp->_size, i);
	}
	while (n > 1)
	{
		Swap(&(hp->_array[n - 1]), &(hp->_array[0]));
		n--;
		AdjustDown(hp->_array,n, 0);
	}
}


void TestHeap()
{
	Heap s;
	HPDataType a[] = { 0, 2, 1, 3, 5, 7, 4, 8 };
	int i = sizeof(a) / sizeof(int);
	HeapInit(&s, a, i);
	printheap(&s);
	HeapPush(&s, 10);
	printheap(&s);
	HeapPop(&s);
	printheap(&s);
	HeapPop(&s);
	printheap(&s);
	heapsort(&s, a, i);
	printheap(&s);
	HeapDestory(&s);
}