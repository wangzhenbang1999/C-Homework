#include <iostream>
using namespace std;


class current_date
{
public:
	current_date();
	current_date(int Year, int Month, int Day)
	{
		day = Day;
		month = Month;
		year = Year;
	}

	void assign_data()
	{
		int Day; int Month; int Year;
		cin >> Year >> Month >> Day;
		day = Day;
		month = Month;
		year = Year;
	}
	
	void display_data()
	{
		cout << year << "/" << month << "/" << day<<" ";
	}
	
	int erro(void) {
		if (year <0 || month <1 || month > 12 || day <= 0 || day > 31)return -1;

		if (1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month) {
			return 1;
		}
		if (IsLeapYear(year)) {
			if (2 == month && (day>29))return -1;
			return 1;
		}
		else {
			if (2 == month && (day>28))return -1;
			return 1;
		}
	}
	bool IsLeapYear(int year)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			return true;
		return false;
	}
	void increment_date()
	{
		day++;
		if (1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month){
			if(day>=31){
					month++;
			if (month > 12)
			{
				year++;
				month = month % 12;
			}
				day = day % 31;
			}	
		}else if(4 == month || 6 == month || 9 == month || 11 == month){
			if(day>=30){
					month++;
				day = day % 30;
			}	
		}else if(2 == month&&IsLeapYear(year)){
			if(day>=29){
					month++;

				day = day % 29;
			}
		}else if(2 == month&&!IsLeapYear(year)){
			if(day>=28){
					month++;
				day = day % 28;
			}
		}
		
	}
private:
	int day;
	int month;
	int year;
};


class current_time
{
public:
	current_time();

	void assign_time()
	{
		int Hour; int Minute;float Second;
		cin >> Hour >> Minute >> Second;
		hours = Hour;
		minutes = Minute;
		seconds = Second;
	}
	current_time(int Hour, int Minute, float Second)
	{
		hours = Hour;
		minutes = Minute;
		seconds = Second;
	}

	void display_time()
	{
		cout << hours << ":" << minutes << ":" << seconds;
	} 

	void increment_time(float s)
	{
		
		seconds += s;
		int addMin =seconds/60;
		if (seconds >= 60)
		{
			minutes+=addMin;
			if (minutes >= 60)
			{
				hours = (hours + 1);
				if(hours==24);
				minutes = minutes % 60;
			}
			seconds = seconds - addMin*60;
		}
	}


private:
	int hours;
	int minutes;
	float seconds;
};


current_date::current_date(void)
{	
}
current_time::current_time(void)
{
}

int main()
{
	float s = 0;
	current_date date(0,0,0);
	current_time time(0,0,0);
	while(1)
{
			date.assign_data();
			time.assign_time();
			cin>>s;
			//erro()判断输入date是否正确
			int erro = date.erro();
			if(erro==-1)
				cout<<erro<<endl;
			else
{
				   date.increment_date();
				   time.increment_time(s);
	               date.display_data();
				   time.display_time();
				   return 0;
			    }
	  }
}



