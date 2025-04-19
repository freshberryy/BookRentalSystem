#pragma once
#include"Command.h"


class RentBookCommand : public Command
{
public:
	RentBookCommand(Library*, RentalManager*, Customer*, const string&);
	void execute() override;

private:
	Library* lib;
	RentalManager* rm;
	Customer* cus;
	string title;
};

