#pragma once
#include "Command.h"
class ListBooksCommand : public Command
{
public:
	ListBooksCommand(Library *, const string&);
	void execute() override;

private:
	string name;
	Library* lib;
};

