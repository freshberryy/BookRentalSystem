#pragma once
#include "RentalPolicy.h"

class BasicRentalPolicy : public RentalPolicy
{
public:
	bool canRent(const CustomerProfile&) const override {}
	int maxBooks() const override {};
};

