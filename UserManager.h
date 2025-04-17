#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "User.h"
#include "UserManager.h"
#include "Customer.h"
#include "Admin.h"
#include "BasicRentalPolicy.h"
#include "PremiumRentalPolicy.h"
using namespace std;

class UserManager
{
public:
	UserManager();
	~UserManager();
	void loadUsers(const string& file);
	bool addUser(User* user);
	bool login(const string& id, const string& pw);
	User* getCurrentUser() const;

private:
	User** users;
	int userCount = 0;
	int capacity;
	User* currentUser;
	void resize();
};

