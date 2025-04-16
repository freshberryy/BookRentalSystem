#pragma once
#include<iostream>
#include<string>
#include "User.h"
using namespace std;

class UserManager
{
public:
	UserManager() {}
	void loadUsers(const string& file) {}
	bool login(const string& id, const string& pw) {}
	User* getCurrentUser() const {};

private:
	User** users;
	int userCount;
	User* currentUser;
};

