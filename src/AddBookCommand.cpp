#include "AddBookCommand.h"
#include<string>
class BookPricePolicy;

AddBookCommand::AddBookCommand(Library* lib, const string& name, User*user) :Command(name)
{
	this->lib = lib;
    this->user = user;
}


void AddBookCommand::execute()
{
    if (!user->isAdmin())
    {
        cout << "관리자만 실행 가능한 명령입니다.\n";
        return;
    }
        

    string title, author, publisher;
    double price;
    int year;

    cout << "\n[추가할 도서 정보 입력]\n";
    cout << "---------------------------\n";
    cout << "책 제목     : ";
    getline(cin, title);

    cout << "글쓴이      : ";
    getline(cin, author);

    cout << "출판사      : ";
    getline(cin, publisher);

    cout << "출판년도    : ";
    cin >> year;

    cout << "대여료      : ";
    cin >> price;
    cin.ignore(); 

    cout << "---------------------------\n";

    BookPricePolicy* p = new FixedPricePolicy();

    char* tmp = new char[title.size()+1];
    strcpy_s(tmp, title.size() + 1, title.c_str());

    Book* book = new Book(tmp, author, publisher, year, p, price);
    lib->addBook(book);
    cout << "도서 추가됨!\n";
}
