#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;

class InventoryManager
{
public:
	int getQuatity(const string& rhs) const {}
	void increase(const string& rhs) {}
	void decrease(const string& rhs) {}

private:
	map<string, int> stock;
};

