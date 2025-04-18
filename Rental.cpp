#include "Rental.h"

Rental::Rental() {}

Rental::Rental(Book* rentBook, Customer* borrower, string rentDate, string returnDate, bool isReturned):rentDate(rentDate), returnDate(returnDate), isReturned(isReturned)
{
	this->rentBook = rentBook;
	this->borrower = borrower;
}

Rental::Rental(const Rental& rhs)
{
	rentBook = rhs.rentBook->clone();
	borrower = rhs.borrower->clone();
	rentDate = rhs.rentDate;
	returnDate = rhs.returnDate;
	isReturned = rhs.isReturned;
}

Rental::~Rental()
{
	delete rentBook;
	delete borrower;
}

Rental& Rental::operator=(const Rental& rhs)
{
	if (this == &rhs)
		return *this;
	delete rentBook;
	delete borrower;

	rentBook = rhs.rentBook->clone();
	borrower = rhs.borrower->clone();
	rentDate = rhs.rentDate;
	returnDate = rhs.returnDate;
	isReturned = rhs.isReturned;

	return *this;
}

void Rental::markReturned(string actualReturnDate)
{
	returnDate = actualReturnDate;
	isReturned = true;
}

bool Rental::isOverdue(string today)const
{
	if (isReturned) return false;
	return returnDate < today;
}

bool Rental::operator<(const Rental& rhs) const
{
	return rentDate < rhs.rentDate;
}

Book* Rental::getRentBook()const
{
	return rentBook;
}

Customer* Rental::getBorrower()const
{
	return borrower;
}

string Rental::getRentDate()const
{
	return rentDate;
}

string Rental::getReturnDate()const
{
	return returnDate;
}

bool Rental::getReturned()const
{
	return isReturned;
}

Rental* Rental::clone() const
{
	return new Rental(*this);
}