#pragma once
#include<functional>
#include<vector>
#include"Rental.h"
class RentalHistory
{
public:
	RentalHistory();
	~RentalHistory();
	void addRental(Rental* rhs);

	//반드시 호출측에서 자원 해제 해주세요.
	Rental** getRentalByBookTitle(string& title);

	//반드시 호출측에서 자원 해제 해주세요.
	Rental** getAllActiveRentals();

	void printAll()const;
	void sort(std::function<bool(Rental*, Rental*)> cmp);


private:
	Rental** records;
	int size;
	int capacity;
	void resize();
};

