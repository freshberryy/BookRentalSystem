#pragma once
#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include <iomanip>
#include "Book.h"
#include"InventoryManager.h"
#include"CSVLoader.h"
#include"Exceptions.h"
using namespace std;


class Library
{
public:
	Library();
	~Library();
	Book* findByTitle(const string& title) const;
	void addBook(Book* book);
	bool removeBook(const string& book);
	int getBookCount() const;
	Book* getBookAt(int index);
	void listAllBooks(ostream& os) const;
	bool isAvailable(const string& title);
	int getBookStock(const string& title);
	vector<Book*>getAvailableBooks();
	void printInventory(ostream& os);
	void filterBooks(std::function<bool(const Book&)> pred, ostream&);
	Book** filterBooks(std::function<bool(const Book&)> pred);
	void sortBooksByTitle();
	void sortBooksByPrice();
	void sortBooksByYearDesc();
	void sortBooks(function<bool(Book*, Book*)> comp);
	void loadFromFile(const string& filename);
	void saveToFile(const string& filename);
	friend ostream& operator<<(const Library& lib, ostream& os);

private:
	Book**books;
	int bookCount;
	int capacity;
	InventoryManager inventory;
	void resize();
};



