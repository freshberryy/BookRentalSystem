#pragma once
#include "RentalPolicy.h"

class PremiumRentalPolicy : public RentalPolicy
{
public:
	PremiumRentalPolicy();
	~PremiumRentalPolicy();
	int maxBooks() const override;
};

