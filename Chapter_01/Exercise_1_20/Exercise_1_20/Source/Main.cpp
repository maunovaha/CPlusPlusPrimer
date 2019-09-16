#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;

    std::cout << "Hello, and welcome to record book transactions!\n"
        << "The program accepts multiple transactions separated by spaces.\n"
        << "Example input: `1-100-10000-X 2 20.00 1-200-20000-X 3 15.00`\n\n"
        << "Please enter your book(s) details: ";

    while (std::cin >> book) {
        std::cout << book << std::endl;
    }

    return 0;
}