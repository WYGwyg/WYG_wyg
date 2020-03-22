#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define NUM 10
typedef int Datetype;
typedef struct SeqList
{
	Datetype *Data;
	size_t count;//˳���������
	size_t size;//˳���ǰռ�˶��ٸ�Ԫ��
}seqlist;
void test(seqlist *cp)//��˳���ֵ���Ա��ڶ�˳��������ɾ���ġ��鹦�ܽ��в���
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cp->Data[i] = i;
		cp->size += 1;
	}
}
void SeqListInit(seqlist *cp)//˳����ʼ��
{
	cp->Data = (Datetype*)malloc(sizeof(seqlist) * NUM);
	if (cp->Data == NULL)
	{
		printf("����ռ�ʧ��!!!\n");
		exit(1);
	}
	cp->count = NUM;
	cp->size = 0;
}
void SeqListAdd(seqlist *cp)//˳�������Ԫ��
{
	size_t value = 0;
	size_t pos = 0;
	size_t i = 0;
	printf("��������Ҫ�������#:");
	scanf("%d", &value);
	printf("��ѡ����������λ��#:");
	scanf("%d", &pos);
	for (i = cp->size; i > pos; i--)
	{
		cp->Data[i] = cp->Data[i - 1];
	}
	cp->Data[pos] = value;
	cp->size += 1;
	for (i = 0; i < cp->size; i++)
	{
		printf("%d ", cp->Data[i]);
	}
	printf("\n");
}
void SeqListDel(seqlist *cp)//˳������
{
	size_t pos = 0;
	size_t i = 0;
	printf("����������Ҫɾ����λ��#:");
	scanf("%d", &pos);
	if (pos >= 0 && pos <= cp->size - 1)
	{
		for (i = pos + 1; i < cp->size; i++)
		{
			cp->Data[i - 1] = cp->Data[i];
		}
		cp->size -= 1;
		for (i = 0; i < cp->size; i++)
		{
			printf("%d ", cp->Data[i]);
		}
		printf("\n");
	}
}
void SeqListCheck(seqlist *cp)//˳������
{
	size_t pos = 0;
	printf("������������ҵ�λ��#:");
	scanf("%d", &pos);
	printf("%d", cp->Data[pos]);
	printf("\n");
}
void SeqListChange(seqlist *cp)//˳����޸�
{
	size_t value = 0;
	size_t pos = 0;
	size_t i = 0;
	printf("����������ĵ�����#:");
	scanf("%d", &value);
	printf("����������ĵ�λ��#:");
	scanf("%d", &pos);
	cp->Data[pos] = value;
	for (i = 0; i < cp->size; i++)
	{
		printf("%d ", cp->Data[i]);
	}
	printf("\n");
}
int main()
{
	seqlist cp;
	SeqListInit(&cp);
	test(&cp);
	int quit = 0;
	while (!quit)
	{
		printf("����������Ҫѡ��Ĳ���# 1����  2��ɾ  3����  4����  5���˳�:\n");
		int select = 0;
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			SeqListAdd(&cp);
			break;
		case 2:
			SeqListDel(&cp);
			break;
		case 3:
			SeqListCheck(&cp);
			break;
		case 4:
			SeqListChange(&cp);
			break;
		case 5:
			quit = 1;
			break;
		}
	}
	system("pause");
	return 0;
}