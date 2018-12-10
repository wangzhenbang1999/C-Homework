#include"item.h"
#include"Books.h"
#include"Magazines.h"
#include"Movies.h"
#include"DVDs.h"
#include"Blurays.h"
#include"itemList.h"
#include<iostream>
#include"Person.h"
using namespace std;
int main() {

	int choice;
	itemList L;
	Person p;
	L.Init();

	while (1)
	{
		L.Show();
		cin >> choice;
		switch (choice)
		{
		case 1:
			L.Insert();
			break;
		case 2:
			L.List();
			break;
		case 3:
			p.borrow_book(L);
			break;
		case 4:
			p.return_book(L);
			break;
		case 5:
			exit(1);
		}
	}
	return 0;
}