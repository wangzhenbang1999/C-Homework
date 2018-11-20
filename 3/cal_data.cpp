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
	static int Year(int y);
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

int cal_data::Year(int y)
{
	if (y % 4 == 0) { return 366; }
	else { return 365; }
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
			throw "请检查输入,输入的第一个日期需要大于第二次输入的日期";
		}
		else {
			int i = 0, date1 = 0;
			for (i = 1;i < year;i++) {//算出从1年到去年的日期和
				date1 += Year(i);
			}
			for (i = 1;i < month;i++) {//算出当年一月到前一个月份的所有日期
				date1 += GetMonthDay(year, month);
			}
			date1 += day;//加上已经过去的日期

			int j = 0, date2 = 0;
			for (j = 1;j < c.year;j++) {//算出从1年到去年的日期和
				date2 += Year(j);
			}
			for (j = 1;j < c.month;j++) {//算出当年一月到前一个月份的所有日期
				date2 += GetMonthDay(c.year, c.month);
			}
			date2 += c.day;//加上已经过去的日期
			return abs(date2 - date1);
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
	return (year != c.year) || (month != c.month) || (day != c.day);
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

	return *this;
}
cal_data cal_data::operator--()
{
	day -= 1;
	if (day == 0) {
		month -= 1;
		day = GetMonthDay(year, month);
		if (month == 0) {
			day = 31;
			month = 12;
			year -= 1;
		}
	}
	return *this;
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
	string::size_type idx = s.find(str);
	if (idx != string::npos) {
		int pos = s.find("/");
		int pos2 = s.rfind("/");//反向查找
		string sTmp = s.substr(0, pos);
		c.year = atof(sTmp.c_str());
		sTmp = s.substr(pos + 1, pos2 + 1);
		c.month = atof(sTmp.c_str());
		sTmp = s.substr(pos2 + 1, s.length());
		c.day = atof(sTmp.c_str());
		return in;
	}
	else {
		cout << "ERROR";
		exit(0);
	}

}
int main()
{
//	cal_data c1, c2, c3, c4, c5;
//	while (1) {
		//>>
//		cout << "输入c1和c2,格式为yyyy/mm/dd" << endl;
//		cin >> c1 >> c2;
//		cout << "c1：" << c1 << "" << "c2:  " << c2 << endl;
		//+		
//		c3 = c1 + 5;
		//<<
//		cout << "c3 is" << c3 << endl;
		//-erro
//		int i = c1 - c2;
//		cout << "c1,c2:" << i << endl;
		//++,--
//		++c1;--c2;
//		cout << "++c1: " << c1 << "--c2: " << c2 << endl;
//		cout << "输入c4c5" << endl;
//		cin >> c4 >> c5;
		//==
//		if (c4 == c5) {
//			cout << "c4==c5" << endl;
//		}
//		else if (c4 != c5) {
			//!= 
//			cout << "c4!=c5" << endl;
//			if (c4 < c5) {
				//<
//				cout << "c4<c5" << endl;
//			}
//			else if (c4 > c5) {
				//>
//				cout << "c4>c5" << endl;
//			}
//		}
//	}
	return 0;
}



