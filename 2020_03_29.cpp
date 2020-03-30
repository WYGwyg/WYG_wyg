#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
typedef struct heap
{
	int *_array;
	int _size;//��ǰ����
	int _count;//������
}heap;
void swap(int *arr, int child, int parent)//���������ѽڵ�
{
	int temp = arr[child];
	arr[child] = arr[parent];
	arr[parent] = temp;
}
void print(heap *hp)//��ӡ��
{
	int i = 0;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
}
void heapShiftDown(int *arr, int size, int parent)//�Ӹ��ڵ����µ���
{
	int child = 2 * parent + 1;//���ҵ�����
	while (child  < size)
	{
		if (child + 1 <size &&  arr[child] < arr[child + 1])
		{
			child += 1;
		}
		if (arr[child] > arr[parent])
		{
			swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void heapInit(heap *hp, int *arr, int size)//�ѵĳ�ʼ�����൱�ڹ���һ����
{
	int i = 0;
	int j = (size - 2) / 2;
	hp->_array = (int *)malloc(sizeof(int)*size);//���������С���ռ�
	memcpy(hp->_array, arr, sizeof(int)*size);//������������ݿ��������ٵĶѿռ���
	hp->_size = hp->_count = size;
	for (i = j; i >= 0; i--)
	{
		heapShiftDown(hp->_array, size, i);
	}
	print(hp);
}
void heapShiftUp(int *arr, int child)//�Ӻ��ӽڵ����ϵ���
{
	int parent = (child - 1) / 2;
	while (child > 0)//while(parent>=0)Ҳ����
	{
		if (arr[child] > arr[parent])
		{
			swap(arr, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void heapInster(heap *hp,int *arr)//���
{
	if (hp->_count == hp->_size)//�����ǰԪ�ظ������������������ʱ��Ҫ����
	{
		hp->_count = 2 * hp->_count;
		hp->_array = (int *)realloc(hp->_array,sizeof(int)*(hp->_count));
	}
	int value = 0;
	printf("��������������ֵ#:");
	scanf("%d", &value);
	hp->_array[hp->_size] = value;
	hp->_size++;
	heapShiftUp(hp->_array, hp->_size - 1);
	print(hp);
	printf("\n");
}
void heapDel(heap *hp)//����
{
	if (hp->_size == 0)
	{
		printf("��ʱ��Ϊ�գ����ܳ���!!!\n");
	}
	else
	{
		hp->_array[0] = hp->_array[hp->_size - 1];
		hp->_size--;
		heapShiftDown(hp->_array, hp->_size, 0);
		print(hp);
		printf("\n");
	}
}
void heapTop(heap *hp)//�鿴�Ѷ�Ԫ��
{
	printf("%d", hp->_array[0]);
	printf("\n");
}
void heapSize(heap *hp)//�鿴��Ԫ�ظ���
{
	printf("%d", hp->_size);
	printf("\n");
}
void heapEmpty(heap *hp)//�ж϶��Ƿ�Ϊ��
{
	if (hp->_size == 0)
	{
		printf("��ʱ��Ϊ��!!!\n");
	}
	else
	{
		printf("��ʱ�Ѳ�Ϊ��!!!\n");
	}
}
int main()
{
	heap hp;
	int arr[] = { 20, 40, 8, 56, 90, 4, 67, 23, 45, 60 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("�Ѵ����õĶ�����:  ");
	heapInit(&hp, arr, size);
	printf("\n");
	printf("1�����  2������  3���鿴�Ѷ�Ԫ��  4���鿴��Ԫ�ظ���  5���п�  6���˳�\n");
	int select = 0;
	int quit = 0;
	while (!quit)
	{
		printf("������������еĲ���#:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			heapInster(&hp, arr);
			break;
		case 2:
			heapDel(&hp);
			break;
		case 3:
			heapTop(&hp);
			break;
		case 4:
			heapSize(&hp);
			break;
		case 5:
			heapEmpty(&hp);
			break;
		case 6:
			quit = 1;
			break;
		}
	}
	system("pause");
	return 0;
}



