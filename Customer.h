#pragma once
#include "User.h"
#include "CustomerProfile.h"
#include"RentalHistory.h"
class Customer : public User
{
public:
	Customer();
	Customer(string name, UserCredential credential, CustomerProfile profile, RentalHistory history);
	void displayMenu() const override;
	Customer* clone() const;
	CustomerProfile& getProfile();
	RentalHistory& getHistory();

private:
	CustomerProfile profile;
	RentalHistory history;

};

