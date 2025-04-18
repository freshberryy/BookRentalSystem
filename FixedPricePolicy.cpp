#include "FixedPricePolicy.h"

double FixedPricePolicy::calculatePrice(double basePrice) const
{
	return basePrice;
}

BookPricePolicy* FixedPricePolicy::clone() const
{
	return new FixedPricePolicy(*this);
}

string FixedPricePolicy::getPolicyType() const
{
	return "Á¤»ó°¡";
}
