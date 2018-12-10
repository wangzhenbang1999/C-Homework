#include "Person.h"



Person::Person()
{
}


Person::~Person()
{
}

void Person::setName(string aName)
{
	name = aName;
}

void Person::setAddress(string aAddress)
{
	address = aAddress;
}

string Person::getName()
{
	return name;
}

string Person::getAddress()
{
	return address;
}

void Person::borrow_book(itemList L)
{
	string bookName;
	cout << "借哪本书？输入名字" << endl;
	cin >> bookName;
	if ((L.Findbook(bookName)).IsBorrow()) {
		cout << "书已经借出去啦" << endl;
	}
	else {
		(L.Findbook(bookName)).setBorrow(true);
	}
					
}

void Person::return_book(itemList L)
{
	string bookName;
	cout << "还哪本书？输入名字" << endl;
	cin >> bookName;
	(L.Findbook(bookName)).setBorrow(false);
}

