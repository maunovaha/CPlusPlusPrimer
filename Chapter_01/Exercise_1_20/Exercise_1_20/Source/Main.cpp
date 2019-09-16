#include <iostream>
#include "Sales_item.h"

int main()
{
    /*do {
        std::cout << "Enter book ISBN, number of copies and average price: " << std::endl;

        Sales_item book;
        std::cin >> book;

        std::cout << "Stored book details: " << book << std::endl << std::endl;
    }
    while (!std::cin.fail());*/

    // for (Sales_item item; std::cin >> item; std::cout << item << std::endl);

    Sales_item book;

    while (std::cin >> book) {
        std::cout << "Give details for book: " << std::endl;

        std::cout << book << std::endl;
    }
    
    return 0;
}