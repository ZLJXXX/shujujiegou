#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
void test()
{
	SeqList s;
	SeqListInit(&s);
	////˳�������
	//SeqListNEWCapacity(&s);
	// β��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 8);
	PrintSeqList(&s);
	// βɾ 
	SeqListPopBack(&s);
	PrintSeqList(&s);
	//ͷ��
	SeqListPushFront(&s, 2);
	PrintSeqList(&s);
 //   ͷɾ
	SeqListPopFront(&s);
	PrintSeqList(&s);
	//������Ԫ�ظ���
	printf("%d \n", SeqListSize(&s));
	//����λ�ò���
	SeqListInsert(&s, 2, 3);
	PrintSeqList(&s);
	//����λ��ɾ��
	SeqListErase(&s,2);
	PrintSeqList(&s);
	//����Ԫ��
	printf("Ѱ�ҵ���Ԫ���±�Ϊ%d \n",SeqListFind(&s, 5));
	// ��ȡ˳�������� 
	SeqListCapacity(&s);
	printf("˳��������%d \n", SeqListCapacity(&s));
	// ���˳����Ƿ�Ϊ�� 
	SeqListEmpty(&s);
	// ��ȡ˳����е�һ��Ԫ�� 
	printf("˳����е�һ��Ԫ��%d \n", SeqListFront(&s));
	// ��ȡ˳��������һ��Ԫ�� 
	printf("˳��������һ��Ԫ��%d \n", SeqListBack(&s));
	//�Ƴ�˳����еĵ�һ��data
	SeqListRemove(&s, 5);
	PrintSeqList(&s);
	// �Ƴ�˳���������ֵΪdata��Ԫ�� 
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