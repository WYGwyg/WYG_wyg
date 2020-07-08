#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <conio.h> 
#pragma warning(disable:4996)
#define N 100 

struct employee//ְ���������
{
	char num[6];//���
	char name[8];//����
	char birth[8];//��������
	char workplace[10];//�������� 
	char salarylevel[8];//���ʼ���
	char position[8];//ְ��
	char tel[16];//�绰
	char sex;//�Ա�fΪŮmΪ��
} em[N];


/*��Ҫ����*/


void input();//���ְ����Ϣ
void display();//��ʾְ����Ϣ
void save();//����ְ����Ϣ
void change();//�޸�ְ����Ϣ
void search();
void searchByname();//����������
void searchBynum();//����Ų��� 
void Delete();

int total = 0;//����total��������¼�� 
int i = 0;

void main(){
	int choice;
	do
	{
		printf("                                        *                \n");//ϵͳ��ӭ���� 
		printf("                                      *   *                 \n");
		printf("                              * * * *       * * * *            \n");
		printf("                               *                *         \n");
		printf("                         _____��ӭ����ְ������ϵͳ_____\n");
		printf("                                   *          *         \n");
		printf("                                  *      *     *       \n");
		printf("                                *   *       *   *       \n");
		printf("                               *                 *     \n");
		printf("                                ����ѡ���������:  \n");
		printf("                           =============================== \n");
		printf("                                 1.���ְ����Ϣ\n");//�û�ѡ�� 
		printf("                                 2.��ʾְ����Ϣ\n");
		printf("                                 3.����ְ����Ϣ\n");
		printf("                                 4.�޸�ְ����Ϣ\n");
		printf("                                 5.ɾ��ְ����Ϣ\n");
		printf("                                 0. �˳�ϵͳ\n");
		printf("                           ================================\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			input();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			change();
			break;
		case 5:
			Delete();
			break;
		case 0:
		{
			printf("ллʹ��!�ټ�! ");
			exit(0);//�˳�ϵͳ 
		}
		default:
		{printf("�����д�������������: ");
		return;
		}
		}
	} while (1);//��Ϊ��ֵʱִ��doѭ��
}

