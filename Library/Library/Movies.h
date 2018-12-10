#pragma once
#include "item.h"
#include<string>
using namespace std;
class Movies :
	public item
{
public:
	Movies();
	Movies(string aName, bool b) :item(aName, b) {
		type = "Movies";
	}
	~Movies();
};

