#include"Exceptions.h"

OutOfStockException::OutOfStockException() {}

OutOfStockException::OutOfStockException(const string& msg, const string& title) : msg(msg), title(title)
{
	fullMsg = msg + " [" + title + "]";
}

const char* OutOfStockException::what() const noexcept
{
	return fullMsg.c_str();
}