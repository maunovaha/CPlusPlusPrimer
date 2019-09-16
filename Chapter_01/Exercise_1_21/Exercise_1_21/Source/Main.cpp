#include <iostream>
#include "Sales_item.h"

int main()
{
    std::cout << "Hello, and welcome to record book transactions!\n"
        << "The program accepts two books with same ISBN.\n"
        << "Example input: `1-100-10000-X 2 10.00 1-100-10000-X 3 20.00`\n\n"
        << "Please enter your book(s) details: ";

    Sales_item book1;
    Sales_item book2;

    std::cin >> book1 >> book2;

    if (book1.isbn() != book2.isbn()) {
      std::cerr << "Error: The given books had different ISBNs!" << std::endl;
      return -1;
    }

    std::cout << "The sum is: " << (book1 + book2) << std::endl;
    return 0;
}