#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct Node//һ���ڵ�
{
	struct Node* _next;
	int _data;
}Node;
typedef struct Queue//����
{
	Node *_front;//ͷ�ڵ�
	Node *_rear;//β�ڵ�
	int size;//Ԫ�ظ���
}Queue;
void queueInit(Queue *q)//��ʼ������
{
	q->_front = q->_rear = NULL;
	q->size = 0;
}
void print(Queue *q)
{
	Node *cur = q->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}
void queueInsert(Queue *q)//���,�Ӷ�ͷ���β��ӡ
{
	int x = 0;
	printf("������������ӵ�Ԫ��#:");
	scanf("%d", &x);
	Node *node = (Node *)malloc(sizeof(Node));
	node->_data = x;
	node->_next = NULL;
	if (q->_front == NULL)
	{
		q->_front = q->_rear = node;
		q->size++;
	}
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
		q->size++;
	}
	print(q);
	printf("\n");
}
void queueDel(Queue *q)//����
{
	if (q->_front != NULL)
	{
		Node *next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		print(q);
	}
	else
	{
		q->_rear = NULL;
		printf("��ʱ����Ϊ��,���ɽ��г��Ӳ���!!!\n");
	}
	q->size--;
}
void queueTop(Queue *q)
{
	printf("%d", q->_front->_data);
}
void queueRear(Queue *q)
{
	printf("%d", q->_rear->_data);
}
void queueEmpty(Queue *q)
{
	if (q->_front == NULL)
	{
		printf("��ʱ����Ϊ��!!!\n");
	}
	else
	{
		printf("��ʱ���в�Ϊ��!!!\n");
	}
}
void queueSize(Queue *q)
{
	printf("%d", q->size);
}
void queueDistory(Queue *q)
{
	Node *cur = q->_front;
	Node *next = q->_front;
	while(cur)
	{
		next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		cur = next;
	}
	printf("�˶����ѱ�����!!!\n");
}
int main()
{
	Queue q;
	queueInit(&q);
	int select = 0;
	int quit = 0;
	printf("1����� 2������ 3���鿴��ͷԪ�� 4���鿴��βԪ�� 5���ж������Ƿ�Ϊ�� 6���鿴����Ԫ�ظ��� 7�����ٶ��� 8���˳�\n");
	while (!quit)
	{
		printf("������������еĲ���#:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			queueInsert(&q);
			break;
		case 2:
			queueDel(&q);
			break;
		case 3:
			queueTop(&q);
			break;
		case 4:
			queueRear(&q);
			break;
		case 5:
			queueEmpty(&q);
			break;
		case 6:
			queueSize(&q);
			break;
		case 7:
			queueDistory(&q);
			break;
		case 8:
			quit = 1;
			break;
		}
	}
}