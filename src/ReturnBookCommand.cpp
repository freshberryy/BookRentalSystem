#include "ReturnBookCommand.h"


ReturnBookCommand::ReturnBookCommand(Library* lib, RentalManager* rm, Customer* cus, const string& name) :Command(name)
{
	this->lib = lib;
	this->rm = rm;
	this->cus = cus;
}

void ReturnBookCommand::execute()
{
    cout << "\n[도서 반납]\n";
    cout << "---------------------------\n";
    cout << "반납할 책 제목을 입력하세요: ";

    string title;
    cin.ignore();              
    getline(cin, title);      

    Rental* tmp = rm->returnBook(cus, title, getToday());

    cout << "---------------------------\n";
    if (tmp == nullptr)
        cout << "반납에 실패했습니다.\n";
    else
        cout << "반납에 성공했습니다.\n";
}
