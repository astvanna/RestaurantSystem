CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -pthread -g
LDLIBS = -lgtest -lgtest_main -pthread

SRCS = Appetizer.cpp Customer.cpp Menu.cpp Order.cpp Dish.cpp Entree.cpp Dessert.cpp Restaurant.cpp
TEST_SRCS = $(SRCS) restaurantTests.cpp
MAIN_SRCS = $(SRCS) main.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
TEST_TARGET = restaurantTest
MAIN_TARGET = Restaurant

.PHONY: all test clean

all: $(MAIN_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TEST_TARGET) $(MAIN_TARGET) *.o
