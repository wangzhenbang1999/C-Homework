#pragma once
#include<string>
#include"item.h"
#include<iostream>
#include"itemList.h"
using namespace std;
class Person
{
public:
	Person();
	~Person();
	void setName(string aName);
	void setAddress(string aAddress);
	string getName();
	string getAddress();
	void borrow_book(itemList L);	
	void return_book(itemList L);
private:
	string name;
	string address;
};

