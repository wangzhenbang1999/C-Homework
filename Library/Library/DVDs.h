#pragma once
#include "Movies.h"
class DVDs :
	public Movies
{
public:
	DVDs();
	DVDs(string aName, bool b) :Movies(aName, b) {
		type = "DVDs";
	}
	~DVDs();
};

