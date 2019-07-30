#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
//直接插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)//如果i走到n-1的位置，则tmp访问越界
	{
		int end = i;//一次遍历
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;

	}
	
}
//希尔排序
//1.通过gap进行分组预排序
//2.直接插入排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//选择排序
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	//找到最大元素和最小元素的下标
	//奇数数组 begin = end;偶数数组 begin > end;
	while (begin <= end)
	{
		int min = begin;
		int max = end;
		for (int i = begin ; i <=end; i++)
		{
			if (a[min] >= a[i])
			{
				Swap(&(a[min]),&(a[i]));
			}
			if (a[max] <= a[i])
			{
				Swap(&(a[max]), &a[i]);
			}
			
		}
		Swap(&(a[min]), &(a[begin]));
		Swap(&(a[max]), &a[end]);
		if (max = begin)
		{
				max = min;
		}
		begin++;
		end--;
	}
}
//堆排序
//升序建大堆
//堆的初始化
void AdjustDown(int* array, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出最小孩子
		if (child + 1 < n && array[child] < array[child + 1])
		{
			child++;
		}
		//较大孩子大于双亲，交换
		if (array[child]>array[parent])
		{
			Swap(&(array[child]), &(array[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a,int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	while (n > 1)
	{
		Swap(&(a[n - 1]), &(a[0]));
		n--;
		AdjustDown(a, n, 0);
	}
}
void Bubblesort(int* a, int n)
{
	for (int j = n; j >=0 ; j--)//走多躺，每走一趟 其要便利的数组--;
	{
		//先走一趟 把最大的数找出来
		for (int i = 1; i < j; ++i)
		{
			if (a[i - 1]>a[i])
			{
				Swap(&(a[i - 1]), &(a[i]));
			}
		}
		n--;
	}
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
//快排左右指针法单趟排序
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
//挖坑法单趟排序
int SingleSort2(int* a, int left, int right)
{
	int index = GetMinindex(a, left, right);
	Swap(&(a[index]), &(a[right]));//将中间数的小标与最后一个元素交换，防止出现最坏情况；
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] < key)
		{
			++left;
		}
		a[right] = a[left];
		while (left < right && a[right] > key)
		{
			--right;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}
//前后指针法
int SingleSort3(int* a, int left, int right)
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		//cur找key小的数，找到则prev也++，若不相等则交换
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&(a[cur]), &(a[prev]));
		}
		cur++;
	}
	++prev;
	Swap(&(a[cur]), &(a[prev]));
	return prev;
}
void QuickSort1(int* a, int left,int right)//左右指针法多躺采用递归调用
{    if (left >= right)
		return;                                                                         
	int key = SingleSort1(a, left, right);
	QuickSort1(a, left, key - 1);
	QuickSort1(a, key + 1, right);
}
void QuickSort2(int* a, int left, int right)//挖坑法多趟递归调用
{
	if (left >= right)
		return;
	int key = SingleSort2(a, left, right);
	QuickSort2(a, left, key - 1);
	QuickSort2(a, key + 1, right);
}
void QuickSort3(int* a, int left, int right)//前后指针法
{
	if (left >= right)
		return;
	int key = SingleSort3(a, left, right);
	QuickSort3(a, left, key - 1);
	QuickSort3(a, key + 1, right);
}
void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestSort()
{
	int array[] = { 10, 3, 5, 7, 9, 2, 4, 6, 8, 1 };
	int arraysize = sizeof(array) / sizeof(int);
	//InsertSort(array, arraysize);
	//ShellSort(array, arraysize);
	//SelectSort(array, arraysize);
	
	//HeapSort(array, arraysize);
	//Bubblesort(array, arraysize);
	//QuickSort1(array,0, arraysize - 1);
	//QuickSort2(array,0, arraysize - 1);
	QuickSort3(array, 0, arraysize - 1);
	PrintSort(array, arraysize);
}