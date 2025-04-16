#pragma once
#include "RentalPolicy.h"
class CustomerProfile
{
public:
	CustomerProfile() {}
	CustomerProfile(RentalPolicy* rentalPolicy, int curRentalCount, int rentalLimit){}
	bool canRent() const {}
	void incrementRent() {}
	void decrementRent() {}

private:
	RentalPolicy* rentalPolicy;
	int curRentalCount;
	int rentalLimit;
};

