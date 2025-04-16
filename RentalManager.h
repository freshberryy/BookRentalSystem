#pragma once
#include"LateFeePolicy.h"
#include"Customer.h"
#include"Book.h"
#include"Rental.h"



class RentalManager
{
public:
	RentalManager() {}
	RentalManager(LateFeePolicy* feePolicy) {}
	Rental* rentBook(Customer* customer, Book* book) {}
	bool returnBook(Rental* rental) {}
private:
	LateFeePolicy* feePolicy;
};

