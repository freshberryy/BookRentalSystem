#include"Exceptions.h"

OutOfStockException::OutOfStockException() {}

OutOfStockException::OutOfStockException(int stock, const string& msg) : stock(stock), msg(msg)
{
	fullMsg = msg + " (남은 재고: " + to_string(stock) + "권)";
}

const char* OutOfStockException::what() const noexcept
{
	return fullMsg.c_str();
}