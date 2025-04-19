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

void Rental::serialize(ostream& os) const
{
	os << "\"" << rentBook->getTitle() << "\""
		<< ",," << "\"" << borrower->getUserCredential().getUserId() << "\""
		<< ",," << "\"" << rentDate << "\""
		<< ",," << "\"" << returnDate << "\""
		<< "\n";
}

Rental* Rental::deserialize(const string& line)
{
	string fields[4];
	int fieldIndex = 0;

	bool inQuotes = false;
	string token;
	string temp;
	for (size_t i = 0; i < line.size(); ++i)
	{
		char c = line[i];
		if (c == '"')
		{
			inQuotes = !inQuotes;
		}
		else if (!inQuotes && c == ',' && i + 1 < line.size() && line[i + 1] == ',')
		{
			if (fieldIndex < 4)
				fields[fieldIndex++] = token;
			token.clear();
			++i; 
		}
		else
		{
			token += c;
		}
	}
	if (fieldIndex < 4)
		fields[fieldIndex] = token;
	if (fieldIndex != 4)
	{
		throw invalid_argument("잘못된 CSV 포맷");
	}
	return new Rental(nullptr, nullptr, fields[2], fields[3], false);
}

void Rental::setRentBook(Book* book)
{
	rentBook = book;
}

void Rental::setBorrower(Customer* customer)
{
	borrower = customer;
}