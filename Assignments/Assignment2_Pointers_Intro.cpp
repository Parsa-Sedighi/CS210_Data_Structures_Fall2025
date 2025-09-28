#include <iostream>

int main() {

    int price = 100; // Initializing and assigning price integer variable.
    int* pPrice = NULL; // Initializing pointer of the same type as price, assigning it to NULL.
    pPrice = &price; // Assigning the address of price to the pointer pPrice.

    int discount = 25;  // Initializing and assigning discount integer variable.
    int * pDiscount = &discount; // Initializing and assigning the address of discount to pDiscount.  

    std::cout << "Price value: " << price << std::endl; // Printing the value of price.
    std::cout << "Price address: " << pPrice << std::endl; // Printing the address of price.

    std::cout << "discount value: " << discount << std::endl; // Printing the value of discount.
    std::cout << "discount address: " << pDiscount << std::endl; // Printing the address of discount.


    return 0;
}