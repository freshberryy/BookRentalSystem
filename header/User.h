#pragma once
#include<string>
#include "UserCredential.h"
using namespace std;

class User
{
public:
	User();
	User(string name, UserCredential credential);
	virtual void displayMenu() const = 0;
	virtual bool isAdmin() const = 0;
	UserCredential getUserCredential() const;
	virtual ~User() = default;
	string getName() const;

protected:
	string name;
	UserCredential credential;
};

