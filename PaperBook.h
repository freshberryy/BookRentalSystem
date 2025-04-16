#pragma once
#include<iostream>
#include<string>
#include "Book.h"
using namespace std;

class PaperBook :public Book
{
public:
	PaperBook(int totalPages);
	int getTotalPages()const;

private:
	int totalPages;
};

