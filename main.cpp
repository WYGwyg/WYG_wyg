#include"����.h"
#include"�Ͽ�����.h"
#include<stdlib.h>
int main()
{
	system("color 70");
	int s;
	printf("************************************************************************************\n");
	printf("************************************************************************************\n");
	printf("*******************************��ҵ���¹���������!******************************\n");
	printf("************************************************************************************\n");
	printf("************************************************************************************\n");
	printf("1:����Ա��¼      ");
	printf("2:Ա����¼      ");
	printf("3:�˳�\n");
	int quit1 = 0;
	while (!quit1)
	{
		printf("���������ѡ��");
		scanf("%d", &s);
		switch (s)
		{
		case 1://ϵͳ����Ա��¼ϵͳģ��
		{
			lianjie();
			printf("�������¼�˺ţ�\n");
			scanf("%s", Account);
			printf("�������¼���룺\n");
			scanf("%s", Password);
			SQLCHAR sql3[] = "use Enterprise_management_system";
			SQLCHAR sql4[] = "select * from admin";
			ret = SQLExecDirect(hstmt, sql3, SQL_NTS);
			ret = SQLExecDirect(hstmt, sql4, SQL_NTS);
			if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
			{
				SQLCHAR str1[50], str2[50];
				SQLINTEGER len_str1, len_str2;
				while (SQLFetch(hstmt) != SQL_NO_DATA)
				{
					SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //��ȡ��һ������
					SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);

					for (int i = 0; i < 8; i++)
					{
						a[i] = str1[i];
					}
					for (int i = 0; i < 6; i++)
					{
						p[i] = str2[i];
					}
					if (strcmp(Account, a) == 0 && strcmp(Password, p) == 0 || strcmp(Account, a) == 0 && strcmp(Password, p) == 0)
					{
						printf("��¼�ɹ�\n");
						int x;
						duankai();
						printf("1:��ѯԱ����Ϣ   2:���Ա����Ϣ   3:�޸�Ա����Ϣ  4:ɾ��Ա����Ϣ\n");
						printf("5:��ѯ������Ϣ   6:��Ӳ�����Ϣ   7:�޸Ĳ�����Ϣ  8:ɾ��������Ϣ\n");
						printf("9:�鿴����Ա��ƽ������   10:�޸Ĳ���Ա��ƽ������    11:�˳�\n");
						int quit = 0;
						while (!quit)
						{
							printf("���������ѡ��:");
							scanf("%d", &x);
							switch (x)
							{
								//��ѯԱ����Ϣ
							case 1:
							{
								lianjie();
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[] = { "select * from staff" };
								ret = SQLExecDirect(hstmt, sql1, SQL_NTS);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									SQLCHAR str1[50], str2[50], str3[50], str4[50], str5[50];
									SQLINTEGER len_str1, len_str2, len_str3, len_str4, len_str5;
									printf("������ѯ������Ա����Ϣ���£�\n");
									while (SQLFetch(hstmt) != SQL_NO_DATA)
									{
										SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //��ȡ��һ������
										SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);
										SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
										SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);
										printf("%s\t%s\t%s\t%s\t\n", str1, str2, str3, str4);
									}
								}
							}
								duankai();
								break;
								//����Ա����Ϣ
							case 2:
							{
								lianjie();
								char w[] = { "'," };
								char b[] = { "'" };
								char i[] = { ")" };
								char cNo[50];
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[1000] = { "insert into staff(sNo,sName,sPhone,sAddress) values('" };
								printf("������Ա����ţ�");
								scanf("%s", &cNo);
								strcat((char*)sql2, cNo);
								strcat((char*)sql2, w);
								char cName[50];
								printf("������Ա��������");
								scanf("%s", &cName);
								strcat((char*)sql2, b);
								strcat((char*)sql2, cName);
								strcat((char*)sql2, w);
								char sPhone[50];
								printf("������Ա���绰��");
								scanf("%s", &sPhone);
								strcat((char*)sql2, b);
								strcat((char*)sql2, sPhone);
								strcat((char*)sql2, w);
								char sAddress[50];
								printf("������Ա����ַ��");
								scanf("%s", &sAddress);
								strcat((char*)sql2, b);
								strcat((char*)sql2, sAddress);
								strcat((char*)sql2, b);
								strcat((char*)sql2, i);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									printf("��ӳɹ�\n");
								}
								else {
									printf("���ʧ��\n");
								}
							}
								duankai();
								break;
								//�޸�Ա����Ϣ
							case 3:
							{
								//��ɾ��
								lianjie();
								char sNo[50];
								char a[] = { "'" };
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[1000] = { "delete from staff where sNo = '" };
								printf("�����������޸ĵ�Ա����ţ�");
								scanf("%s", &sNo);
								strcat((char*)sql2, sNo);
								strcat((char*)sql2, a);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								//�ٲ���
								printf("�����ν����޸ģ�\n");
								char w[] = { "'," };
								char b[] = { "'" };
								char i[] = { ")" };
								char cNo[50];
								SQLCHAR sql3[] = { "use Enterprise_management_system" };
								SQLCHAR sql4[1000] = { "insert into staff(sNo,sName,sPhone,sAddress) values('" };
								printf("������Ա����ţ�");
								scanf("%s", &cNo);
								strcat((char*)sql4, cNo);
								strcat((char*)sql4, w);
								char cName[50];
								printf("������Ա��������");
								scanf("%s", &cName);
								strcat((char*)sql4, b);
								strcat((char*)sql4, cName);
								strcat((char*)sql4, w);
								char sPhone[50];
								printf("������Ա���绰��");
								scanf("%s", &sPhone);
								strcat((char*)sql4, b);
								strcat((char*)sql4, sPhone);
								strcat((char*)sql4, w);
								char sAddress[50];
								printf("������Ա����ַ��");
								scanf("%s", &sAddress);
								strcat((char*)sql4, b);
								strcat((char*)sql4, sAddress);
								strcat((char*)sql4, b);
								strcat((char*)sql4, i);
								ret = SQLExecDirect(hstmt, sql4, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									printf("�޸ĳɹ�\n");
								}
								else {
									printf("�޸�ʧ��\n");
								}

							}
								duankai();
								break;
								//ɾ��Ա����Ϣ
							case 4:
							{
								lianjie();
								char sNo[50];
								char a[] = { "'" };
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[1000] = { "delete from staff where sNo = '" };
								printf("����������ɾ����Ա����ţ�");
								scanf("%s", &sNo);
								strcat((char*)sql2, sNo);
								strcat((char*)sql2, a);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									printf("ɾ���ɹ�\n");
								}
								else {
									printf("ɾ��ʧ��\n");
								}
							}
								duankai();
								break;
								//��ѯ����
							case 5:
							{
								lianjie();
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[] = { "select * from department" };
								ret = SQLExecDirect(hstmt, sql1, SQL_NTS);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									SQLCHAR str1[50], str2[50], str3[50], str4[50], str5[50];
									SQLINTEGER len_str1, len_str2, len_str3, len_str4, len_str5;
									printf("������ѯ�����в�����Ϣ���£�\n");
									printf("���ű�� ������Ϣ\n");
									while (SQLFetch(hstmt) != SQL_NO_DATA)
									{
										SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //��ȡ��һ������
										SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);
										/*SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
										SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);*/
										printf("%s\t%s\t\n", str1, str2);
									}
								}
							}
								duankai();
								break;
								//��Ӳ�����Ϣ
							case 6:
							{
								lianjie();
								char w[] = { "'," };
								char b[] = { "'" };
								char i[] = { ")" };
								char cNo[50];
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[1000] = { "insert into department(dNo,dName) values('" };
								printf("�����벿�ű�ţ�");
								scanf("%s", &cNo);
								strcat((char*)sql2, cNo);
								strcat((char*)sql2, w);
								char cName[50];
								printf("������Ա��������");
								scanf("%s", &cName);
								strcat((char*)sql2, b);
								strcat((char*)sql2, cName);
								strcat((char*)sql2, b);
								strcat((char*)sql2, i);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									printf("��ӳɹ�\n");
								}
								else {
									printf("���ʧ��\n");
								}
							}
								duankai();
								break;
								//�޸Ĳ�����Ϣ
							case 7:
							{
								//��ɾ��
								lianjie();
								char sNo[50];
								char a[] = { "'" };
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[1000] = { "delete from department where dNo = '" };
								printf("�����������޸ĵĲ��ű�ţ�");
								scanf("%s", &sNo);
								strcat((char*)sql2, sNo);
								strcat((char*)sql2, a);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								//���
								printf("�����ΰ��������޸�\n");
								lianjie();
								char w[] = { "'," };
								char b[] = { "'" };
								char i[] = { ")" };
								char cNo[50];
								SQLCHAR sql11[] = { "use Enterprise_management_system" };
								SQLCHAR sql21[1000] = { "insert into department(dNo,dName) values('" };
								printf("�����벿�ű�ţ�");
								scanf("%s", &cNo);
								strcat((char*)sql21, cNo);
								strcat((char*)sql21, w);
								char cName[50];
								printf("�����벿��������");
								scanf("%s", &cName);
								strcat((char*)sql21, b);
								strcat((char*)sql21, cName);
								strcat((char*)sql21, b);
								strcat((char*)sql21, i);
								ret = SQLExecDirect(hstmt, sql21, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									printf("�޸ĳɹ�\n");
								}
								else {
									printf("�޸�ʧ��\n");
								}
							}
								duankai();
								break;
								//ɾ��������Ϣ
							case 8:
							{
								lianjie();
								char sNo[50];
								char a[] = { "'" };
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[1000] = { "delete from department where dNo = '" };
								printf("����������ɾ���Ĳ��ű�ţ�");
								scanf("%s", &sNo);
								strcat((char*)sql2, sNo);
								strcat((char*)sql2, a);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									printf("ɾ���ɹ�\n");
								}
								else {
									printf("ɾ��ʧ��\n");
								}
							}
								duankai();
								break;
								//�鿴����ƽ������
							case 9:
							{
								lianjie();
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[] = { "select * from d_money" };
								ret = SQLExecDirect(hstmt, sql1, SQL_NTS);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									SQLCHAR str1[50], str2[50], str3[50], str4[50], str5[50];
									SQLINTEGER len_str1, len_str2, len_str3, len_str4, len_str5;
									printf("������ѯ�����в��Ź�����Ϣ���£�\n");
									printf("���ű�� ���Ź���\n");
									while (SQLFetch(hstmt) != SQL_NO_DATA)
									{
										SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //��ȡ��һ������
										SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);
										/*SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
										SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);*/
										printf("%s\t%s\t\n", str1, str2);
									}
								}
							}
								duankai();
								break;
							case 10:
							{
								//��ɾ��
								lianjie();
								char sNo[50];
								char a[] = { "'" };
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[1000] = { "delete from d_money where dNo = '" };
								printf("�����������޸ĵĲ��ű�ţ�");
								scanf("%s", &sNo);
								strcat((char*)sql2, sNo);
								strcat((char*)sql2, a);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								//���
								printf("�����ΰ��������޸�\n");
								lianjie();
								char w[] = { "'," };
								char b[] = { "'" };
								char i[] = { ")" };
								char cNo[50];
								SQLCHAR sql12[] = { "use Enterprise_management_system" };
								SQLCHAR sql22[1000] = { "insert into department(dNo,dName) values('" };
								printf("�����벿�ű�ţ�");
								scanf("%s", &cNo);
								strcat((char*)sql22, cNo);
								strcat((char*)sql22, w);
								char cName[50];
								printf("�����벿�Ź��ʣ�");
								scanf("%s", &cName);
								strcat((char*)sql22, b);
								strcat((char*)sql22, cName);
								strcat((char*)sql22, b);
								strcat((char*)sql22, i);
								ret = SQLExecDirect(hstmt, sql22, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									printf("�޸ĳɹ�\n");
								}
								else {
									printf("�޸�ʧ��\n");
								}
							}
								duankai();
								break;
							case 11:
							{
								quit = 1;
							}
								duankai();
								break;
							}
						}
					}

				}
			}
		}
			duankai();
			break;


			//Ա����¼
		case 2:
		{
			lianjie();
			printf("�������¼�˺ţ�\n");
			scanf("%s", Account);
			printf("�������¼���룺\n");
			scanf("%s", Password);
			SQLCHAR sql3[] = "use Enterprise_management_system";
			SQLCHAR sql4[] = "select * from admin";
			ret = SQLExecDirect(hstmt, sql3, SQL_NTS);
			ret = SQLExecDirect(hstmt, sql4, SQL_NTS);
			if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
			{
				SQLCHAR str1[50], str2[50];
				SQLINTEGER len_str1, len_str2;
				while (SQLFetch(hstmt) != SQL_NO_DATA)
				{
					SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //��ȡ��һ������
					SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);

					for (int i = 0; i < 8; i++)
					{
						a[i] = str1[i];
					}
					for (int i = 0; i < 6; i++)
					{
						p[i] = str2[i];
					}
					if (strcmp(Account, a) == 0 && strcmp(Password, p) == 0 || strcmp(Account, a) == 0 && strcmp(Password, p) == 0)
					{
						printf("��¼�ɹ�\n");
						int x;
						duankai();
						printf("1:��ѯԱ����Ϣ   2:��ѯ���Ź���  3:�˳�\n");
						int quit2 = 0;
						while (!quit2)
						{
							printf("���������ѡ��:");
							scanf("%d", &x);
							switch (x)
							{
							case 1:
							{
								//��ѯԱ����Ϣ
								lianjie();
								char sNo[50];
								char a[] = { "'" };
								printf("�����������ѯ��Ա����ţ�");
								scanf("%s", &sNo);
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[] = { "select * from staff where sNo = '" };
								strcat((char*)sql2, sNo);
								strcat((char*)sql2, a);
								ret = SQLExecDirect(hstmt, sql1, SQL_NTS);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									SQLCHAR str1[50], str2[50], str3[50], str4[50], str5[50];
									SQLINTEGER len_str1, len_str2, len_str3, len_str4, len_str5;
									printf("������ѯ��Ա����Ϣ���£�\n");
									while (SQLFetch(hstmt) != SQL_NO_DATA)
									{
										SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //��ȡ��һ������
										SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);
										SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
										SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);
										printf("%s\t%s\t%s\t%s\t\n", str1, str2, str3, str4);
									}
								}
							}
								break;
							case 2:
							{
								//��ѯ���Ź���
								lianjie();
								char dNo[50];
								char a[] = { "'" };
								printf("�����������ѯ�Ĳ��ű�ţ�");
								scanf("%s", &dNo);
								SQLCHAR sql1[] = { "use Enterprise_management_system" };
								SQLCHAR sql2[] = { "select * from d_money where dNo = '" };
								strcat((char*)sql2, dNo);
								strcat((char*)sql2, a);
								ret = SQLExecDirect(hstmt, sql1, SQL_NTS);
								ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
								if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
								{
									SQLCHAR str1[50], str2[50], str3[50], str4[50], str5[50];
									SQLINTEGER len_str1, len_str2, len_str3, len_str4, len_str5;
									printf("������ѯ��Ա����Ϣ���£�\n");
									while (SQLFetch(hstmt) != SQL_NO_DATA)
									{
										SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //��ȡ��һ������
										SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);
										/*SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
										SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);*/
										printf("���ű��   ����Ա��ƽ������\n");
										printf("%s\t%s\t\n", str1, str2);
									}
								}
							}
								break;
							case 3:
							{
								quit2 = 1;
							}
								break;
							}
						}
					}
				}
			}
		}
			//p
		case 3:
		{
			quit1 = 1;
		}
			duankai();
			break;

		}
		system("pause");
		return 0;
	}
}