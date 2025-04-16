#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "User.h"
using namespace std;

class UserManager
{
public:
	UserManager();
	void loadUsers(const string& file);
	bool addUser(User* user);
	bool login(const string& id, const string& pw);
	User* getCurrentUser() const;

private:
	vector<User>users;
	User* currentUser;
};

