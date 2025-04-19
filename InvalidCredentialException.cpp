#include"Exceptions.h"

InvalidCredentialException::InvalidCredentialException() {}

InvalidCredentialException::InvalidCredentialException(const string& userId, const string& msg):userId(userId), msg(msg)
{
	fullMsg = msg + " (userId: " + userId + ")";
}

const char* InvalidCredentialException::what() const noexcept
{
	return fullMsg.c_str();
}