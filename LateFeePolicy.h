#pragma once
#include<string>
#include "Rental.h"

template <typename T>
class LateFeePolicy
{
public:

	LateFeePolicy(T feePerDay): feePerDay(feePerDay)
	{

	}

	T calculate(const Rental& rental, const string& curDate) const
	{
		T result{};

		string rentalDate = rental.getRentDate();
		result = calculateLateDays(rentalDate, curDate);

		if (result < 0)
			result = 0;
		return result;
	}

private:
	T feePerDay;

	//YYYY-MM-DD
	int calculateLateDays(const string& from, const string& to)const
	{
		int sY = stoi(from.substr(0, 4));
		int sM = stoi(from.substr(5, 2));
		int sD = stoi(from.substr(8, 2));

		int eY = stoi(to.substr(0, 4));
		int eM = stoi(to.substr(5, 2));
		int eD = stoi(to.substr(8, 2));

		return (365 * eY + 30 * eM + eD) - (365 * sY + 30 * sM + sD);
	}
};

