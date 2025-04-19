#pragma once
#include<iostream>
#include<string>
using namespace std;

class UserCredential
{
public:
	UserCredential();
	UserCredential(string userId, string password);
	UserCredential(const UserCredential& rhs);
	UserCredential& operator=(const UserCredential& rhs);
	bool operator==(const UserCredential& rhs)const;
	string getUserId()const;
	string getPassword()const;

private:
	string userId;
	string password;
};

