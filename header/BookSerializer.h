#pragma once
#include<iostream>
#include "Book.h"

class BookSerializer
{
public:
	static void serialize(const Book& rhs, ostream& os);
	static Book* deserialize(const string& rhs);
};

