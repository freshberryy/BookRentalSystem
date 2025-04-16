#pragma once
using namespace std;

class CustomerProfile;

class RentalPolicy
{
public:
	virtual bool canRent(const CustomerProfile& rhs) const = 0;
	virtual int maxBooks() const = 0;
	virtual ~RentalPolicy() = default;

};

