#include "LogoutCommand.h"

LogoutCommand::LogoutCommand(UserManager* um, const string& name) :Command(name)
{
	this->um = um;
}

void LogoutCommand::execute()
{
	try
	{
		User* current = um->getCurrentUser(); 
		um->logout(); 
		cout << "�α׾ƿ� �Ϸ�!\n";
	}
	catch (const exception& e)
	{
		cerr << "�α׾ƿ� ����: " << e.what() << endl;
	}
}
