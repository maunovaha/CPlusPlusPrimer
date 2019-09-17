#include <iostream>
#include "Sales_item.h"

int main()
{
    std::cout << "Hello, and welcome to record book transactions!\n"
        << "The program accepts multiple books with same ISBN.\n"
        << "Example input: `1-100-10000-X 2 10.00 1-100-10000-X 3 20.00 "
        << "2-200-20000-X 2 10.00 2-200-20000-X 3 25.00`\n\n"
        << "Please enter your book(s) details: ";

    Sales_item previous;

    if (std::cin >> previous) {
        Sales_item current;
        int replicas = 1;

        while (std::cin >> current) {
            if (previous.isbn() == current.isbn()) {
                ++replicas;
            }
            else {
                std::cout << previous << " occurs " << replicas << " times" << std::endl;
                previous = current;
                replicas = 1;
            }
        }

        std::cout << previous << " occurs " << replicas << " times" << std::endl;
    }
    else {
        std::cout << "\nNo data?!" << std::endl;
        return -1;
    }

    return 0;
}