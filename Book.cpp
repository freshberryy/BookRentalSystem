#include "Book.h"

Book::Book() {}

Book::Book(char* title, string author, string publisher, int year, BookPricePolicy* policy, double basePrice) :author(author), publisher(publisher), publishYear(year), basePrice(basePrice)
{
	cout << "Book()" << endl;
	int len = 0;
	while (title[len] != '\0')
	{
		len++;
	}
	this->title = new char[len + 1];
	strcpy_s(this->title, len + 1, title);
	this->pricePolicy = policy;
}

Book::Book(const Book& rhs)
{
	cout << "Book(const Book &)" << endl;
	int len = 0;
	while (rhs.title[len] != '\0')
	{
		len++;
	}
	this->title = new char[len + 1];
	strcpy_s(this->title, len + 1, rhs.title);
	author = rhs.author;
	publisher = rhs.publisher;
	publishYear = rhs.publishYear;
	pricePolicy = rhs.pricePolicy;
	basePrice = rhs.basePrice;

}

Book& Book::operator=(const Book& rhs)
{
	cout << "operator=(const Book &)" << endl;
	if (this == &rhs)
		return *this;
	delete[] this->title;
	delete pricePolicy;
	int len = 0;
	while (rhs.title[len] != '\0')
	{
		len++;
	}
	this->title = new char[len + 1];
	strcpy_s(this->title, len + 1, rhs.title);
	author = rhs.author;
	publisher = rhs.publisher;
	publishYear = rhs.publishYear;
	pricePolicy = rhs.pricePolicy;
	basePrice = rhs.basePrice;
	return *this;
}

Book::Book(Book&& rhs)
{
	cout << "Book(Book &&)" << endl;
	this->title = rhs.title;
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
	cout << "operator(Book &&)" << endl;
	if (this == &rhs)
		return *this;
	delete[] this->title;
	delete pricePolicy;
	this->title = rhs.title;
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
	return* this;
}

Book::~Book()
{
	cout << "~Book()" << endl;
	delete[] title;

	//Book은 pricePolicy의 소유권 보유. 따라서 소멸 시 delete.
	delete pricePolicy;
}

double Book::getFinalPrice() const
{
	return pricePolicy->calculatePrice(basePrice);
}

bool Book::operator==(const Book& rhs) const
{
	if (strcmp(title, rhs.title) == 0)
		return true;
	return false;
}

void Book::print(ostream& os) const
{
	os << "제목: " << title
		<< ", 지은이: " << author
		<< ", 출판사: " << publisher
		<< ", 출판년: " << publishYear << endl;
}

ostream& operator<<(ostream& os, const Book& rhs)
{
	rhs.print(os);
	return os;
}

string Book::getTitle() const
{
	return string(title);
}

string Book::getAuthor()const
{
	return author;
}

string Book::getPublisher() const
{
	return publisher;
}

int Book::getPublishYear() const
{
	return publishYear;
}

Book* Book::clone() const
{
	return new Book(*this);
}