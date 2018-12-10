#pragma once
#include "item.h"
#include<string>
using namespace std;
class Books :
	public item
{
public:
	Books();
	Books(string aName, bool b) :item(aName, b) {
		type = "book";
	}
	~Books();
};

