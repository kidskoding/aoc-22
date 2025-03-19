#include <iostream>

#include "calorie_counting.hpp"
#include "sample_problem.hpp"
#include "rock_paper_scissors.hpp"

int main() {
    std::cout << "Problem 0: " << '\n';
    sample_problem();

    std::cout << "Problem 1.1: " << getMaxCalories() << '\n';
    std::cout << "Problem 1.2: " << getTopThreeCalories() << '\n';
    std::cout << "Problem 2.1: " << getScore() << '\n';
    std::cout << "Problem 2.2: " << getScore2() << '\n';
}
