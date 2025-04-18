#include "InventoryManager.h"
#include <iomanip>

int InventoryManager::getQuantity(const string& title) const
{
	auto it = stock.find(title);

	try
	{
		if (it != stock.end())
		{
			return it->second;
		}
		else
		{
			throw domain_error("해당 제목의 책 재고가 없습니다.\n");
		}
	}
	catch (const exception& e)
	{
		cout << "ERROR: " << e.what();
		return -1;
	}
	
}

void InventoryManager::increase(const string& title)
{
	stock[title]++;
}

bool InventoryManager::decrease(const string& title)
{
	if (stock[title] <= 0) return false;
	stock[title]--;
	return true;
}

bool InventoryManager::isAvailable(const string& title) const
{
	auto it = stock.find(title);
	if (it == stock.end())
		return false;
	return it->second > 0;
}

void InventoryManager::printAllStock(ostream& os)
{
	for (auto it = stock.begin(); it != stock.end(); it++)
	{
		os << left;
		os << setw(10) << "책 제목" << " : " << it->first << "\n"
			<< setw(10) << "재고 수량" << " : " << it->second << "\n\n";

	}
}

ostream& operator<<(ostream& os, InventoryManager& rhs)
{
	rhs.printAllStock(os);
	return os;
}
