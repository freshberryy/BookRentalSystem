#pragma once
#include "Command.h"
class User;
class Book;

class AddBookCommand : public Command
{
public:
	AddBookCommand(Library*, const string&, User*);
	void execute() override;

private:
	Library* lib;
	User* user;
};

