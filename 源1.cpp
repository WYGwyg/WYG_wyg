#include<iostream>
union a1
{
	int a;
	char b;
};
int main()
{
	//��һ�ַ���
	a1 q;
	q.a = 1;
	if (q.b == 1)
	{
		std::cout << "С��" << std::endl;
	}
	else
	{
		std::cout << "���" << std::endl;
	}
	//�ڶ��ַ���
	int a = 1;
	char *b = (char*)&a;
	if (*b == 1)
	{
		std::cout << "С��" << std::endl;
	}
	else
	{
		std::cout << "���" << std::endl;
	}
	system("pause");
	return 0;
}
