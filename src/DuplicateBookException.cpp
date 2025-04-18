#include "Exceptions.h"

DuplicateBookException::DuplicateBookException() {}

DuplicateBookException::DuplicateBookException(const string& title, const string& msg) :title(title), msg(msg)
{
	fullMsg = msg + " (å����: " + title + ")";
}

const char* DuplicateBookException::what() const noexcept
{
	return fullMsg.c_str();
}