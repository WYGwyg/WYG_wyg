#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
#define USER "WYG"
#define PSD "123456"
Menu()
{
	printf("***************************************************\n");
	printf("*******           ��������Ϸ             **********\n");
	printf("********1��play                   2��Exit**********\n");
	printf("***************************************************\n");
}
play()
{
	int n = 0;
	int count = 0;
	int x = rand() % 100 + 1;
	do
	{
		printf("����������µ�����:\n");
		scanf("%d", &n);
		if (x > n)
		{
			printf("���С��\n");
			count++;
		}
		else if (x < n)
		{
			printf("��´���\n");
			count++;
		}
		else
		{
			printf("��¶���\n");
			break;
		}
	} while (1);
	printf("���ܹ�����%d��", count + 1);
}
int main()
{
	char name[16];
	char passwd[16];
	int count = 3;
	while (count > 0)
	{
		count--;
		printf("�������û���#:\n");
		scanf("%s", &name);
		printf("����������#:\n");
		scanf("%s", &passwd);
		if (strcmp(USER, name) == 0 && strcmp(PSD, passwd) == 0)
		{
			printf("�˺�����������ȷ\n");
			break;
		}
		else
		{
			printf("�˺Ż����������������������\n");
		}
		printf("�㻹��%d�λ���", count);
	}
	int quit = 0;
	while (!quit)
	{
		srand((unsigned long)time(NULL));
		Menu();
		int select = 0;
		printf("���������ѡ��:\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			play();
		case 2:
			quit = 1;
			break;
		default:
			printf("ѡ�����,������ѡ��:\n");
			continue;
		}
	}
	return 0;
}