#pragma once
#include<stdio.h>
#include<windows.h>
#include<sql.h>
#include<sqlext.h>
#include<sqltypes.h>
#include<string.h>
#pragma warning(disable:4996)
char Account[50], Password[50], a[50], p[50];
SQLRETURN   ret;
SQLHENV    henv;
SQLHDBC    hdbc;
SQLHSTMT  hstmt;
void lianjie()
{
	ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//���뻷�����
	ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//�������ݿ����Ӿ��

	ret = SQLConnect(hdbc, (SQLCHAR*)"test", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123456", SQL_NTS);
	/*data_testΪ���õ�ODBC����Դ����*/
	if (!(ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO))
	{
		printf("�������ݿ�ʧ��!\n");
	}
	else {
		printf("�������ݿ�ɹ�!\n");
	}                                      /*��������odbc���ӵ����ݿ⣬�����õ����ǽ�����study���ݿ����������*/
	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
}