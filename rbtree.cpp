#include<iostream>
#include<utility>
using namespace std;
enum Color
{
	RED,
	BLACK
};
template < class K, class V >
struct rbNode
{
	pair<K, V> _val;
	Color _color;
	rbNode<K, V> *_parent;
	rbNode<K, V> *_left;
	rbNode<K, V> *_right;
	rbNode(const pair<K, V>& val = pair<K, V>())
		:_val(val)
		, _color(RED)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{}
};
template<class K,class V>
class rbtree
{
public:
	typedef rbNode<K, V> Node;
	rbtree()
		:_header(new Node)
	{
		_header->_parent = nullptr;
		_header->_left = _header->_right = _header;
	}
	bool insert(const pair<K, V>& val)
	{
		//1������
		if (_header->_parent == nullptr)
		{
			Node *root = new Node(val);
			root->_color = BLACK;
			_header->_parent = root;
			root->_parent = _header;
			_header->_left = root;
			_header->_right = root;
			return true;
		}
		//2���������������룬�ҵ�Ҫ�����λ��
		Node *cur = _header->_parent;//root
		Node *parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val.first == val.first)
			{
				return false;
			}
			else if (cur->_val.first < val.first)
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		cur = new Node(val);
		if (parent->_val.first < val.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		//����
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node *g = parent->_parent;
			if (g->_left == parent)//�������游�����
			{
				Node *u = g->_right;
				//1�����������Ϊ��
				if (u && u->_color == RED)
				{
					parent->_color = u->_color = BLACK;
					g->_color = RED;
					cur = g;
				}
				//2�����������Ϊ�ڻ������岻����
				else
				{
					//���cur��parent�ұߣ���Ҫ�Ƚ����������ڽ����������ڸ�����ɫ
					if (parent->_right == cur)
					{
						RotateL(parent);
						swap(parent, cur);
					}
					//���cur��parent���,��Ҫ��������
					RotateR(g);
					parent->_color = BLACK;
					g->_color = RED;
					break;
				}
			}
			else//�������游���ұ�
			{
				Node *u = g->_left;
				if (u && u->_color == RED)
				{
					parent->_color = u->_color = BLACK;
					g->_color = RED;
					cur = g;
				}
				else
				{
					//cur��parent��ߣ���Ҫ��������������
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(parent, cur);
					}
					//cur��parent�ұߣ���Ҫ����
					RotateL(g);
					parent->_color = BLACK;
					g->_color = RED;
					break;
				}
			}
		}
		_header->_parent->_color = BLACK;
		_header->_left = LeftMost();
		_header->_right = RightMost();
		return true;
	}
	void RotateR(Node *parent)//����
	{
		Node *curL = parent->_left;
		Node *curLR = curL->_right;
		curL->_right = parent;
		parent->_left = curLR;
		if (curLR)
		{
			curLR->_parent = parent;
		}
		if (parent == _header->_parent)
		{
			_header->_parent = curL;
			curL->_parent = _header;
		}
		else
		{
			Node *pp = parent->_parent;
			curL->_parent = pp;
			if (pp->_left == parent)
			{
				pp->_left = curL;
			}
			else
			{
				pp->_right = curL;
			}
		}
		parent->_parent = curL;
	}
	void RotateL(Node *parent)
	{
		Node *curL = parent->_right;
		Node *curLR = curL->_left;
		curL->_left = parent;
		parent->_right = curLR;
		if (curLR)
		{
			curLR->_parent = parent;
		}
		if (parent == _header->_parent)
		{
			curL->_parent = _header;
			_header->_parent = curL;
		}
		else
		{
			Node *pp = parent->_parent;
			curL->_parent = pp;
			if (pp->_left == parent)
			{
				pp->_left = curL;
			}
			else
			{
				pp->_right = curL;
			}
		}
		parent->_parent = curL;
	}
	Node *LeftMost()
	{
		Node *cur = _header->_parent;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	Node *RightMost()
	{
		Node *cur = _header->_right;
		while (cur && cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}
	void inorder()
	{
		_inorder(_header->_parent);
		cout << endl;
	}
	void _inorder(Node *cur)
	{
		if (cur)
		{
			_inorder(cur->_left);
			cout << cur->_val.first << "----->" << cur->_val.second << endl;
			_inorder(cur->_right);
		}
	}
private:
	Node *_header;
};
void test()
{
	rbtree<int, int> rbt;
	rbt.insert(make_pair(1, 1));
	rbt.insert(make_pair(0, 1));
	rbt.insert(make_pair(5, 1));
	rbt.insert(make_pair(3, 1));
	rbt.insert(make_pair(2, 1));
	rbt.insert(make_pair(4, 1));
	rbt.insert(make_pair(8, 1));
	rbt.insert(make_pair(12, 1));
	rbt.inorder();
}
int main()
{
	test();
	system("pause");
	return 0;
}