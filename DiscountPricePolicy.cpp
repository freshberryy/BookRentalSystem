#include "DiscountPricePolicy.h"

DiscountPricePolicy::DiscountPricePolicy(double rate) : discountRate(rate)
{

}

double DiscountPricePolicy::calculatePrice(double basePrice) const
{
	return basePrice * discountRate;
}

BookPricePolicy* DiscountPricePolicy::clone() const
{
	return new DiscountPricePolicy(*this);
}