#include "DiscountPricePolicy.h"

DiscountPricePolicy::DiscountPricePolicy(double rate) : discountRate(rate)
{

}

double DiscountPricePolicy::calculatePrice(double basePrice) const
{
	return basePrice - (basePrice * discountRate);
}

BookPricePolicy* DiscountPricePolicy::clone() const
{
	return new DiscountPricePolicy(*this);
}

string DiscountPricePolicy::getPolicyType()const
{
	return "«“¿Œ∞°";
}