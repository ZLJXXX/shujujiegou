#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
typedef int HPDataType;

typedef struct Heap{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* _array, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
HPDataType HeapSize(Heap* hp);
void AdjustDown(HPDataType* _array, size_t n, size_t parent);
void Adjustup(HPDataType* _array, size_t child);
bool HeapEmpty(Heap* hp);
void TestHeap();