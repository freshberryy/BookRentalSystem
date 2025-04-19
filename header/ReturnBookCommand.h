#pragma once
#include "Command.h"
class ReturnBookCommand : public Command
{
public:
	ReturnBookCommand(Library*, RentalManager*, Customer*, const string&);
	void execute() override;

private:
	Library* lib;
	RentalManager* rm;
	Customer* cus;
	string title;
};

