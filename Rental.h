#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book;
class Customer;

class Rental
{
public:
	Rental(Book* rentBook, Customer* borrower, string rentDate, string returnDate);
	bool operator<(const Rental& rhs) const;
	bool isOverdue(string today)const;
	string getRentDate()const;
	string getReturnDate()const;

private:
	Book* rentBook;
	Customer* borrower;
	string rentDate;
	string returnDate;
};

