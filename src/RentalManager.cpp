#include "RentalManager.h"

string addDays(const string& start, int days)
{
	tm tm = {};
	istringstream ss(start);
	ss >> get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
	{
		throw runtime_error("날짜 파싱 실패");
	}

	time_t tt = mktime(&tm);
	if (tt == -1)
	{
		throw runtime_error("유효하지 않은 날짜입니다.");
	}
	system_clock::time_point tp = system_clock::from_time_t(tt);
	tp += std::chrono::seconds(60 * 60 * 24 * days);
	time_t  new_tt = system_clock::to_time_t(tp);
	std::tm new_tm = {};
	localtime_s(&new_tm, &new_tt);
	std::ostringstream out;
	out << std::put_time(&new_tm, "%Y-%m-%d");
	return out.str();
}


RentalManager::RentalManager(LateFeePolicy<double>* feePolicy, InventoryManager* inventory)
{
	this->feePolicy = feePolicy;
	this->inventory = inventory;
}

RentalManager::~RentalManager()
{
	delete feePolicy;
}

Rental* RentalManager::rentBook(Customer* customer, Book* book, string rentDate)
{
	try
	{
		if (customer->getProfile().canRent() && inventory->isAvailable(book->getTitle()))
		{
			int rentDuration = customer->getProfile().getRentalPolicy()->maxRentDuration();

			customer->getProfile().incrementRent();

			Rental * rental = new Rental(book, customer, rentDate, addDays(rentDate, rentDuration), false);
			history.addRental(rental);

			return rental;
		}
		else if(!customer->getProfile().canRent())
		{
			throw RentalLimitExceededException(customer->getUserCredential().getUserId(), customer->getProfile().getRentalLimit(), "대여 가능 한도를 초과했습니다.");
			return nullptr;
		}
		else if (!inventory->isAvailable(book->getTitle()))
		{
			throw OutOfStockException("재고 부족", book->getTitle());
			return nullptr;
		}
		else
		{
			throw invalid_argument("대여 한도를 초과했으며, 도서의 재고도 부족합니다.");
			return nullptr;
		}
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
		return nullptr;
	}
	
}

Rental* RentalManager::returnBook(Customer* customer, string bookTitle, string returnDate)
{
	Rental* target = history.getActiveRental(customer,bookTitle);
	try
	{
		if (target)
		{
			target->markReturned(returnDate);
			customer->getProfile().decrementRent();
			return target;
		}
		throw invalid_argument("반납할 대여 기록이 없습니다");
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
		return nullptr;
	}

}


RentalHistory& RentalManager::getAllHistory() 
{
	return history;
}

Rental** RentalManager::getUnreturnedByCustomer(Customer* customer)
{
	Rental** tmp = customer->getHistory().getAllActiveRentals();
	int unReturned = 0, size = customer->getHistory().getSize();
	for (int i = 0; i < size; i++)
	{
		if (tmp[i]->getBorrower() == customer && !tmp[i]->getReturned())
			unReturned++;
	}
	Rental** ret = new Rental * [unReturned];
	int idx = 0;
	for (int i = 0; i < size; i++)
	{
		if (tmp[i]->getBorrower() == customer && !tmp[i]->getReturned())
			ret[idx++] = tmp[i];
	}
	for (int i = 0; i < size; i++)
	{
		delete tmp[i];

	}
	delete[] tmp;
	return ret;
}

double RentalManager::calculateLateFee(Rental* rental, string currentDate)
{
	return feePolicy->calculate(*rental, currentDate);
}

Rental** RentalManager::getRentalListByCustomer(Customer* customer, int size)
{
	Rental** tmp = new Rental * [size];
	tmp = history.getRentalsByCustomer(customer);
	return tmp;
}
