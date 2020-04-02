#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef char DataType;
typedef struct Node//����һ�����
{
	struct Node *_left;
	struct Node *_right;
	DataType _data;
}Node;
typedef struct BinaryTree//������
{
	Node *root;
}BinaryTree;
Node *Treecreat(DataType *array, int *idx)//��ǰ���������һ��������
{
	if (array[*idx] != '#')
	{
		Node *root = (Node *)malloc(sizeof(Node));
		root->_data = array[*idx];
		(*idx)++;
		root->_left = Treecreat(array, idx);
		(*idx)++;
		root->_right = Treecreat(array, idx);
		return root;
	}
	else
	{
		return NULL;
	}
}
void InOrder(Node *root)
{
	if (root)
	{
		InOrder(root->_left);
		printf("%c ", root->_data);
		InOrder(root->_right);
	}
}
int main()
{
	DataType array[100];
	int idx = 0;
	scanf("%s", array);
	Node *root = Treecreat(array, &idx);
	InOrder(root);
	system("pause");
	return 0;
}
