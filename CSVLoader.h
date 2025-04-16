#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Book.h"
using namespace std;

template <typename T>
class CSVLoader
{
public:
	static void load(const string& fileName, T& container) {}
	static void save(const string& fileName, const T& container) {}
};

template<>
class CSVLoader<Book>
{
	static void load(const string& filename, vector<Book*>& out);
	static void save(const string& filename, const vector<Book*>& in);
};