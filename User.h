#pragma once
#include<string>
#include "UserCredential.h"
using namespace std;

class User
{
public:
	User() {}
	User(string name, UserCredential credential) {}
	virtual void displayMenu() const = 0;
	virtual ~User() = default;

protected:
	string name;
	UserCredential credential;
};

