#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
void test()
{
	SeqList s;
	SeqListInit(&s);
	////顺序表增容
	//SeqListNEWCapacity(&s);
	// 尾插
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 8);
	PrintSeqList(&s);
	// 尾删 
	SeqListPopBack(&s);
	PrintSeqList(&s);
	//头插
	SeqListPushFront(&s, 2);
	PrintSeqList(&s);
 //   头删
	SeqListPopFront(&s);
	PrintSeqList(&s);
	//所存在元素个数
	printf("%d \n", SeqListSize(&s));
	//任意位置插入
	SeqListInsert(&s, 2, 3);
	PrintSeqList(&s);
	//任意位置删除
	SeqListErase(&s,2);
	PrintSeqList(&s);
	//查找元素
	printf("寻找到的元素下标为%d \n",SeqListFind(&s, 5));
	// 获取顺序表的容量 
	SeqListCapacity(&s);
	printf("顺序表的容量%d \n", SeqListCapacity(&s));
	// 检测顺序表是否为空 
	SeqListEmpty(&s);
	// 获取顺序表中第一个元素 
	printf("顺序表中第一个元素%d \n", SeqListFront(&s));
	// 获取顺序表中最后一个元素 
	printf("顺序表中最后一个元素%d \n", SeqListBack(&s));
	//移除顺序表中的第一个data
	SeqListRemove(&s, 5);
	PrintSeqList(&s);
	// 移除顺序表中所有值为data的元素 
	SeqListRemoveAll(&s, 5);
	PrintSeqList(&s);
	SeqListDestroy(&s);
}
int main()
{
	test();
	system("pause");
	return 0;
}