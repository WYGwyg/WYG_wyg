#include"game.h"
int main()
{
	char name[32];
	char passed[32];
	int count = 3;
	while (count > 0)
	{
		count--;
		printf("*************************\n");
		printf("*��ӭ�����ҵ���Ϸ����!!!*\n");
		printf("*************************\n");
		printf("\n");
		printf("��������е�����###:\n");
		scanf("%s", &name);
		printf("����������######:\n");
		scanf("%s", &passed);
		if (strcmp(USER, name) == 0 && \
			strcmp(PSD, passed) == 0)
		{
			printf("������ȷ!!!\n");
			break;
		}
		else
		{
			printf("�û��������������������������:\n");
			continue;
		}
		printf("\n");
	}
	if (count > 0)
	{
		printf("��¼�ɹ�!!!\n");
		int i = 9;
		while (i > 0)
		{
			printf("������!!!...................%d\r",i);
			Sleep(1000);
			i--;
		}
		printf("���ڼ���.........................���Ե�!!!\n");
		printf("���سɹ�!!!\n");
	}
	int quit = 0;
	while (!quit)
	{
		Menu();
		int select = 0;
		printf("���������ѡ��\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game();//������
			break;
		case 2:
			Game();//ɨ��
			break;
		case 3:
			GAme();//������
			break;
		case 4:
			quit = 1;
			break;
		default:
			printf("��ѡ������������ѡ��\n");
			break;
		}
	}
	printf("�ݰ��ˣ���ӭ�´�����!!!\n");
	system("pause");
	return 0;
}