#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
union endian
{
	int i;
	char a;
}en;
int main()
{
	en.i = 1;
	if (en.a == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	system("pause");
	return 0;
}