#pragma once
#include<iostream>
#include<string>
#include<functional>
#include"Book.h"
using namespace std;

class Catalog
{
public:
	void searchByTitle(const string& title)const {}
	void filter(function<bool(const Book& rhs)> predicate) {}
};

