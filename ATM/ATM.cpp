#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class Card
{
public:
	Card();
	Card(string pwd, string n){
		passwd = pwd;
		num = n;
		money = 3000;
	}
	~Card();
	string getpasswd()const;
	void setpassword(const string s);
	void setmoney(const int m);
	void addmoney(const int m);
	int getmoney();
	void drawmoneymoney(const int m);
private:
	string passwd;
	string num;
	int money;
};
class ATM
{
public:
	ATM():c1("123456", "1234567891234567891"), c2("123456", "1234567891234567892"), c3("123456", "1234567891234567893"), c4("123456", "1234567891234567895"), c5("123456", "1234567891234567895"){};
	~ATM();
	void welcome();
	void function(Card &c);
	void savemoney(Card &c);
	void drawmoney(Card &c);
	void transfer(Card &c);
	void change_pwd(Card &c);
	void showinfo();
private:
	Card c1;
	Card c2;
	Card c3;
	Card c4;
	Card c5;

};
Card::Card()
{
}

Card::~Card()
{
}

string Card::getpasswd()const
{
	return passwd;
}

void Card::setpassword(string s)
{
	passwd = s;
}

void Card::setmoney(int m)
{
	money = m;
}

void Card::addmoney(int m)
{
	money += m;
}

int Card::getmoney()
{
	return this->money;
}

void Card::drawmoneymoney(int m)
{
	money -= m;
}
ATM::~ATM()
{
}

void ATM::welcome()
{
	int times = 0;
	do{	
		cout << "欢迎使用自动取款机" << endl;
		string pwd, num1;
		char ch;
		cout << endl << "请输入卡号:";
		cin >> num1;
		cout << "请输入密码： " << endl;
	
		while ((ch = _getch()) != 13)
		{
			pwd += ch;
			sizeof(ch);
			cout << "*";
		}
		if (num1 == "1234567891234567891"&&pwd == c1.getpasswd())	
		{
//			system("cls");
			while (1) {
			function(c1);
			}
			
		}
		else if (num1 == "1234567891234567892"&&pwd ==c2.getpasswd()) {
//			system("cls");
			while (1) {
				function(c2);
			}
		}
		else if (num1 == "1234567891234567893"&&pwd == c3.getpasswd()) {
//			system("cls");
			while (1) {
				function(c3);
			}
		}
		else if (num1 == "1234567891234567894"&&pwd == c4.getpasswd()) {
//			system("cls");
			while (1) {
				function(c4);
			}
		}
		else if (num1 == "1234567891234567892"&&pwd == c5.getpasswd()) {
			system("cls");
			while (1) {
				function(c5);
			}
		}

		else {
			times++;
		}
	} while (times < 3);
}

void ATM::function(Card &c)
{
	cout << "1.存钱" << endl;
	cout << "2.取钱" << endl;
	cout << "3.转帐" << endl;
	cout << "4.改密" << endl;
	cout << "5.所有信息" << endl;
	cout << "6.退出" << endl;
	int n;
	cin >> n;
	while (n < 1 || n>6)
	{
		cout << "请输入正确的操作序号!" << endl;
		cin >> n;
	}
	switch (n)
	{
	case 1: savemoney(c); break;
	case 2: drawmoney(c); break;
	case 3: transfer(c); break;
	case 4: change_pwd(c); break;
	case 5: showinfo(); break;
	case 6: system("cls");welcome(); break;
	
	}
}

void ATM::savemoney(Card & c)
{
	int m;
	cout << "请问需要存多少钱" << endl;
	cin >> m;
	if ((m % 100)==0) {
		c.addmoney(m);
		cout << "存款成功" << endl;
	}
	else {
		cout << "请检查输入" << endl;
	}
	
}
void ATM::drawmoney(Card & c)
{
	int m;
	cout << "请问需要取多少钱" << endl;
	cin >> m;
	if (m % 100 == 0&&c.getmoney()>m) {
		c.drawmoneymoney(m);
		cout << "取款成功" << endl;
	}
	else {
		cout << "请检查输入" << endl;
	}

}
void ATM::transfer(Card & c)
{
	cout << "请输入要转帐的用户" << endl;
	string s;
	cin >> s;
	cout << "转多少钱？" << endl;
	int m;
	cin >> m;
	c.drawmoneymoney(m);
	if (s == "1234567891234567891") {
		c1.addmoney(m);
	}else if (s == "1234567891234567892") {
		c2.addmoney(m);
	}
	else if (s == "1234567891234567893") {
		c3.addmoney(m);
	}
	else if (s == "1234567891234567894") {
		c4.addmoney(m);
	}
	else if (s == "1234567891234567895") {
		c5.addmoney(m);
	}
	else {
		cout << "账号不存在" << endl;
		c.addmoney(m);
	}
	
}

void ATM::change_pwd(Card & c)
{
	string s;
	cout << "请问需要改成什么密码" << endl;
	cin >> s;
	c.setpassword(s);
}

void ATM::showinfo()
{
	cout <<"账户1"<<"   " <<c1.getmoney() << "   " << "密码" << "   " <<c1.getpasswd()<<endl;
	cout << "账户2" << "   " << c2.getmoney()<< "   "  << "密码" << "   " << c2.getpasswd() << endl;
	cout << "账户3" << "   " << c3.getmoney() << "   " << "密码" << "   " << c3.getpasswd() << endl;
	cout << "账户4" << "   " << c4.getmoney() << "   " << "密码" << "   " << c4.getpasswd ()<< endl;
	cout << "账户5" << "   " << c5.getmoney() << "   " << "密码" << "   " << c5.getpasswd() << endl;
}
int main() {
//	ATM atm;
//	atm= ATM();
//	atm.welcome();
	return 0; 
}
