#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//自己实现简单的单链表
typedef struct ListNode{
	int val;
	ListNode* next;
}ListNode;
typedef struct List{
	ListNode* _head;
}List;
void ListInit(List* plt){
	plt->_head = NULL;
}
void List_pushback(List* plt,int data)
{
	ListNode* newnode = new ListNode;
	newnode->val = data;
	newnode->next = NULL;
	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else{
		ListNode* cur = plt->_head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	
}
//不改变链表结构，只是获得链表元素保存在数组中进行翻转
/*vector<int> printListFromTailToHead(List* plt) {
	vector<int> _array;
	ListNode* cur = plt->_head;
	while (cur)
	{
		_array.push_back(cur->val);
		cur = cur->next;
	}
	reverse(_array.begin(), _array.end());
	return _array;
}*/
//改变链表结构
vector<int> printListFromTailToHead(List* plt) {
	vector<int> _array;
	ListNode* head = plt->_head;
	ListNode* cur = plt->_head;
	ListNode* prev = plt->_head;
	if (plt->_head == NULL)
		return _array;
	while (head->next != NULL)
	{
		cur = head->next;
		head->next = cur->next;
		cur->next = prev;
		prev = cur;
	}
	head = nullptr;
	while (cur)
	{
		_array.push_back(cur->val);
		cur = cur->next;
	}
	return _array;
}
int main()
{
	List s;
	ListInit(&s);
	List_pushback(&s,1);
	List_pushback(&s, 2);
	List_pushback(&s, 3);
	List_pushback(&s, 4);
	vector<int> array = printListFromTailToHead(&s);
	for (int i = 0; i < (int)array.size(); i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}
