#include<iostream>
using namespace std;
class Date
{
public:
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	int Getmonthday(int year, int month)//��ȡĳһ��ĳ�����ж�����
	{
		static int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = array[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			day += 1;
		}
		return day;
	}
	Date(int year = 1, int month = 1, int day = 1)//ȫȱʡ���캯��
	{
		if ((year <= 0) || (month < 1 && month>12) || (day > Getmonthday(year, month)))
		{
			cout << "��������·ݺ�����������ʵ�����" << endl;
			_year = _month = _day = 1;
			cout << "������Ϊ" << " " << "_year = " << _year << " " << "_month = ",
				cout << _month << " " << "_day = " << _day << endl;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
		}
	}
	Date(const Date& date)//��������
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}
	//~Date();//��������
	Date& operator=(const Date& date)//��ֵ�����
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}
	Date& operator+=(int day)//�ӵ������  ����+����
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > Getmonthday(_year, _month))
		{
			_day = _day - Getmonthday(_year, _month);
			_month += 1;
			if (_month == 13)
			{
				_year += 1;
			}
		}
		return *this;
	}
	Date& operator-=(int day)//���������  ����-����
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
			}
			_day += Getmonthday(_year, _month);
		}
		return *this;
	}
	Date operator+(int day)//�ӷ������ ��һ������
	{
		Date ret = *this;
		return ret += day;
	}
	Date operator-(int day)//��������� ��һ������
	{
		Date ret = (*this);
		return ret -= day;
	}
	Date &operator++()//ǰ��++�����
	{
		return *this += 1;
	}
	Date operator++(int)//����++�����
	{
		Date ret = (*this);
		return ret += 1;
	}
	Date& operator--()//ǰ��--�����
	{
		return *this -= 1;
	}
	Date operator--(int)//����--�����
	{
		Date ret = (*this);
		return ret -= 1;
	}
	bool operator>(const Date& d)//���������
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool operator<(const Date& d)//С�������
	{
		return !(*this >= d);
	}
	bool operator==(const Date& d)//���������
	{
		if (_year == d._year && _month == d._month && _day == d._day)
		{
			return true;
		}
		return false;
	}
	bool operator>=(const Date& d)//���ڵ��������
	{
		return *this > d || *this == d;
	}
	bool operator<=(const Date& d)//С�ڵ��������
	{
		return !(*this > d);
	}
	bool operator!=(const Date& d)//�����������
	{
		return !(*this == d);
	}
	int operator-(const Date& d)//����-����  ��������
	{
		int day = 0;
		if (*this > d)
		{
			Date ret = d;
			while (ret != *this)
			{
				++ret;
				day++;
			}
		}
		else if (*this < d)
		{
			Date ret = (*this);
			while (ret != d)
			{
				++ret;
				day++;
			}
		}
		else
		{
			day = 0;
		}
		return day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1(2021, 8, 18);
	Date d2(2020, 8, 18);
	cout << d1 - d2 << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}