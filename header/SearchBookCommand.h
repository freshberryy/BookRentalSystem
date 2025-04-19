#pragma once
#include "Command.h"

class SearchBookCommand : public Command
{
public:
	SearchBookCommand(Library*, const string&);
	void execute() override;

private:
	Library* lib;
	string title;
};

