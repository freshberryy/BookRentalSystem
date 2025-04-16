#pragma once
#include "BookPricePolicy.h"

class FixedPricePolicy : public BookPricePolicy
{
public:
	double calculatePrice(double basePrice) const override;
};

