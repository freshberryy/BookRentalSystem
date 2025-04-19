#pragma once
#include"Command.h"
class LoginCommand : public Command
{
public:
	LoginCommand(UserManager*, const string&);
	void execute();

private:
	UserManager* um;
};

