#pragma once
#include "Book.h"

class BookFilterByYearRange
{
public:
	BookFilterByYearRange(int start, int end) : start(start), end(end)
	{

	}

	bool operator()(const Book& rhs)
	{
		int now = rhs.getPublishYear();

		if (now >= start && now <= end)
			return true;
		return false;
	}

private:
	int start;
	int end;
};