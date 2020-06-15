#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<functional>
using namespace std;
template<class T,class Container  = vector<T>,class Compare = less<T>>
class Priority_Queue
{
public:
	void push(const T& val)//���
	{
		_c.push_back(val);
		shiftup(_c.size() - 1);
	}
	void pop()//����
	{
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftdown(0);
	}
	const T& top()//��ȡ�Ѷ�Ԫ��
	{
		return _c.front();
	}
	size_t size()//��ȡ��ǰ�ѣ����ȶ��У���ЧԪ�ظ���
	{
		return _c.size();
	}
	bool empty()//�ж϶��Ƿ�Ϊ��
	{
		return _c.empty();
	}
private:
	void shiftdown(int parent)//���µ���
	{
		int child = 2 * parent + 1;
		while (child < _c.size())
		{
			if (child + 1 < _c.size() && _com(_c[child + 1],_c[child]))
			{
				child += 1;
			}
			if (_com(_c[parent],_c[child]))
			{
				swap(_c[parent], _c[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}
	void shiftup(int child)//���ϵ���
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_com(_c[parent],_c[child]))
			{
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
private:
	Container _c;
	Compare _com;
};
void test1()//���������
{
	Priority_Queue<int> str;//Ĭ�ϰ��մ������
	str.push(1);
	str.push(23);
	str.push(9);
	str.push(27);
	str.push(45);
	str.push(19);
	while (!str.empty())
	{
		cout << str.top() << " ";
		str.pop();
	}
	cout << endl;
}
void test2()//��С������
{
	Priority_Queue<int,vector<int>,greater<int>> str;
	str.push(1);
	str.push(23);
	str.push(9);
	str.push(27);
	str.push(45);
	str.push(19);
	while (!str.empty())
	{
		cout << str.top() << " ";
		str.pop();
	}
	cout << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}