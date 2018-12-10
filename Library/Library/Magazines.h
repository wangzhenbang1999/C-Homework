#pragma once
#include "item.h"
#include<string>
using namespace std;
class Magazines :
	public item
{
public:
	Magazines();
	Magazines(string aName, bool b) :item(aName, b) {
		type = "Magazines";
	}
	~Magazines();
};

