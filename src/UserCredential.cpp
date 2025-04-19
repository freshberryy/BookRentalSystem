#include "UserCredential.h"

UserCredential::UserCredential() {}

UserCredential::UserCredential(string userId, string password) : userId(userId), password(password) {}

UserCredential::UserCredential(const UserCredential& rhs)
{
	userId = rhs.userId;
	password = rhs.password;
}

UserCredential& UserCredential::operator=(const UserCredential& rhs)
{
	if (this == &rhs)
		return *this;
	userId = rhs.userId;
	password = rhs.password;
	return *this;
}

bool UserCredential::operator==(const UserCredential& rhs) const
{
	if (userId == rhs.userId && password == rhs.password)
		return true;
	return false;
}

string UserCredential::getUserId() const
{
	return userId;
}

string UserCredential::getPassword() const
{
	return password;
}