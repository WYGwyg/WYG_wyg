#pragma once
#include"����.h"
void duankai() {
	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//�ͷ����Ӿ��
	SQLFreeHandle(SQL_HANDLE_ENV, henv);//�ͷŻ������
}