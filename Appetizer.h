#ifndef APPETIZER_H
#define APPETIZER_H

#include "Dish.h"

class Appetizer : public Dish {
private:
	bool isSpicy;
public:
	Appetizer(std::string dishName, double dishPrice, bool spicy);
	void display() const override;
};

#endif
