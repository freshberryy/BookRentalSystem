#pragma once
#include "Book.h"

class BookFilterByPriceRange
{
public:
	BookFilterByPriceRange(double minPrice, double maxPrice) : minPrice(minPrice), maxPrice(maxPrice)
	{

	}

	bool operator()(const Book& rhs)
	{
		double price = rhs.getFinalPrice();

		if (price >= minPrice && price <= maxPrice)
			return true;
		return false;
	}

private:
	double minPrice;
	double maxPrice;
};
