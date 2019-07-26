#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<malloc.h>
#include<Windows.h>
typedef int STDataType;
//动态开辟生长的栈
typedef struct Stack
{
	STDataType* _array;
	STDataType _top; //栈顶
	STDataType _capacity;//容量
}Stack;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
bool StackEmpty(Stack* ps);
STDataType StackSize(Stack* ps);
void TestStack();
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//先进行增容
	if (ps->_capacity == ps->_top)
	{
		STDataType newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	if (ps->_top != 0)
	{
		ps->_top--;
	}
}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top - 1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}
STDataType StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	StackDestory(&s);
	
}