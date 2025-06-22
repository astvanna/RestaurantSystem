#include "Restaurant.h"
#include <iostream>
#include <limits>

void displayWelcome() {
    std::cout << "---------------------------------\n";
    std::cout << "   RESTAURANT ORDERING SYSTEM    \n";
    std::cout << "---------------------------------\n\n";
}

void displayMainMenu() {
    std::cout << "\nMAIN MENU:\n";
    std::cout << "1. View Menu\n";
    std::cout << "2. Place New Order\n";
    std::cout << "3. View Order History\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter choice: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Restaurant restaurant;
    restaurant.showMenu();
    displayWelcome();
    
    while (true) {
        displayMainMenu();
        
        int choice;
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                restaurant.showMenu();
                break;
            }
            case 2: {
                std::string customerName;
                std::cout << "Enter customer name: ";
                std::getline(std::cin, customerName);
                restaurant.placeNewOrder(customerName);
                break;
            }
            case 3: {
                std::string customerName;
                std::cout << "Enter customer name: ";
                std::getline(std::cin, customerName);
                restaurant.viewCustomerOrderHistory(customerName);
                break;
            }
            case 4: {
                std::cout << "Exiting system. Goodbye!\n";
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
    
    return 0;
}
