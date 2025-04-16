#pragma once
#include "User.h"
#include "CustomerProfile.h"
#include"RentalHistory.h"
class Customer : public User
{
public:
	Customer() {}
	Customer(CustomerProfile profile, RentalHistory history);
	CustomerProfile& getProfile();
	RentalHistory& getHistory();

private:
	CustomerProfile profile;
	RentalHistory history;

};

