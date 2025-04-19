#include "RentBookCommand.h"

RentBookCommand::RentBookCommand(Library* lib, RentalManager* rm, Customer* cus, const string&name):Command(name)
{
	this->lib = lib;
	this->rm = rm;
	this->cus = cus;
}

void RentBookCommand::execute()
{
    cout << "\n[도서 대여]\n";
    cout << "---------------------------\n";
    cout << "대여할 도서명을 입력하세요: ";

    string title;
    cin.ignore();               
    getline(cin, title);        

    Rental* tmp = rm->rentBook(cus, lib->findByTitle(title), getToday());

    cout << "---------------------------\n";
    if (tmp == nullptr)
        cout << "대여에 실패했습니다.\n";
    else
        cout << "대여에 성공했습니다.\n";
}

