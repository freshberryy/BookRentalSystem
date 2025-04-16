#include "Book.h"

Book::Book(char* title, string author, string publisher, int year, BookPricePolicy* policy, double basePrice) :author(author), publisher(publisher), publishYear(year), basePrice(basePrice)
{
	int len = 0;
	while (title[len] != '\0')
	{
		len++;
	}
	this->title = new char[len+1];
	strcpy_s(this->title, len + 1, title);

	this->pricePolicy = policy;
}

Book::Book(const Book& rhs)
{
	int len = 0;
	while (rhs.title[len] != '\0')
	{
		len++;
	}
	this->title = new char[len+1];
	strcpy_s(this->title, len + 1, rhs.title);
	author = rhs.author;
	publisher = rhs.publisher;
	publishYear = rhs.publishYear;
	pricePolicy = rhs.pricePolicy->clone();
	basePrice = rhs.basePrice;
}

Book& Book::operator=(const Book& rhs)
{
	if (this == &rhs)
		return *this;
	delete[] this->title;
	delete this->pricePolicy;

	int len = 0;
	while (rhs.title[len] != '\0')
	{
		len++;
	}
	this->title = new char[len+1];
	strcpy_s(this->title, len + 1, rhs.title);
	author = rhs.author;
	publisher = rhs.publisher;
	publishYear = rhs.publishYear;
	pricePolicy = rhs.pricePolicy->clone();
	basePrice = rhs.basePrice;

	return *this;
}

Book::Book(Book&& rhs)
{
	title = rhs.title;
	author = rhs.author;
	publisher = rhs.publisher;
	publishYear = rhs.publishYear;
	pricePolicy = rhs.pricePolicy;
	basePrice = rhs.basePrice;
	rhs.title = nullptr;
	rhs.author.clear();
	rhs.publisher.clear();
	rhs.publishYear = 0;
	rhs.pricePolicy = nullptr;
	rhs.basePrice = 0;
}

Book& Book::operator=(Book&& rhs)
{
	if (this == &rhs)
		return *this;
	delete[] this->title;
	delete this->pricePolicy;
	title = rhs.title;
	author = rhs.author;
	publisher = rhs.publisher;
	publishYear = rhs.publishYear;
	pricePolicy = rhs.pricePolicy;
	basePrice = rhs.basePrice;
	rhs.title = nullptr;
	rhs.author.clear();
	rhs.publisher.clear();
	rhs.publishYear = 0;
	rhs.pricePolicy = nullptr;
	rhs.basePrice = 0;
	return *this;
}

Book::~Book()
{
	delete[] title;
	delete pricePolicy;
}