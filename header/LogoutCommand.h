#pragma once
#include"Command.h"
class LogoutCommand : public Command
{
public:
	LogoutCommand(UserManager*, string const&);
	void execute();

private:
	UserManager* um;
};

