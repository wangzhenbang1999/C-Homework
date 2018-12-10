#pragma once
#include "Movies.h"
class Blurays :
	public Movies
{
public:
	Blurays();
	Blurays(string aName, bool b) :Movies(aName, b) {
		type = "Blurays";
	}
	~Blurays();
};

