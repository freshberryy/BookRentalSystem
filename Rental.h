#pragma once
#include<iostream>
#include<string>
#include "Book.h"
#include "Customer.h"
using namespace std;

class Rental
{
public:
	Rental(Book* rentBook, Customer* borrower, string rentDate, string returnDate) {}
	bool operator<(const Rental& rhs) const {}
	bool isOverdue()const {}

private:
	Book* rentBook;
	Customer* borrower;
	string rentDate;
	string returnDate;
};

