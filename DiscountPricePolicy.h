#pragma once
#include "BookPricePolicy.h"

class DiscountPricePolicy : public BookPricePolicy
{
public:
	DiscountPricePolicy(double rate) {}
	double calculatePrice(double basePrice) const override {}

private:
	double discountRate;
};

