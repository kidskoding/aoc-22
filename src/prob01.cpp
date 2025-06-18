#include "prob01.h"

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

int getMaxCalories() {
    std::vector<int> calories;
    std::fstream fs("./input/prob01.txt");

    std::string line;
    int totalCalories = 0;
    while(std::getline(fs, line)) {
        if(line.empty()) {
            calories.push_back(totalCalories);
            totalCalories = 0;
        } else {
            totalCalories += std::stoi(line);
        }
    }

    return *std::max_element(calories.begin(), calories.end());
}

int getTopThreeCalories() {
    std::vector<int> calories;
    std::fstream fs("./input/prob01.txt");

    std::string line;
    int totalCalories = 0;
    while(std::getline(fs, line)) {
        if(line.empty()) {
            calories.push_back(totalCalories);
            totalCalories = 0;
        } else {
            totalCalories += std::stoi(line);
        }
    }

    std::sort(calories.begin(), calories.end(), std::greater<int>());
    return calories[0] + calories[1] + calories[2];
}
