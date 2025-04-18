#include "RentalHistory.h"
#include"Rental.h"
RentalHistory::RentalHistory() :size(0), capacity(10)
{
	records = new Rental * [capacity];
}

RentalHistory::~RentalHistory()
{
	for (int i = 0; i < size; i++)
	{
		delete records[i];
	}

	delete[] records;
}

void RentalHistory::addRental(Rental* rhs)
{
	if (size == capacity)
		resize();
	records[size++] = rhs;
}

void RentalHistory::resize()
{
	Rental** tmp = new Rental * [capacity * 2];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = records[i];
	}
	delete[] records;
	records = tmp;
	capacity *= 2;
}

Rental** RentalHistory::getRentalByBookTitle(string& title)
{
	int len = 0;

	for (int i = 0; i < size; i++)
	{
		if (records[i]->getRentBook()->getTitle() == title)
		{
			len++;
		}
	}
	Rental** ret = new Rental * [len];
	int idx = 0;
	for (int i = 0; i < size; i++)
	{
		if (records[i]->getRentBook()->getTitle() == title)
		{
			ret[idx++] = records[i]->clone();
		}
	}
	return ret;
}

Rental** RentalHistory::getAllActiveRentals()
{
	int len = 0;
	for (int i = 0; i < size; i++)
	{
		if (!records[i]->getReturned())
		{
			len++;
		}
	}

	Rental** ret = new Rental * [len];
	int idx = 0;
	for (int i = 0; i < size; i++)
	{
		if (!records[i]->getReturned())
		{
			ret[idx++] = records[i]->clone();
		}
	}
	return ret;
}

void RentalHistory::printAll()const
{
	for (int i = 0; i < size; i++)
	{
		cout << "대출자: " << records[i]->getBorrower()->getName()
			<< " 빌린 책: " << records[i]->getRentBook()->getTitle()
			<< " 빌린 날짜: " << records[i]->getRentDate()
			<< " 대출 만기일: " << records[i]->getReturnDate() << endl;
	}
}

int RentalHistory::getSize() const
{
	return size;
}

Rental* RentalHistory::getActiveRentalByTitle(const string& title)
{
	for (int i = 0; i < size; i++)
	{
		if (!records[i]->getReturned() && records[i]->getRentBook()->getTitle() == title)
		{
			return records[i];
		}
	}
	return nullptr;
}