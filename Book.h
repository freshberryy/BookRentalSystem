#pragma once
#include<iostream>
#include<string>
#include"BookPricePolicy.h"
using namespace std;

class Book
{
public:
	Book();
	Book(char* title, string author, string publisher, int year, BookPricePolicy* policy, double basePrice);
	Book(const Book& rhs);
	Book(Book&& rhs);
	Book& operator=(const Book& rhs);
	Book& operator=(Book&& rhs);
	~Book();
	bool operator==(const Book& rhs) const;
	void serialize(ostream& os) const;
	static Book* deserialize(const string& rhs);
	string getTitle() const;
	string getAuthor() const;
	string getPublisher() const;
	int getPublishYear() const;
	double getFinalPrice() const;
	void print(ostream& os) const;
	friend ostream& operator<<(ostream&os, const Book& rhs);
	Book* clone() const;

protected:
	char* title;
	string author;
	string publisher;
	int publishYear;
	BookPricePolicy* pricePolicy;
	double basePrice;
};

