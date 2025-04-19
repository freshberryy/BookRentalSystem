#pragma once
#include "Command.h"
class ShowMyRentalsCommand : public Command
{
public:
	ShowMyRentalsCommand(RentalManager*, Customer*, const string&);
	void execute();

private:
	RentalManager* rm;
	Customer* cus;
};

