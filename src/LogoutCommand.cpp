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
		cout << "로그아웃 완료!\n";
	}
	catch (const exception& e)
	{
		cerr << "로그아웃 실패: " << e.what() << endl;
	}
}
