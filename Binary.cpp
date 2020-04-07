#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
//����һ��ջ����ʵ����ջ��ջ��ȡջ��Ԫ�صĲ���
#define num 10
typedef char BDataType;
typedef struct Node//��������һ���ڵ�
{
	struct Node *_left;
	struct Node *_right;
	BDataType _data;
}Node;
typedef Node* SDataType;
typedef struct stack//����ջ
{
	SDataType *_array;
	int _count;//��������С
	int _size;//��ǰԪ�ش�С
}stack;
void stackInit(stack *st)//ջ�ĳ�ʼ��
{
	st->_array = (SDataType*)malloc(sizeof(SDataType)*num);
	st->_count = num;
	st->_size = 0;
}
void stackInsert(stack *st, SDataType value)//��ջ
{
	if (st->_size == st->_count)//�ռ���������Ҫ����
	{
		st->_array = (SDataType*)realloc(st->_array, sizeof(SDataType)*(2 * st->_count));
		st->_count = 2 * st->_count;
	}
	st->_array[st->_size] = value;
	st->_size++;
}
void stackDel(stack *st)//��ջ
{
	if (st->_size == 0)
	{
		printf("ջ��Ϊ�գ����ܳ�ջ!!!\n");
	}
	st->_size--;
}
 SDataType stackTop(stack *st)//��ȡջ��Ԫ��
{
	 return st->_array[st->_size - 1];
}
int stackEmpty(stack *st)//�ж�ջ�Ƿ�Ϊ��
{
	if (st->_size == 0)
	{
		return 1;
	}
	return 0;
}
//��ջ��ʵ�ֶ������ķǵݹ�����ֱ�������
//�ȴ���һ����
Node *TreeCreat(BDataType *array, int *pos)//����һ��������������������и�������
{
	if (array[*pos] != '#')
	{
		Node *root = (Node *)malloc(sizeof(Node));
		root->_data = array[*pos];
		(*pos)++;
		root->_left = TreeCreat(array, pos);
		(*pos)++;
		root->_right = TreeCreat(array, pos);
		return root;
	}
	else
	{
		return NULL;
	}
}
//1��ǰ�����
void preOrder(Node *root)//ǰ������ǵݹ�
{
	printf("ǰ�����#: ");
	stack st;
	stackInit(&st);
	Node *cur = root;
	Node *top;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			stackInsert(&st, cur);
			cur = cur->_left;
		}
		top = stackTop(&st);
		stackDel(&st);
		cur = top->_right;
	}
	printf("\n");
}
//2���������
void MidOrder(Node *root)//��������ǵݹ�
{
	printf("ǰ�����#: ");
	stack st;
	stackInit(&st);
	Node *cur = root;
	Node *top;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			stackInsert(&st, cur);
			cur = cur->_left;
		}
		top = stackTop(&st);
		stackDel(&st);
		printf("%c ", top->_data);
		cur = top->_right;
	}
	printf("\n");
}
//3���������
void EndOrder(Node *root)//��������ǵݹ�
{
	printf("ǰ�����#: ");
	stack st;
	stackInit(&st);
	Node *cur = root;
	Node *top;
	Node *prev = NULL;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			stackInsert(&st, cur);
			cur = cur->_left;
		}
		top = stackTop(&st);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			stackDel(&st);
			prev = top;
		}
		else
		{
			cur = top->_right;
		}
	}
	printf("\n");
}
int main()
{
	BDataType array[100];//����һ��char����
	scanf("%s", array);
	int pos = 0;
	Node *root = TreeCreat(array, &pos);
	preOrder(root);//ǰ�����
	MidOrder(root);//�������
	EndOrder(root);//�������
	system("pause");
	return 0;
}


