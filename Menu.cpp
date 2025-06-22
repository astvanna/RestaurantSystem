#include "Menu.h"
#include "Appetizer.h"
#include "Entree.h"
#include "Dessert.h"
#include <iostream>
#include <vector>

// Default constructor
Menu::Menu() {}

// Destructor
Menu::~Menu() {
	for (size_t i = 0; i < dishes.size(); i++) {
		delete dishes[i];
	}
}

// Add a dish to the menu
void Menu::addDish(Dish* dish) {
	dishes.push_back(dish);
}

// Display the entire menu
void Menu::displayMenu() const {
	std::cout << "\n---------- MENU ----------\n";
	
	// Display Appetizers
	std::cout << "\nAPPETIZERS:\n";
	for (size_t i = 0; i < dishes.size(); i++) {
		if (dynamic_cast<const Appetizer*>(dishes[i])) {
			dishes[i]->display();
			std::cout << "\n";
		}
	}
	
	// Display Entrees
	std::cout << "\nENTREES:\n";
	for (size_t i = 0; i < dishes.size(); i++) {
		if (dynamic_cast<const Entree*>(dishes[i])) {
			dishes[i]->display();
			std::cout << "\n";
		}
	}
	
	// Display Desserts
	std::cout << "\nDESSERTS:\n";
	for (size_t i = 0; i < dishes.size(); i++) {
		if (dynamic_cast<const Dessert*>(dishes[i])) {
			dishes[i]->display();
			std::cout << "\n";
		}
	}
	
	std::cout << "--------------------------\n";
}

// Find dish by name
Dish* Menu::getDishByName(const std::string& dishName) const {
	for (size_t i = 0; i < dishes.size(); i++) {
		if (dishes[i]->getName() == dishName) {
			return dishes[i];
		}
	}
	return nullptr;
}

// Copy constructor
Menu::Menu(const Menu& other) {
	for (size_t i = 0; i < other.dishes.size(); i++) {
		dishes.push_back(other.dishes[i]->clone());
	}
}

// Copy assignment
Menu& Menu::operator=(const Menu& other) {
	if (this != &other) {
		for (size_t i = 0; i < dishes.size(); i++) {
			delete dishes[i];
		}
		dishes.clear();
		for (size_t i = 0; i < other.dishes.size(); i++) {
			dishes.push_back(other.dishes[i]->clone());
		}
	}
	return *this;
}

// Move constructor
Menu::Menu(Menu&& other) noexcept {
	dishes = std::move(other.dishes);
	other.dishes.clear();
}

// Move assignment
Menu& Menu::operator=(Menu&& other) noexcept {
	if (this != &other) {
		for (size_t i = 0; i < dishes.size(); i++) {
			delete dishes[i];
		}
		dishes = std::move(other.dishes);
		other.dishes.clear();
	}
	return *this;
}
