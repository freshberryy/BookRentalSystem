#pragma once
#include "Command.h"
class ReturnCommand : public Command
{
public:
	void execute() override;

private:
	Library* library;
	RentalManager* manage;
	Customer* customer;
};

