#include "Exceptions.h"

RentalLimitExceededException::RentalLimitExceededException() {}

RentalLimitExceededException::RentalLimitExceededException(const string& userId, int limit, const string& msg) :userId(userId), limit(limit), msg(msg)
{
	fullMsg = msg + " (userId: " + userId + ", 대여한도: " + to_string(limit) + "권)";
}

const char* RentalLimitExceededException::what() const noexcept
{
	return fullMsg.c_str();
}