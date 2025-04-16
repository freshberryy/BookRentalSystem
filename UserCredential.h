#pragma once
#include<iostream>
#include<string>
using namespace std;

class UserCredential
{
public:
	UserCredential() {}
	UserCredential(string userId, string password) {}
	bool operator==(const UserCredential& rhs)const {}
	string getUserId()const {}
	string getPassWord()const {}

private:
	string userId;
	string password;
};

