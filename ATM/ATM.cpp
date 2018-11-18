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
		cout << "��ӭʹ���Զ�ȡ���" << endl;
		string pwd, num1;
		char ch;
		cout << endl << "�����뿨��:";
		cin >> num1;
		cout << "���������룺 " << endl;
	
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
	cout << "1.��Ǯ" << endl;
	cout << "2.ȡǮ" << endl;
	cout << "3.ת��" << endl;
	cout << "4.����" << endl;
	cout << "5.������Ϣ" << endl;
	cout << "6.�˳�" << endl;
	int n;
	cin >> n;
	while (n < 1 || n>6)
	{
		cout << "��������ȷ�Ĳ������!" << endl;
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
	cout << "������Ҫ�����Ǯ" << endl;
	cin >> m;
	if ((m % 100)==0) {
		c.addmoney(m);
		cout << "���ɹ�" << endl;
	}
	else {
		cout << "��������" << endl;
	}
	
}
void ATM::drawmoney(Card & c)
{
	int m;
	cout << "������Ҫȡ����Ǯ" << endl;
	cin >> m;
	if (m % 100 == 0&&c.getmoney()>m) {
		c.drawmoneymoney(m);
		cout << "ȡ��ɹ�" << endl;
	}
	else {
		cout << "��������" << endl;
	}

}
void ATM::transfer(Card & c)
{
	cout << "������Ҫת�ʵ��û�" << endl;
	string s;
	cin >> s;
	cout << "ת����Ǯ��" << endl;
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
		cout << "�˺Ų�����" << endl;
		c.addmoney(m);
	}
	
}

void ATM::change_pwd(Card & c)
{
	string s;
	cout << "������Ҫ�ĳ�ʲô����" << endl;
	cin >> s;
	c.setpassword(s);
}

void ATM::showinfo()
{
	cout <<"�˻�1"<<"   " <<c1.getmoney() << "   " << "����" << "   " <<c1.getpasswd()<<endl;
	cout << "�˻�2" << "   " << c2.getmoney()<< "   "  << "����" << "   " << c2.getpasswd() << endl;
	cout << "�˻�3" << "   " << c3.getmoney() << "   " << "����" << "   " << c3.getpasswd() << endl;
	cout << "�˻�4" << "   " << c4.getmoney() << "   " << "����" << "   " << c4.getpasswd ()<< endl;
	cout << "�˻�5" << "   " << c5.getmoney() << "   " << "����" << "   " << c5.getpasswd() << endl;
}
int main() {
//	ATM atm;
//	atm= ATM();
//	atm.welcome();
	return 0; 
}
