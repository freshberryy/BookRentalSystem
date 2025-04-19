#pragma once
#include "User.h"
class Admin : public User
{
public:
	Admin(string name, UserCredential credential);
	void displayMenu() const override;
	bool isAdmin() const override;
};

