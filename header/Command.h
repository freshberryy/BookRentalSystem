#pragma once
#include<iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Library.h"
#include"RentalManager.h"
#include "Customer.h"
#include "Book.h"
#include "Rental.h"
#include "UserManager.h"
using namespace std;
class Command
{
public:
	Command(const string& name);
	virtual void execute() = 0;
	virtual ~Command() = default;
	string getName()const { return name; }
	string getToday() const;
private:
	string name;
};

