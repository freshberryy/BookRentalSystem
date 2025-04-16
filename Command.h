#pragma once
#include "Library.h"
#include"RentalManager.h"
#include "Customer.h"
using namespace std;
class Command
{
public:
	virtual void execute() = 0;
	virtual ~Command() = default;
};

