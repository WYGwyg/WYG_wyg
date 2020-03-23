#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef int DataType;
typedef struct Stack
{
	DataType *_array;
	int _count;//�ռ������ɵ���Ԫ��
	int _size;//��ǰԪ�ظ���
}Stack;
void stackInit(Stack *st)//ջ�ĳ�ʼ��
{
	int n = 10;
	st->_array = (DataType *)malloc(sizeof(DataType)*n);
	st->_count = n;
	st->_size = 0;
}
void print(Stack *st)//��ӡջ��Ԫ�أ��ӵ����ϴ�ӡ
{
	int count = st->_size;
	st->_size = 0;
	for (st->_size=0; st->_size < count; st->_size++)
	{
		printf("%d ", st->_array[st->_size]);
	}
	st->_size = count;
	printf("\n");
}
void stackInsert(Stack *st)//��ջ��β��
{
	if (st->_size == st->_count)
	{
		st->_array = (DataType *)realloc(st->_array, sizeof(DataType) * 2 * st->_count);
		st->_count = 2 * st->_count;
	}
	int x = 0;
	printf("������������ջ������#:");
	scanf("%d", &x);
	st->_array[st->_size] = x;
	st->_size++;
	print(st);
}
void stackDel(Stack *st)//��ջ,ÿ��ջһ��ջ��Ԫ�ؾ���һ��
{
	if (st->_size > 0)
	{
		st->_size--;
		print(st);
	}
	else
	{
		printf("��ջ����ջ���Ѿ�û��Ԫ����!!!\n");
	}
}
void stackTop(Stack *st)
{
	if (st->_size > 0)
	{
		printf("%d", st->_array[st->_size-1]);
		printf("\n");
	}
	else
	{
		printf("����ʧ�ܣ�ջ��û��Ԫ��!!!\n");
	}
}
void stackSize(Stack *st)
{
	printf("%d", st->_size);
	printf("\n");
}
void stackEmpty(Stack *st)
{
	if (st->_size == 0)
	{
		printf("��ʱջΪ��!!!\n");
	}
	else
	{
		printf("��ʱջ��Ϊ��!!!\n");
	}
}
void stackDestory(Stack *st)
{
	if (st->_array)
	{
		free(st->_array);
		st->_size = st->_count = 0;
		printf("ջ�ѱ�����!!!\n");
	}
}
int main()
{
	Stack st;
	stackInit(&st);
	int select = 0;
	printf("1����ջ 2����ջ 3���鿴ջ��Ԫ�� 4���鿴ջԪ�ظ��� 5���鿴ջ�Ƿ�Ϊ�� 6������ջ 7���˳�\n");
	int quit = 0;
	while (!quit)
	{
		printf("������������еĲ���#:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			stackInsert(&st);
			break;
		case 2:
			stackDel(&st);
			break;
		case 3:
			stackTop(&st);
			break;
		case 4:
			stackSize(&st);
			break;
		case 5:
			stackEmpty(&st);
			break;
		case 6:
			stackDestory(&st);
			break;
		case 7:
			quit = 1;
			break;
		}
	}
	system("pause");
	return 0;
}