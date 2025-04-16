#pragma once
#include"UserManager.h"
#include"Library.h"
#include"RentalManager.h"
#include"Logger.h"

class Application
{
public:
	void run() {}
	void printMainMenu() {}
private:
	UserManager userManager;
	Library library;
	RentalManager rentalManager;
	Logger* logger;
};

