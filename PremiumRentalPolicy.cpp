#include "PremiumRentalPolicy.h"

PremiumRentalPolicy::PremiumRentalPolicy() {
	cout << "PremiumRentalPolicy 생성자 호출" << endl; 
}

PremiumRentalPolicy::~PremiumRentalPolicy()
{
	cout << "~PremiumRentalPolicy 소멸자 호출" << endl;
}

int PremiumRentalPolicy::maxBooks() const
{
	return 10;
}

int PremiumRentalPolicy::maxRentDuration() const
{
	return 15;
}
