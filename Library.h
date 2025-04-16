#pragma once
#include<iostream>
#include<string>
#include<functional>
#include "Book.h"
#include"InventoryManager.h"
using namespace std;

class Library
{
public:
	Book* findByTitle(const string& title) const {}
	void addBook(Book* book) {}
	void removeBook(const string& book) {}
	void listAllBook()const{}
	int getBookCount() const;
	void sortBooksByTitle();
	void sortBooksByPrice();
	void sortBooksByYearDesc();
	void sortBooks(function<bool(Book*, Book*)> comp);
	void loadFromFile(const string& filename);
	void saveToFile(const string& filename);

private:
	Book** books;
	int bookCount;
	InventoryManager invetory;
};

