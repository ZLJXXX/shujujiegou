#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
//ֱ�Ӳ�������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);
//ѡ������
void SelectSort(int* a, int n);
//������
void HeapSort(int* a, int n);
//ð������
void Bubblesort(int* a, int n);
//��������
void QuickSort1(int* a, int left,int right);//����ָ�뷨
void QuickSort2(int* a, int left, int right);//�ڿӷ�
void QuickSort3(int* a, int left, int right);//����ָ�뷨
void PrintSort(int* a, int n);



void TestSort();