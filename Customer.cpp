#include "Customer.h"

Customer::Customer(){}

Customer::Customer(string name, UserCredential credential, CustomerProfile profile, RentalHistory history) : User(name, credential), profile(profile), history(history){}

void Customer::displayMenu() const
{
    cout << "\n======  고객 메뉴 ======\n";
    cout << "1. 도서 검색\n";
    cout << "2. 도서 대여\n";
    cout << "3. 도서 반납\n";
    cout << "4. 대여 이력 조회\n";
    cout << "5. 내 정보 보기\n";
    cout << "0. 로그아웃\n";
    cout << "=========================\n";
    cout << ">> 번호를 선택하세요: ";
}

Customer* Customer::clone() const
{
    return new Customer(*this);
}

CustomerProfile& Customer::getProfile()
{
    return profile;
}

RentalHistory& ::Customer::getHistory()
{
    return history;
}
