#include "User.h"

User::User() {}

User::User(string name, UserCredential credential) : name(name), credential(credential)
{

}

UserCredential User::getUserCredential() const
{
	return credential;
}

string User::getName()const
{
	return name;
}