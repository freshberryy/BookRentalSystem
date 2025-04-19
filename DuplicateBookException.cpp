#include "Exceptions.h"

DuplicateBookException::DuplicateBookException() {}

DuplicateBookException::DuplicateBookException(const string& title, const string& msg) :title(title), msg(msg)
{
	fullMsg = msg + " (Ã¥Á¦¸ñ: " + title + ")";
}

const char* DuplicateBookException::what() const noexcept
{
	return fullMsg.c_str();
}