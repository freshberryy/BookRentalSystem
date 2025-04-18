#include "Library.h"

Library::Library() : bookCount(0), capacity(1000)
{
	books = new Book * [capacity];
}

Library::~Library()
{
	for (int i = 0; i < bookCount; i++)
	{
		delete books[i];
	}
	delete[] books;
}

void Library::resize()
{
	Book** tmp = new Book * [capacity * 2];
	for (int i = 0; i < bookCount; i++)
	{
		tmp[i] = books[i];
	}
	delete[] books;
	books = tmp;
	capacity *= 2;
}

void Library::addBook(Book* book)
{
	if (bookCount == capacity)
		resize();
	string title = book->getTitle();
	
	for (int i = 0; i < bookCount; i++)
	{
		if (books[i]->getTitle() == title)
		{
			inventory.increase(title);
			return;
		}
	}
	//Library에서만 수명을 관리하므로(소유권을 넘기므로) 얕은 복사
	books[bookCount++] = book;
	inventory.increase(title);
}

bool Library::removeBook(const string& title)
{
	for (int i = 0; i < bookCount; i++)
	{
		if (books[i]->getTitle() == title)
		{
			delete books[i];
			for (int j = i; j < bookCount - 1; j++)
			{
				books[j] = books[j + 1];
			}
			bookCount--;
			return inventory.decrease(title);  
		}
	}
	return false;

}

Book* Library::findByTitle(const string& title) const
{
	for (int i = 0; i < bookCount; i++)
	{
		if (books[i]->getTitle() == title)
		{
			return books[i];
		}
	}
	return nullptr;
}

int Library::getBookCount()const
{
	return bookCount;
}

Book* Library::getBookAt(int index)
{
	if (index < 0 || index >= bookCount)
		return nullptr;
	return books[index];
}

void Library::listAllBooks(ostream& os) const
{
	for (int i = 0; i < bookCount; i++)
	{
		os << left;  
		os << setw(10) << "책 제목" << " : " << books[i]->getTitle() << "\n"
			<< setw(10) << "글쓴이" << " : " << books[i]->getAuthor() << "\n"
			<< setw(10) << "출판사" << " : " << books[i]->getPublisher() << "\n"
			<< setw(10) << "출판년도" << " : " << books[i]->getPublishYear() << "\n"
			<< setw(10) << "대여료" << " : " << books[i]->getFinalPrice() << "\n"
			<< setw(10) << "재고 수량" << " : " << inventory.getQuantity(books[i]->getTitle()) << "\n\n";
	}
}

ostream& operator<<(const Library& lib, ostream& os)
{
	lib.listAllBooks(os);
	return os;
}

bool Library::isAvailable(const string& title)
{
	return inventory.isAvailable(title);
}

int Library::getBookStock(const string& title)
{
	return inventory.getQuantity(title);
}

void Library::printInventory(ostream& os)
{
	inventory.printAllStock(os);
}

vector<Book*> Library::getAvailableBooks()
{
	vector<Book*> ret;

	for (int i = 0; i < bookCount; i++)
	{
		if (inventory.isAvailable(books[i]->getTitle()))
		{
			ret.push_back(books[i]);
		}
	}
	return ret;
}

void Library::filterBooks(std::function<bool(const Book& book)> pred, ostream& os)
{
	for (int i = 0; i < bookCount; i++)
	{
		if (pred(*books[i]))
		{
			os << left;
			os << setw(10) << "책 제목" << " : " << books[i]->getTitle() << "\n"
				<< setw(10) << "글쓴이" << " : " << books[i]->getAuthor() << "\n"
				<< setw(10) << "출판사" << " : " << books[i]->getPublisher() << "\n"
				<< setw(10) << "출판년도" << " : " << books[i]->getPublishYear() << "\n"
				<< setw(10) << "대여료" << " : " << books[i]->getFinalPrice() << "\n"
				<< setw(10) << "재고 수량" << " : " << inventory.getQuantity(books[i]->getTitle()) << "\n\n";
		}
	}
}

Book** Library::filterBooks(std::function<bool(const Book&)> pred)
{
	int size = 0, idx = 0;
	for (int i = 0; i < bookCount; i++)
	{
		if (pred(*books[i])) size++;
	}

	Book** ret = new Book * [size];
	for (int i = 0; i < bookCount; i++)
	{
		if (pred(*books[i]))
			ret[idx++] = books[i];
	}
	return ret;
	//TODO: 리턴형 벡터로 변경하기
}

void Library::loadFromFile(const string& filename)
{
	vector<Book*> tmp;
	CSVLoader<Book>::load(filename, tmp);
	for (int i = 0; i < tmp.size(); i++)
	{
		addBook(tmp[i]);
	}
}

void Library::saveToFile(const string& filename)
{
	vector<Book*> tmp;
	for (int i = 0; i < bookCount; i++)
	{
		tmp.push_back(books[i]);
	}
	CSVLoader<Book>::save(filename, tmp);
}