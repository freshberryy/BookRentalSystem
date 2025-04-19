#include "BasicRentalPolicy.h"

BasicRentalPolicy::BasicRentalPolicy()
{
	cout << "BasicRentalPolicy 생성자 호출" << endl;
}

BasicRentalPolicy::~BasicRentalPolicy()
{
	cout << "~BasicRentalPolicy 소멸자 호출" << endl; 
}

int BasicRentalPolicy::maxBooks() const
{
	return 5;
}

int BasicRentalPolicy::maxRentDuration() const
{
	return 10;
}
