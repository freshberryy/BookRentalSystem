#pragma once
#include<iostream>
#include<string>
#include "Book.h"
using namespace std;

class Ebook : public Book
{
public:
	Ebook(bool drmProtected) {}
	bool getDrm() const;

private:
	bool drmProtected;
};

