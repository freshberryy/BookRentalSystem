#pragma once
#include "Command.h"
class User;
class DeleteBookCommand : public Command
{
	DeleteBookCommand(Library*, const string&, User*);
	void execute()override;

private:
	Library* lib;
	User* user;
};

