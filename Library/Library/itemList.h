#pragma once
#include"item.h"
#include"Books.h"
#include"Magazines.h"
#include"Movies.h"
#include"DVDs.h"
#include"Blurays.h"
#include"itemList.h"
#include"MusicCDs.h"

class itemList
{
public:
	itemList();
	void Init();
	void List();
	void Insert();
	void Show();
	void TypeShow();
	item & Findbook(string name);
	~itemList();

private:
	item *m_first;
	int m_sum;
};

