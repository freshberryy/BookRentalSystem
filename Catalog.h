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
	Book* searchByTitle(const string& title, ostream& os) const;
	Book* searchByAuthor(const string& autor, ostream& os) const;
	Book* searchByPublisher(const string& publisher, ostream& os)const;
	vector<Book*> searchByYearRange(int startYear, int endYear, ostream& os)const;
	vector<Book*> filterBooks(function<bool(const Book& book)> predicate, ostream& os)const;
	vector<Book*> filterAndSort(function<bool(const Book& book)> filter, function<bool(Book*, Book*)> cmp, ostream& os)const;

private:
	Library* library;
};

