#include <iostream>
#include "Book.h"
#include "FixedPricePolicy.h"
#include "DiscountPricePolicy.h"
using namespace std;

int main()
{
    cout << "===== 생성자 테스트 =====\n";
    BookPricePolicy* policy1 = new FixedPricePolicy();
    Book b1((char*)"C++ Programming", "Bjarne Stroustrup", "Addison-Wesley", 2013, policy1, 5000);

    cout << "===== 복사 생성자 테스트 =====\n";
    Book b2(b1);  // 복사 생성자

    cout << "===== 복사 대입 연산자 테스트 =====\n";
    Book b3((char*)"Temp", "None", "None", 0, new FixedPricePolicy(), 0);
    b3 = b1;  // 복사 대입

    cout << "===== 이동 생성자 테스트 =====\n";
    Book b4(std::move(b1));  // 이동 생성자

    cout << "===== 이동 대입 연산자 테스트 =====\n";
    Book b5((char*)"Another", "Temp", "Temp", 2020, new DiscountPricePolicy(0.1), 3000);
    b5 = std::move(b2);  // 이동 대입

    cout << "===== 프로그램 종료 전 소멸자 테스트 =====\n";
    return 0;
}
