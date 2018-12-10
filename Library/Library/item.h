#pragma once
#include<string>
#include<iostream>
using namespace std;
class item
{
public:
	item();
	item(string aName, bool b);
	~item();
	void setName(string aName);
	string getName();
	void setBorrow(bool b);
	bool IsBorrow();
	void SetNext(item *n);
	item *GetNext();
	string getType();
	string type;
private:
	string name;
	bool borrow;
	item *m_next;
};

