#pragma once
#include<iostream>
#include<string>
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

private:
	Book** books;
	int bookCount;
	InventoryManager invetory;
};

