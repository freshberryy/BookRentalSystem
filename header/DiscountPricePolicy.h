#pragma once
#include "BookPricePolicy.h"

class DiscountPricePolicy : public BookPricePolicy
{
public:
	DiscountPricePolicy(double rate);
	double calculatePrice(double basePrice) const override;
	BookPricePolicy* clone() const override;
	string getPolicyType() const override;

private:
	double discountRate;
};

