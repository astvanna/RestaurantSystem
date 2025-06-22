#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "Dish.h"
#include "Customer.h"

class Customer;

class Order {
private:
	const Customer* customer;
	std::vector<Dish*> orderedDishes;
	double totalPrice;
public:
	Order(const Customer* customer);
	Order(const Order& other);
	Order& operator=(const Order& other);
	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;
	~Order() = default;
	
	void addDish(Dish* dish);
	void calculateTotal();
	void displayOrder() const;
};

#endif
