CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -O2 -g -I$(SRC_DIR)

SRC_DIR = src
BUILD_DIR = build

all: $(BUILD_DIR)/main
	./$(BUILD_DIR)/main

$(BUILD_DIR)/main: $(SRC_DIR)/main.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)
