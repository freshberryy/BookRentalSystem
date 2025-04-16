#pragma once
class Rental;

class RentalHistory
{
public:
	void addRental(Rental* rhs) {}
	void printHistory()const {}
	int getCount()const {}

private:
	Rental** rentals;
	int count;
};

