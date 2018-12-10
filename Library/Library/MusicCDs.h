#pragma once
#include "item.h"
#include<string>
using namespace std;
class MusicCDs :
	public item
{
public:
	MusicCDs();
	MusicCDs(string aName, bool b) :item(aName, b) {
		type = "MusicCDs";
	}
	~MusicCDs();
};

