#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
#define USER "WYG"
#define PSD "123456"
int main()
{
	int count = 3;
	while (count > 0)
	{
		count--;
		char name[32];
		char passwd[32];
		printf("�������û���#:\n");
		scanf("%s", &name);
		printf("����������#:\n");
		scanf("%s", &passwd);
		if (strcmp(USER, name) == 0 && strcmp(PSD, passwd) == 0)
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("�û����������������,����������\n");
		}
	}
	system("pause");
	return 0;
}