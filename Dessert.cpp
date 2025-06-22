#include "Dessert.h"
#include <iostream>

Dessert::Dessert(std::string dishName, double dishPrice, bool nuts)
	: Dish(std::move(dishName), dishPrice), containsNuts(nuts) {}

void Dessert::display() const {
	Dish::display();
	if (containsNuts) {
		std::cout << " (CONTAINS NUTS)";
	}
}
