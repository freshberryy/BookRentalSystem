#include "DeleteBookCommand.h"

DeleteBookCommand::DeleteBookCommand(Library* lib, const string& name, User* user) :Command(name)
{
	this->lib = lib;
	this->user = user;
}

void DeleteBookCommand::execute()
{
	if (!user->isAdmin())
	{
		cout << "관리자만 실행 가능한 명령입니다.\n";
		return;
	}

	string title;
	cout << "\n[추가할 도서 정보 입력]\n";
	cout << "---------------------------\n";
	cout << "책 제목     : ";
	getline(cin, title);



	if (lib->removeBook(title))
		cout << "삭제 성공!\n";
	else
		cout << "삭제 실패.\n";
}
