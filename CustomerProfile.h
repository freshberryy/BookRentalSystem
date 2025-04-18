#pragma once
#include "RentalPolicy.h"
class CustomerProfile
{
public:
	CustomerProfile();
	CustomerProfile(RentalPolicy* rentalPolicy, int curRentalCount, int rentalLimit);
	~CustomerProfile();
	bool canRent() const ;
	void incrementRent();
	void decrementRent();
	int getRentalLimit() const;
	int getCurRentalCount() const;
	void applyPolicy();
	RentalPolicy* getRentalPolicy() const;

private:
	RentalPolicy* rentalPolicy;
	int curRentalCount;
	int rentalLimit;
};

