#pragma once
#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

class InventoryManager
{
public:
	int getQuantity(const string& rhs) const;
	void increase(const string& rhs);
	bool decrease(const string& rhs);
	bool isAvailable(const string& title)const;
	void printAllStock(ostream& os);
	friend ostream& operator<<(ostream& os, InventoryManager& rhs);

private:
	unordered_map<string, int> stock;
};

