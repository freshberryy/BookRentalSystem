#pragma once
#include<functional>
#include<vector>
#include<string>
using namespace std;
class Rental;
class RentalHistory
{
public:
	RentalHistory();
	~RentalHistory();
	void addRental(Rental* rhs);

	//반드시 호출측에서 자원 해제 해주세요.
	//책 제목으로 대여 리스트 반환
	Rental** getRentalByBookTitle(string& title);

	//반드시 호출측에서 자원 해제 해주세요.
	//반납되지 않은 대여 리스트 반환
	Rental** getAllActiveRentals();

	//책 제목으로 반납되지 않은 대여기록 반환
	Rental* getActiveRentalByTitle(const string& title);

	int getSize() const;
	void printAll()const;
	void sort(std::function<bool(Rental*, Rental*)> cmp);


private:
	Rental** records;
	int size;
	int capacity;
	void resize();
};

