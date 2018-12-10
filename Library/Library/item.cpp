#include "item.h"
#include"iostream"


item::item()
{
}

item::item(string aName, bool b)
{
	name = aName;
	borrow = b;
	m_next = NULL;
}


item::~item()
{
}

void item::setName(string aName)
{
	name = aName;
}

string item::getName()
{
	return name;
}

void item::setBorrow(bool b)
{
	borrow = b;
}

bool item::IsBorrow()
{
	return borrow;
}

void item::SetNext(item * n)
{
	m_next = n;
}

item *item::GetNext()
{
	return m_next;
}

string item::getType()
{
	return type;
}
