#include "Appetizer.h"
#include <iostream>

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy) : Dish(std::move(dishName), dishPrice), isSpicy(spicy) {}

void Appetizer::display() const {
	Dish::display();
	if (isSpicy) {
		std::cout << " (SPICY)";
	}
}
