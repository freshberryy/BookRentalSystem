#pragma once
#include<string>
#include "Rental.h"

class LateFeePolicy
{
public:

	LateFeePolicy(double feePerDay);

	double calculate(const Rental& rental, const string&curDate) const {}

private:
	double feePerDay;

	//YYYY-MM-DD
	int calculateLateDays(const string& from, const string& to)const;
};

