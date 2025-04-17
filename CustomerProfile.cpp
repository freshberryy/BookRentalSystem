#include "CustomerProfile.h"

CustomerProfile::CustomerProfile() {}

CustomerProfile::CustomerProfile(RentalPolicy* rentalPolicy, int curRentalCount, int rentalLimit) : curRentalCount(curRentalCount), rentalLimit(rentalLimit)
{
	//추상 클래스이므로 동적할당 불가
	this->rentalPolicy = rentalPolicy;
}

CustomerProfile::~CustomerProfile()
{
	delete rentalPolicy;
}

void CustomerProfile::incrementRent()
{
	curRentalCount++;
}

void CustomerProfile::decrementRent()
{
	if (curRentalCount > 0) curRentalCount--;
}

bool CustomerProfile::canRent() const
{
	return curRentalCount < rentalLimit;

}

int CustomerProfile::getRentalLimit() const
{
	return rentalLimit;
}

int CustomerProfile::getCurRentalCount() const
{
	return curRentalCount;
}

void CustomerProfile::applyPolicy()
{
	rentalLimit = rentalPolicy->maxBooks();
}