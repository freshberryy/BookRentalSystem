#include "UserManager.h"

UserManager::UserManager() : capacity(10)
{
	users = new User * [capacity];
	currentUser = nullptr;
}

UserManager::~UserManager()
{
	for (int i = 0; i < capacity; i++)
	{
		delete users[i];
	}
	delete[] users;
}

bool UserManager::addUser(User* user)
{
	if (userCount == capacity)
		resize();
	users[userCount++] = user;

	return users[userCount - 1] == user;
}

void UserManager::resize()
{
	User** tmp = new User * [capacity * 2];
	for (int i = 0; i < userCount; i++)
	{
		tmp[i] = users[i];
	}
	delete[] users;
	users = tmp;
	capacity *= 2;
}

bool UserManager::login(const string& id, const string& pw)
{
	try
	{
		for (int i = 0; i < userCount; i++)
		{
			if (users[i]->getUserCredential().getUserId() == id && users[i]->getUserCredential().getPassword() == pw)
			{
				currentUser = users[i];
				return true;
			}
		}
		throw invalid_argument("없는 사용자입니다.\n");
	}
	catch (invalid_argument& e)
	{
		cout << "ERROR: " << e.what();
		return false;
	}
}

User* UserManager::getCurrentUser() const
{
	return currentUser;
}

void UserManager::loadUsers(const string& file)
{
	// TODO: 파일 입출력으로 대체해야 하고, (ex. users.csv) 사용자 추가 실패 시 예외처리 구현

	addUser(new Admin("관리자", UserCredential("juha", "9889")));
	addUser(new Customer("김철수", UserCredential("kimcs", "1111"),
		CustomerProfile(new BasicRentalPolicy(), 0, 0), RentalHistory()));
	addUser(new Customer("이영희", UserCredential("leeyh", "2222"),
		CustomerProfile(new PremiumRentalPolicy(), 0, 0), RentalHistory()));
	addUser(new Customer("박준형", UserCredential("parkjh", "3333"),
		CustomerProfile(new BasicRentalPolicy(), 0, 0), RentalHistory()));
	addUser(new Customer("최유리", UserCredential("choiyr", "4444"),
		CustomerProfile(new PremiumRentalPolicy(), 0, 0), RentalHistory()));
	addUser(new Customer("정지훈", UserCredential("jungjh", "5555"),
		CustomerProfile(new BasicRentalPolicy(), 0, 0), RentalHistory()));

	for (int i = 1; i < userCount; i++)
		static_cast<Customer*>(users[i])->getProfile().applyPolicy();
}

