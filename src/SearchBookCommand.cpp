#include "SearchBookCommand.h"

SearchBookCommand::SearchBookCommand(Library* lib, const string& name) :Command(name)
{
	this->lib = lib;
}

void SearchBookCommand::execute()
{
    cout << "\n[도서 검색]\n";
    cout << "---------------------------\n";
    cout << "검색할 책 제목을 입력하세요: ";

    string title;
    cin.ignore();
    getline(cin, title);  

    Book* tmp = nullptr;

    cout << "---------------------------\n";
    try
    {
        tmp = lib->findByTitle(title);

        if (tmp != nullptr)
        {
            cout << "[검색 결과]\n";
            cout << "---------------------------\n";
            cout << *tmp;  
            cout << "---------------------------\n";
        }
        else
        {
            throw BookNotFoundException("책을 찾을 수 없습니다.");
        }
    }
    catch (const exception& e)
    {
        cerr << "오류: " << e.what() << "\n";
    }
}
