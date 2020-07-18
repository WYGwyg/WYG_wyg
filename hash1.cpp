#include<iostream>
#include<vector>
using namespace std;
enum State
{
	EMPTY,
	EXIST,
	DELETE
};
template<class K, class V>
struct hashNode
{
	pair<K, V> _val;
	State _state;
	hashNode(const pair<K, V>& value = pair<K, V>())
		:_state(EMPTY)
		, _val(value)
	{}
};
template<class K,class V>
class hashTable
{
public:
	hashTable(int n = 10)
	{
		_table.resize(n);
		_size = 0;
	}
	bool insert(const pair<K,V>& value)//�������
	{
		//1���������
		checkcapacity();
		//2�������ϣλ�ã���Ҫ���������Ӧ�÷����λ��
		int idx = value.first % _table.size();
		//3���ж�λ���Ƿ���ú������Ƿ��Ѿ�����
		while (_table[idx]._state == EXIST)
		{
			if (_table[idx]._val.first == value.first)
			{
				return false;
			}
			idx++;
			if (idx == _table.size())
			{
				idx = 0;
			}
		}
		//һ���ҵ���һ���յ�λ�û����Ѿ�ɾ���˵�λ��
		_table[idx]._val = value;
		_table[idx]._state = EXIST;
		_size++;
		return true;
	}
	void checkcapacity()
	{
		if (_size * 10 / _table.size() >= 7)//�������Ӵ��ڵ��ڰٷ�֮70��ʱ�����Ҫ����������
		{
			hashTable ht(2 * _table.size());
			//�Ѿɱ���Ԫ�ز��뵽�±���ȥ
			int i = 0;
			for (i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					ht.insert(_table[i]._val);
				}
			}
			swap(_table, ht._table);
		}
	}
	hashNode<K, V> *find(const K& key)//����
	{
		int idx = key % _table.size();
		//�����ս�������
		while (_table[idx]._state != EMPTY)
		{
			if (_table[idx]._state == EXIST && _table[idx]._val.first == key)
			{
				return &_table[idx];
			}
			idx++;
			if (idx == _table.size())
			{
				idx = 0;
			}
		}
		return nullptr;
	}
	bool erase(const K& key)//ɾ��
	{
		hashTable<K, V> *ptr = find(key);
		if (ptr)
		{
			ptr->_state == DELETE;
			_size--;
			return true;
		}
		return false;
	}
private:
	vector<hashNode<K, V>> _table;
	size_t _size;
};
void test()
{
	hashTable<int, int> str;
	str.insert(make_pair(1, 2));
	str.insert(make_pair(2, 3));
}
int main()
{
	test();
	system("pause");
	return 0;
}
