#pragma once
#include "Command.h"
class Catalog;
class SearchCommand : public Command
{
public:
	void execute() override;

private:
	Library* library;
	Catalog* catalog;
};

