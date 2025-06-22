#include <gtest/gtest.h>
#include "Dish.h"
#include "Appetizer.h"
#include "Entree.h"
#include "Dessert.h"
#include "Menu.h"
#include "Customer.h"
#include "Order.h"
#include "Restaurant.h"

TEST(DishTest, DishCtor) {
	Dish dish("Pepperoni Pizza", 15.99);
	EXPECT_EQ(dish.getName(), "Pepperoni Pizza");
	EXPECT_DOUBLE_EQ(dish.getPrice(), 15.99);
}

TEST(AppetizerTest, AppetizerDisplay) {
	Appetizer app("Tabouleh", 12.99, false);
	testing::internal::CaptureStdout();
	app.display();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Tabouleh - $12.99");
}

TEST(EntreeTest, EntreeDisplay) {
	Entree entree("Khorovats", 28.99, 950);
	testing::internal::CaptureStdout();
	entree.display();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Khorovats \t$28.99 (950 cal)");
}

TEST(DessertTest, DessertDisplay) {
	Dessert dessert("Baklava", 8.99, true);
	testing::internal::CaptureStdout();
	dessert.display();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Baklava - $8.99 [CONTAINS NUTS]");
}

TEST(MenuTest, AddDish) {
	Menu menu;
	menu.addDish(new Appetizer("Chicken wings", 8.99, true));
	Dish* found = menu.getDishByName("Chicken wings");
	ASSERT_NE(found, nullptr);
	EXPECT_EQ(found->getName(), "Chicken wings");
}

TEST(CustomerTest, CustomerOrder) {
	Customer customer("Turencho", "665");
	Dish* dish = new Appetizer("Shrimp cocktail", 6.99, false);
	Order order(&customer);
	order.addDish(dish);
	customer.placeOrder(order);
	EXPECT_EQ(customer.getOrderHistory().size(), 1);
	delete dish;
}

TEST(OrderTest, OrderTotal) {
	Customer customer("Ashxen", "666");
	Order order(&customer);
	order.addDish(new Appetizer("Ceasar salad", 7.99, false));
	order.addDish(new Dessert("Chocolate Mousse", 8.99, true));
	testing::internal::CaptureStdout();
	order.displayOrder();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Total: $16.98") != std::string::npos);
}

TEST(RestaurantTest, GetCustomer) {
	Restaurant restaurant;
	Customer* cust = restaurant.getCustomerByName("Tyomik");
	EXPECT_EQ(cust->getName(), "Tyomik");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