void input()
{
	char j = '\0';//��ʼ��jֵΪ��
	do
	{
		total++;
		i++;
		printf("��%d��ְ��:\n", i);
		printf("����������: ");//������ 
		scanf("%s", em[i].num);
		printf("������������: ");//��������
		scanf("%s", em[i].name);
		printf("���������Ա���(m��fŮ): ");//�����Ա� 
		getchar();
		scanf("%c", &em[i].sex);
		printf("���������������(��ʽ�磺1990.03): ");//����������� 
		scanf("%s", em[i].birth);
		printf("�������빤������: ");//���빤������
		scanf("%s", em[i].workplace);
		printf("��������ְλ: ");//����ְλ 
		scanf("%s", em[i].position);
		printf("�������빤�ʼ���: ");//���빤�ʼ� 
		scanf("%s", em[i].salarylevel);
		printf("����������ϵ�绰: ");//������ϵ�绰 
		scanf("%s", em[i].tel);
		printf("�Ƿ��������?(y/n):");
		getchar();
		j = getchar();
		while (j != 'y'&&j != 'n')
		{
			printf("���벻�Ϸ�\n�Ƿ��������?(y/n):");
			getchar();
			j = getchar();
		}
	} while (j == 'y');
	save();//����ְ����¼
	printf("�������,�밴���������\n ");
	getch();//conio�⺯����ģ����ռ�����������~~~  
	return;
}
void save()
{
	FILE *fp;
	int i = 0;
	if ((fp = fopen("employee.txt", "ab")) == NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for (i = 1; i <= total; i++)
	{
		if (fwrite(&em[i], sizeof(struct employee), 1, fp) != 1)
			printf("file write error\n");
	}
	fclose(fp);
}
void display()//��ʾ����ְ����Ϣ
{
	FILE *fp;
	int i;
	if ((fp = fopen("employee.txt", "rb")) == NULL)
	{
		printf("�ļ���ʧ�ܻ�δ�����ļ���\n");
		return;
	}
	printf("����ְ����Ϣ����: \n");//�������ְ����Ϣ  
	printf("\n===========================================================================\n");
	printf("���   ����    �Ա�   ��������   ���ڲ���    ְ��    ���ʼ���   ��ϵ�绰\n");
	printf("===========================================================================\n");
	for (i = 1; fread(&em[i], sizeof(struct employee), 1, fp) != 0; i++)//������������  
		printf("%-6s%8s%6c%12s%10s%8s%8s%18s\n", em[i].num, em[i].name, em[i].sex, em[i].birth, em[i].workplace, em[i].position, em[i].salarylevel, em[i].tel);
	printf("��ϣ��밴���������\n ");
	getch();
	fclose(fp);
	return;
}

void search()
{
	int choice;
	printf("����ѡ����ҷ�ʽ ��\n");
	printf("1.����Ų���\n 2.����������\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:searchBynum(); break;
	case 2:searchByname(); break;
	default:printf("���������������룺\n");
	}
}

void searchBynum()
{
	FILE *fp;
	int i;
	char numb[6];
	if ((fp = fopen("employee.txt", "r")) == NULL)
	{
		printf("���ܹ�������ļ����밴���������");
		return;
	}
	printf("��������Ҫ���ҵ��˵ı��: ");
	scanf("%s", numb);
	for (i = 0; i<N; i++)//��������Ϣ�в��ҷ���Ҫ���ְ��
		if (strcmp(em[i].num, numb) == 0) //�ҵ�����ʾ��ְ����¼ 
		{
		printf("�� �� �� �� Ҫ �� ѯ �� �� �� �� Ϣ :\n");
		printf("��� ���� �Ա� �������� ���ڲ��� ְ�� ���ʼ��� ��ϵ�绰\n");
		printf("*****                                 *****\n");
		printf("%-6s%8s%6c%12s%10s%8s%8s%18s\n", em[i].num, em[i].name, em[i].sex, em[i].birth, em[i].workplace, em[i].position, em[i].salarylevel, em[i].tel);
		printf("������ϣ��밴���������\n ");
		getch();
		fclose(fp);
		return;
		}
	printf("û���������ˣ��밴���������\n");
	getch();
	fclose(fp);
	return;
}

void searchByname()
{
	FILE *fp;
	int i = 0;
	char nam[8];
	if ((fp = fopen("employee.txt", "rb")) == NULL)
	{
		printf("���ܹ�������ļ����밴���������\n");
		return;
	}
	printf("��������Ҫ���ҵ��˵�����: ");
	scanf("%s", nam);
	for (i = 0; i<N; i++)
		if (strcmp(em[i].name, nam) == 0) //�ҵ�����ʾ��ְ����¼
		{
		printf("��������Ҫ��ѯ���˵���Ϣ:\n ");
		printf("\n===========================================================================\n");
		printf("���  ����  �Ա�  ��������  ���ڲ���  ְ��  ���ʼ���  ��ϵ�绰\n");
		printf("===========================================================================\n");
		printf("%-6s%8s%6c%12s%10s%8s%8s%18s\n", em[i].num, em[i].name, em[i].sex, em[i].birth, em[i].workplace, em[i].position, em[i].salarylevel, em[i].tel);
		fclose(fp);
		printf("������ϣ��밴���������\n ");
		getch();
		return;
		}
	printf("û���������ˣ��밴���������\n ");
	getch();
	fclose(fp);
	return;
}



void change()
{
	FILE *fp;
	int i;
	char newnum[6];//�±��
	char newname[8];//������
	char newsex;//���Ա�
	char newbirth[8];//�³�������
	char newworkplace[10];//�¹�������
	char newposition[8];//��ְ��
	char newsalarylevel[8];//�¹���ˮƽ 
	char newtel[16];//�µ绰����
	char nam[8];
	int choice;
	printf("��������Ҫ�޸ĵ��˵�����: ");
	scanf("%s", &nam);
	if ((fp = fopen("employee.txt", "w+")) == NULL)
	{
		printf("���ܹ�������ļ�");
		return;
	}
	for (i = 1; i <= N; i++)
		if (strcmp(nam, em[i].name) == 0)
		{
		printf("������Ҫ�޸ĵĸ�����Ϣ��\n");
		printf("\n===========================================================================\n");
		printf("���  ����   �Ա�  ��������  ���ڲ���    ְ��   ���ʼ���    ��ϵ�绰\n");
		printf("=============================================================================\n");
		printf("%-6s%8s%6c%12s%10s%8s%8s%18s\n", em[i].num, em[i].name, em[i].sex, em[i].birth, em[i].workplace, em[i].position, em[i].salarylevel, em[i].tel);
		printf("-----------------------\n ");
		printf("����ѡ��Ҫ�޸ĵĲ��� : \n");
		printf("=======================\n ");
		printf("1.�޸ı��\n ");
		printf("2.�޸�����\n ");
		printf("3.�޸��Ա�\n ");
		printf("4.�޸ĳ�������\n ");
		printf("5.�޸����ڲ���\n ");
		printf("6.�޸�ְλ\n ");
		printf("7.�޸Ĺ��ʼ���\n ");
		printf("8.�޸���ϵ�绰\n ");
		printf("0.�������˵�\n ");
		printf("========================\n ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: printf("���������µı��: ");
			scanf("%s", newnum);
			strcpy(em[i].num, newnum);
			break;
		case 2: printf("���������µ�����: ");
			scanf("%s", newname);
			strcpy(em[i].name, newname);
			break;
		case 3: printf("���������µ��Ա�: ");
			getchar();
			scanf("%c", &newsex);
			em[i].sex = newsex;
			break;
		case 4: printf("���������µĳ�������: ");
			scanf("%s", newbirth);
			strcpy(em[i].birth, newbirth);
			break;
		case 5: printf("���������µĹ�������: ");
			scanf("%s", newworkplace);
			strcpy(em[i].workplace, newworkplace);
			break;
		case 6:printf("���������µ�ְλ: ");
			scanf("%s", newposition);
			strcpy(em[i].position, newposition);
			break;
		case 7:printf("���������µĹ��ʼ���: ");
			scanf("%s", newsalarylevel);
			strcpy(em[i].salarylevel, newsalarylevel);
			break;
		case 8:printf("���������µ���ϵ�绰: ");
			scanf("%s", newtel);
			strcpy(em[i].tel, newtel);
			break;
		case 0:
		{
			printf("�������˵�");
			main();//���� 
		}
		default:printf("�����д���!����������!"); return;
		}
		printf("\n===========================================================================\n");
		printf("���     ����    �Ա�    ��������    ���ڲ���   ְ��   ���ʼ���    ��ϵ�绰\n");
		printf("===========================================================================\n");
		printf("%-6s%8s%6c%12s%10s%8s%8s%18s\n", em[i].num, em[i].name, em[i].sex, em[i].birth, em[i].workplace, em[i].position, em[i].salarylevel, em[i].tel);
		save();//�����޸���Ϣ 
		break;
		}
		else if (i == N)
		{
			printf("û�����ְ����\n");
			change();
		}
	printf("\n===================\n");
	printf("1.�����޸�\n2.�������˵�\n");
	printf("===================\n");
	printf("\n����ѡ��:");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		change();
		break;
	case 2:
		main();
		break;
	default:printf("���벻�Ϸ�������\n"); main();
	}
}
void Delete(){
	FILE *fp;
	if ((fp = fopen("employee.txt", "w+")) == NULL)
	{
		printf("���ܹ�������ļ�");
		return;
	}
	int i, j;
	char id[6];
	printf("������Ҫɾ���ı��:");
	scanf("%s", id);
	for (i = 0; i<total; i++)
	{
		if (strcmp(id, em[i].num) == 0) 
		{
			for (j = i + 1; j < total; j++)
			{
				em[j - 1] = em[j];
			}
			total--;
			printf("ɾ���ɹ�!\n");
		}
	}
	save();
}
