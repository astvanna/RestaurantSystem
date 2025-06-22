#include "Restaurant.h"

Restaurant::Restaurant() {}

Restaurant::~Restaurant() {
	for (size_t i = 0; i < customers.size(); i++) {
		delete customers[i];
	}
}

void Restaurant::showMenu() const {
	menu.displayMenu();
}

Customer* Restaurant::getCustomerByName(const std::string& name) {
	for (size_t i = 0; i < customers.size(); i++) {
		if (customers[i]->getName() == name) {
			return customers[i];
		}
	}
	Customer* newCustomer = new Customer(name, "");
	customers.push_back(newCustomer);
	return newCustomer;
}

void Restaurant::placeNewOrder(const std::string& customerName) {
	Customer* customer = getCustomerByName(customerName);
	Order newOrder(customer);
	
	showMenu();
	std::cout << "\nEnter dish names to order (type 'done' when finished):\n";
	std::string dishName;
	
	while (true) {
		std::cout << "> ";
		std::getline(std::cin, dishName);
		if (dishName == "done") break;
		
		Dish* dish = menu.getDishByName(dishName);
		if (dish) {
			newOrder.addDish(dish);
			std::cout << "Added " << dishName << " to order.\n";
		} else {
			std::cout << "Dish not found!\n";
		}
	}
	
	customer->placeOrder(newOrder);
	orders.push_back(newOrder);
	std::cout << "Order placed successfully!\n";
}

void Restaurant::viewCustomerOrderHistory(const std::string& customerName) const {
	for (size_t i = 0; i < customers.size(); i++) {
		if (customers[i]->getName() == customerName) {
			customers[i]->viewOrderHistory();
			return;
		}
	}
	std::cout << "Customer not found.\n";
}
