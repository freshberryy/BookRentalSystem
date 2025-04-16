#pragma once
#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include"Book.h"
#include"Library.h"
using namespace std;

class Catalog
{
public:

	Catalog(Library* lib);
	void searchByTitle(const string& title, ostream& os) const;
	void searchByAuthor(const string& autor, ostream& os) const;
	void searchByPublisher(const string& publisher, ostream& os)const;
	void searchByYearRange(int startYear, int endYear, ostream& os)const;
	void filterBooks(function<bool(const Book& book)> predicate, ostream& os)const;
	void filterBooks(function<bool(const Book&book)> predicate)const;
	void filterAndSort(function<bool(const Book& book)> filter, function<bool(Book*, Book*)> cmp, ostream& os)const;

private:
	Library* library;
};

