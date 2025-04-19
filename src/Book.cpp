#include "Book.h"

Book::Book() {}

Book::Book(char* title, string author, string publisher, int year, BookPricePolicy* policy, double basePrice) :author(author), publisher(publisher), publishYear(year), basePrice(basePrice)
{
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
	os << left;
	os << setw(10) << "제목" << " : " << title << "\n"
		<< setw(10) << "지은이" << " : " << author << "\n"
		<< setw(10) << "출판사" << " : " << publisher << "\n"
		<< setw(10) << "출판년도" << " : " << publishYear << "\n\n";

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

void Book::serialize(ostream& os) const
{
	os << "\"" << string(title) << "\","
		<< "\"" << author << "\","
		<< "\"" << publisher << "\","
		<< "\"" << publishYear << "\","
		<< "\"" << getFinalPrice() << "\","
		<< "\"" << pricePolicy->getPolicyType() << "\""
		<< "\n";
}

Book* Book::deserialize(const string& line)
{
	string parsed[5];
	int fieldIndex = 0;
	bool inQuotes = false;
	string token;
	for (size_t i = 0; i < line.size(); i++)
	{
		char c = line[i];
		if (c == '"')
			inQuotes = !inQuotes;
		else if (c == ',' && !inQuotes)
		{
			if (fieldIndex < 5)
				parsed[fieldIndex++] = token;
			token.clear();
		}
		else
		{
			token += c;
		}
	}
	if (fieldIndex < 5)
		parsed[fieldIndex] = token;

	if (fieldIndex != 4)
	{
		throw invalid_argument("잘못된 CSV 포맷");
		
	}

	char* title_cstr = new char[parsed[0].size() + 1];
	strcpy_s(title_cstr, parsed[0].size() + 1, parsed[0].c_str());
	string author = parsed[1];
	string publisher = parsed[2];

	string yearStr = parsed[3];

	int year = stoi(yearStr);
	double basePrice = stod(parsed[4]);
	BookPricePolicy* p = nullptr;
	if (basePrice >= 5000)
		p = new DiscountPricePolicy(0.1);
	else
		p = new FixedPricePolicy();

	return new Book(title_cstr, author, publisher, year, p, basePrice);
}