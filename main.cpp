#include <iostream>
#include "Book.h"
#include "FixedPricePolicy.h"
#include "DiscountPricePolicy.h"
#include "Library.h"
using namespace std;

int main()
{
    Library lib;
    
    try
    {
        lib.loadFromFile("books.csv");
        lib.listAllBooks(std::cout);

    }
    catch (const exception& e)
    {
        cerr << "error: " << e.what() << endl;
    }
}
