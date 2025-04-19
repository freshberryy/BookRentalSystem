#include"Exceptions.h"

BookNotFoundException::BookNotFoundException(){}

BookNotFoundException::BookNotFoundException(const string& msg) : msg(msg)
{

}

const char* BookNotFoundException::what() const noexcept
{
	return msg.c_str();
}