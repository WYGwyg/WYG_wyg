//���ߣ������
//�༶�����繤��1801
//ʱ�䣺2019_12_25
//��Ŀ�����������������30000���������������˳����ҡ��۰����
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
#define MAX 10
void OrderFind(int a[], int num)
{
	clock_t start;
	clock_t finish;
	double time;
	int i = 0;
	start = clock();
	for (i = 0; i < MAX; i++)
	{
		if (a[i] == num)
		{
			printf("ͨ��˳������ҵ�������%d\n", a[i]);
			break;
		}
	}
	if (i == MAX)
	{
		printf("˳�����δ�ҵ�������\n");
		return;
	}
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("��˳���������ʱ��Ϊ%f\n", time);
}
void HalfFind(int a[], int num)
{
	clock_t start = 0;
	clock_t finish;
	double time;
	int left = 0;
	int right = MAX - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] < num)
		{
			left = mid + 1;
		}
		else if (a[mid]>num)
		{
			right = mid - 1;
		}
		else
		{
			printf("�������ѱ��ҵ�Ϊ%d\n", a[mid]);
			break;
		}
		if (left > right)
		{
			printf("������δ�ҵ�\n");
			return;
		}
	}
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("���۰��������ʱ��Ϊ%f\n", time);
}
int main()
{
	srand((unsigned long)time(NULL));
	printf("******************************************\n");
	printf("*******       1-->˳�����         *******\n");
	printf("*******       2-->�۰����         *******\n");
	printf("*******       3-->�˳�             *******\n");
	int a[MAX] = { 0 };
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		a[i] = rand() % 10 + 1;
	}
	printf("�漴���ɵ�30000����Ϊ\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", a[i]);
	}
	int num = rand() % 10 + 1;//������ɵ�һ��������
	printf("������ɵ�����Ϊ%d\n", num);
	int quit = 0;
	while (!quit)
	{
		int select = 0;
		printf("���������ѡ��#\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			OrderFind(a, num);
			break;
		case 2:
			HalfFind(a, num);
			break;
		case 3:
			quit = 1;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}