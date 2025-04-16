#pragma once
#include<iostream>
#include<string>
using namespace std;
class BookMetaData
{
public:
	BookMetaData() {}
	BookMetaData(string description, string category, string publisher, int month, int year) {}
	BookMetaData(const BookMetaData& rhs) {}
	BookMetaData(BookMetaData&& rhs) {}
	BookMetaData& operator=(const BookMetaData&rhs){}
	BookMetaData& operator=(BookMetaData&& rhs) {}

private:
	string description;
	string category;
	string publisher;
	int publishMonth;
	int publishYear;
};

