#include "Entree.h"
#include <iostream>

Entree::Entree(std::string dishName, double dishPrice, int cal) : Dish(std::move(dishName), dishPrice), calories(cal) {}

void Entree::display() const {
	Dish::display();
	std::cout << " (" << calories << " cal)";
}
