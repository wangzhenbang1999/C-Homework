#include<iostream>
#include<cmath>
#include <string>
#include <cstdlib>
using namespace std;
class cal_data {
public:
	cal_data() { year = 1752;month = 9;day = 14; }
	cal_data(int y, int m, int d) { year = y;month = m;day = d; }

	int getYear();

	int getMonth();

	int getday();
	static bool IsLeapYear(int year);
	static int GetMonthDay(int year, int month);
	cal_data operator+(int day);
	int operator-(const cal_data &c);
	cal_data& operator=(const cal_data& d);
	bool operator==(const cal_data &c);
	bool operator!=(const cal_data &c);
	bool operator>(const cal_data& c);
	bool operator<(const cal_data& c);
	cal_data operator++();
	cal_data operator--();
	friend ostream & operator<<(ostream &out, cal_data& c);
	friend istream & operator >> (istream &in, cal_data& c);
private:
	int year;
	int month;
	int day;
};


int cal_data::cal_data::getYear()
{
	return year;
}



int cal_data::cal_data::getMonth()
{
	return month;
}



int cal_data::cal_data::getday()
{
	return day;
}

bool cal_data::IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

int cal_data::GetMonthDay(int year, int month)
{
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int day = monthArray[month];

	if (month == 2 && IsLeapYear(year))
	{
		day += 1;
	}
	return day;

}

cal_data cal_data:: operator+(int day)
{
	try {
		if (day < 0)
			throw "天数应该大于0";
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	cal_data temp(*this);
	temp.day += day;
	int daysInMonth = GetMonthDay(temp.getYear(), temp.getMonth());
	while (temp.day > daysInMonth)
	{
		temp.day -= daysInMonth;
		temp.month += 1;
		if (temp.month > 12)
		{
			temp.year += 1;
			temp.month = 1;
		}
	}
	return temp;
}
int cal_data::operator-(const cal_data &c)
{
	try {
		if (year < c.year) {
			throw "请检查输入";
		}
		else {
			int days = 0;	//天数计数器

	//计算相差的年之间所有天数，即把从d1的那年到d2的前一年的所有年的天数累加
			for (int i = c.year; i < year; i++)
			{
				if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
					days += 366;
				else
					days += 365;
			}

			//去掉d1那年已过的天数，即从一月到的d1.month的前一个月的天数和d1.day的和
			for (int j = 1; j < c.month; j++)
			{
				if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
					days -= 31;
				else if (j == 4 || j == 6 || j == 9 || j == 11)
					days -= 30;
				else if (j == 2)
				{
					if ((c.year % 4 == 0 && c.year % 100 != 0) || c.year % 400 == 0)
						days -= 29;
					else
						days -= 28;
				}
			}
			days -= c.day;

			//加上d2那年已过的天数，同计算d1时相同
			for (int k = 1; k < month; k++)
			{
				if (k == 1 || k == 3 || k == 5 || k == 7 || k == 8 || k == 10 || k == 12)
					days += 31;
				else if (k == 4 || k == 6 || k == 9 || k == 11)
					days += 30;
				else if (k == 2)
				{
					if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
						days += 29;
					else
						days += 28;
				}

			}
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	
	
}
cal_data & cal_data::operator=(const cal_data & d)
{
	if (this != &d);
	{
		year = d.year;
		month = d.month;
		day = d.day;
	}
	return *this;
}
bool cal_data::operator==(const cal_data &c)
{
	return (year == c.year) && (month == c.month) && (day == c.day);
}
bool cal_data::operator!=(const cal_data &c)
{
	return (year != c.year) && (month != c.month) && (day != c.day);
}
bool cal_data::operator>(const cal_data& c)
{
	if (year > c.year) {
		return true;
	}
	else if (year == c.year) {
		if (month > c.month) {
			return true;
		}
		else if (month == month) {
			if (day > c.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (day < c.day) {
			return false;
		}
	}
	else if (year < c.year) {
		return false;
	}
}
bool cal_data::operator<(const cal_data& c)
{
	if (year < c.year) {
		return true;
	}
	else if (year == c.year) {
		if (month < c.month) {
			return true;
		}
		else if (month == month) {
			if (day < c.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (day > c.day) {
			return false;
		}
	}
	else if (year > c.year) {
		return false;
	}
}
cal_data cal_data::operator++()
{
	*this = *this + 1;
	//_day += 1;
	return *this;
}
cal_data cal_data::operator--()
{
	return cal_data();
}
ostream & operator<<(ostream &out, cal_data& c)
{
	out << c.year << "/" << c.month << "/" << c.day << endl;
	return out;
}
istream & operator>>(istream &in, cal_data& c)
{
	string s;
	in >> s;
	string str = "/";
	string::size_type idx = s.find(str);//判断虚部正负 
	if (idx != string::npos) {
		int pos = s.find("/");
		int pos2 = s.rfind("/");//反向查找
		string sTmp = s.substr(0, pos);
		c.year = atof(sTmp.c_str());
		sTmp = s.substr(pos + 1, pos2 + 1);
		c.month = atof(sTmp.c_str());
		sTmp = s.substr(pos2 + 1, s.length());
		c.month = atof(sTmp.c_str());
		return in;
	}
	cout << "ERROR";
}
int main()
{
	return 0;
}


