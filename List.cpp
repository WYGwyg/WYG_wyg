#include<iostream>
using namespace std;
template<class T>
struct ListNode//����һ���ڵ�
{
	T _value;
	ListNode<T> *_next;
	ListNode<T> *_prev;
	ListNode(const T&val=T())
		:_value(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

//��װ�ڵ㹹��һ��������
template<class T,class Ref,class Ptr>
struct Listiterator
{
	typedef ListNode<T> Node;
	typedef Listiterator<T,Ref,Ptr> self;
	Node *_node;
	Listiterator(Node *node)
		:_node(node)
	{}
	Ref& operator*()//�������Ľ�����
	{
		return _node->_value;
	}
	self& operator++()//�ƶ�����һ���ڵ�
	{
		_node = _node->_next;
		return *this;
	}
	self& operator--()//�ƶ�����һ���ڵ�
	{
		_node = _node->_prev;
		return *this;
	}
	bool operator!=(const self& it)//�ж������ڵ��Ƿ����
	{
		return _node != it._node;
	}
	Ptr operator->()//->���������
	{
		return &_node->_value;
	}
};

//�ô�ͷ˫��ѭ������
template<class T>
class List
{
public:
	typedef Listiterator<T,T&,T*> iterator;
	typedef Listiterator<T, const T&, const T*> const_iterator;
	typedef ListNode<T> Node;
	List()//�޲ι��캯��
		:_header(new Node)
	{
		_header->_prev = _header->_next = _header;
	}
	void pushBack(const T& val)//β��һ��ֵ
	{
		Node *prev = _header->_prev;
		Node *newNode = new Node(val);
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = _header;
		_header->_prev = newNode;
	}
	void insert(iterator pos, const T& val)//����λ�ò���һ��ֵ
	{
		Node *prev = pos._node->_prev;
		Node *newNode = new Node(val);
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = pos._node;
		pos._node->_prev = newNode;
	}
	void pushFront(const T& val)//ͷ��
	{
		insert(begin(), val);
	}
	void popFront()//ͷɾ
	{
		erase(begin());
	}
	void popBack()//βɾ
	{
		erase(--end());
	}
	iterator erase(iterator pos)//ɾ������λ��
	{
		if (pos != end())
		{
			Node *prev = pos._node->_prev;
			Node *next = pos._node->_next;
			Node *curNode = pos._node;
			delete curNode;
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		return pos;
	}
	iterator begin()
	{
		return iterator(_header->_next);
	}
	iterator end()
	{
		return iterator(_header);
	}
	const_iterator cbegin() const
	{
		return const_iterator(_header->_next);
	}
	const_iterator cend() const
	{
		return const_iterator(_header);
	}
	void clear()
	{
		Node *start = _header->_next;
		while (start != _header)
		{
			Node *next = start->_next;
			delete start;
			start = next;
		}
	}
	~List()
	{
		if (_header)
		{
			clear();
			delete _header;
			_header = nullptr;
		}
	}
private:
	Node *_header;
};
void test()
{
	List<int> str1;
	str1.pushBack(1);
	str1.pushBack(2);
	str1.pushBack(3);
	str1.pushBack(4);
	str1.pushFront(10);
	str1.popFront();
	str1.popBack();
	List<int>::const_iterator cit = str1.cbegin();
	while (cit != str1.cend())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}