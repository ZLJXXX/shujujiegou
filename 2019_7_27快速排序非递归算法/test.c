#include"Stack.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//快排的优化算法：三数取中法
int GetMinindex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid]<a[left])
			return mid;
		else if (a[right]>a[left])
			return right;
		else
			return left;

	}
}
int SingleSort1(int* a, int left, int right)
{
	int index = GetMinindex(a, left, right);
	Swap(&(a[index]), &(a[right]));//将中间数的小标与最后一个元素交换，防止出现最坏情况；
	int key = a[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			++left;
		}
		while (left < right && a[right] >= key)
		{
			--right;
		}
		Swap(&(a[left]), &(a[right]));
	}
	Swap(&(a[left]), &(a[key_index]));
	return left;
}
void Quicksort1(int* a, int left, int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);
		int div = SingleSort1(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&s, left);
			StackPush(&s, div - 1);
		}
		if (div + 1 < end)
		{ 
			StackPush(&s, div + 1); 
		    StackPush(&s, end); 
		}
	}

}
void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int array[] = { 10, 3, 5, 7, 9, 2, 4, 6, 8, 1 };
	int arraysize = sizeof(array) / sizeof(int);
	Quicksort1(array, 0, arraysize - 1);
	PrintSort(array, arraysize);
	system("pause");
	return 0;
}