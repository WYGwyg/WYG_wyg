#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct Node//����һ���ڵ�ṹ��
{
	int _date;
	struct Node *_next;
}Node;
typedef struct SList//����һ��ͷ�ڵ�
{
	Node *head;
}slist;
Node *CreateNode(int date)//����һ���ڵ㣬�����в����пɵ����������
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->_date = date;
	node->_next = NULL;
	return node;
}
void Print(slist *sl)//��ӡ�����е�����Ԫ�أ������в����пɵ����������
{
	Node *cur = sl->head;
	while (cur)
	{
		printf("%d ", cur->_date);
		cur = cur->_next;
	}
}
void SListInit(slist *sl)//�����ʼ��Ϊ��
{
	sl->head = NULL;
}
void test(slist *sl)//��ͷ�巨������ֵһЩ���ݣ��Ա��ں�������ļ��
{
	int i = 0;
	Node *node = NULL;
	for (i = 5; i > 0; i--)
	{
		node = CreateNode(i);
		if (sl->head == NULL)
		{
			sl->head = node;
		}
		else
		{
			node->_next = sl->head;
			sl->head = node;
		}
	}
	printf("�������²���֮ǰ����Ԫ������\n");
	Print(sl);
	printf("\n");
}
void SListAdd(slist *sl)//������������һ��Ԫ��
{
	int x = 0;
	int n = 0;
	printf("����������������#:");
	scanf("%d", &n);
	printf("��������������ĸ����ĺ���#:");
	scanf("%d", &x);
	Node *cur = sl->head;
	while (cur)
	{
		if (cur->_date == x)
		{
			Node *newnode = CreateNode(n);
			newnode->_next = cur->_next;
			cur->_next = newnode;
		}
		cur = cur->_next;
	}
	Print(sl);
	printf("\n");
}
void SListDel(slist *sl)//ɾ�������е�һ��Ԫ��
{
	if (sl->head == NULL)
	{
		printf("����Ϊ�գ�����ɾ��!!!\n");
		return;
	}
	else if (sl->head->_next == NULL)
	{
		free(sl->head);
		sl->head = NULL;
		return;
	}
	int x = 0;
	printf("����������ɾ������#:");
	scanf("%d", &x);
	Node *cur = sl->head;
	Node *pre = NULL;
	while (cur)
	{
		if (cur->_date == x)
		{
			pre->_next = pre->_next->_next;
			free(cur);
			Print(sl);
			printf("\n");
			return;
		}
		pre = cur;
		cur = cur->_next;
	}
	printf("û���ҵ�����ɾ������!!!\n");
}
void SListChange(slist *sl)//�������е�һ��Ԫ�ؽ����޸�
{
	if (sl->head == NULL)
	{
		printf("����Ϊ�ղ����޸�!!!\n");
		return;
	}
	int x = 0;
	int n = 0;
	printf("�����������޸ĵ�Ԫ��#:");
	scanf("%d", &x);
	printf("��������������Ԫ���޸ĵ�ֵ#:");
	scanf("%d", &n);
	Node *cur = sl->head;
	while (cur)
	{
		if (cur->_date == x)
		{
			cur->_date = n;
			Print(sl);
			printf("\n");
			return;
		}
		cur = cur->_next;
	}
	printf("û�ҵ������޸ĵ���!!!\n");
}
void SListcheck(slist *sl)//���������е�һ��Ԫ��
{
	int x = 0;
	printf("������������ҵ���#:");
	scanf("%d", &x);
	Node *cur = sl->head;
	while (cur)
	{
		if (cur->_date == x)
		{
			printf("������ҵ���Ϊ:%d\n", cur->_date);
			printf("\n");
			return;
		}
		cur = cur->_next;
	}
	printf("û�ҵ�\n");
}
int main()
{
	slist sl;
	SListInit(&sl);
	test(&sl);
	int quit = 0;
	int select = 0;
	printf("������������еĲ���#: 1����  2��ɾ  3����  4����  5���˳�\n");
	while (!quit)
	{
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			SListAdd(&sl);
			break;
		case 2:
			SListDel(&sl);
			break;
		case 3:
			SListChange(&sl);
			break;
		case 4:
			SListcheck(&sl);
			break;
		case 5:
			quit = 1;
			break;
		}
	}
	system("pause");
	return 0;
}