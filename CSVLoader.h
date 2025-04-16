#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename T>
class CSVLoader
{
public:
	static void load(const string& fileName, T& container) {}
	static void save(const string& fileName, const T& container) {}
};

