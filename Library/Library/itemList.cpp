#include "itemList.h"
#include<iostream>




itemList::itemList()
{
	m_first = NULL;
	m_sum = 0;
}

void itemList::Init()
{
	m_first = new item;
}

void itemList::List()
{
	item *p = m_first->GetNext();

	while (p != NULL)
	{
		cout << p->getName() << "  " << p->IsBorrow() << "   "<< p->getType()<< endl;
		p = p->GetNext();
	}
	
}

void itemList::Insert()
{
	string name;
	int a;
	item *p = m_first;
	TypeShow();
	cin >> a;
	cout << "Please input name :" << endl;
	cin >> name;
	if (a == 1) {
		Books *s = new Books(name, false);
		for (int i = 0; i < m_sum; i++)
		{
			p = p->GetNext();
		}
		p->SetNext(s);
	}
	else if (a == 2) {
		Magazines *s = new Magazines(name, false);
		for (int i = 0; i < m_sum; i++)
		{
			p = p->GetNext();
		}
		p->SetNext(s);
	}
	else if (a == 3) {
		MusicCDs  *s = new MusicCDs(name, false);
		for (int i = 0; i < m_sum; i++)
		{
			p = p->GetNext();
		}
		p->SetNext(s);
	}
	else if (a == 4) {
		DVDs  *s = new DVDs(name, false);
		for (int i = 0; i < m_sum; i++)
		{
			p = p->GetNext();
		}
		p->SetNext(s);
	}
	else if (a == 5) {
		Blurays *s = new Blurays(name, false);
		for (int i = 0; i < m_sum; i++)
		{
			p = p->GetNext();
		}
		p->SetNext(s);
	}
	m_sum++;
}


void itemList::Show()
{
	cout << "Please make your desion !" << endl;
	cout << "1、 Insert" << endl;
	cout << "2、 List" << endl;
	cout << "3、 Borrow" << endl;
	cout << "4、 Return" << endl;
	cout << "5、 Exit" << endl;
}

void itemList::TypeShow()
{
	cout << "Please make your desion !" << endl;
	cout << "1、 Books" << endl;
	cout << "2、 Magazines" << endl;
	cout << "3、 MusicCDs " << endl;
	cout << "4、 DVDs " << endl;
	cout << "5、 Blurays " << endl;

}

item & itemList::Findbook(string name)
{
	item *p = m_first->GetNext();

	while (p != NULL)
	{
		if (p->getName() == name) 
			return *p;
		p = p->GetNext();
	}	
	cout << "没这本书"<<endl;
}

itemList::~itemList()
{
}
