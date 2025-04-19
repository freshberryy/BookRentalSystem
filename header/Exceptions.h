#pragma once
#include<exception>
#include<iostream>
#include<string>
using namespace std;

class BookNotFoundException : public exception
{
public:
	BookNotFoundException();
	BookNotFoundException(const string& msg);
	const char* what() const noexcept;

private:
	string msg;
};

class DuplicateBookException : public exception
{
public:
	DuplicateBookException();
	DuplicateBookException(const string& title, const string& msg);
	const char* what() const noexcept;

private:
	string title;
	string msg;
	string fullMsg;
};

class RentalLimitExceededException : public exception
{
public:
	RentalLimitExceededException();
	RentalLimitExceededException(const string& userId, int limit, const string&msg);
	const char* what() const noexcept;

private:
	string userId;
	int limit;
	string msg;
	string fullMsg;
};

class InvalidCredentialException : public exception
{
public:
	InvalidCredentialException();
	InvalidCredentialException(const string& userId, const string&msg);
	const char* what() const noexcept;

private:
	string userId;
	string msg;
	string fullMsg;
};

class OutOfStockException : public exception
{
public:
	OutOfStockException();
	OutOfStockException(const string&msg, const string&title);
	const char* what() const noexcept;

private:
	string title;
	string msg;
	string fullMsg;
};