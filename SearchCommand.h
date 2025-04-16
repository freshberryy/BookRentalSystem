#pragma once
#include "Command.h"
class SearchCommand : public Command
{
public:
	void execute() override {}

private:
	Library* library;
	RentalManager* manage;
	Customer* customer;
};

