#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include"LateFeePolicy.h"
#include"RentalHistory.h"
#include"Customer.h"
#include"Book.h"
#include"Rental.h"
using namespace std;
using namespace chrono;

string addDays(const string& start, int days);




class RentalManager
{
public:
	RentalManager();
	RentalManager(LateFeePolicy<double>* feePolicy);
	~RentalManager();
	Rental* rentBook(Customer* customer, Book* book, string rentDate);
	Rental* returnBook(string bookTitle, string returnDate);
	RentalHistory& getAllHistory();

	//호출하고 반드시 배열 해제해주세요.
	//고객의 미반납 도서 리스트 반환
	Rental** getUnreturnedByCustomer(Customer* customer);

	double calculateLateFee(Rental*, string currentDate);

private:
	LateFeePolicy<double>* feePolicy;
	RentalHistory history;
};

