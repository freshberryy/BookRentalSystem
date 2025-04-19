#include "LoginCommand.h"

LoginCommand::LoginCommand(UserManager* um, const string& name) :Command(name)
{
	this->um = um;
}

void LoginCommand::execute()
{
	string id, pw;
	cout << "아이디와 패스워드를 입력하세요: " << endl;
	cout << "ID: ";
	cin >> id;
	cout << "PASSWORD: ";
	cin >> pw;

	if (um->login(id, pw))
		cout << "로그인 성공!\n";
	else
		cout << "다시 시도하세요.\n";

}
