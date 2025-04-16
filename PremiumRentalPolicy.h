#pragma once
#include "RentalPolicy.h"

class PremiumRentalPolicy : public RentalPolicy
{
public:
	bool canRent(const CustomerProfile&) const override;
	int maxBooks() const override;
};

