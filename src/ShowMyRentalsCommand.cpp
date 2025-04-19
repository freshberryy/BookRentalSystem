#include "ShowMyRentalsCommand.h"

ShowMyRentalsCommand::ShowMyRentalsCommand(RentalManager* rm, Customer* cus, const string& name) : Command(name)
{
	this->rm = rm;
	this->cus = cus;
}


void ShowMyRentalsCommand::execute()
{
	int len = rm->getAllHistory().getListSizeByCustomer(cus);
	Rental** tmp = rm->getRentalListByCustomer(cus, len);

	for (int i = 0; i < len; i++)
	{
		tmp[i]->serialize(cout);
	}
	delete[] tmp;
}