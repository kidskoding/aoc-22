#include <iostream>
#include "calorie_counting.hpp"
#include "sample_problem.hpp"

int main() {
    std::cout << "Problem 0: " << '\n';
    sample_problem();

    std::cout << "Problem 1.1: " << getMaxCalories() << '\n';
    std::cout << "Problem 1.2: " << getTopThreeCalories() << '\n';
}
