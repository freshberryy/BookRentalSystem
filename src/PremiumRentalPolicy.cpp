#include "PremiumRentalPolicy.h"

PremiumRentalPolicy::PremiumRentalPolicy() {
}

PremiumRentalPolicy::~PremiumRentalPolicy()
{
}

int PremiumRentalPolicy::maxBooks() const
{
	return 10;
}

int PremiumRentalPolicy::maxRentDuration() const
{
	return 15;
}
