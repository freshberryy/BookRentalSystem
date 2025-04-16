#pragma once
#include<functional>
#include<vector>
#include"Rental.h"
class RentalHistory
{
public:
	void addRental(Rental* rhs) {}
	void printHistory()const {}
	void sort(std::function<bool(Rental*, Rental*)> cmp);


private:
	vector<Rental> rentals;
};

