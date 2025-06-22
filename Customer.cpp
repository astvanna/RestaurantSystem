#include <iostream>
#include "Customer.h"
#include "Order.h"

Customer::Customer(std::string customerName, std::string contact) : name(std::move(customerName)), contactInfo(std::move(contact)) {}

Customer::Customer(const Customer& other) : name(other.name), contactInfo(other.contactInfo), orderHistory(other.orderHistory) {}

Customer& Customer::operator=(const Customer& other) {
	if (this != &other) {
		name = other.name;
		contactInfo = other.contactInfo;
		orderHistory = other.orderHistory;
	}
	return *this;
}

Customer::Customer(Customer&& other) noexcept : name(std::move(other.name)), contactInfo(std::move(other.contactInfo)), orderHistory(std::move(other.orderHistory)) {}

Customer& Customer::operator=(Customer&& other) noexcept {
	if (this != &other) {
		name = std::move(other.name);
		contactInfo = std::move(other.contactInfo);
		orderHistory = std::move(other.orderHistory);
	}
	return *this;
}

void Customer::placeOrder(const Order& order) {
	orderHistory.push_back(order);
}

void Customer::viewOrderHistory() const {
	std::cout << "\nOrder History for " << name << ":\n";
	for (size_t i = 0; i < orderHistory.size(); i++) {
		orderHistory[i].displayOrder();
	}
}

std::string Customer::getName() const {
	return name;
}
