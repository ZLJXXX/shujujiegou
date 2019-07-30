#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
//ֱ�Ӳ�������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)//���i�ߵ�n-1��λ�ã���tmp����Խ��
	{
		int end = i;//һ�α���
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
//ϣ������
//1.ͨ��gap���з���Ԥ����
//2.ֱ�Ӳ�������
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
//ѡ������
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
	//�ҵ����Ԫ�غ���СԪ�ص��±�
	//�������� begin = end;ż������ begin > end;
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
//������
//���򽨴��
//�ѵĳ�ʼ��
void AdjustDown(int* array, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ���С����
		if (child + 1 < n && array[child] < array[child + 1])
		{
			child++;
		}
		//�ϴ��Ӵ���˫�ף�����
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
	for (int j = n; j >=0 ; j--)//�߶��ɣ�ÿ��һ�� ��Ҫ����������--;
	{
		//����һ�� ���������ҳ���
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
//���ŵ��Ż��㷨������ȡ�з�
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
//��������ָ�뷨��������
int SingleSort1(int* a, int left, int right)
{
	int index = GetMinindex(a, left, right);
	Swap(&(a[index]), &(a[right]));//���м�����С�������һ��Ԫ�ؽ�������ֹ����������
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
//�ڿӷ���������
int SingleSort2(int* a, int left, int right)
{
	int index = GetMinindex(a, left, right);
	Swap(&(a[index]), &(a[right]));//���м�����С�������һ��Ԫ�ؽ�������ֹ����������
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
//ǰ��ָ�뷨
int SingleSort3(int* a, int left, int right)
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		//cur��keyС�������ҵ���prevҲ++����������򽻻�
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
void QuickSort1(int* a, int left,int right)//����ָ�뷨���ɲ��õݹ����
{    if (left >= right)
		return;                                                                         
	int key = SingleSort1(a, left, right);
	QuickSort1(a, left, key - 1);
	QuickSort1(a, key + 1, right);
}
void QuickSort2(int* a, int left, int right)//�ڿӷ����˵ݹ����
{
	if (left >= right)
		return;
	int key = SingleSort2(a, left, right);
	QuickSort2(a, left, key - 1);
	QuickSort2(a, key + 1, right);
}
void QuickSort3(int* a, int left, int right)//ǰ��ָ�뷨
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