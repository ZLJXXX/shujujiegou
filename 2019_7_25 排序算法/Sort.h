#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
//Ö±½Ó²åÈëÅÅĞò
void InsertSort(int* a, int n);
//Ï£¶ûÅÅĞò
void ShellSort(int* a, int n);
//Ñ¡ÔñÅÅĞò
void SelectSort(int* a, int n);
//¶ÑÅÅĞò
void HeapSort(int* a, int n);
//Ã°ÅİÅÅĞò
void Bubblesort(int* a, int n);
//¿ìËÙÅÅĞò
void QuickSort1(int* a, int left,int right);//×óÓÒÖ¸Õë·¨
void QuickSort2(int* a, int left, int right);//ÍÚ¿Ó·¨
void QuickSort3(int* a, int left, int right);//×óÓÒÖ¸Õë·¨
void PrintSort(int* a, int n);



void TestSort();