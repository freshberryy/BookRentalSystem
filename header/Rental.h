#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include "Book.h"
#include"Customer.h"

using namespace std;


class Rental
{
public:
	Rental();
	Rental(Book* rentBook, Customer* borrower, string rentDate, string returnDate, bool isReturned);
	Rental(const Rental& rhs);
	~Rental();
	Rental& operator=(const Rental& rhs);
	bool operator<(const Rental& rhs) const;
	bool isOverdue(string today)const;
	void markReturned(string actualReturnDate);
	Book* getRentBook()const;
	Customer* getBorrower()const;
	string getRentDate()const;
	string getReturnDate()const;
	bool getReturned()const;
	Rental* clone() const;
	void serialize(ostream& os) const;
	static Rental* deserialize(const string& line);
	void setRentBook(Book*);
	void setBorrower(Customer*);

private:
	Book* rentBook;
	Customer* borrower;
	string rentDate;
	string returnDate;
	bool isReturned;
};


