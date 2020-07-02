#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T _val;
	Node* _left;
	Node* _right;
	Node(const T& val=T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};
template<class T>
class Bst
{
public:
	typedef Node<T> Node;
	Bst()
		:_root(nullptr)
	{}
	Node *copy(Node *root)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}
		Node *cur = new Node(root->_val);
		cur->_left = copy(root->_left);
		cur->_right = copy(root->_right);
		return cur;
	}
	Bst(const Bst<T>& bst)//��������
	{
		_root = copy(bst._root);
	}
	void destroy(Node *root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			delete root;
			root = nullptr;
		}
	}
	~Bst()
	{
		if (_root)
		{
			destroy(_root);
		}
	}
	Node *find(const T& val)//����
	{
		Node *cur = _root;
		if (_root == NULL)
		{
			printf("����ʧ��\n");
			return nullptr;
		}
		while (cur)
		{
			if (cur->_val == val)
			{
				return cur;
			}
			else if (cur->_val < val)
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		return nullptr;
	}
	bool insert(const T& val)//����
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
		}
		Node *cur = _root;
		Node *parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
			{
				return false;
			}
			else if (cur->_val < val)
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		cur = new Node(val);
		if (parent->_val < val)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	bool erase(const T& val)//ɾ��
	{
		if (_root == nullptr)
		{
			return false;
		}
		Node *cur = _root;
		Node *parent = nullptr;
		while (cur)
		{
			if (cur->_val == val)
			{
				break;
			}
			else if (cur->_val < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				parent = cur;
				cur = cur->_left;
			}
		}
		if (cur == nullptr)
		{
			return false;
		}
		//�õ���cur���ֵ����val�Ľڵ�
		//ɾ������
		//1��ɾ��Ҷ��
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			if (_root == cur)
			{
				_root = nullptr;
			}
			else
			{
				if (parent->_right == cur)
				{
					parent->_right = nullptr;
				}
				else
				{
					parent->_left = nullptr;
				}
			}
		}
		//2������нڵ�
		if (cur->_right == nullptr)
		{
			if (_root == cur)
			{
				_root = cur->_left;
			}
			else
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_left;
				}
				else
				{
					parent->_right = cur->_left;
				}
			}
		}
		//3���ұ��нڵ�
		if (cur->_left == nullptr)
		{
			if (_root == cur)
			{
				_root = cur->_right;
			}
			else
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_right;
				}
				else
				{
					parent->_right = cur->_right;
				}
			}
		}
		else
		{
			//4�����Ҷ��нڵ�
			Node *child = cur->_left;
			parent = cur;
			while (child->_right)
			{
				parent = child;
				child = child->_right;
			}
			cur->_val = child->_val;
			if (parent->_left == child)
			{
				parent->_left = child->_left;
			}
			else
			{
				parent->_right = child->_right;
			}
			delete child;
		}
		return true;
	}
	void _inorder(Node *root)//�������
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val <<" ";
			_inorder(root->_right);
		}
	}
	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
private:
	Node *_root;
};
void test()
{
	Bst<string> bst;
	bst.insert("����");
	bst.insert("����");
	bst.insert("�Ϻ�");
	bst.insert("����");
	bst.insert("����");
	bst.insert("����");
	bst.inorder();
}
int main()
{
	test();
	system("pause");
	return 0;
}