#pragma once
#include "RentalPolicy.h"

class BasicRentalPolicy : public RentalPolicy
{
public:
	BasicRentalPolicy();
	~BasicRentalPolicy();
	int maxBooks() const override;
	int maxRentDuration() const override;
};

