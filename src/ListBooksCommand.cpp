#include "ListBooksCommand.h"

ListBooksCommand::ListBooksCommand(Library* lib, const string&name) : Command(name)
{
	this->lib = lib;
}

void ListBooksCommand::execute()
{
	lib->listAllBooks(std::cout);
}