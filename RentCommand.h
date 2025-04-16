#pragma once
#include"Command.h"

class RentCommand : public Command
{
public:
	void execute() override;

private:
	Library* library;
	RentalManager* manage;
	Customer* customer;
};

