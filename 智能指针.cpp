#include<iostream>
#include<mutex>
#include<thread>
#include<memory>
using namespace std;
//auto_ptr����ָ��ʵ��
template<class T>
class autoptr
{
public:
	autoptr(T *ptr)
		:_ptr(ptr)
	{}
	~autoptr()
	{
		if (_ptr)
		{
			delete _ptr;
			cout << "~autoptr delete" << endl;
		}
	}
	//����Ȩת������
	autoptr(autoptr<T>& sp)//��������
		:_ptr(sp._ptr)
	{
		sp._ptr = nullptr;
	}
	autoptr<T>& operator=(autoptr<T>& sp)//��ֵ
	{
		if (this != &sp)
		{
			//�ͷ�ԭ����Դ
			if (_ptr)
			{
				delete _ptr;
			}
			//����Ȩת��
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
private:
	T *_ptr;
};
void test()
{
	int *sp = new int(10);
	autoptr<int> ptr(sp);
	cout << *ptr << endl;
}
//unique_ptr����ָ���ʵ��
template<class T>
class uniqueptr
{
public:
	uniqueptr(T *ptr)
		:_ptr(ptr)
	{}
	~uniqueptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	//�������͸�ֵ�����԰ѿ����͸�ֵ������Ϊdelete
	uniqueptr(const uniqueptr<T>& up) = delete;
	uniqueptr& operator=(const uniqueptr<T>& up) = delete;
private:
	T *_ptr;
};
//shared_ptr����ָ��ʵ��
template<class T>
class sharedptr
{
public:
	sharedptr(T *ptr,deletor del)
		:_ptr(ptr)
		, _usecount(new int(1))
		, _mtx(new mutex)
		, _del(del)
	{}
	~sharedptr()
	{
		//���ü����Լ�
		if (sunref() == 0)
		{
			del(_ptr);
			delete _usecount;
			delete _mtx;
		}
	}
	sharedptr(const sharedptr<T> &sp)//����
		:_ptr(sp._ptr)
		, _usecount(sp._usecount)
		, _mtx(sp._mtx)
	{
		addref();
	}
	sharedptr& operator=(const sharedptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			if (sunref() == 0)
			{
				delete _ptr;
				delete _usecount;
				delete _mtx;
			}
			//��ֵ
			_ptr = sp._ptr;
			_usecount = sp._usecount;
			_mtx = sp._mtx;
			addref();
		}
		return *this;
	}
	int getusecount()
	{
		return *_usecount;
	}
	int addref()
	{
		_mtx->lock();
		++(*_usecount);
		_mtx->unlock();
		return *_usecount;
	}
	int sunref()
	{
		_mtx->lock();
		--(*_usecount);
		_mtx->unlock();
		return *_usecount;
	}
private:
	T* _ptr;
	int *_usecount;//���ü���
	mutex *_mtx;
	deletor _del;
};
int main()
{
	test();
	system("pause");
	return 0;
}