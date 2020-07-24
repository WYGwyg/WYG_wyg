#include<iostream>
using namespace std;
#include<vector>
#include<string>
class BitMap
{
public:
	BitMap(size_t n)
	{
		_bit.resize(n / 32 + 1);
	}
	bool Test(size_t n)//����
	{
		int idx = n / 32;//���ҵ�����λ��
		int bitidx = n % 32;//���ҵ�����ı���λ��
		if ((_bit[idx] >> bitidx) & 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Set(size_t n)//���ã�������
	{
		int idx = n / 32;
		int bitidx = n % 32;
		_bit[idx] = _bit[idx] | (1 << bitidx);
	}
	void Reset(size_t n)//ɾ��
	{
		int idx = n / 32;
		int bitidx = n % 32;
		_bit[idx] = _bit[idx] & ~(1 << bitidx);
	}
private:
	vector<int> _bit;
};
void test()
{
	BitMap bt(100);
	bt.Set(30);
	bt.Reset(30);
	cout << bt.Test(30) << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}